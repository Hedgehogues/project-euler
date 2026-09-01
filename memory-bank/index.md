# Index

> Memory-bank хранит только переиспользуемое знание — приёмы и подходы. Конкретные задачи здесь
> не описываются; каждая запись ссылается на задачу, где применена, полем `Used in:` — прямой
> ссылкой на `euler{NNN}/README.md`. Задачи не индексируются здесь отдельно.

## projecteuler — объяснение решений
- [visualizations](specs/visualizations.md) — Status: draft — каталог визуальных приёмов объяснения: кадры проблема → преобразования → решение, детерминированная сборка `build.sh` из каркаса + `examples/`, привязка к подходам
- [approaches](specs/approaches.md) — Status: draft — коллекция математических подходов для объяснения (не `TRICKS.md`): схема записи, дисциплина «атом или композиция», двусторонняя связь с картинками
- [_terms.md](_terms.md) — словарь и ЕДИНСТВЕННОЕ место описаний: контексты `viz` (Catalog, PageSkeleton, SkipCounting, BarModel, GaussPairing, VennDiagram, BinarySearch, LadderMethod — с картинками) и `approach` (Collection, InclusionExclusion, VennDiagram, ArithmeticProgressionSum, Precomputation, BinarySearch, TrialDivision)

### Визуализации — исходники и сборка
- `visualizations/examples/<slug>.{css,html,js}` — код кадров (правится руками)
- `visualizations/skeleton.html` — общий каркас страницы
- `visualizations/build.sh` — сборка: `build/<slug>.html` + `build/<slug>.png` (headless-браузер, светлая тема)
- `visualizations/build/` — результат; картинки вставлены в `_terms.md`

### Вне memory-bank
- `euler{NNN}/README.md` — сама задача: условие, алгоритм, статус сабмита, ссылки на использованные подходы/приёмы отсюда
- `.claude/rules/visualization-principles.md` — принципы 1–12 (короткая автозагружаемая форма требований спеков)
- `.claude/skills/visualize-approach/SKILL.md` — навык: находит приём в `_terms.md`, запускает `build.sh`, открывает результат
