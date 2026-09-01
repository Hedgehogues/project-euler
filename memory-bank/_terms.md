# Ubiquitous Language Index — projecteuler (объяснение решений)

> Канонический словарь методов объяснения решений. Формат: `## [context::TermName]` · ссылки —
> обычные markdown-ссылки на этот же файл, `[context::Name](#анкор)` (не `[[wikilink]]` — GitHub
> его не рендерит кликабельным в обычном `.md`, только в своей Wiki). Контекст один: `method` —
> метод объяснения (идея + её картинка в ОДНОМ блоке).
>
> **Один метод — один блок.** Идея («что это и когда узнаётся») и её картинка («как это
> показать») — не два параллельных списка, а поля одной записи: `Essence`/`Recognized by`/
> `General case` — про идею, `Picture`/`Sequence`/`Example` — про её изображение, `Limits` — про
> границы обоих, с пометкой, где предел идеи, а где только рисунка. Картинок у метода не больше
> одной; метод без картинки легитимен, если у идеи нет устоявшегося визуального образа.
>
> **Здесь нет ни одного упоминания конкретной задачи** — ни условия, ни решения, ни ссылки
> «использовано в». Это базовые примитивы сами по себе. Связь идёт в ОДНУ сторону: задача
> (`euler{NNN}/README.md`) ссылается на нужный ей блок по имени (`[method::Name]` →
> `_terms.md#methodname`); обратной ссылки отсюда на задачу нет. Задача, повторно использующая
> уже описанный метод, просто ссылается на существующий блок — этот файл при этом не меняется.
>
> Картинка каждого метода — `visualizations/build/<slug>.png`, собранная скриптом
> `visualizations/build.sh` из `visualizations/skeleton.html` + `visualizations/examples/<slug>.*`;
> после любой правки `examples/` — перезапустить сборку, картинка руками не правится.

## [method::Catalog]
Class: aggregate
Description: Каталог методов объяснения — блоки `[method::*]` этого файла плюс их исходники в `memory-bank/visualizations/` (кадры в `examples/`, каркас `skeleton.html`, сборка `build.sh`, результат в `build/`).
Invariants:
  - MUST: один метод — ОДИН блок `[method::*]`; идея и её картинка живут в одном блоке, не в двух параллельных списках (прецедент: раньше было два контекста, `[viz::*]` и `[approach::*]`, с одинаковыми именами, одними и теми же картинками и источниками — чистое дублирование)
  - MUST: у метода не больше одной картинки; идея с двумя независимо стандартными визуальными формами — это два разных метода, а не один с двумя портретами
  - MUST: метод без картинки легитимен — если у идеи нет устоявшегося визуального образа, `Picture: —` с причиной; отсутствие картинки НЕ довод против отдельной записи
  - MUST: каждый метод — атомарная идея ИЛИ явно названная композиция атомарных; «атом + неназванный довесок» запрещён
  - MUST: `build/*.png` — только результат `build.sh` (headless-браузер, светлая тема, ширина 720), никогда не рисуется и не правится руками; после правки `examples/` пересобирается
  - MUST: повторная сборка метода из каркаса + `examples/` даёт байт-в-байт ту же страницу
  - MUST: сквозной пример один на весь каталог — «числа до 20, кратные 2 или 3», не числа конкретной задачи
  - MUST NOT: хранить что-либо о конкретной задаче, даже обратную ссылку «использовано в»
  - MUST NOT: оставлять файл-редирект без единой входящей ссылки (перед выбором редирект/удаление — grep)
Entities:
  - Method — один метод: блок здесь + код кадров + собранные html/png
  - Frame — один кадр картинки: Problem | Transform | Solution
Commands: AddMethod, ReviseMethod (правка блока/кода + `build.sh`); повторное использование метода НЕ меняет этот файл — задача ссылается на существующий блок из своего README
Depends on: [method::PageSkeleton](#methodpageskeleton)
Spec: [approaches](specs/approaches.md) (качество идеи) · [visualizations](specs/visualizations.md) (качество картинки)

## [method::PageSkeleton]
Class: value-object
Description: Общий каркас страницы (шрифты, цветовые токены, layout карточки и потока кадров) — `visualizations/skeleton.html`, плейсхолдеры `{{TITLE}} {{STDNAME}} {{SLUG}} {{TERM}} {{CSS}} {{HTML}} {{JS}} {{QR}}`; один на все методы.
Invariants:
  - MUST: не содержит ни одного метод-специфичного класса — те только в `examples/<slug>.css`
  - MUST: страница собирается подстановкой файлов `examples/` в плейсхолдеры без пересказа и без новых чисел/цветов (`build.sh`)
  - MUST: тёмная палитра включается только медиа-запросом и отключается атрибутом `data-theme="light"` — так снимок фиксируется светлым независимо от машины
  - MUST: несёт блок `.repo` с QR-кодом на репозиторий (`visualizations/qr-repo.svg`, плейсхолдер `{{QR}}`) и адресом текстом; метод не может его убрать; `build.sh` не собирает без файла QR
Depends on:
Spec: [visualizations](specs/visualizations.md)

## [method::SkipCounting]
Class: entity
Standard name: Skip counting — счёт прыжками по числовой прямой
Essence: Идти по числам равными прыжками — куда приземлился, то и кратно длине прыжка.
Recognized by: нужно понять или показать, какие числа обладают свойством кратности, ДО каких-либо вычислений — прикинуть на глаз, проверить гипотезу, объяснить саму идею «кратно» с нуля
General case: прыжки длиной k отмечают ровно кратные k; несколько разных длин прыжков дают несколько групп, а числа, кратные сразу нескольким, — те, где приземления совпали
Picture: ![Skip counting](visualizations/build/skip-counting.png)
Sequence:
  1. Problem — числа на прямой без пометок, неизвестно, какие обладают нужным свойством
  2. Transform ×2 — прыжки шагом 2 отмечают кратные 2
  3. Transform ×3 — прыжки шагом 3 отмечают кратные 3
  4. Solution — объединённая прямая, каждое число окрашено по принадлежности (2 / 3 / оба)
Limits:
  - MUST NOT: применяться как буквальный ручной способ счёта для больших чисел (тысячи и больше) — предел ПРАКТИКИ, не идеи: сама идея верна для любых чисел, но там ту же кратность считают формулой, а не рисуют прыжки
  - MUST NOT: применяться для трёх и более условий одновременно — предел КАРТИНКИ: число цветов на прямой превышает различимое одним взглядом
Source: [Wikipedia — Skip counting](https://en.wikipedia.org/wiki/Skip_counting) · [Wikipedia — Number line](https://en.wikipedia.org/wiki/Number_line) · методика: [SplashLearn](https://www.splashlearn.com/blog/how-to-teach-skip-counting/) · [WeAreTeachers](https://www.weareteachers.com/skip-counting/)
Example: `visualizations/examples/skip-counting.{css,html,js}` → `visualizations/build/skip-counting.html`
Depends on: [method::Catalog](#methodcatalog)
Spec: [visualizations](specs/visualizations.md)

## [method::InclusionExclusion]
Class: entity
Standard name: Inclusion–exclusion principle · картинка — bar model / tape diagram (Singapore Math)
Essence: Посчитать по отдельности, потом вычесть то, что посчитано дважды.
Recognized by: в условии есть «или» между двумя и более свойствами числа/объекта, и важно точное количество или сумма («кратно A ИЛИ кратно B»)
General case: для k условий — знакопеременная сумма по всем пересечениям (попарным, тройным, …); «А+Б−АБ» — только случай k=2
Picture: ![Bar model](visualizations/build/bar-model.png)
Sequence:
  1. Problem — суммы по двум условиям складываются напрямую; итог зачёркнут (двойной счёт общей части)
  2. Transform − — те же два числа показаны перекрывающимися; дважды учтённая часть выделена
  3. Solution — полоска разбита на три честных куска (только 2, оба, только 3); их сумма — верный ответ
Limits:
  - MUST NOT: применяться для трёх и более условий — предел КАРТИНКИ: полоска показывает только ряд непересекающихся кусков подряд, при трёх пересекающихся условиях пересечения в один ряд честно не выстраиваются. Сама идея работает для любого k (ценой роста числа слагаемых как 2^k)
Source: [Wikipedia — Inclusion–exclusion principle](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle) · картинка: [Wikipedia — Tape diagram](https://en.wikipedia.org/wiki/Tape_diagram) · [Maths — No Problem!](https://mathsnoproblem.com/en/approach/bar-modelling)
Example: `visualizations/examples/bar-model.{css,html}` (js не требуется — значения статичны) → `visualizations/build/bar-model.html`
Depends on: [method::Catalog](#methodcatalog)
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::VennDiagram]
Class: entity
Standard name: Venn diagram — John Venn, 1880 (термин ввёл C. I. Lewis, 1918)
Essence: Показать связь двух (или трёх) условий кругами — сама структура пересечения видна раньше любых чисел.
Recognized by: важно понять, ЕСТЬ ли общая часть у условий и как области соотносятся, а точное количество в каждой — уже вторично
General case: каждая непересекающаяся область соответствует своей комбинации условий; диаграмма остаётся осмысленной и без единого числа — это про структуру, не про счёт
Picture: ![Venn diagram](visualizations/build/venn.png)
Sequence:
  1. Problem — два круга раздельно; неясно, как условия связаны
  2. Transform ∩ — круги сближаются, появляется общая область без числа
  3. Solution — три области подписаны числами
Limits:
  - MUST NOT: применяться для четырёх и более условий одними кругами — здесь предел идеи и предел картинки совпадают (идея по сути визуальна): доказано, что четыре круга не отображают все возможные пересечения; для двух-трёх работает без ограничений
Source: [Wikipedia — Venn diagram](https://en.wikipedia.org/wiki/Venn_diagram) · [Britannica — John Venn](https://www.britannica.com/biography/John-Venn) · [ReadWriteThink](https://www.readwritethink.org/classroom-resources/lesson-plans/introducing-venn-diagram-kindergarten) · [Science Sparks](https://www.science-sparks.com/make-venn-diagram-hula-hoop/)
Example: `visualizations/examples/venn.{css,html,js}` → `visualizations/build/venn.html`
Note: родственна [method::InclusionExclusion](#methodinclusionexclusion) и часто применяется вместе с ней, но это отдельный метод по происхождению: диаграмма изобретена в 1880 для представления логических утверждений, не для счёта.
Depends on: [method::Catalog](#methodcatalog)
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::ArithmeticProgressionSum]
Class: entity
Standard name: Sum of an arithmetic progression · картинка — Gauss's trick, парное сложение («радуга»)
Essence: Сумму чисел, идущих с равным шагом, можно получить одним умножением, не складывая по одному.
Recognized by: нужна сумма (не количество) чисел, идущих с постоянным шагом — кратных чему-то на отрезке, любого равномерного ряда
General case: сумма первых m членов прогрессии с шагом k равна `k · m·(m+1)/2`, где m — сколько таких чисел на отрезке; любые k, m, N
Picture: ![Gauss pairing](visualizations/build/gauss-pairing.png)
Sequence:
  1. Problem — числа ряда стоят по порядку, соединены «+», сумма не подсчитана
  2. Transform ↔ — числа сцеплены в пары с двух концов дугами; над каждой дугой — сумма пары
  3. Solution — итоговая сумма (число пар × сумма пары, плюс середина при нечётном числе элементов)
Limits:
  - MUST NOT: применяться при переменном шаге между числами — предел ИДЕИ: пары с двух концов перестают давать одинаковую сумму, формула неприменима
  - MUST: все промежуточные числа примера различны (пример 4·8·12·16·20, пары по 24, итог 60) — предел КАРТИНКИ: прецедент 30/30, где площадь и итог совпали, и объяснение читалось как замкнутое само на себя
Source: [Wikipedia — Arithmetic progression](https://en.wikipedia.org/wiki/Arithmetic_progression) · [BetterExplained — Techniques for Adding the Numbers 1 to 100](https://betterexplained.com/articles/techniques-for-adding-the-numbers-1-to-100/) · картинка: [NCTM — The Story of Gauss](https://www.nctm.org/Publications/TCM-blog/Blog/The-Story-of-Gauss/)
Example: `visualizations/examples/gauss-pairing.{css,html,js}` → `visualizations/build/gauss-pairing.html`
Depends on: [method::Catalog](#methodcatalog)
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::Precomputation]
Class: entity
Standard name: Precomputation
Essence: Один раз построить всё, что не зависит от конкретного запроса, заранее — каждый запрос потом не пересчитывает это, а только читает готовое.
Recognized by: одна и та же структура (список, таблица, сумма) используется много раз подряд с разными запросами, и сама она от запроса не зависит; строить её заново на каждый запрос — повторять одну и ту же работу T раз без необходимости
General case: вынести построение общей структуры из цикла обработки запросов — стоимость построения платится один раз, а не T раз; конкретный способ ОТВЕТИТЬ на запрос по готовой структуре (поиск, чтение по индексу, суммирование диапазона) — уже отдельный метод, не часть предвычисления
Picture: — (у самого «посчитай заранее» нет устоявшегося визуального образа, в отличие от того, ЧТО делают с готовой структурой; отсутствие картинки — не довод против отдельной записи)
Limits:
  - MUST NOT: применяться, когда структура зависит от запроса — тогда предвычислять нечего
  - MUST: помнить, что стоимость построения платится всегда, даже если запрос один — при единственном запросе выигрыша нет
Source: [Wikipedia — Precomputation](https://en.wikipedia.org/wiki/Precomputation) · [Wikipedia — Lookup table](https://en.wikipedia.org/wiki/Lookup_table) · [GeeksforGeeks — Precomputation Techniques for Competitive Programming](https://www.geeksforgeeks.org/dsa/precomputation-techniques-for-competitive-programming/)
Depends on: [method::Catalog](#methodcatalog)
Spec: [approaches](specs/approaches.md)

## [method::BinarySearch]
Class: entity
Standard name: Binary search
Essence: Найти место значения в уже отсортированном списке, каждый раз отбрасывая половину, где его точно нет.
Recognized by: нужно найти элемент или позицию в списке, который уже отсортирован (или сам растёт по порядку)
General case: сравниваем искомое значение с серединой оставшегося куска и отбрасываем ту половину, где ответа быть не может — O(log m) сравнений вместо перебора всех m элементов
Picture: ![Binary search](visualizations/build/binary-search.png)
Sequence:
  1. Problem — список чисел и искомое значение; где оно — неизвестно
  2. Transform ½ — середина списка сравнена с искомым, половина, где его точно нет, отброшена
  3. Transform ½ — то же самое повторяется на оставшемся куске
  4. Solution — остался один элемент — это и есть ответ
Limits:
  - MUST NOT: применяться к неотсортированному списку — предел ИДЕИ: деление пополам перестаёт что-либо гарантировать
Source: [cp-algorithms — Binary Search](https://cp-algorithms.com/num_methods/binary_search.html) · [Wikipedia — Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
Example: `visualizations/examples/binary-search.{css,html}` (js не требуется — значения статичны) → `visualizations/build/binary-search.html`
Depends on: [method::Catalog](#methodcatalog)
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::TrialDivision]
Class: entity
Standard name: Trial division · картинка — ladder method (division ladder), a.k.a. birthday cake method
Essence: Проверить по очереди маленькие числа, начиная с 2 — делится ли на них — и так выделить простые множители.
Recognized by: нужно разложить число на простые множители или найти конкретный (например, самый большой) простой множитель
General case: перебираем делители d от 2, пока d·d ≤ ОСТАВШЕГОСЯ числа; на каждом делителе выносим его, пока делится нацело — остаток при этом падает, и граница перебора падает вместе с ним; если после перебора осталось число больше 1, оно само простое (и при переборе по возрастанию это наибольший множитель)
Picture: ![Ladder method](visualizations/build/ladder-method.png)
Sequence:
  1. Problem — число 30 без разбиения
  2. Transform ÷2 — делим на 2, снизу остаток 15
  3. Transform ÷3 — делим 15 на 3, снизу остаток 5
  4. Solution — 5 уже само простое, дальше не делится — это и есть самый большой простой множитель
Limits:
  - MUST NOT: применяться к большим числам без маленьких множителей — предел ИДЕИ по стоимости: перебор доходит до корня из числа, что при полупростом числе из десятков цифр непрактично (там нужны другие методы факторизации)
  - MUST: на картинке делим именно на простое, начиная с наименьшего — предел КАРТИНКИ: лесенка обязана повторять механику перебора (сначала все двойки, потом нечётные по возрастанию), а не произвольную разбивку на любые два множителя, как в вольном факторном дереве
Source: [Wikipedia — Trial division](https://en.wikipedia.org/wiki/Trial_division) · картинка: [Math = Love — Birthday Cake Method](https://mathequalslove.net/prime-factorization-using-birthday-cake-method/) · [Scaffolded Math and Science — Ladder Method](https://www.scaffoldedmath.com/2019/02/finding-gcf-and-lcm-with-upside-down-cake-method.html)
Example: `visualizations/examples/ladder-method.{css,html}` (js не требуется — значения статичны) → `visualizations/build/ladder-method.html`
Depends on: [method::Catalog](#methodcatalog)
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)
