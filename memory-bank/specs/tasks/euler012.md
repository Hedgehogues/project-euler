---
status: draft
app: projecteuler
tags: [projecteuler, euler012, solution, draft]
---

# euler012 — Highly divisible triangular number

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 10`, `1 ≤ N ≤ 10^3`), find the first triangular
number with more than `N` divisors. Factoring each triangular number `T_n = n(n+1)/2` directly by
trial division, for every `n` up to the point the answer for `N=1000` is found, would repeatedly
pay `O(sqrt(T_n))` per number — `T_n` grows quadratically in `n`, so this cost climbs fast.
Splitting `T_n` into its two coprime halves and factoring each with a precomputed smallest-prime-factor
sieve turns every factorization into a fast walk of prime powers instead of trial division from
scratch.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum),
[method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
[method::DivisorCountFormula](../../_terms.md#methoddivisorcountformula), [method::LinearSieve](../../_terms.md#methodlinearsieve) (the sieve stores every number smallest prime factor, so any number in range is taken apart by repeated division), [method::MultiplicativeFunction](../../_terms.md#methodmultiplicativefunction) (the triangular number splits into two factors sharing no prime, and their divisor counts multiply), and [method::OfflineAlgorithm](../../_terms.md#methodofflinealgorithm) (the thresholds are all read first and answered in one ascending pass).

## Scope
**In scope:** `problems/euler012/solution.cpp` — the coprime split, the SPF sieve, the divisor
count, correctness criteria.

**Out of scope:** the visual explanation of any of the three methods (the catalog, not this
task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`T_n = n(n+1)/2`, [method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum)'s
general formula at `k=1`. Since `gcd(n,n+1)=1`, exactly one of `n`, `n+1` is even; splitting it as
`a = n/2, b = n+1` (n even) or `a = n, b = (n+1)/2` (n odd) gives two coprime factors whose product
is `T_n`. A smallest-prime-factor sieve
([method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes), storing the smallest
prime factor per number instead of a composite flag) is built once up to a fixed bound. Each of
`a`, `b` is factored by repeatedly dividing out its smallest prime factor, and
[method::DivisorCountFormula](../../_terms.md#methoddivisorcountformula)'s multiplicativity gives
`d(T_n) = d(a)·d(b)` without ever factoring `T_n` itself. Walking `n` upward and recording, for
every threshold `1..1000`, the first `T_n` whose divisor count exceeds it, fills every possible
query answer in one pass.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 1000`).
- Output: `T` lines — the first triangular number with more than `N` divisors, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent brute-force divisor count (trial division directly on
  `T_n`) across the ENTIRE valid range `n = 1..1000` — **MUST-match-bruteforce** — criterion: zero
  difference across all 1000 threshold values. Status: done (HackerRank Accepted 100%, submission
  1410851713, 2026-07-12; re-checked live on 2026-09-01: the official sample (`N=1→3, N=2→6,
  N=3→6, N=4→28`) plus the full exhaustive range against an independently written trial-division
  divisor counter, exact match on every value).
- The divisor count MUST be computed via the two coprime halves of `T_n`, never by factoring
  `T_n` itself — **MUST-coprime-split** — criterion: `computeAnswers()` factors `a` and `b`
  separately and multiplies their divisor counts. Status: done.
- The smallest-prime-factor sieve MUST be built ONCE, not per triangular number — **MUST-precompute-once**
  — criterion: `buildSmallestPrimeFactor` is called exactly once, before the loop over `n`.
  Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  the triangular number reached for `N=1000` stays well under `10^9`, comfortably inside `long
  long`; verified by direct computation (the sieve limit `60000` bounds `a`/`b`, so `T_n < 60000 ×
  another factor`, still far under overflow). Status: done.
- `problems/euler012/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler012/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum),
  [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::DivisorCountFormula](../../_terms.md#methoddivisorcountformula),
  [method::LinearSieve](../../_terms.md#methodlinearsieve),
  [method::MultiplicativeFunction](../../_terms.md#methodmultiplicativefunction),
  [method::OfflineAlgorithm](../../_terms.md#methodofflinealgorithm).
- Code: `problems/euler012/solution.cpp`; directory README: `problems/euler012/README.md`.
