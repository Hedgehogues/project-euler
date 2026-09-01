# euler019 — Counting Sundays

For each of `T` given date ranges (`Y1 M1 D1` to `Y2 M2 D2`, `1900 ≤ Y1`, years up to `10^16`),
count how many months in the range start on a Sunday.

## Approach

- For every first-of-the-month date in the range, compute its day of the week directly with
  Sakamoto's algorithm — no calendar simulation, no day-by-day stepping.
- Count how many of those come out as Sunday.

Status: **Accepted**, 100% on HackerRank (submission 1410851764, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`18`, `35`) and 1000 randomized date ranges (years
1900–2105) cross-checked against Python's own `datetime` — exact match on every case; also
confirmed to run without overflow on years as large as `10^16`.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler019.md).

## The idea(s) behind it

**Day-of-week formula** — a single formula gives any date's weekday directly, letting the search
skip straight from one first-of-the-month to the next instead of stepping through every day.
[`[method::DayOfWeekFormula]`](../../memory-bank/_terms.md#methoddayofweekformula)

[![Day-of-week formula](../../memory-bank/visualizations/build/day-of-week-formula.png)](../../memory-bank/visualizations/build/day-of-week-formula.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
