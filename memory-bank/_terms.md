# Ubiquitous Language Index — projecteuler (объяснение решений)

> Канонический словарь терминов каталога визуализаций и коллекции подходов. Формат:
> `## [context::TermName]` · ссылки по `[[context::Name]]`. Контексты: `viz` — визуальные приёмы,
> `approach` — математические подходы. Обновляется атомарно со спеком.

## [viz::Catalog]
Class: aggregate
Description: Каталог визуальных приёмов объяснения решения — `.report/visualizations/`: индекс, по одному RFC-спеку на приём, точный код кадров в `examples/`.
Invariants:
  - MUST: один приём — один `<slug>.md` + до трёх файлов `examples/<slug>.{css,html,js}`; никаких отдельных картинок-файлов
  - MUST: каждая карточка привязана к [[approach::Collection]] полем `Approach:` либо явно помечена «вне подходов» с причиной
  - MUST: повторная сборка приёма из каркаса + `examples/` даёт байт-в-байт ту же картинку
  - MUST: сквозной пример один на весь каталог — «числа до 20, кратные 2 или 3», не числа конкретной задачи
  - MUST NOT: оставлять файл-редирект без единой входящей ссылки (перед выбором редирект/удаление — grep)
Entities:
  - Card — один приём: спек + код кадров
  - Frame — один кадр картинки: Problem | Transform | Solution
Commands: AddCard, ReuseCard (дописать `Used in:`), ReviseCard (правка спека/кода + пересборка)
Depends on: [[approach::Collection]], [[viz::PageSkeleton]]
Spec: [[visualizations]]

## [viz::PageSkeleton]
Class: value-object
Description: Общий каркас страницы (шрифты, цветовые токены, layout карточки и потока кадров), один на все приёмы — живёт в `.claude/skills/visualize-approach/SKILL.md`.
Invariants:
  - MUST: не содержит ни одного приёмо-специфичного класса — те только в `examples/<slug>.css`
  - MUST: страница собирается копированием каркаса + файлов `examples/` без пересказа и без новых чисел/цветов
Depends on:
Spec: [[visualizations]]

## [viz::SkipCounting]
Class: entity
Description: Счёт прыжками по числовой прямой (skip counting) — прыжки постоянной длины отмечают кратные числа.
Invariants:
  - MUST: кадры — Problem (прямая без пометок) → Transform ×A → Transform ×B → Solution (объединённая раскраска)
  - MUST: `Approach: —` — показывает само понятие «кратно», подготовительный шаг, не способ счёта
  - MUST NOT: применяться для трёх и более условий одновременно (цвета перестают различаться)
Depends on: [[viz::Catalog]]
Spec: [[visualizations]]

## [viz::BarModel]
Class: entity
Description: Модель-полоска (bar model / tape diagram, Singapore Math) — полоска разбита на непересекающиеся куски, длина куска = количество.
Invariants:
  - MUST: кадры — Problem (прямая сумма помечена как неверная) → Transform (перекрытие выделено) → Solution (три честных куска)
  - MUST: `Approach:` = [[approach::InclusionExclusion]], арифметическая форма (из каких чисел состоит каждая часть)
  - MUST NOT: применяться для трёх и более условий — пересечения не выстраиваются в один ряд честно
Depends on: [[viz::Catalog]], [[approach::InclusionExclusion]]
Spec: [[visualizations]]

## [viz::GaussPairing]
Class: entity
Description: Приём Гаусса, парное сложение («радуга») — числа сцепляются парами с двух концов, каждая пара даёт одну сумму.
Invariants:
  - MUST: кадры — Problem (ряд со знаками «+», сумма не подсчитана) → Transform (дуги пар с суммой над каждой) → Solution (итог)
  - MUST: `Approach:` = [[approach::ArithmeticProgressionSum]]
  - MUST: все промежуточные числа примера различны (прецедент 30/30: площадь и итог совпадали — объяснение читалось как замкнутое)
  - MUST NOT: применяться при переменном шаге между числами
Depends on: [[viz::Catalog]], [[approach::ArithmeticProgressionSum]]
Spec: [[visualizations]]

## [viz::VennDiagram]
Class: entity
Description: Диаграмма Венна (John Venn, 1880) — два пересекающихся круга, каждая область — своя комбинация условий.
Invariants:
  - MUST: кадры — Problem (круги раздельно) → Transform (сближение, общая область без чисел) → Solution (три подписанные области)
  - MUST: `Approach:` = [[approach::InclusionExclusion]], пространственная форма (что общая часть вообще есть)
  - MUST NOT: применяться для четырёх и более условий одними кругами (доказуемо не покрывают все пересечения)
Depends on: [[viz::Catalog]], [[approach::InclusionExclusion]]
Spec: [[visualizations]]

## [approach::Collection]
Class: aggregate
Description: Коллекция математических подходов для объяснения решений — `.report/approaches.md`; не путать с `TRICKS.md` (приёмы ускорения, найденные в исследовании).
Invariants:
  - MUST: каждая запись — Суть / Когда узнаётся / Общий случай / Визуализируется / Использовано в
  - MUST: поле «Визуализируется» ссылается на карточки [[viz::Catalog]]; «—» = сигнал завести картинку, не постоянное состояние
  - MUST NOT: заводить подход под существующую картинку ради симметрии — картинка без подхода помечается на своей стороне
Entities:
  - Entry — одна запись подхода
Commands: AddEntry, LinkVisualization, ReuseEntry (дописать «Использовано в:»)
Depends on: [[viz::Catalog]]
Spec: [[approaches]]

## [approach::InclusionExclusion]
Class: entity
Description: Включение-исключение — посчитать по отдельности, потом вычесть посчитанное дважды.
Invariants:
  - MUST: узнаётся по «или» между двумя и более свойствами в условии
  - MUST: общий случай — знакопеременная сумма по всем пересечениям k условий; «А+Б−АБ» — только k=2
  - MUST: визуализируется двумя формами — [[viz::BarModel]] (числа) и [[viz::VennDiagram]] (форма)
Depends on: [[approach::Collection]]
Spec: [[approaches]]

## [approach::ArithmeticProgressionSum]
Class: entity
Description: Замкнутая формула суммы арифметической прогрессии — сумма чисел с равным шагом одним умножением.
Invariants:
  - MUST: узнаётся, когда нужна сумма (не количество) чисел, кратных чему-то, на отрезке
  - MUST: общий случай — `k · m·(m+1)/2`, m — сколько таких чисел на отрезке; любые k, m, N
  - MUST: визуализируется [[viz::GaussPairing]]
Depends on: [[approach::Collection]]
Spec: [[approaches]]
