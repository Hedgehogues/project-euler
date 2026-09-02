# euler026 — Reciprocal cycles

For each of `T` given values of `N` (`4 ≤ N ≤ 10^4`), find the value below `N` whose reciprocal
`1/d` has the longest repeating cycle in its decimal expansion.

## Approach

- For each `d`, simulate long division of `1/d` one digit at a time, recording the step at which
  each remainder first appears; the moment a remainder repeats, the gap between the two steps is
  the cycle length.
- Track the running best `d` seen so far as `d` increases, so every threshold's answer is filled
  in during one pass.

Status: **Accepted**, 100% on HackerRank (submission 1410851922, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=5→3`, `N=10→7`) and an exhaustive brute-force
cross-check across the ENTIRE valid range `N = 1..10000` — exact match on every value.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler026.md).

## The idea(s) behind it

**Cycle detection via remainders** — a fraction's repeating block length falls straight out of
tracking which division remainders have already been seen.
[`[method::CycleDetectionViaRemainders]`](../../memory-bank/_terms.md#methodcycledetectionviaremainders)

[![Cycle detection via remainders](../../memory-bank/visualizations/build/cycle-detection-remainders.png)](../../memory-bank/visualizations/build/cycle-detection-remainders.html)

**Prefix sum** — The longest period so far is carried along one ascending pass, with the tie-break stated.
[`[method::PrefixSum]`](../../memory-bank/_terms.md#methodprefixsum)

[![Prefix sum](../../memory-bank/visualizations/build/prefix-sum.png)](../../memory-bank/visualizations/build/prefix-sum.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
