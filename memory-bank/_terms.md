# Ubiquitous Language Index — projecteuler (объяснение решений)

> Канонический словарь терминов каталога визуализаций и коллекции подходов. Формат:
> `## [context::TermName]` · ссылки — обычные markdown-ссылки на этот же файл,
> `[context::Name](#анкор)` (не `[[wikilink]]` — GitHub его не рендерит кликабельным в обычном
> `.md`, только в своей Wiki). Контексты: `viz` — визуальные приёмы, `approach` — математические
> подходы. Обновляется атомарно со спеком.
>
> **Здесь нет конкретных задач.** Memory-bank хранит только переиспользуемое знание — приёмы и
> подходы; сама задача (её условие, решение, критерии корректности) живёт в своей директории
> (`euler{NNN}/README.md`), и каталог ссылается на неё только полем `Used in:` — одной строкой,
> не отдельным спеком. Задача, повторно использующая уже описанный подход/приём, дописывает
> строку в `Used in:`, а не заводит новый блок.
>
> Картинка каждого приёма — `visualizations/build/<slug>.png`, собранная скриптом
> `visualizations/build.sh` из `visualizations/skeleton.html` + `visualizations/examples/<slug>.*`;
> после любой правки `examples/` — перезапустить сборку, картинка руками не правится.

## [viz::Catalog]
Class: aggregate
Description: Каталог визуальных приёмов объяснения решения — `memory-bank/visualizations/`: исходники кадров в `examples/`, каркас `skeleton.html`, сборка `build.sh`, результат в `build/` (html + png на приём); описания приёмов — блоки `[viz::*]` этого файла.
Invariants:
  - MUST: один приём — один блок `[viz::*]` здесь + до трёх файлов `examples/<slug>.{css,html,js}` + `build/<slug>.{html,png}`
  - MUST: `build/*.png` — только результат `build.sh` (headless-браузер, светлая тема, ширина 720), никогда не рисуется и не правится руками; после правки `examples/` пересобирается
  - MUST: каждый приём привязан к [approach::Collection](#approachcollection) полем `Approach:` либо явно помечен «вне подходов» с причиной
  - MUST: повторная сборка приёма из каркаса + `examples/` даёт байт-в-байт ту же страницу
  - MUST: сквозной пример один на весь каталог — «числа до 20, кратные 2 или 3», не числа конкретной задачи
  - MUST NOT: оставлять файл-редирект без единой входящей ссылки (перед выбором редирект/удаление — grep)
Entities:
  - Card — один приём: блок здесь + код кадров + собранные html/png
  - Frame — один кадр картинки: Problem | Transform | Solution
Commands: AddCard, ReuseCard (дописать `Used in:`), ReviseCard (правка блока/кода + `build.sh`)
Depends on: [approach::Collection](#approachcollection), [viz::PageSkeleton](#vizpageskeleton)
Spec: [visualizations](specs/visualizations.md)

## [viz::PageSkeleton]
Class: value-object
Description: Общий каркас страницы (шрифты, цветовые токены, layout карточки и потока кадров) — `visualizations/skeleton.html`, плейсхолдеры `{{TITLE}} {{STDNAME}} {{SLUG}} {{TERM}} {{CSS}} {{HTML}} {{JS}}`; один на все приёмы.
Invariants:
  - MUST: не содержит ни одного приёмо-специфичного класса — те только в `examples/<slug>.css`
  - MUST: страница собирается подстановкой файлов `examples/` в плейсхолдеры без пересказа и без новых чисел/цветов (`build.sh`)
  - MUST: тёмная палитра включается только медиа-запросом и отключается атрибутом `data-theme="light"` — так снимок фиксируется светлым независимо от машины
  - MUST: несёт блок `.repo` с QR-кодом на репозиторий (`visualizations/qr-repo.svg`, плейсхолдер `{{QR}}`) и адресом текстом; приём не может его убрать; `build.sh` не собирает без файла QR
Depends on:
Spec: [visualizations](specs/visualizations.md)

## [viz::SkipCounting]
Class: entity
Standard name: Skip counting — счёт прыжками по числовой прямой
Description: Числа на прямой отмечаются прыжками постоянной длины; точка приземления каждого прыжка кратна длине прыжка.
Picture: ![Skip counting](visualizations/build/skip-counting.png)
Approach: — (вне коллекции подходов: показывает само понятие «кратно», а не способ счёта; подготовительный шаг перед любым из подходов, не подход сам по себе)
Sequence:
  1. Problem — числа на прямой без пометок, неизвестно, какие обладают нужным свойством
  2. Transform ×2 — прыжки шагом 2 отмечают кратные 2
  3. Transform ×3 — прыжки шагом 3 отмечают кратные 3
  4. Solution — объединённая прямая, каждое число окрашено по принадлежности (2 / 3 / оба)
Invariants:
  - MUST: свойство чисел проверяется делением/остатком (кратность, чётность, делимость)
  - MUST: число одновременных условий — одно или два
  - MUST NOT: применяться как буквальный ручной способ счёта для больших чисел — приём верен для любых чисел, но рисовать прыжки вручную непрактично; для больших чисел ту же идею считают формулой
  - MUST NOT: применяться для трёх и более условий одновременно — число цветов на прямой превышает различимое одним взглядом
Source: [SplashLearn](https://www.splashlearn.com/blog/how-to-teach-skip-counting/) · [WeAreTeachers](https://www.weareteachers.com/skip-counting/) · [Math and Movement](https://mathandmovement.com/product/skip-counting-hopping-mat-2s/)
Example: `visualizations/examples/skip-counting.{css,html,js}` → `visualizations/build/skip-counting.html`
Used in: [euler001](../euler001/README.md)
Depends on: [viz::Catalog](#vizcatalog)
Spec: [visualizations](specs/visualizations.md)

## [viz::BarModel]
Class: entity
Standard name: Bar model / tape diagram — методика Singapore Math
Description: Полоска фиксированной длины разбивается на непересекающиеся куски; длина каждого куска равна количеству элементов этой части.
Picture: ![Bar model](visualizations/build/bar-model.png)
Approach: [approach::InclusionExclusion](#approachinclusionexclusion)
Sequence:
  1. Problem — суммы по двум условиям складываются напрямую; итог зачёркнут (двойной счёт общей части)
  2. Transform − — те же два числа показаны перекрывающимися; дважды учтённая часть выделена
  3. Solution — полоска разбита на три честных куска (только 2, оба, только 3); их сумма — верный ответ
Invariants:
  - MUST: в задаче есть «или» между двумя условиями, часть элементов удовлетворяет обоим сразу
  - MUST NOT: применяться для трёх и более условий — полоска показывает только последовательность непересекающихся кусков подряд; при трёх пересекающихся условиях пересечения не выстраиваются в один ряд честно, раскладка перестаёт соответствовать структуре
Source: [Third Space Learning](https://thirdspacelearning.com/us/blog/teach-bar-model-method/) · [Maths — No Problem!](https://mathsnoproblem.com/en/approach/bar-modelling)
Example: `visualizations/examples/bar-model.{css,html}` (js не требуется — значения статичны) → `visualizations/build/bar-model.html`
Used in: [euler001](../euler001/README.md)
Depends on: [viz::Catalog](#vizcatalog), [approach::InclusionExclusion](#approachinclusionexclusion)
Spec: [visualizations](specs/visualizations.md)

## [viz::GaussPairing]
Class: entity
Standard name: Gauss's trick — парное сложение («радуга»)
Description: Числа складываются не по порядку, а парами с двух концов ряда; каждая пара даёт одну и ту же сумму.
Picture: ![Gauss pairing](visualizations/build/gauss-pairing.png)
Approach: [approach::ArithmeticProgressionSum](#approacharithmeticprogressionsum)
Sequence:
  1. Problem — числа ряда стоят по порядку, соединены «+», сумма не подсчитана
  2. Transform ↔ — числа сцеплены в пары с двух концов дугами; над каждой дугой — сумма пары
  3. Solution — итоговая сумма (число пар × сумма пары, плюс середина при нечётном числе элементов)
Invariants:
  - MUST: числа идут подряд с постоянным шагом (арифметическая прогрессия)
  - MUST: все промежуточные числа примера различны (пример 4·8·12·16·20, пары 24, итог 60; прецедент 30/30 — площадь и итог совпадали, объяснение читалось как замкнутое)
  - MUST NOT: применяться при переменном шаге — пары с двух концов дают разные суммы
Source: [eduSeed](https://eduseed.in/2025/12/04/gauss-method-of-addition-the-day-a-10-year-old-outsmarted-his-teacher/) · [NCTM — The Story of Gauss](https://www.nctm.org/Publications/TCM-blog/Blog/The-Story-of-Gauss/)
Example: `visualizations/examples/gauss-pairing.{css,html,js}` → `visualizations/build/gauss-pairing.html`
Used in: [euler001](../euler001/README.md)
Depends on: [viz::Catalog](#vizcatalog), [approach::ArithmeticProgressionSum](#approacharithmeticprogressionsum)
Spec: [visualizations](specs/visualizations.md)

## [viz::VennDiagram]
Class: entity
Standard name: Venn diagram — John Venn, 1880 (термин ввёл C. I. Lewis, 1918)
Description: Два (или три) пересекающихся круга; каждая непересекающаяся область — своя комбинация условий.
Picture: ![Venn diagram](visualizations/build/venn.png)
Approach: [approach::VennDiagram](#approachvenndiagram)
Sequence:
  1. Problem — два круга раздельно; неясно, как условия связаны
  2. Transform ∩ — круги сближаются, появляется общая область без числа
  3. Solution — три области подписаны числами
Invariants:
  - MUST: важно увидеть саму структуру пересечения (есть общая часть или нет), не только размер
  - MUST NOT: применяться для четырёх и более условий одними кругами — четыре круга доказуемо не отображают все пересечения; для двух-трёх работает без ограничений
Source: [Britannica — John Venn](https://www.britannica.com/biography/John-Venn) · [ReadWriteThink](https://www.readwritethink.org/classroom-resources/lesson-plans/introducing-venn-diagram-kindergarten) · [Science Sparks](https://www.science-sparks.com/make-venn-diagram-hula-hoop/)
Example: `visualizations/examples/venn.{css,html,js}` → `visualizations/build/venn.html`
Used in: [euler001](../euler001/README.md)
Depends on: [viz::Catalog](#vizcatalog), [approach::VennDiagram](#approachvenndiagram)
Spec: [visualizations](specs/visualizations.md)

## [viz::BinarySearch]
Class: entity
Standard name: Binary search
Description: Ищем значение в уже отсортированном списке — каждый раз сравниваем с серединой оставшегося куска и отбрасываем половину, где искомого точно нет.
Picture: ![Binary search](visualizations/build/binary-search.png)
Approach: [approach::BinarySearch](#approachbinarysearch)
Sequence:
  1. Problem — список чисел и искомое значение; где оно — неизвестно
  2. Transform ½ — середина списка сравнена с искомым, половина, где его точно нет, отброшена
  3. Transform ½ — то же самое повторяется на оставшемся куске
  4. Solution — остался один элемент — это и есть ответ
Invariants:
  - MUST: список заранее отсортирован (или значения монотонны)
  - MUST NOT: применяться к неотсортированному списку — деление пополам перестаёт что-либо гарантировать
Source: [cp-algorithms — Binary Search](https://cp-algorithms.com/num_methods/binary_search.html) · [Wikipedia — Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
Example: `visualizations/examples/binary-search.{css,html}` (js не требуется — значения статичны) → `visualizations/build/binary-search.html`
Used in: [euler002](../euler002/README.md)
Depends on: [viz::Catalog](#vizcatalog), [approach::BinarySearch](#approachbinarysearch)
Spec: [visualizations](specs/visualizations.md)

## [viz::LadderMethod]
Class: entity
Standard name: Ladder method (division ladder) — a.k.a. birthday cake method, upside-down division
Description: Число делим на маленькие простые по очереди, записывая делитель слева и остаток снизу, пока то, что осталось, само не окажется простым.
Picture: ![Ladder method](visualizations/build/ladder-method.png)
Approach: [approach::TrialDivision](#approachtrialdivision)
Sequence:
  1. Problem — число 30 без разбиения
  2. Transform ÷2 — делим на 2, снизу остаток 15
  3. Transform ÷3 — делим 15 на 3, снизу остаток 5
  4. Solution — 5 уже само простое, дальше не делится — это и есть самый большой простой множитель
Invariants:
  - MUST: на каждом шаге делим именно на простое число, начиная с самого маленького
  - MUST: точно повторяет механику пробного деления (сначала все двойки, потом нечётные делители по возрастанию) — не произвольную разбивку на любые два множителя, как в вольном факторном дереве
  - MUST NOT: применяться, если само число уже больше, чем практично проверять пробными делителями (очень большие числа без маленьких множителей) — метод остаётся верным, но лесенка станет неоправданно длинной
Source: [Wikipedia — Trial division](https://en.wikipedia.org/wiki/Trial_division) · [Math = Love — Birthday Cake Method](https://mathequalslove.net/prime-factorization-using-birthday-cake-method/) · [Scaffolded Math and Science — Ladder Method](https://www.scaffoldedmath.com/2019/02/finding-gcf-and-lcm-with-upside-down-cake-method.html)
Example: `visualizations/examples/ladder-method.{css,html}` (js не требуется — значения статичны) → `visualizations/build/ladder-method.html`
Used in: [euler003](../euler003/README.md)
Depends on: [viz::Catalog](#vizcatalog), [approach::TrialDivision](#approachtrialdivision)
Spec: [visualizations](specs/visualizations.md)

## [approach::Collection]
Class: aggregate
Description: Коллекция математических подходов для объяснения решений — блоки `[approach::*]` этого файла; не путать с `TRICKS.md` (приёмы ускорения, найденные в исследовании). Каждый подход — простая, атомарная идея ИЛИ явная композиция нескольких атомарных идей; ни у одной записи картинок не может быть больше одной.
Invariants:
  - MUST: каждая запись — Essence / Recognized by / General case / Visualized by / Source / Used in
  - MUST: `Visualized by` ссылается ровно на ОДИН блок `[viz::*]` (0 — легитимно и помечается явно; 2+ — нарушение, идеи разводятся на отдельные записи)
  - MUST: у записи есть `Source:` — ссылка на независимый источник, откуда идея стандартна (не только у картинки)
  - MUST NOT: заводить подход под существующую картинку ради симметрии — картинка без подхода помечается на своей стороне
  - MUST NOT: быть «простой идеей + шум» — либо запись атомарна (одна неделимая идея), либо явно называет, из каких атомарных идей она составлена
Entities:
  - Entry — одна запись подхода
Commands: AddEntry, LinkVisualization, ReuseEntry (дописать `Used in:`)
Depends on: [viz::Catalog](#vizcatalog)
Spec: [approaches](specs/approaches.md)

## [approach::InclusionExclusion]
Class: entity
Essence: Посчитать по отдельности, потом вычесть то, что посчитано дважды.
Recognized by: в условии есть «или» между двумя и более свойствами числа/объекта, и важно точное количество/сумма («кратно A ИЛИ кратно B»)
General case: для k условий — знакопеременная сумма по всем пересечениям (попарным, тройным, …); «А+Б−АБ» — только k=2
Visualized by: [viz::BarModel](#vizbarmodel)
Picture: [![Bar model](visualizations/build/bar-model.png)](visualizations/build/bar-model.html)
Source: [Wikipedia — Inclusion–exclusion principle](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle)
Used in: [euler001](../euler001/README.md)
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [approach::VennDiagram]
Class: entity
Essence: Показать связь двух (или трёх) условий кругами на плоскости — сама структура пересечения видна раньше любых чисел.
Recognized by: важно понять, ЕСТЬ ли общая часть у двух условий и как области соотносятся, а точное количество в каждой — уже вторично
General case: каждая непересекающаяся область соответствует своей комбинации условий; диаграмма остаётся осмысленной и без единого числа — это про структуру, не про счёт
Visualized by: [viz::VennDiagram](#vizvenndiagram)
Picture: [![Venn diagram](visualizations/build/venn.png)](visualizations/build/venn.html)
Source: [Wikipedia — Venn diagram](https://en.wikipedia.org/wiki/Venn_diagram) · [Britannica — John Venn](https://www.britannica.com/biography/John-Venn) (диаграмма изобретена в 1880 для представления логических утверждений, не для счёта — родственна [approach::InclusionExclusion](#approachinclusionexclusion), но отдельная по происхождению идея, часто используемая вместе с ней)
Used in: [euler001](../euler001/README.md)
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [approach::ArithmeticProgressionSum]
Class: entity
Essence: Сумму чисел, идущих с равным шагом, можно получить одним умножением, не складывая по одному.
Recognized by: нужна сумма (не количество) чисел, кратных чему-то, на отрезке
General case: сумма первых m членов прогрессии с шагом k равна `k · m·(m+1)/2`, m — сколько таких чисел на отрезке; любые k, m, N
Visualized by: [viz::GaussPairing](#vizgausspairing)
Picture: [![Gauss's trick](visualizations/build/gauss-pairing.png)](visualizations/build/gauss-pairing.html)
Source: [eduSeed](https://eduseed.in/2025/12/04/gauss-method-of-addition-the-day-a-10-year-old-outsmarted-his-teacher/) · [BetterExplained — Techniques for Adding the Numbers 1 to 100](https://betterexplained.com/articles/techniques-for-adding-the-numbers-1-to-100/)
Used in: [euler001](../euler001/README.md)
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [approach::Precomputation]
Class: entity
Essence: Один раз построить всё, что не зависит от конкретного запроса, заранее — каждый запрос потом не пересчитывает это, а только читает готовое.
Recognized by: одна и та же структура (список, таблица, сумма) используется много раз подряд с разными запросами, и сама она от запроса не зависит; строить её заново на каждый запрос — повторять одну и ту же работу T раз без необходимости
General case: вынести построение общей структуры из цикла обработки запросов — стоимость построения платится один раз, а не T раз; конкретный способ ОТВЕТИТЬ на запрос по готовой структуре (поиск, чтение по индексу, суммирование диапазона) — уже отдельная, самостоятельная идея, не часть предвычисления
Visualized by: — (у самого «посчитай заранее» нет устоявшегося визуального образа, в отличие от того, ЧТО делают с готовой структурой; см. [approach::BinarySearch](#approachbinarysearch) — конкретный способ использования этой задачи)
Source: [GeeksforGeeks — Precomputation Techniques for Competitive Programming](https://www.geeksforgeeks.org/dsa/precomputation-techniques-for-competitive-programming/)
Used in: [euler002](../euler002/README.md)
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [approach::BinarySearch]
Class: entity
Essence: Найти место значения в уже отсортированном списке, каждый раз отбрасывая половину, где его точно нет.
Recognized by: нужно найти элемент или позицию в списке, который уже отсортирован (или сам растёт по порядку)
General case: сравниваем искомое значение с серединой оставшегося куска списка и отбрасываем ту половину, где ответа точно нет — O(log m) сравнений вместо перебора всех m элементов
Visualized by: [viz::BinarySearch](#vizbinarysearch)
Picture: [![Binary search](visualizations/build/binary-search.png)](visualizations/build/binary-search.html)
Source: [cp-algorithms — Binary Search](https://cp-algorithms.com/num_methods/binary_search.html) · [Wikipedia — Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
Used in: [euler002](../euler002/README.md)
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [approach::TrialDivision]
Class: entity
Essence: Проверить по очереди все маленькие числа, начиная с 2 — делится ли на них — и выделить простые множители.
Recognized by: нужно разложить число на простые множители или найти конкретный (например, самый большой) простой множитель
General case: перебираем делители d от 2, пока d·d ≤ оставшегося числа; на каждом делителе выносим его из числа, пока делится нацело; если после перебора осталось число больше 1 — оно само простое (и, если делители перебирались по возрастанию, это и есть самый большой множитель)
Visualized by: [viz::LadderMethod](#vizladdermethod)
Picture: [![Ladder method](visualizations/build/ladder-method.png)](visualizations/build/ladder-method.html)
Source: [Wikipedia — Trial division](https://en.wikipedia.org/wiki/Trial_division)
Used in: [euler003](../euler003/README.md)
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)
