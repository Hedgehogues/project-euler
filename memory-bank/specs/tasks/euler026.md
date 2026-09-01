---
status: draft
app: projecteuler
tags: [projecteuler, euler026, solution, draft]
---

# euler026 — Reciprocal cycles

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 1000`, `4 ≤ N ≤ 10^4`), find the `d < N` whose
`1/d` has the longest repeating decimal cycle. Actually generating decimal digits of `1/d` until a
repeat is visually obvious would mean comparing against every previous digit — up to `O(d)`
comparisons per digit, `O(d²)` per denominator. Tracking only the LAST step each remainder was
seen at (there are only `d` possible remainders) finds the repeat in `O(d)` total per denominator,
and computing every denominator's cycle length once, in increasing order, fills every query's
answer in a single pass.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::CycleDetectionViaRemainders](../../_terms.md#methodcycledetectionviaremainders).

## Scope
**In scope:** `problems/euler026/solution.cpp` — the remainder-tracking cycle length, the
running-best table, correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::CycleDetectionViaRemainders](../../_terms.md#methodcycledetectionviaremainders),
`cycleLength(d)` simulates long division of `1/d`, recording the step index at which each
remainder first occurs in a `pos` array sized `d`; the loop stops (returning `0`) if the remainder
ever reaches `0` (a terminating decimal) or returns the gap between steps the moment a remainder
repeats. `upto[d]` tracks, for `d` increasing from `2`, which denominator so far has produced the
longest cycle — filled once, in one forward pass, before any query is answered.

### Data
- Input: `T`, then `T` lines with `N` (`4 ≤ N ≤ 10^4`).
- Output: `T` lines — the `d < N` with the longest reciprocal cycle.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent implementation of the same remainder-tracking process
  across the ENTIRE valid range `n = 1..10000` — **MUST-match-bruteforce** — criterion: zero
  difference across all 10000 values. Status: done (HackerRank Accepted 100%, submission
  1410851922, 2026-07-12; re-checked live on 2026-09-01: the official sample (`N=5→3, N=10→7`)
  plus the full exhaustive range against an independently written cycle-length checker, exact
  match on every value; also confirmed directly that `1/7 = 0.(142857)` has cycle length 6, the
  longest for any denominator below 10).
- `pos` MUST be re-initialized (or freshly allocated) for every denominator — **MUST-fresh-state**
  — criterion: `vector<int> pos(d, -1)` is constructed inside `cycleLength`, not shared or reused
  across calls. Status: done.
- The running-best table MUST be built in ONE forward pass over increasing `d`, not once per
  query — **MUST-precompute-once** — criterion: the `for (d = 2; d < MAXN; ++d)` loop runs once,
  before the query loop. Status: done.
- `problems/euler026/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler026/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::CycleDetectionViaRemainders](../../_terms.md#methodcycledetectionviaremainders).
- Code: `problems/euler026/solution.cpp`; directory README: `problems/euler026/README.md`.
