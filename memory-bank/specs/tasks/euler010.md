---
status: draft
app: projecteuler
tags: [projecteuler, euler010, solution, draft]
---

# euler010 — Summation of primes

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 10^4`, `1 ≤ N ≤ 10^6`), find the sum of all primes
not greater than `N`. Re-sieving and re-summing from scratch for every query costs up to
`T × N = 10^4 × 10^6 = 10^10` operations in the worst case — far past the time limit. Sieving once
for the largest `N` actually queried, and keeping a running total alongside it, turns every query
into a single array lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
[method::PrefixSum](../../_terms.md#methodprefixsum),
[method::Precomputation](../../_terms.md#methodprecomputation).

## Scope
**In scope:** `problems/euler010/solution.cpp` — the sieve, the running total, correctness
criteria.

**Out of scope:** the visual explanation of any of the three methods (the catalog, not this
task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
The largest `N` across all `T` queries is found first, per
[method::Precomputation](../../_terms.md#methodprecomputation): build once, not once per query.
[method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes) marks every composite up
to that bound in a single pass. Alongside it, a
[method::PrefixSum](../../_terms.md#methodprefixsum) array accumulates the running sum of primes
seen so far. Each query is then answered by indexing directly into that array, `prefixSum[n]`.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 10^6`).
- Output: `T` lines — the sum of primes `≤ N`, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent brute-force sieve across the ENTIRE valid range `n =
  1..1000000` — **MUST-match-bruteforce** — criterion: zero difference across all 1000000 values.
  Status: done (HackerRank Accepted 100%, submission 1410851700, 2026-07-12; re-checked live on
  2026-09-01: the official sample (`n=5→10`, `n=10→17`) plus the full exhaustive range against an
  independently written sieve+prefix-sum, exact match on every value).
- The prime list and its running total MUST be built ONCE for the largest `N` across all queries,
  not once per query — **MUST-precompute-once** — criterion: both loops run before, and outside
  of, the per-query answer loop. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at `n=10^6`, the sum of primes below it is `≈3.755×10^10`, comfortably inside `long long` (64
  bits, max `~9.2×10^18`); verified by direct computation. Status: done.
- `problems/euler010/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler010/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::PrefixSum](../../_terms.md#methodprefixsum),
  [method::Precomputation](../../_terms.md#methodprecomputation).
- Code: `problems/euler010/solution.cpp`; directory README: `problems/euler010/README.md`.
