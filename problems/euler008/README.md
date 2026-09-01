# euler008 — Largest product in a series

Given an `N`-digit number and a window size `K`, find the greatest product of `K` consecutive
digits in it.

## Approach

- For every starting position, multiply the `K` digits from there and keep the running maximum.
- `K ≤ 7` and `N ≤ 1000`, so the whole scan is at most `1000 × 7 = 7000` multiplications per query
  — direct, no shortcut needed.

Status: **Accepted**, 100% on HackerRank (submission 1410851654, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=10,K=5` on `3675356291` → `3150`; on `2709360626` →
`0`).

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler008.md).

## The idea(s) behind it

**Brute-force search** — the limits themselves settle it: at most 1000 starting positions times at
most 7 digits each, times 100 queries — around 700,000 multiplications in the worst case, far
inside the time budget, so every window is simply checked directly.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
