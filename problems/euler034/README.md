# euler034 — Digit factorials

Given `N` (`10 ≤ N ≤ 10^5`), find the sum of all numbers below `N` that DIVIDE the sum of the
factorials of their own digits.

Note: this is a genuinely different condition from the original Project Euler #34 ("numbers EQUAL
to the sum of the factorial of their digits") — the HackerRank version asks for divisibility, not
equality, confirmed directly against the fetched problem statement and the official sample.

## Approach

- Precompute `0!` through `9!` once.
- For every number from `10` up to `N-1`, sum the factorials of its digits directly and check
  whether that sum is divisible by the number itself.

Status: **Accepted**, 100% on HackerRank (submission 1410852057, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=20 → 19`) and an independent Python search — exact
match at `N=20` and `N=100000` (`99752`).

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler034.md).

## The idea(s) behind it

None of this repository's catalogued methods apply — the search is a direct definition check over
a small range, with no shortcut a named technique would explain.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
