# euler037 — Truncatable primes

Given `N`, find the sum of every prime below `N` that stays prime as digits are truncated one at a
time from the left, and separately from the right (`2, 3, 5, 7` don't count).

## Approach

- Sieve every prime below `N` once.
- For each prime `p ≥ 10`, check that every right-to-left truncation (dropping the leftmost digit
  each time) is prime, and every left-to-right truncation (dropping the rightmost digit each time)
  is prime too — using the sieve for every check, never re-testing primality from scratch.

Status: **Accepted**, 100% on HackerRank (submission 1410852083, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=100 → 186`) and the classic known answer at
`N=1000000` (`748317`, the original Project Euler #37 answer, the sum of all eleven truncatable
primes) — exact match on both, cross-checked against an independent trial-division search.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler037.md).

## The idea(s) behind it

**Sieve of Eratosthenes** — cross out every multiple of each prime found so far; whatever survives
unmarked is exactly the primes, checked once and reused for every truncation.
[`[method::SieveOfEratosthenes]`](../../memory-bank/_terms.md#methodsieveoferatosthenes)

[![Sieve of Eratosthenes](../../memory-bank/visualizations/build/sieve-of-eratosthenes.png)](../../memory-bank/visualizations/build/sieve-of-eratosthenes.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
