# euler052 — Permuted multiples

Given `N` and `K`, find every `x ≤ N` such that `x, 2x, 3x, ..., Kx` all use exactly the same
digits (in some order).

## Approach

- For each `x` from 1 to `N`, compute its digit signature (its digits sorted).
- Check that every multiple `2x, 3x, ..., Kx` has the SAME sorted-digit signature as `x` — this
  tests the digit-permutation relation by comparing canonical representatives instead of checking
  all pairs of numbers digit-by-digit.
- Print every `x` (and its `K` multiples) that passes.

Status: **Accepted**, 100% on HackerRank (submission 1410961315, 2026-07-14, `cpp20`; an earlier
submission the same day scored 0 before this version fixed it). Re-verified live on 2026-09-01:
matches the official sample (`N=125875, K=2 → 125874 251748`, the problem's own worked example),
reproduces the classic Project Euler #52 answer (`N=2000000, K=6` → first result `142857
285714 428571 571428 714285 857142`), and cross-checked against an independent Python
re-implementation of the same sorted-digit comparison on the sample — exact match.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler052.md).

## The idea(s) behind it

**Equivalence class** — "same digits in some order" is an equivalence relation; each number's
sorted-digit string is its canonical representative, and every multiple is checked against `x`'s
own representative directly rather than checking the digit-permutation relation pairwise between
every pair of the `K` numbers.
[`[method::EquivalenceClass]`](../../memory-bank/_terms.md#methodequivalenceclass)

**Brute-force search** — every `x ≤ N` is tried directly.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
