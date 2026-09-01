# Ubiquitous Language Index — projecteuler (объяснение решений)

> Канонический словарь терминов каталога визуализаций, коллекции подходов и решённых задач.
> Формат: `## [context::TermName]` · ссылки — обычные markdown-ссылки на этот же файл,
> `[context::Name](#анкор)` (не `[[wikilink]]` — GitHub его не рендерит кликабельным в обычном
> `.md`, только в своей Wiki). Контексты: `viz` — визуальные
> приёмы, `approach` — математические подходы, `euler` — сами задачи. Обновляется атомарно со
> спеком.
>
> Это ЕДИНСТВЕННОЕ место, где живёт описание каждого приёма и подхода (карточек в `.report/`
> больше нет). Картинка каждого приёма — `visualizations/build/<slug>.png`, собранная скриптом
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
Used in: euler001
Depends on: [viz::Catalog](#vizcatalog)
Spec: [visualizations](specs/visualizations.md)

## [viz::BarModel]
Class: entity
Standard name: Bar model / tape diagram — методика Singapore Math
Description: Полоска фиксированной длины разбивается на непересекающиеся куски; длина каждого куска равна количеству элементов этой части.
Picture: ![Bar model](visualizations/build/bar-model.png)
Approach: [approach::InclusionExclusion](#approachinclusionexclusion) — арифметическая форма (из каких чисел складывается каждая часть)
Sequence:
  1. Problem — суммы по двум условиям складываются напрямую; итог зачёркнут (двойной счёт общей части)
  2. Transform − — те же два числа показаны перекрывающимися; дважды учтённая часть выделена
  3. Solution — полоска разбита на три честных куска (только 2, оба, только 3); их сумма — верный ответ
Invariants:
  - MUST: в задаче есть «или» между двумя условиями, часть элементов удовлетворяет обоим сразу
  - MUST NOT: применяться для трёх и более условий — полоска показывает только последовательность непересекающихся кусков подряд; при трёх пересекающихся условиях пересечения не выстраиваются в один ряд честно, раскладка перестаёт соответствовать структуре
Source: [Third Space Learning](https://thirdspacelearning.com/us/blog/teach-bar-model-method/) · [Maths — No Problem!](https://mathsnoproblem.com/en/approach/bar-modelling)
Example: `visualizations/examples/bar-model.{css,html}` (js не требуется — значения статичны) → `visualizations/build/bar-model.html`
Used in: euler001
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
Used in: euler001
Depends on: [viz::Catalog](#vizcatalog), [approach::ArithmeticProgressionSum](#approacharithmeticprogressionsum)
Spec: [visualizations](specs/visualizations.md)

## [viz::VennDiagram]
Class: entity
Standard name: Venn diagram — John Venn, 1880 (термин ввёл C. I. Lewis, 1918)
Description: Два (или три) пересекающихся круга; каждая непересекающаяся область — своя комбинация условий.
Picture: ![Venn diagram](visualizations/build/venn.png)
Approach: [approach::InclusionExclusion](#approachinclusionexclusion) — пространственная форма (что общая часть вообще есть, до чисел)
Sequence:
  1. Problem — два круга раздельно; неясно, как условия связаны
  2. Transform ∩ — круги сближаются, появляется общая область без числа
  3. Solution — три области подписаны числами
Invariants:
  - MUST: важно увидеть саму структуру пересечения (есть общая часть или нет), не только размер
  - MUST NOT: применяться для четырёх и более условий одними кругами — четыре круга доказуемо не отображают все пересечения; для двух-трёх работает без ограничений
Source: [Britannica — John Venn](https://www.britannica.com/biography/John-Venn) · [ReadWriteThink](https://www.readwritethink.org/classroom-resources/lesson-plans/introducing-venn-diagram-kindergarten) · [Science Sparks](https://www.science-sparks.com/make-venn-diagram-hula-hoop/)
Example: `visualizations/examples/venn.{css,html,js}` → `visualizations/build/venn.html`
Used in: euler001
Depends on: [viz::Catalog](#vizcatalog), [approach::InclusionExclusion](#approachinclusionexclusion)
Spec: [visualizations](specs/visualizations.md)

## [approach::Collection]
Class: aggregate
Description: Коллекция математических подходов для объяснения решений — блоки `[approach::*]` этого файла; не путать с `TRICKS.md` (приёмы ускорения, найденные в исследовании). Картинки — у каждого конкретного подхода ниже (`[approach::InclusionExclusion]`, `[approach::ArithmeticProgressionSum]`), не здесь — этот блок сам не про одну картинку, а про список.
Invariants:
  - MUST: каждая запись — Essence / Recognized by / General case / Visualized by / Used in
  - MUST: `Visualized by` ссылается на блоки `[viz::*]`; «—» = сигнал завести картинку, не постоянное состояние
  - MUST NOT: заводить подход под существующую картинку ради симметрии — картинка без подхода помечается на своей стороне
Entities:
  - Entry — одна запись подхода
Commands: AddEntry, LinkVisualization, ReuseEntry (дописать `Used in:`)
Depends on: [viz::Catalog](#vizcatalog)
Spec: [approaches](specs/approaches.md)

## [approach::InclusionExclusion]
Class: entity
Essence: Посчитать по отдельности, потом вычесть то, что посчитано дважды.
Recognized by: в условии есть «или» между двумя и более свойствами числа/объекта («кратно A ИЛИ кратно B»)
General case: для k условий — знакопеременная сумма по всем пересечениям (попарным, тройным, …); «А+Б−АБ» — только k=2
Visualized by: [viz::BarModel](#vizbarmodel) (арифметическая форма — из каких чисел состоит каждая часть), [viz::VennDiagram](#vizvenndiagram) (пространственная — что общая часть вообще есть)
Picture: [![Bar model](visualizations/build/bar-model.png)](visualizations/build/bar-model.html) [![Venn diagram](visualizations/build/venn.png)](visualizations/build/venn.html)
Used in: euler001
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [approach::ArithmeticProgressionSum]
Class: entity
Essence: Сумму чисел, идущих с равным шагом, можно получить одним умножением, не складывая по одному.
Recognized by: нужна сумма (не количество) чисел, кратных чему-то, на отрезке
General case: сумма первых m членов прогрессии с шагом k равна `k · m·(m+1)/2`, m — сколько таких чисел на отрезке; любые k, m, N
Visualized by: [viz::GaussPairing](#vizgausspairing)
Picture: [![Gauss's trick](visualizations/build/gauss-pairing.png)](visualizations/build/gauss-pairing.html)
Used in: euler001
Depends on: [approach::Collection](#approachcollection)
Spec: [approaches](specs/approaches.md)

## [euler::Problem001]
Class: entity
Description: Multiples of 3 and 5 — сумма натуральных чисел меньше N, кратных 3 или 5, за T запросов.
Invariants:
  - MUST: ответ на каждый запрос вычисляется за O(1), без цикла по [0, N)
  - MUST: sumMultiplesBelow(n, k) считает кратные k строго МЕНЬШИЕ n — m = (n-1)/k, не n/k
  - MUST: solve(n) = sumMultiplesBelow(n,3) + sumMultiplesBelow(n,5) − sumMultiplesBelow(n,15) — 15 = НОК(3,5), общая часть, посчитанная дважды
  - MUST: solution.cpp — чистый ASCII
Depends on: [approach::InclusionExclusion](#approachinclusionexclusion), [approach::ArithmeticProgressionSum](#approacharithmeticprogressionsum)
Spec: [euler001](specs/euler001.md)
Code: `euler001/solution.cpp` · `euler001/README.md`
