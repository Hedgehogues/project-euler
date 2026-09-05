---
status: draft
app: projecteuler
tags: [projecteuler, euler045, solution, draft]
---

# euler045 — Triangular, pentagonal, and hexagonal

## Vision
Given `N` (up to `2×10^14`), `a`, `b` (`a<b`, both in `{3,5,6}`), find every number below `N`
belonging to both figurate-number families named. Since every hexagonal number is already
triangular, the problem statement itself narrows real queries to `(3,5)` and `(5,6)`; generating
the SPARSER of the two families directly (pentagonal for `(3,5)`, hexagonal for `(5,6)`) and
testing membership in the other via an exact closed-form inversion keeps the search far smaller
than testing every integer up to `N`.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::QuadraticFormula](../../_terms.md#methodquadraticformula) (inverting
the triangular/pentagonal closed forms to test membership),
[method::BinarySearch](../../_terms.md#methodbinarysearch) (the exact integer square root of each
discriminant), and [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (generating
the sparser sequence term by term).

## Scope
**In scope:** `problems/euler045/solution.cpp` — the per-`(a,b)` generation branch, the
triangular/pentagonal membership tests, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For `(a,b)=(3,5)`: pentagonal numbers `P_n=n(3n-1)/2`
([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)) are generated until `P_n>=N`;
each is tested for triangularity by inverting `T_n=n(n+1)/2`
([method::QuadraticFormula](../../_terms.md#methodquadraticformula) +
[method::BinarySearch](../../_terms.md#methodbinarysearch) for the exact integer square root of
`1+8x`). For `(a,b)=(5,6)`: hexagonal numbers `H_n=n(2n-1)` are generated the same way and tested
for pentagonality (inverting `P_n` via `1+24x`). The `(a,b)=(3,6)` branch lists hexagonal numbers
directly with no triangularity filter, licensed by the fact that every hexagonal number is already
triangular (`H_n=T_{2n-1}`) — the problem's own constraints mean this branch is never actually
exercised by a valid query, since the statement restricts real input to `(3,5)` and `(5,6)`.

### Data
- Input: one line, `N a b`.
- Output: every number below `N` satisfying both `a` and `b`, ascending, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match both official samples (`N=10000,a=3,b=5 → 1,210`;
  `N=100000,a=5,b=6 → 1,40755`) — **MUST-match-sample** — criterion: zero difference against both
  given samples. Status: done (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #45 chain (`1, 40755, 1533776805` for
  `(5,6)`) and the fuller `(3,5)` sequence up to `N=2×10^14`
  (`1, 210, 40755, 7906276, 1533776805, 297544793910, 57722156241751`, matching OEIS
  A014979/A046180) — **MUST-match-original-pe45** — criterion: exact term-for-term match. Status:
  done (re-run live 2026-09-01).
- The solution MUST agree with an independent Python re-implementation of the same membership
  tests — **MUST-match-bruteforce** — criterion: cross-checked on both official samples — exact
  match. Status: done.
- Both membership tests (`isTriangular`, `isPentagonal`) MUST use an exact integer square root,
  never floating-point `sqrt` — **MUST-exact-sqrt** — criterion: both call the shared `isqrt`
  binary-search helper. Status: done.
- `problems/euler045/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler045/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N a b`; qualifying numbers, ascending, one per
  line) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::QuadraticFormula](../../_terms.md#methodquadraticformula),
  [method::BinarySearch](../../_terms.md#methodbinarysearch),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler045/solution.cpp`; directory README: `problems/euler045/README.md`.
