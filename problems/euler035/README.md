# euler035 — Circular primes

Given `N`, find the sum of all circular primes below `N` (primes where every rotation of their
decimal digits is itself prime — note rotations can exceed `N`).

## Approach

- Sieve every prime up to a safe bound covering the largest possible rotation (all-9s at the same
  digit count as `N-1`), not just up to `N` itself, since a rotation of a number below `N` can be
  numerically larger than `N`.
- For each prime below `N`, generate every digit rotation and check each one against the sieve.

Status: **Accepted**, 100% on HackerRank (submission 1410852066, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=100 → 446`) and an independent trial-division
cross-check at `N=100, 1000, 10000` — exact match on every value.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler035.md).

## The idea(s) behind it

**Sieve of Eratosthenes** — cross out every multiple of each prime found so far; whatever survives
unmarked is exactly the primes, sieved once up to a bound safely covering every rotation.
[`[method::SieveOfEratosthenes]`](../../memory-bank/_terms.md#methodsieveoferatosthenes)

[![Sieve of Eratosthenes](../../memory-bank/visualizations/build/sieve-of-eratosthenes.png)](../../memory-bank/visualizations/build/sieve-of-eratosthenes.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
