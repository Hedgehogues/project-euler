---
status: draft
app: projecteuler
tags: [projecteuler, tasks, spec-format, draft]
---

# Task spec format: requirements on specs/tasks/*.md

## Layer

This is a spec about specs — it governs the FORMAT of `specs/tasks/*.md`, not their content's
truth (that's checked per-file, against the actual `solution.cpp`). It sits beside
[approaches](approaches.md) and [visualizations](visualizations.md), not inside their
`problems → pictures → ideas` chain: those two govern the reusable dictionary (`_terms.md`), this
one governs a different kind of document — a fixed, one-time acceptance record for one already
-solved problem. A task spec may reference the dictionary (to cite the methods it uses) but this
spec does not reference `_terms.md` itself; it only requires that references resolve.

## Vision
Every solved problem gets an RFC-style spec: what it asks, why the solution is correct, which
catalogued methods it uses. Not reusable knowledge — the dictionary's job — a checked record for
THIS problem, useful precisely because it never needs to change once written.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Governs every file matching
`memory-bank/specs/tasks/euler{NNN}.md`.

## Scope
**In scope:** the section structure of a task spec, the phrasing of a Requirement, what a
verification Status line must actually name, which paths and method references it must contain.

**Out of scope:** the methods catalog itself — see [approaches](approaches.md) (idea quality),
[visualizations](visualizations.md) (picture quality); the problem's own `README.md` (the prose
write-up — a different document that links to the spec, not a duplicate of it).

## Architecture

### Overview (prose)
One file per solved problem, `memory-bank/specs/tasks/euler{NNN}.md`, in the same RFC shape as the
two catalog specs (frontmatter, `## Vision`/`## Terms`/`## Scope`/`## Architecture`/
`## Requirements`/`## Links`) — a reader who knows one of the three specs in this folder can read
any other without learning a new format. A task spec references the dictionary; the dictionary
never references it back (the same one-way rule [approaches](approaches.md)'s Layer section states
for pictures and ideas, applied here to problems).

## Requirements
> Statement — acceptance criterion — status.

### MUST
- A task spec MUST have exactly six sections, in this order: Vision, Terms, Scope, Architecture,
  Requirements, Links — **MUST-section-shape** — criterion: the `##` headings of a task spec, read
  in order, are exactly this list. Status: done (euler001/002/003).
- Vision MUST name the constraint that rules out the naive approach (why a smarter algorithm is
  needed), not just restate the problem statement — **MUST-vision-names-constraint** — criterion:
  Vision mentions the specific bound (a size, a count, a range) that a brute-force solution cannot
  meet. Status: done.
- Terms MUST list every catalogued method the solution uses as
  `[method::Name](../../_terms.md#methodname)`, and every such anchor MUST resolve to a real
  heading in `_terms.md` — **MUST-methods-resolve** — criterion: grepping the anchor against
  `_terms.md`'s `## [method::*]` headings finds a match for each one. Status: done.
- Every Requirement MUST be phrased: statement — a bold `**MUST-id**` — a `criterion:` clause — a
  `Status:` clause — **MUST-requirement-shape** — criterion: each bullet under `### MUST` contains
  all four parts in that order. Status: done.
- Every task spec MUST include one correctness requirement whose `Status:` line names the ACTUAL
  check performed — a real submission id and date, or a live re-run's command and output — never a
  bare "done" asserted from memory of an earlier claim — **MUST-status-is-evidence** — criterion:
  the correctness requirement's `Status:` clause names either a submission id or a command that was
  actually executed while writing the spec. Status: done (euler001/002 re-verified live on
  2026-09-01; euler003 cites its real submission id, re-verified live the same day).
- Every task spec MUST include an ASCII-only requirement and an I/O-format requirement, each naming
  the solution file's actual path (`problems/euler{NNN}/solution.cpp`) —
  **MUST-standard-requirements** — criterion: both requirements are present and their file path
  matches the problem's real directory. Status: done.
- Links MUST name the code path and the directory README path, both as they actually resolve on
  disk — **MUST-links-resolve** — criterion: both backtick-quoted paths in Links are real files.
  Status: done.
- A task spec MUST NOT introduce a new `[method::*]` catalog entry of its own — if a technique used
  isn't catalogued yet, it is added to `_terms.md` first, following
  [approaches](approaches.md)'s own discipline, and only then referenced —
  **MUST-no-new-methods-here** — criterion: a task spec's only mentions of `[method::*]` are links
  into `_terms.md`, never a `##`-level definition. Status: done.

## Links
- Governs: every file in `memory-bank/specs/tasks/`.
- Sibling meta-specs, which this one does not duplicate: [approaches](approaches.md) (idea
  quality), [visualizations](visualizations.md) (picture quality) — both govern `_terms.md`, not
  task specs.
- Applied instances: `memory-bank/specs/tasks/euler001.md`, `euler002.md`, `euler003.md`.
