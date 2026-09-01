# euler030 — Digit Nth powers

Given `N` (`3 ≤ N ≤ 6`), find the sum of all numbers that equal the sum of the `N`th powers of
their own digits.

## Approach

- A `d`-digit number is at least `10^(d-1)`, but the largest possible sum of `N`th-power digits
  for a `d`-digit number is only `d · 9^N` — once `d · 9^N` falls below `10^(d-1)`, no number with
  that many digits (or more) can ever qualify, which gives a safe, provably-sufficient upper bound
  to search up to.
- Check every number up to that bound directly by summing its digits' `N`th powers.

Status: **Accepted**, 100% on HackerRank (submission 1410852010, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=4 → 19316`, the classic original Project Euler #30
answer) and the full valid range `N=3..6`, cross-checked against an independent Python search over
the same derived bound — exact match on every value (`1301, 19316, 443839, 548834`).

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler030.md).

## The idea(s) behind it

None of this repository's catalogued methods apply — deriving how far the search needs to reach is
a one-off bound specific to this problem's digit-power growth comparison, not a general reusable
technique, and the search itself is a direct definition check once that bound is known.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
