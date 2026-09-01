---
status: draft
app: projecteuler
tags: [projecteuler, euler018, solution, draft]
---

# euler018 — Maximum path sum I

## Vision
For each of `T` given triangles of `N` rows (`1 ≤ T ≤ 10`, `1 ≤ N ≤ 15`), find the maximum
top-to-bottom path sum. `N ≤ 15` makes exhaustive path enumeration (`2^14 ≈ 16384` paths) still
fast enough here, but the intended technique — building the answer bottom-up from each cell's two
possible next steps — is what generalizes: euler067 later asks the identical question for a
triangle with 100 rows, where `2^99` paths make enumeration impossible, and the exact same
bottom-up recurrence still answers it in `O(N²)`.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::DynamicProgramming](../../_terms.md#methoddynamicprogramming).

## Scope
**In scope:** `problems/euler018/solution.cpp` — the bottom-up triangle sweep, correctness
criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::DynamicProgramming](../../_terms.md#methoddynamicprogramming), the triangle is swept
from its second-to-last row upward. Each cell `tri[i][j]` is replaced by
`tri[i][j] + max(tri[i+1][j], tri[i+1][j+1])` — the better of its two reachable cells on the row
below, already holding ITS best sum to the bottom by the time row `i` is processed. After the
sweep reaches row 0, `tri[0][0]` holds the maximum path sum for the whole triangle.

### Data
- Input: `T`, then for each test case a line `N` followed by `N` lines, the `i`th holding `i`
  numbers (`0 ≤ value < 100`).
- Output: `T` lines — the maximum top-to-bottom path sum, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(triangle)` MUST match an independent full path enumeration across randomized triangles —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851758, 2026-07-12; re-checked live on 2026-09-01: the official sample (the
  4-row triangle → `23`) plus 300 randomly generated triangles, 1-15 rows each, against an
  independently written recursive full-enumeration solver, exact match on every case).
- The sweep MUST proceed strictly bottom-to-top, each row read only after the row below it is
  fully updated — **MUST-bottom-up-order** — criterion: the `for` loop over `i` runs from `N-2`
  down to `0`. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at `N=15` values under 100, the maximum possible path sum stays under `1500`, comfortably inside
  `int`. Status: done.
- `problems/euler018/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler018/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::DynamicProgramming](../../_terms.md#methoddynamicprogramming).
- Code: `problems/euler018/solution.cpp`; directory README: `problems/euler018/README.md`.
