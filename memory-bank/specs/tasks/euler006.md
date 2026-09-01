---
status: draft
app: projecteuler
tags: [projecteuler, euler006, solution, draft]
---

# euler006 — Sum square difference

## Vision
For each of `T` given values of `N` (`1 ≤ N ≤ 10^4`, `T ≤ 10^4`), find the absolute difference
between the sum of the squares of the first `N` natural numbers and the square of their sum.
Adding `N` terms one at a time, twice (once for the linear sum, once for the sum of squares), for
up to `10^4` queries each up to `N=10^4` costs up to `10^8` additions — closed-form formulas for
both sums turn every query into a handful of arithmetic operations instead.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods, genuinely
independent of each other (`../../_terms.md`):
[method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum),
[method::SumOfSquares](../../_terms.md#methodsumofsquares).

## Scope
**In scope:** `problems/euler006/solution.cpp` — the model, the two formulas, correctness
criteria.

**Out of scope:** the visual explanation of either formula (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
The sum of the first `N` natural numbers is
[method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum)'s general case
with step `k=1`: `N·(N+1)/2`. The sum of the first `N` squares is a genuinely different, cubic
closed form ([method::SumOfSquares](../../_terms.md#methodsumofsquares)): `N·(N+1)·(2N+1)/6`. The
answer is the square of the first minus the second: `(N·(N+1)/2)² − N·(N+1)·(2N+1)/6`. Both
formulas are evaluated directly, no loop over `1..N` in either.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 10^4`).
- Output: `T` lines — `sum² − sumSquares` for that `N`, per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent brute-force computation (`sum(1..n)² − sum(i² for i in
  1..n)`) across the ENTIRE valid range `n = 1..10000` — **MUST-match-bruteforce** — criterion:
  zero difference across all 10000 values. Status: done (HackerRank Accepted 100%, submission
  1410850893, 2026-07-12; re-checked live on 2026-09-01: both official samples (`n=3→22`,
  `n=10→2640`) plus the full exhaustive range, exact match on every value).
- The linear sum MUST be computed via the arithmetic-progression formula `n·(n+1)/2`, not a loop
  — **MUST-closed-form-sum** — criterion: `solve()` contains no loop accumulating `1..n`. Status:
  done.
- The sum of squares MUST be computed via the cubic closed form `n·(n+1)·(2n+1)/6`, not a loop
  and not derived from the linear-sum formula — **MUST-closed-form-sum-squares** — criterion: a
  separate `sumSquares` expression using `(2*n+1)`, distinct from the `sum` expression. Status:
  done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at `n=10^4`, `sum ≈ 5×10^7`, `sum² ≈ 2.5×10^15`, `sumSquares ≈ 3.3×10^11` — all comfortably
  inside `long long` (64 bits, max `~9.2×10^18`); verified by direct computation, not assumed.
  Status: done.
- `problems/euler006/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler006/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum),
  [method::SumOfSquares](../../_terms.md#methodsumofsquares).
- Code: `problems/euler006/solution.cpp`; directory README: `problems/euler006/README.md`.
