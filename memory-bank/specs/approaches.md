---
status: draft
app: projecteuler
tags: [projecteuler, approaches, explanation, draft]
---

# Explanation method: requirements on the IDEA

## Layer

This is the **base layer** of the catalog. It knows nothing about anything above it: no pictures,
no build pipeline, no problems. Layers above may reference it, and it references none of them —
that direction is fixed and one-way:

```
problems (euler{NNN}/README.md)  →  pictures (specs/visualizations.md)  →  ideas (this spec)
```

A rule about the relationship between an idea and its picture therefore does NOT live here — it
lives in the dependent layer, which is the one allowed to know both sides. This spec must be
readable and applicable on its own, with no other spec open.

## Vision
When explaining a solution to a person, name the idea behind it rather than the formula — so that
the same idea can be recognized in advance from the wording of the next problem. The catalog grows
as problems are worked through, but holds no problem and no link to one: only the bare ideas, like
a textbook.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Terms live in `_terms.md`, context
`method`: [method::Catalog](../_terms.md#methodcatalog),
[method::SkipCounting](../_terms.md#methodskipcounting),
[method::InclusionExclusion](../_terms.md#methodinclusionexclusion),
[method::VennDiagram](../_terms.md#methodvenndiagram),
[method::ArithmeticProgressionSum](../_terms.md#methodarithmeticprogressionsum),
[method::Precomputation](../_terms.md#methodprecomputation),
[method::BinarySearch](../_terms.md#methodbinarysearch),
[method::TrialDivision](../_terms.md#methodtrialdivision).

## Scope
**In scope:** the idea fields of `[method::*]` records — `Essence`, `Recognized by`,
`General case`, `Source`, and the part of `Limits` that bounds the idea itself; the "atomic or
named composition" discipline; and the discipline for adding new records.

**Out of scope:** anything belonging to a layer above — how an idea is drawn, how a page is built,
which problem used it. Also out of scope: `TRICKS.md` at the repository root, which tracks SPEEDUP
techniques found during research and has its own citation discipline.

## Findings this is built on
- **F1** The first wording of inclusion–exclusion was "A+B−AB" — the two-condition special case
  presented as the general one. Traces to: MUST-general-case.
- **F2** (euler002, found by the user asking directly "is it really just one approach?") Two ideas
  used together in one solution — build the whole answer set once, then look each query up in it —
  had been fused into a single record. They are independently recognizable: precomputation appears
  in problems that never binary-search, and binary search in problems that precompute nothing.
  Split into [method::Precomputation](../_terms.md#methodprecomputation) and
  [method::BinarySearch](../_terms.md#methodbinarysearch). Traces to: MUST-atomic-or-composed.
- **F3** (user request: "there must be links to standard approaches") No idea carried a `Source:`
  field of its own — citations existed only elsewhere. Added to every record. Traces to:
  MUST-source.
- **F4** (user request: "the memory bank must not contain specific problems")
  `specs/euler001.md`/`euler002.md`/`euler003.md` and the `[euler::*]` blocks in `_terms.md` held
  the statements and correctness criteria of specific problems — not reusable knowledge, since a
  solved problem has already been checked once by a real submission. Deleted. Traces to:
  MUST-no-task-specifics.
- **F5** (user's follow-up after F4: "these are supposed to be just the primitives, no?") The
  remaining `Used in: [euler001](...)` field is also a mention of a specific problem, and it would
  have required editing THIS layer on every problem rename — duplicating a link already fully
  visible from the problem's side. Removed entirely; the link is strictly one-directional, from
  problem to idea. Traces to: MUST-no-task-specifics (tightened), MUST-reuse-changes-nothing.
- **F6** (user: "are there standard proof links everywhere?", answered by running the check rather
  than from memory) The `Source:` field was present on all seven methods, but two of them had no
  canonical source at all: `SkipCounting` cited only commercial teaching sites — one of them a
  PRODUCT PAGE selling a skip-counting hopping mat — and `Precomputation` cited only GeeksforGeeks.
  Curling every link also found one dead (a Gauss blog returning 444). Wikipedia articles for
  exactly the right concepts were verified to exist and cited; the product page and the dead link
  were removed. Traces to: MUST-canonical-source, MUST-source-resolves.
- **F7** (user: "the requirements on ideas and on pictures must be independent") This spec used to
  open by describing itself as one half of a pair, list picture fields in its own scope, and carry
  requirements about pictures (how many, what if absent, when a picture may not spawn an idea).
  That made the base layer depend on the layer above it — a cycle, and it meant this spec could not
  be read without the other one open. All picture-facing requirements and findings moved to the
  dependent layer; what remains here stands alone. Traces to: the Layer section above.

## Architecture

### Overview (prose)
`[method::*]` records in `memory-bank/_terms.md`, one record per method. The idea fields: Essence
(one plain sentence, no formulas) / Recognized by (signs in the problem statement) / General case
(not for specific numbers) / Source (independent evidence that the idea is standard) / the idea
half of Limits. Not one field about a specific problem. Each record is either an atomic idea or an
explicitly named composition of atomic ones. The catalog grows as problems are worked through;
reusing a known method does not change this file at all — the problem links to the existing record
from its own README.

### Bounded Context and Aggregate Root
- `method` — the only context; [method::Catalog](../_terms.md#methodcatalog) is the root and the
  rest are entities.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- Every record MUST carry Essence / Recognized by / General case / Source, and MUST NOT carry a
  field about a specific problem — **MUST-entry-schema** — criterion: grepping each mandatory
  heading yields as many lines as there are method records (7); there is no `Used in:` field.
  Status: done.
- "Essence" MUST be a single sentence without formulas — **MUST-essence-plain** — criterion: the
  field contains no `·`, `/`, exponents or variable names. Status: done.
- "General case" MUST describe the idea for arbitrary parameters and MUST NOT present a special
  case as the general one — **MUST-general-case** — criterion: inclusion–exclusion states the
  k-condition case and marks "A+B−AB" as k=2. Status: done.
- "Recognized by" MUST name signs in the TEXT OF THE STATEMENT by which the method is visible
  before solving — **MUST-recognition-trigger** — criterion: the sign is phrased as an observation
  about the statement ("the statement has an 'or'", "the sum is needed, not the count"), not as a
  property of the solution. Status: done.
- Every record MUST carry its own `Source:` field — an independent citation that the idea is
  standard — **MUST-source** — criterion: `grep -c '^Source:'` equals the number of method records.
  Status: done (7 of 7).
- At least one source MUST be ENCYCLOPEDIC (Wikipedia, Britannica, cp-algorithms, a professional
  body such as NCTM) — blogs, teaching sites and least of all shop pages are not evidence of
  standardness and may only supplement — **MUST-canonical-source** — criterion: every record's
  `Source:` contains a link to `wikipedia.org`/`britannica.com`/`cp-algorithms.com`/`nctm.org`.
  Status: done — found by running the check on the user's question (F6).
- Every link in `Source:` MUST answer over the network (200, or 403 from anti-bot on a live page)
  — **MUST-source-resolves** — criterion: running `curl -L -o /dev/null -w '%{http_code}'` over
  every link in the file; dead ones are removed or replaced. Status: done — the same check found a
  dead blog link (444) and it was removed as redundant.
- Every record MUST be either atomic (one indivisible idea) or an explicitly named composition of
  two or more atomic ones, and MUST NOT be "an atom plus an unnamed extra" —
  **MUST-atomic-or-composed** — criterion: when a solution uses two or more independently
  recognizable ideas, each gets its own record; the test is whether each is recognized in ANOTHER
  problem WITHOUT the other. Status: done (precedent F2: `Precomputation` + `BinarySearch`).
- The catalog MUST NOT hold ANYTHING about a specific problem — no statement, no solution, no
  correctness criteria, not even a "used in" backlink — **MUST-no-task-specifics** — criterion:
  `memory-bank/` contains no `specs/euler{NNN}.md`, no `[euler::*]` records and no `Used in:`
  field. Status: done (in two passes — F4, then F5).
- Reusing a known method on a new problem MUST NOT change this layer —
  **MUST-reuse-changes-nothing** — criterion: `git diff` on `_terms.md` is empty when a problem
  using an already-described method is added; the link appears only in `euler{NNN}/README.md`.
  Status: done.
- This spec MUST NOT reference any layer above it — **MUST-no-upward-reference** — criterion: it
  contains no link to `visualizations.md` and no requirement whose subject is a picture, a build
  step or a problem; the spec can be applied with no other spec open. Status: done (F7).

### SHOULD
- A method's name SHOULD be the commonly accepted one, verified by search —
  **SHOULD-standard-name**. Status: done for all seven (each name checked by search before it was
  written down).

## Links
- Records this spec governs: the `[method::*]` blocks in `memory-bank/_terms.md`.
- Rules (short auto-loaded form): `.claude/rules/visualization-principles.md`, principles 11
  (atomic/composed), 12 (no problems in the memory bank), 14 (layer direction).
- Not to be confused with: `TRICKS.md` (repository root), CLAUDE.md "Communication style".
