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
problems (problems/euler{NNN}/README.md)  →  pictures (specs/visualizations.md)  →  ideas (this spec)
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
`method` — the `## [method::*]` headings of that file ARE the list, and it is the only place the
list lives: an enumeration copied here would need a synchronized edit on every addition, and the
one time it was copied it went stale within a single working session (see F10 below).

## Scope
**In scope:** the idea fields of `[method::*]` records — `Essence`, `Recognized by`,
`General case`, `Source`, and the part of `Limits` that bounds the idea itself; the "atomic,
named composition, or family along a named axis" discipline; and the discipline for adding new
records.

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
- **F8** (user: "[method::Catalog] and [method::PageSkeleton] need to move out of `_terms.md` —
  where's better?") Neither block was a method — no Essence/Recognized by/Source — and neither
  carried anything new: every one of their bullets already existed, word for word, as a MUST
  requirement below or in `visualizations.md` (one method one block → MUST-single-record-per-method,
  atomic-or-composed → MUST-atomic-or-composed, byte-identical rebuild → MUST-deterministic-rebuild,
  and so on for every remaining line). The two blocks were a second, informal copy of the specs, not
  a distinct fact. Deleted from `_terms.md`; the seven entity records' now-orphaned
  `Depends on: [method::Catalog]` line dropped too — it named nothing that `Spec:` didn't already
  say. Traces to: the Bounded Context section below (no separate aggregate-root record).
- **F9** (user: "each task needs a spec.md too" — first placed in `euler{NNN}/`, then "keep it next
  to the specs, not in the solution", then "separate the specs that describe specs from the applied
  ones") Reopens half of F4, deliberately, on the user's explicit choice: a task's own spec returns
  as a real path under `specs/`. What does NOT reopen: the DICTIONARY (`_terms.md`) stays exactly
  as task-free as F4/F5 left it — no `[euler::*]` record, no `Used in:` field, nothing a
  problem-side rename would ever need to touch. The distinction F4 originally missed: a spec and a
  dictionary entry are different kinds of artifact. A dictionary entry is reusable knowledge that
  must never change when a problem is added or renamed (MUST-reuse-changes-nothing). A task's own
  spec is the opposite by nature — a fixed, one-time acceptance record for one already-solved
  problem, useful as a reference precisely because it never needs to change either, just not for
  the same reason. A second distinction, inside `specs/` itself: this spec and `visualizations.md`
  are META — they describe what makes ANY method record (or its picture) good, the same way for
  every task. `specs/tasks/euler{NNN}.md` is APPLIED — one task's own requirements, checked once.
  Same folder tree, two kinds of document, kept in separate subfolders (`specs/*.md` vs.
  `specs/tasks/*.md`) so the split is visible in the file listing, not just in prose. Traces to:
  MUST-no-task-specifics (narrowed to the dictionary).
- **F10** (found by retro, not by the user directly asking) This Terms section used to spell out
  the count of `[method::*]` records by name ("twenty-seven `[method::*]` records", "(27)"). The
  count went stale inside a single working session: several new methods (`BruteForceSearch`,
  `VariableElimination`, `NextPermutation`, and others) were catalogued in `_terms.md` while this
  file's copy of the number stayed fixed. The fix is the same as MUST itself already states — the
  heading list IS the count, so no number is written down here to go stale. Traces to:
  MUST-reuse-changes-nothing (a count is exactly the kind of enumeration that needs a synchronized
  edit on every addition).
- **F11** (user: "break it into parts and visualize each separately", after "непонятно, в чём
  суть" / "откуда это берётся" across seven prior rounds) `NthPrimeBound`'s General case,
  n(ln n + ln ln n), was catalogued and redesigned four times as one atom. It was never one idea:
  the independence test — "is this recognized in another problem without the rest?" — passes
  separately for the spacing-of-primes fact, for the one-pass refinement of a self-referential
  estimate, and for the log-of-a-product step that produces the "ln ln" term. Each is now its own
  record; `NthPrimeBound` names the composition and links all three. The atomicity test had only
  ever been applied to records built from separate algorithmic steps (F2); a record whose General
  case is a single formula reads as indivisible for the same reason a run-on sentence does, and
  needs the same test run per operation, not skipped because there is only one expression to look
  at. Traces to: MUST-atomic-or-composed (formula case).
- **F12** (user: "find the approaches that aren't there at all — they may be small and
  insignificant", then "let's generalize these, do any of them unify?") Every solved problem's code
  was read line by line against the catalog. Forty-eight techniques were in active use with no
  record of any kind; twenty-two of them are non-trivial by the catalog's own standard (an
  established name plus a transferable general form), and the rest are ways of writing something
  down rather than ideas. Comparing the twenty-two by MECHANISM rather than by topic collapsed them
  into thirteen families — and seven records already in the catalog turned out to be specializations
  of one of those families rather than independent atoms. Two consequences, both structural rather
  than clerical. First, the catalog knew only two relations, atom and composition, so a
  generalization standing above several atoms had no way to exist except by restating them; a third
  relation (a family naming the AXIS along which its specializations differ) is what the audit
  required, and the axis is what keeps the family from being a retelling of its children. Second,
  the split between "worth a record" and "noise" is not a property of a technique alone: decomposing
  a number into digits, rotating its written form and checking a palindrome from both ends are each
  too small to record, yet as one family with three named axes they carry a real, transferable idea.
  Triviality is therefore judged at the family level, never at the instance level. Traces to:
  MUST-atomic-or-composed (family case), MUST-family-axis.
- **F13** (the same audit, recorded so the decision is not silently reopened) Two techniques that
  ARE really used and really transferable were deliberately left uncatalogued, because the source
  rule forbids a record without an established name and an honest search found none. They are
  written down here with what was searched, so that the next pass does not mistake the absence of a
  record for an oversight — and does not invent a name to fill it.
  (a) BOUNDING THE SEARCH REGION BEFORE SEARCHING IT, as a general technique. Three problems each
  derive an upper bound before any search begins, by three different arguments. Rejected names,
  each checked: "a priori estimate" is encyclopedic but means a bound on the solution of a partial
  differential equation, an unrelated form; "branch and bound", "pruning", "backtracking" and
  "bounded exhaustive search" all describe elimination DURING a search, driven by a bound
  recomputed per node against a running best, whereas this fixes one global limit before the search
  starts and never revisits it — labelling it so would be wrong rather than loose; "search space
  reduction" has no encyclopedic article at all. What the search did find went to its proper homes
  instead: the ordering argument is `SymmetryBreaking`, which has a real name; the digit-power
  argument is `DigitalInvariantBound`, which is a published theorem; and the rotation argument is a
  one-line closure observation belonging to a problem's own write-up. The nearest citable framing
  of WHY the umbrella works — an existence proof upgraded to an explicit computable limit — is
  Wikipedia's "Effective results in number theory", which explains the mechanism without naming it.
  (b) COMPUTING VALUES OUTSIDE A CACHE'S RANGE WHILE STORING ONLY THOSE INSIDE IT. Nothing was
  found to name: the memoization and cache-replacement articles were read in full for "bounded",
  "limited", "range", "evict" and "admission", and every hit anywhere described a limit on cache
  SIZE with eviction, not a fixed key RANGE with out-of-range values computed and discarded. This
  one differs from (a) in kind: there the idea is real and only the umbrella name is missing; here
  there is nothing beyond the ordinary notion of a cache to name. It lives as a caveat inside
  `Memoization`. Traces to: MUST-canonical-source, and to SHOULD-standard-name, whose whole point
  is that a name is looked up rather than coined.

## Architecture

### Overview (prose)
`[method::*]` records in `memory-bank/_terms.md`, one record per method. The idea fields: Essence
(one plain sentence, no formulas) / Recognized by (signs in the problem statement) / General case
(not for specific numbers) / Source (independent evidence that the idea is standard) / the idea
half of Limits. Not one field about a specific problem. Each record is either an atomic idea, an
explicitly named composition of atomic ones, or a family that generalizes two or more of them along
an axis it names (`Class: family` plus `Axis:` and `Specializations:`; each specialization carries
`Family:` back). The catalog grows as problems are worked through;
reusing a known method does not change this file at all — the problem links to the existing record
from its own README.

### Bounded Context and Aggregate Root
- `method` — the only context. It has no separate aggregate-root record: the catalog-level
  invariants (schema, atomic-or-composed, sourcing) ARE the requirements below, not a block of
  their own — a record restating them a second time (`Class: aggregate`) would be the same fact
  twice, the exact duplication this spec elsewhere forbids on ideas (MUST-atomic-or-composed).
  `_terms.md` holds only the entities — the `[method::*]` records themselves.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- Every record MUST carry Essence / Recognized by / General case / Source, and MUST NOT carry a
  field about a specific problem — **MUST-entry-schema** — criterion: grepping each mandatory
  heading yields as many lines as there are method records; there is no `Used in:` field.
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
  Status: done — the two counts are compared, never stated as a literal here.
- At least one source MUST be ENCYCLOPEDIC (Wikipedia, Britannica, cp-algorithms, a professional
  body such as NCTM) — blogs, teaching sites and least of all shop pages are not evidence of
  standardness and may only supplement — **MUST-canonical-source** — criterion: every record's
  `Source:` contains a link to `wikipedia.org`/`britannica.com`/`cp-algorithms.com`/`nctm.org`.
  Status: done — found by running the check on the user's question (F6).
- Every link in `Source:` MUST answer over the network (200, or 403 from anti-bot on a live page)
  — **MUST-source-resolves** — criterion: running `curl -L -o /dev/null -w '%{http_code}'` over
  every link in the file; dead ones are removed or replaced. Status: done — the same check found a
  dead blog link (444) and it was removed as redundant.
- Every record MUST be either atomic (one indivisible idea), an explicitly named composition of
  two or more atomic ones, or a family generalizing two or more of them along a named axis, and
  MUST NOT be "an atom plus an unnamed extra" —
  **MUST-atomic-or-composed** — criterion: when a solution uses two or more independently
  recognizable ideas, each gets its own record; the test is whether each is recognized in ANOTHER
  problem WITHOUT the other. Applies equally to a record whose General case is a FORMULA — a
  theorem or a bound reads as one indivisible thing, which is exactly how a composition of two or
  more distinct operations hides inside it; the same independence test is run per operation before
  drawing. Status: done (precedent F2: `Precomputation` + `BinarySearch`; precedent F11:
  `NthPrimeBound` = n(ln n + ln ln n), one formula holding three independently-recognizable ideas,
  redesigned four times before being split; precedent F12: thirteen families found standing above
  atoms that were already catalogued, with no relation available to express that).
- A family record MUST name the axis along which its specializations differ, and MUST NOT restate
  what any single specialization already says — **MUST-family-axis** — criterion: every record with
  `Class: family` carries an `Axis:` field naming exactly ONE axis and a `Specializations:` field
  with two or more `[method::*]` links, each of those records carries `Family:` back, a choice made
  inside a single specialization is never counted as an axis (an axis is what tells one child from
  another), and the family's `General case`
  survives the deletion test — remove every specialization from the catalog and the family still
  reads as one idea; keep them and the family adds no sentence they already carry. A family that
  cannot name an axis is a retelling of its children, which is the duplication MUST-atomic-or-composed
  forbids arriving from above instead of from the side. Status: done (F12) — the axis is also what
  decides triviality: instances too small to record separately (decomposing a number into digits,
  rotating its written form, converging two pointers) become one recordable idea as a family with
  named axes, so triviality is judged at the family level, never per instance.
- The catalog — `_terms.md`'s `[method::*]` records — MUST NOT hold ANYTHING about a specific
  problem — no statement, no solution, no correctness criteria, not even a "used in" backlink —
  **MUST-no-task-specifics** — criterion: `_terms.md` contains no `[euler::*]` records and no
  `Used in:` field; reusing a known method on a new problem touches no line of it (see
  MUST-reuse-changes-nothing below). A task's OWN requirements and acceptance criteria are a
  different artifact and live in `memory-bank/specs/tasks/euler{NNN}.md` — applied specs, kept in
  their own subfolder next to this meta-spec, not inside the dictionary. Status: done (F4, F5;
  narrowed by F9 to name the dictionary specifically once task specs returned to `specs/`).
- Reusing a known method on a new problem MUST NOT change this layer —
  **MUST-reuse-changes-nothing** — criterion: `git diff` on `_terms.md` is empty when a problem
  using an already-described method is added; the link appears only in `problems/euler{NNN}/README.md`.
  Status: done.
- This spec MUST NOT reference any layer above it — **MUST-no-upward-reference** — criterion: it
  contains no link to `visualizations.md` and no requirement whose subject is a picture, a build
  step or a problem; the spec can be applied with no other spec open. Status: done (F7).

### SHOULD
- A method's name SHOULD be the commonly accepted one, verified by search —
  **SHOULD-standard-name**. Status: done — each name checked by search before it was written down.

## Links
- Records this spec governs: the `[method::*]` blocks in `memory-bank/_terms.md`.
- Rules (short auto-loaded form): `.claude/rules/visualization-principles.md`, principles 11
  (atomic/composed), 12 (no problems in the memory bank), 14 (layer direction).
- Not to be confused with: `TRICKS.md` (repository root), CLAUDE.md "Communication style".
