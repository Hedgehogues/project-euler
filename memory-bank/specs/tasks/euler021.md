---
status: draft
app: projecteuler
tags: [projecteuler, euler021, solution, draft]
---

# euler021 — Amicable numbers

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 1000`, `1 ≤ N ≤ 10^5`), sum the amicable numbers
below `N`. Computing each number's proper-divisor sum independently by trial division, for every
number up to the largest queried `N` and for every query, costs `O(sqrt(x))` per number and would
repeat that work across queries. Accumulating every number's divisor sum in one pass (touching
each multiple of each `d` once) and then prefix-summing the amicable ones answers every query with
a lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::PrefixSum](../../_terms.md#methodprefixsum). The divisor-sum
accumulation itself is a plain variant of the "touch every multiple" sieve mechanism (see
`problems/euler021/README.md`) — not independently catalogued (no encyclopedic source found for
this specific summing variant, only blogs/teaching sites).

## Scope
**In scope:** `problems/euler021/solution.cpp` — the divisor-sum accumulation, the amicable check,
the prefix sum, correctness criteria.

**Out of scope:** the visual explanation of the catalogued method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`divSum[x]` accumulates the sum of `x`'s proper divisors: for each `d` from `1` below the limit,
`d` is added to `divSum[multiple]` for every `multiple = 2d, 3d, ...` below the limit — every
number's divisor sum is complete after this single pass. A number `a` is amicable when
`divSum[a] ≠ a`, `divSum[a]` is itself a valid index, and `divSum[divSum[a]] == a`. Per
[method::PrefixSum](../../_terms.md#methodprefixsum), a running total of amicable numbers is built
once; each query reads `prefix[N-1]` directly.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 10^5`).
- Output: `T` lines — the sum of amicable numbers below `N`, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent trial-division divisor-sum computation across the ENTIRE
  valid range `n = 1..100000` — **MUST-match-bruteforce** — criterion: zero difference across all
  100000 values. Status: done (HackerRank Accepted 100%, submission 1410851780, 2026-07-12;
  re-checked live on 2026-09-01: the official sample (`N=300→504`) plus the full exhaustive range
  against an independently written trial-division divisor-sum checker, exact match on every
  value).
- The divisor-sum accumulation MUST touch each multiple of each `d` exactly once, in a single pass
  built before any query is answered — **MUST-precompute-once** — criterion: the double loop over
  `d`/`multiple` runs once, before the prefix-sum loop and the query loop. Status: done.
- A number MUST NOT be counted as amicable when its divisor-sum partner equals itself (a perfect
  number) — **MUST-exclude-perfect** — criterion: `amicable` requires `b != a`. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  the prefix sum at `N=10^5` stays under `10^5 × 10^5 = 10^10`, comfortably inside `long long`
  (the divisor sums themselves are individually bounded by `N`, fitting easily in `int`). Status:
  done.
- `problems/euler021/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler021/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::PrefixSum](../../_terms.md#methodprefixsum).
- Code: `problems/euler021/solution.cpp`; directory README: `problems/euler021/README.md`.
