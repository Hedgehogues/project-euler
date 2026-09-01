# Index

> The **dictionary** (`_terms.md`) holds only reusable knowledge — explanation methods, like a
> textbook. Not a single specific problem and not a single link to one lives there: the link runs
> the other way, a problem (`problems/euler{NNN}/README.md`) points at the block it needs by name.
>
> **One method, one block.** The idea and its picture are not split across two parallel lists but
> live as fields of a single `[method::*]` record; a method has at most one picture, and having
> none is legitimate with a stated reason.
>
> The **specs** folder is a different thing: RFC documents, not dictionary entries, split by kind.
> `specs/*.md` describes the catalog itself (idea quality, picture quality) — a meta-spec, about
> what makes any method record and its picture good. `specs/tasks.md` is a THIRD meta-spec, about
> what makes a task's own spec good — the format, not the catalog. `specs/tasks/*.md` is where that
> format is actually applied: one file per problem, its own requirements and acceptance criteria.
> That is exactly the kind of content the dictionary above must never hold, but a spec is not a
> dictionary entry.

## projecteuler — explaining solutions
- [_terms.md](_terms.md) — the dictionary and the ONLY place descriptions live: context `method` — SkipCounting, InclusionExclusion, VennDiagram, ArithmeticProgressionSum, Precomputation, BinarySearch, TrialDivision, EuclideanAlgorithm, LCMViaGCD, SumOfSquares, SieveOfEratosthenes, NthPrimeBound, PrimeNumberTheorem (the catalog- and shell-level invariants live in the two specs below, not as blocks of their own)
- [approaches](specs/approaches.md) — Status: draft — requirements on the IDEA in a method record: atomic or a named composition, recognizable from the statement, canonical source, at most one picture
- [visualizations](specs/visualizations.md) — Status: draft — requirements on the PICTURE: frames problem → transforms → solution, deterministic `build.sh`, observing the render, repository QR
- [tasks](specs/tasks.md) — Status: draft — requirements on a TASK SPEC's own format: six sections in order, methods must resolve, a Status line must name real evidence
- [specs/tasks/euler001.md](specs/tasks/euler001.md) · [specs/tasks/euler002.md](specs/tasks/euler002.md) · [specs/tasks/euler003.md](specs/tasks/euler003.md) · [specs/tasks/euler004.md](specs/tasks/euler004.md) · [specs/tasks/euler005.md](specs/tasks/euler005.md) · [specs/tasks/euler006.md](specs/tasks/euler006.md) · [specs/tasks/euler007.md](specs/tasks/euler007.md) — the applied instances of `tasks.md`'s format; linked from each `problems/euler{NNN}/README.md`

### Pictures — sources and build
- `visualizations/examples/<slug>.{css,html,js}` — frame code (edited by hand)
- `visualizations/skeleton.html` — the shared page shell
- `visualizations/build.sh` — build: `build/<slug>.html` + `build/<slug>.png` (headless browser, light theme); the `cards()` table maps a picture slug to its `[method::*]` block name
- `visualizations/build/` — output; the pictures are embedded in `_terms.md`

### Outside the memory bank
- `problems/euler{NNN}/README.md` — the problem itself: statement, algorithm, submission status, links to the methods it uses and to its spec (all problems live under one `problems/` folder, not loose at the repo root)
- `.claude/rules/visualization-principles.md` — principles 1–16 (the short, auto-loaded form of the spec requirements)
- `.claude/skills/document-problem/SKILL.md` — the skill: writes a solved problem's README + spec + any new method entries (catalog lookup, picture build, both), by precedent from `problems/euler001-003`; escalates when a new problem doesn't fit that precedent
