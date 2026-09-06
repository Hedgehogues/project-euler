# euler047 — Distinct primes factors

Given `N` and `K` (`2 ≤ K ≤ 4`), find every run of `K` consecutive integers, first one `≤ N`, each
having exactly `K` distinct prime factors — printing the first integer of each such run, ascending.

## Approach

- Sieve the count of DISTINCT prime factors (`ω(n)`) for every number up to `N+K`: walk every
  prime `p` (detected the moment its own cell is still 0 when reached) and increment the cell of
  every multiple of `p` by one — each prime contributes at most once per number, regardless of its
  own power.
- For each candidate `m ≤ N`, check whether `ω(m), ω(m+1), ..., ω(m+K-1)` are all exactly `K`.

Status: **Accepted**, 100% on HackerRank (submission 1410853255, 2026-07-13, `cpp20`). Re-verified
live on 2026-09-01: matches both official samples (`N=20,K=2 → 14,20` and `N=644,K=3 → 644`),
reproduces the classic Project Euler #47 answer (`N=2000000,K=4` → first result `134043`), and
cross-checked against an independent Python computation using direct trial-division factorization
(not the sieve) on both samples — exact match.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler047.md).

## The idea(s) behind it

**Sieving over multiples** — the same walk-the-multiples-of-every-prime sweep as the Sieve of
Eratosthenes, here incrementing a per-number counter instead of marking composites, to fill in the
distinct-prime-factor count for every number up to the limit at once.
[`[method::SievingOverMultiples]`](../../memory-bank/_terms.md#methodsievingovermultiples)

**Brute-force search** — each of the `N` candidate starting points is checked directly against its
`K` consecutive `ω` values.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

**Precomputation** — the `ω` table is built once, before any candidate is tested, and every check
against it is then a plain array read.
[`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation)

[![Precomputation](../../memory-bank/visualizations/build/precomputation.png)](../../memory-bank/visualizations/build/precomputation.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
