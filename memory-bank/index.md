# Index

> The memory bank holds only reusable knowledge — explanation methods, like a textbook. Not a
> single specific problem and not a single link to one lives here: the link runs the other way,
> a problem (`euler{NNN}/README.md`) points at the block it needs by name.
>
> **One method, one block.** The idea and its picture are not split across two parallel lists but
> live as fields of a single `[method::*]` record; a method has at most one picture, and having
> none is legitimate with a stated reason.

## projecteuler — explaining solutions
- [_terms.md](_terms.md) — the dictionary and the ONLY place descriptions live: context `method` — SkipCounting, InclusionExclusion, VennDiagram, ArithmeticProgressionSum, Precomputation, BinarySearch, TrialDivision (the catalog- and shell-level invariants live in the two specs below, not as blocks of their own)
- [approaches](specs/approaches.md) — Status: draft — requirements on the IDEA in a method record: atomic or a named composition, recognizable from the statement, canonical source, at most one picture
- [visualizations](specs/visualizations.md) — Status: draft — requirements on the PICTURE: frames problem → transforms → solution, deterministic `build.sh`, observing the render, repository QR

### Pictures — sources and build
- `visualizations/examples/<slug>.{css,html,js}` — frame code (edited by hand)
- `visualizations/skeleton.html` — the shared page shell
- `visualizations/build.sh` — build: `build/<slug>.html` + `build/<slug>.png` (headless browser, light theme); the `cards()` table maps a picture slug to its `[method::*]` block name
- `visualizations/build/` — output; the pictures are embedded in `_terms.md`

### Outside the memory bank
- `euler{NNN}/README.md` — the problem itself: statement, algorithm, submission status, links to the methods it uses
- `.claude/rules/visualization-principles.md` — principles 1–15 (the short, auto-loaded form of the spec requirements)
- `.claude/skills/visualize-approach/SKILL.md` — the skill: finds a method in `_terms.md`, runs `build.sh`, opens the result
