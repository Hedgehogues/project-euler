# Index

## projecteuler — объяснение решений
- [euler001](specs/euler001.md) — Status: draft — спек решения euler001 (Multiples of 3 and 5): модель, формула, критерии корректности; README задачи — `../euler001/README.md`
- [euler002](specs/euler002.md) — Status: draft — спек решения euler002 (Even Fibonacci numbers): предвычисление + бинарный поиск, критерии корректности; README задачи — `../euler002/README.md`
- [visualizations](specs/visualizations.md) — Status: draft — каталог визуальных приёмов объяснения: кадры проблема → преобразования → решение, детерминированная сборка `build.sh` из каркаса + `examples/`, привязка к подходам
- [approaches](specs/approaches.md) — Status: draft — коллекция математических подходов для объяснения (не `TRICKS.md`): схема записи, двусторонняя связь с картинками
- [_terms.md](_terms.md) — словарь и ЕДИНСТВЕННОЕ место описаний: контексты `viz` (Catalog, PageSkeleton, SkipCounting, BarModel, GaussPairing, VennDiagram, BinarySearch — с картинками), `approach` (Collection, InclusionExclusion, ArithmeticProgressionSum, PrecomputeAndBinarySearch), `euler` (Problem001, Problem002)

### Визуализации — исходники и сборка
- `visualizations/examples/<slug>.{css,html,js}` — код кадров (правится руками)
- `visualizations/skeleton.html` — общий каркас страницы
- `visualizations/build.sh` — сборка: `build/<slug>.html` + `build/<slug>.png` (headless-браузер, светлая тема)
- `visualizations/build/` — результат; картинки вставлены в `_terms.md`

### Вне memory-bank
- `.claude/rules/visualization-principles.md` — принципы 1–10 (короткая автозагружаемая форма требований спеков)
- `.claude/skills/visualize-approach/SKILL.md` — навык: находит приём в `_terms.md`, запускает `build.sh`, открывает результат
