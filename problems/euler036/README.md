# euler036 — Double-base palindromes

Given `N` and `K`, sum every natural number below `N` that is palindromic in both base 10 and
base `K`.

## Approach

- For every number below `N`, check directly whether its decimal digits read the same forwards
  and backwards, and separately whether its base-`K` digits do too.
- Sum the numbers passing both checks.

Status: **Accepted**, 100% on HackerRank (submission 1410852077, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=10,K=2 → 25`), the classic known answer at
`N=1000000,K=2` (`872187`, the original Project Euler #36 answer), and an independent Python
cross-check at both — exact match.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler036.md).

## The idea(s) behind it

None of this repository's catalogued methods apply — checking whether a sequence of digits reads
the same forwards and backwards is a direct comparison, not a technique with any shortcut to
explain.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
