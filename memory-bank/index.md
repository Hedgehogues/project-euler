# Index

> Memory-bank хранит только переиспользуемое знание — методы объяснения, как учебник. Ни одной
> конкретной задачи и ни одной ссылки на задачу здесь нет: связь идёт в обратную сторону, задача
> (`euler{NNN}/README.md`) сама ссылается на нужный ей блок по имени.
>
> **Один метод — один блок.** Идея и её картинка не разведены по двум параллельным спискам, а
> живут полями одной записи `[method::*]`; картинок у метода не больше одной, отсутствие картинки
> легитимно с явной причиной.

## projecteuler — объяснение решений
- [_terms.md](_terms.md) — словарь и ЕДИНСТВЕННОЕ место описаний: контекст `method` — Catalog, PageSkeleton, SkipCounting, InclusionExclusion, VennDiagram, ArithmeticProgressionSum, Precomputation, BinarySearch, TrialDivision
- [approaches](specs/approaches.md) — Status: draft — требования к КАЧЕСТВУ ИДЕИ в записи метода: атомарность или названная композиция, узнаваемость по условию, независимый источник, не больше одной картинки
- [visualizations](specs/visualizations.md) — Status: draft — требования к КАЧЕСТВУ КАРТИНКИ: кадры проблема → преобразования → решение, детерминированная сборка `build.sh`, наблюдение рендера, QR на репозиторий

### Картинки — исходники и сборка
- `visualizations/examples/<slug>.{css,html,js}` — код кадров (правится руками)
- `visualizations/skeleton.html` — общий каркас страницы
- `visualizations/build.sh` — сборка: `build/<slug>.html` + `build/<slug>.png` (headless-браузер, светлая тема); таблица `cards()` связывает slug картинки с именем блока `[method::*]`
- `visualizations/build/` — результат; картинки вставлены в `_terms.md`

### Вне memory-bank
- `euler{NNN}/README.md` — сама задача: условие, алгоритм, статус сабмита, ссылки на использованные методы отсюда
- `.claude/rules/visualization-principles.md` — принципы 1–12 (короткая автозагружаемая форма требований спеков)
- `.claude/skills/visualize-approach/SKILL.md` — навык: находит метод в `_terms.md`, запускает `build.sh`, открывает результат
