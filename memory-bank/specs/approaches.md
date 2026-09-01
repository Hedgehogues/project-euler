---
status: draft
app: projecteuler
tags: [projecteuler, approaches, explanation, draft]
---

# Explanation method: requirements on the IDEA

## Vision
When explaining a solution to a person, name the idea behind it rather than the formula — so that
the same idea can be recognized in advance from the wording of the next problem. The catalog grows
as problems are worked through, but holds no problem and no link to one: only the bare ideas, like
a textbook.

This spec and its sibling [visualizations](visualizations.md) describe THE SAME set of
`[method::*]` records in `_terms.md` from two sides: here, the requirements on the idea
(atomicity, recognizability, sourcing); there, on its picture (frames, build, observing the
render). These are not two catalogs — they are two aspects of one.

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
**In scope:** the idea fields of `[method::*]` blocks (`Essence` / `Recognized by` /
`General case` / the idea half of `Limits` / `Source`), the "atomic or named composition"
discipline, and the discipline for adding new records.

**Out of scope:** the picture fields of those same blocks (`Picture` / `Sequence` / `Example` /
the drawing half of `Limits`) — see [visualizations](visualizations.md); `TRICKS.md` at the
repository root, which tracks SPEEDUP techniques found during research and has its own citation
discipline; and the problems themselves (statement, solution, correctness criteria), which live in
`euler{NNN}/README.md`, not here (see MUST-no-task-specifics).

## Findings this is built on
- **F1** The approach collection and the picture catalog existed side by side with no links; once
  connected it turned out no approach lacked a picture, while one picture had no approach (skip
  counting — a notion, not a counting method). Traces to: MUST-picture-optional,
  MUST-no-invented-approach.
- **F2** The first wording of inclusion–exclusion was "A+B−AB" — the two-condition special case
  presented as the general one. Traces to: MUST-general-case.
- **F3** (euler002) "Precompute once + binary search per query" is easy to confuse with
  precomputation itself, which has no visualization of its own (the same class as skip counting
  for "multiple of", F1); the separately standard technique is binary search. Traces to:
  MUST-picture-optional, MUST-no-invented-approach.
- **F4** (euler002, found by the user asking directly "is it really just one approach?") F3
  conflated two different questions — "does this step deserve its own PICTURE" (no, precomputation
  does not draw, F1) and "does it deserve its own RECORD" (a different question: both of euler001's
  ideas — inclusion–exclusion and the progression sum — have their own literature and are
  recognized independently in different problems; so are precomputation and binary search). The
  single `PrecomputeAndBinarySearch` block had been fused out of that confusion. Split into
  [method::Precomputation](../_terms.md#methodprecomputation) (no picture — honestly marked, not
  invented) and [method::BinarySearch](../_terms.md#methodbinarysearch) (with one). Traces to:
  MUST-entry-independent-of-picture.
- **F5** (user request: "one approach — one picture", "the memory bank must not contain specific
  problems", "there must be links to standard approaches"). Three findings in one pass:
  1. Inclusion–exclusion violated "one picture per record" — it had TWO (the bar and the Venn
     diagram). The review showed this was NOT one idea drawn twice but two separate, independently
     standard ideas often used together (the same pattern as F4): inclusion–exclusion is counting
     arithmetic; the Venn diagram represents logical propositions with circles and was invented by
     John Venn in 1880 for an ENTIRELY DIFFERENT purpose (not counting). Split; both pictures kept,
     each with its own record.
  2. No idea carried a `Source:` field — independent citations existed only for the pictures.
     Added. Traces to: MUST-source.
  3. `euler001.md`/`euler002.md`/`euler003.md` lived as separate specs INSIDE the memory bank —
     specific problems, not reusable knowledge. Deleted. Traces to: MUST-no-task-specifics.
- **F6** (user's follow-up after F5: "these are supposed to be just the primitives, no?") The
  remaining `Used in: [euler001](...)` field is also a mention of a specific problem, and it would
  have required editing THIS file on every problem rename — duplicating a link already fully
  visible from the other side. Removed entirely; the link is now strictly one-directional, from
  problem to primitive. Traces to: MUST-no-task-specifics (tightened), MUST-reuse-changes-nothing.
- **F7** (user: "there are duplicates again", confirmed by grepping the file) The split into two
  contexts — `[approach::*]` (idea) and `[viz::*]` (picture) — was itself the duplication: two
  blocks with IDENTICAL names (`VennDiagram`, `BinarySearch`), each of five pictures embedded
  twice, sources duplicated, descriptions paraphrasing each other. This split had been defended
  twice on the grounds that "they are different layers" (F4/F5 even used it as the reason to split
  ideas apart) — the argument was wrong: layers are distinguished by FIELDS within one record, not
  by two lists. The contexts were merged into a single `method`; idea and picture fields live in
  one block, and `Limits` marks per bullet which limit belongs to the idea and which only to the
  drawing. Traces to: MUST-single-entry-per-method.
- **F8** (user: "are there standard proof links everywhere?", answered by running the check rather
  than from memory) The `Source:` field was present on all seven methods, but two of them had no
  canonical source at all: `SkipCounting` cited only commercial teaching sites — one of them a
  PRODUCT PAGE selling a skip-counting hopping mat — and `Precomputation` cited only GeeksforGeeks.
  Curling every link also found one dead (a Gauss blog returning 444). Wikipedia articles for
  exactly the right concepts were verified to exist and cited; the product page and the dead link
  were removed. Traces to: MUST-canonical-source, MUST-source-resolves.

## Architecture

### Overview (prose)
`[method::*]` blocks in `memory-bank/_terms.md`, one block per method. Idea fields: Essence (one
plain sentence, no formulas) / Recognized by (signs in the problem statement) / General case (not
for specific numbers) / Source (independent evidence that the idea is standard) / Limits (the idea
half). Not one field about a specific problem. Each record is either an atomic idea or an
explicitly named composition of atomic ones. The catalog grows as problems are worked through;
reusing a known method does not change this file at all — the problem links to the existing block
from its own README.

### Bounded Context and Aggregate Root
- `method` — the only context; [method::Catalog](../_terms.md#methodcatalog) (root),
  [method::PageSkeleton](../_terms.md#methodpageskeleton) (VO), the rest are entities. There is no
  separate context for pictures (see F7) — a picture is a set of fields on a method record.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- One method MUST be described by ONE `[method::*]` record; the idea and its picture MUST NOT be
  split across two parallel blocks or contexts — **MUST-single-entry-per-method** — criterion:
  `grep -oE '^## \[\w+::\w+\]' _terms.md | sort | uniq -d` is empty and only the `method` context
  appears; every `build/*.png` is referenced exactly once in the file. Status: done (found by the
  user — F7).
- Every record MUST carry Essence / Recognized by / General case / Source (plus the picture fields
  when there is one) and MUST NOT carry a field about a specific problem — **MUST-entry-schema** —
  criterion: grepping each mandatory heading yields as many lines as there are method records (7);
  there is no `Used in:` field in the file. Status: done.
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
  standard; when the picture has its own separate source it goes in the same field marked
  "picture:" — **MUST-source** — criterion: `grep -c '^Source:'` equals the number of method
  records. Status: done (7 of 7).
- At least one source MUST be ENCYCLOPEDIC (Wikipedia, Britannica, cp-algorithms, a professional
  body such as NCTM) — blogs, teaching sites and least of all shop pages are not evidence of
  standardness and may only supplement — **MUST-canonical-source** — criterion: every record's
  `Source:` contains a link to `wikipedia.org`/`britannica.com`/`cp-algorithms.com`/`nctm.org`.
  Status: done — found by running the check on the user's question (F8): `SkipCounting` had only
  commercial teaching sites (one of them a product listing for a hopping mat) and `Precomputation`
  only GeeksforGeeks; Wikipedia articles (Skip counting, Number line, Precomputation, Lookup table,
  Tape diagram) were added and the product page removed.
- Every link in `Source:` MUST answer over the network (200, or 403 from anti-bot on a live page)
  — **MUST-source-resolves** — criterion: running `curl -L -o /dev/null -w '%{http_code}'` over
  every link in the file; dead ones are removed or replaced. Status: done — the same check found a
  dead eduSeed blog link (444), removed as redundant (Gauss is already covered by Wikipedia,
  BetterExplained and NCTM).
- A record MUST have at most one picture — **MUST-one-picture-max** — criterion: no more than one
  `Picture:` field and one `build/*.png` reference per block. An idea with two independently
  standard visual forms is two records (see F5.1), not one with two portraits. Status: done.
- The absence of a picture MUST NOT decide whether to create a separate record — these are two
  different questions: "is this idea recognized apart from its neighbours" (decides the record) and
  "does it have an established visual form" (decides the picture) —
  **MUST-entry-independent-of-picture** — criterion:
  [method::Precomputation](../_terms.md#methodprecomputation) is a legitimate record with
  `Picture: —` sitting next to [method::BinarySearch](../_terms.md#methodbinarysearch), which has
  one. Status: done (found by the user — F4).
- A record without a picture MUST state the reason rather than leaving the field blank —
  **MUST-picture-optional** — criterion: the value `Picture: —` is accompanied by an explanation of
  why no visual form exists. Status: done.
- A method MUST NOT be created just to give an existing picture something to point at —
  **MUST-no-invented-approach** — criterion: a picture with no self-standing idea produces no
  record; skip counting is not such a case (it is a method in its own right — that is how "multiple
  of" is defined). Status: done.
- Every record MUST be either atomic (one indivisible idea) or an explicitly named composition of
  two or more atomic ones, and MUST NOT be "an atom plus an unnamed extra" —
  **MUST-atomic-or-composed** — criterion: when a solution uses two or more independently standard
  ideas, each gets its own record (as with `Precomputation`+`BinarySearch`,
  `InclusionExclusion`+`VennDiagram`). Status: done.
- The catalog MUST NOT hold ANYTHING about a specific problem — no statement, no solution, no
  correctness criteria, not even a "used in" backlink — **MUST-no-task-specifics** — criterion:
  `memory-bank/` contains no `specs/euler{NNN}.md`, no `[euler::*]` blocks and no `Used in:` field.
  Status: done (in two passes — F5.3, then F6).
- Reusing a known method on a new problem MUST NOT change this file —
  **MUST-reuse-changes-nothing** — criterion: `git diff` on `_terms.md` is empty when a problem
  using an already-described method is added; the link appears only in `euler{NNN}/README.md`.
  Status: done.

### SHOULD
- A method's name SHOULD be the commonly accepted one, verified by search —
  **SHOULD-standard-name**. Status: done for all seven (each name checked by search before it was
  written down).

## Links
- Records: the `[method::*]` blocks in `memory-bank/_terms.md`.
- The other aspect of the same records: [visualizations](visualizations.md) (requirements on the
  picture).
- Rules: `.claude/rules/visualization-principles.md`, principles 9 (one record per method), 11
  (atomic/composed, at most one picture), 12 (no problems in the memory bank).
- Not to be confused with: `TRICKS.md` (repository root), CLAUDE.md "Communication style".
