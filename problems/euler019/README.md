# euler019 — Counting Sundays

For each of `T` given date ranges (`Y1 M1 D1` to `Y2 M2 D2`, `1900 ≤ Y1`, years up to `10^16`),
count how many months in the range start on a Sunday.

## Approach

- For every first-of-the-month date in the range, compute its day of the week directly with
  Sakamoto's algorithm — no calendar simulation, no day-by-day stepping.
- Count how many of those come out as Sunday.

Status: **Accepted**, 100% on HackerRank (submission 1410851764, 2026-07-12), for the version that
reduced the year modulo 2800. Re-verified live on 2026-09-01: matches the official sample (`18`,
`35`) and 1000 randomized date ranges (years 1900–2105) cross-checked against an independent
calendar implementation — exact match on every case; also confirmed to run without overflow on
years as large as `10^16`.

Changed on 2026-09-02 — the reduction is now modulo 400, the calendar's real period, and the
comment states why (shifting the year by 400 shifts the formula's sum by 497, which is 71 sevens;
the old 2800 came from demanding each term shift by a multiple of seven on its own, which is
stricter than the formula needs). Not re-submitted, so the Accepted line above belongs to the
previous version; equivalence was established locally instead, and the two are output-identical:
2,416,336 direct comparisons of the weekday formula under both moduli (every year 0–6000 across
all twelve months and twenty-eight days, plus 400,000 random years up to `10^16`) and 3,000
randomized date ranges compared between the two compiled programs — zero differences in either.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler019.md).

## The idea(s) behind it

**Day-of-week formula** — a single formula gives any date's weekday directly, letting the search
skip straight from one first-of-the-month to the next instead of stepping through every day.
[`[method::DayOfWeekFormula]`](../../memory-bank/_terms.md#methoddayofweekformula)

[![Day-of-week formula](../../memory-bank/visualizations/build/day-of-week-formula.png)](../../memory-bank/visualizations/build/day-of-week-formula.html)

**Modular arithmetic** — The year is reduced by the calendar own period before the formula runs, and the remainder is normalized.
[`[method::ModularArithmetic]`](../../memory-bank/_terms.md#methodmodulararithmetic)

[![Modular arithmetic](../../memory-bank/visualizations/build/modular-arithmetic.png)](../../memory-bank/visualizations/build/modular-arithmetic.html)

**Lookup table** — The months offsets are a given, irregular table rather than a formula.
[`[method::LookupTable]`](../../memory-bank/_terms.md#methodlookuptable)

[![Lookup table](../../memory-bank/visualizations/build/lookup-table.png)](../../memory-bank/visualizations/build/lookup-table.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
