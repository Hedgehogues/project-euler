# euler010 — Summation of primes

For each of `T` given values of `N` (`1 ≤ N ≤ 10^6`), find the sum of all primes not greater
than `N`.

## Approach

- Sieve every prime up to the largest `N` across all queries once.
- Build a running total of primes alongside the sieve: `prefixSum[i] = prefixSum[i-1] + (i if
  prime else 0)`.
- Answer each query with a single array lookup, `prefixSum[n]`.

Status: **Accepted**, 100% on HackerRank (submission 1410851700, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=5 → 10`, `N=10 → 17`) and an exhaustive brute-force
cross-check across the ENTIRE valid range `N = 1..1000000` — exact match on every value.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler010.md).

## The idea(s) behind it

**Sieve of Eratosthenes** — cross out every multiple of each prime found so far; whatever survives
unmarked is exactly the primes. [`[method::SieveOfEratosthenes]`](../../memory-bank/_terms.md#methodsieveoferatosthenes)

[![Sieve of Eratosthenes](../../memory-bank/visualizations/build/sieve-of-eratosthenes.png)](../../memory-bank/visualizations/build/sieve-of-eratosthenes.html)

**Prefix sum** — a running total built once turns the sum of primes up to any `N` into a single
array lookup, instead of re-adding primes for every query.
[`[method::PrefixSum]`](../../memory-bank/_terms.md#methodprefixsum)

[![Prefix sum](../../memory-bank/visualizations/build/prefix-sum.png)](../../memory-bank/visualizations/build/prefix-sum.html)

The sieve and the running total are both built once for the largest `N` across all `T` queries,
not once per query — the same [`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation)
pattern already catalogued.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
