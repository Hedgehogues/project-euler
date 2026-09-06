# euler046 — Goldbach's other conjecture

Goldbach conjectured every odd composite number is a prime plus twice a square. For each of `T`
given odd composite `N` (`< 5×10^5`), count how many ways `N = p + 2k²` (`p` prime, `k ≥ 1`).

## Approach

- Sieve every number up to the global limit `5×10^5` for primality once.
- For each query, try every `k` with `2k² < N`, and count how many times `N - 2k²` is a prime `≥ 2`.

Status: **Accepted**, 100% on HackerRank (submission 1410853249, 2026-07-13, `cpp20`). Re-verified
live on 2026-09-01: matches the official sample (`9,15 → 1,2`), reproduces the historically known
smallest counterexample to the conjecture (`5777 → 0`, no representation exists at all), and
cross-checked against an independent Python re-implementation of the same sieve-and-count on
several values — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler046.md).

## The idea(s) behind it

**Sieve of Eratosthenes** — primality of every number up to the global limit is determined once,
up front, rather than per query.
[`[method::SieveOfEratosthenes]`](../../memory-bank/_terms.md#methodsieveoferatosthenes)

[![Sieve of Eratosthenes](../../memory-bank/visualizations/build/sieve-of-eratosthenes.png)](../../memory-bank/visualizations/build/sieve-of-eratosthenes.html)

**Brute-force search** — every `k` with `2k² < N` is tried directly; `N < 5×10^5` bounds `k` to
about 500, well inside budget per query.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

**Precomputation** — the sieve is built once, independent of any query, before the `T` test cases
are even read.
[`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation)

[![Precomputation](../../memory-bank/visualizations/build/precomputation.png)](../../memory-bank/visualizations/build/precomputation.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
