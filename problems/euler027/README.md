# euler027 — Quadratic primes

Find coefficients `a` (`|a| < N`) and `b` (prime, `b ≤ N`) that maximize the number of consecutive
values of `n = 0, 1, 2, ...` for which `n² + an + b` is prime.

## Approach

- `b` must be prime (`n=0` gives `b` itself), so only prime `b ≤ N` are tried.
- For each candidate `(a, b)`, count consecutive primes produced by `n = 0, 1, 2, ...` directly
  with trial division, stopping at the first non-prime value.
- Track the pair with the longest run seen.

Status: **Accepted**, 100% on HackerRank (submission 1410851936, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=42 → -1 41`) and the classic known answer at `N=1000`
(`a=-61, b=971`, the original Project Euler #27 answer) — exact match on both.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler027.md).

## The idea(s) behind it

**Trial division** — every candidate value `n² + an + b` is tested for primality the same way as
factoring: trying divisors up to its square root.
[`[method::TrialDivision]`](../../memory-bank/_terms.md#methodtrialdivision)

[![Ladder method](../../memory-bank/visualizations/build/ladder-method.png)](../../memory-bank/visualizations/build/ladder-method.html)

**Brute-force search** — the `(a, b)` pairs themselves are simply all tried: `N ≤ 2000` bounds them
to at most 2000 values of `a` times the primes up to `N`, each scored by a short prime run.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
