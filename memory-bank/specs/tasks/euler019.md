---
status: draft
app: projecteuler
tags: [projecteuler, euler019, solution, draft]
---

# euler019 — Counting Sundays

## Vision
For each of `T` given date ranges (`1 ≤ T ≤ 100`, `1900 ≤ Y1 ≤ 10^16`, `Y2 ≤ Y1+1000`), count
first-of-month Sundays in the range. Years up to `10^16` rule out any approach that simulates
whole days or even builds a lookup table of weekdays — with a range spanning up to 1000 years
(~12000 months) per query and up to 100 queries, only a DIRECT, O(1)-per-month formula for a given
date's weekday (no simulation of the days before it) keeps the total work bounded regardless of
how astronomically large the year is.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::DayOfWeekFormula](../../_terms.md#methoddayofweekformula).

## Scope
**In scope:** `problems/euler019/solution.cpp` — the month-by-month scan, the day-of-week
formula, correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For every month from the start date to the end date, `dayOfWeek(y, m, 1)` — per
[method::DayOfWeekFormula](../../_terms.md#methoddayofweekformula) — computes that first-of-month
date's weekday directly. If it comes out `0` (Sunday), the count increments. The starting month is
skipped when the given start day `D1 > 1` (the 1st of that month falls before the requested
range). The year is reduced modulo `2800` inside the formula before any arithmetic, keeping every
intermediate value small no matter how large the input year is.

### Data
- Input: `T`, then for each test case two lines: `Y1 M1 D1` and `Y2 M2 D2`.
- Output: `T` lines — the count of first-of-month Sundays in `[start, end]`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(range)` MUST match Python's `datetime` module across randomized ranges —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851764, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`18, 35`) plus 1000 randomized date ranges in 1900-2105 against Python's own `datetime`, exact
  match on every case).
- The weekday formula MUST reduce the year modulo 2800 before any other arithmetic, so no
  intermediate value grows with the size of the input year — **MUST-bounded-intermediate** —
  criterion: `y = ((y % 2800) + 2800) % 2800` runs before the sum is computed. Status: done
  (confirmed live: `Y=10^16` runs without overflow or timeout).
- The starting month MUST be excluded from the count when the given start day is after the 1st —
  **MUST-exclude-partial-start-month** — criterion: `include = !(y==y1 && m==m1 && d1>1)`.
  Status: done.
- `problems/euler019/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler019/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::DayOfWeekFormula](../../_terms.md#methoddayofweekformula).
- Code: `problems/euler019/solution.cpp`; directory README: `problems/euler019/README.md`.
