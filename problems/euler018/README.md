# euler018 — Maximum path sum I

For each of `T` given triangles of `N` rows, find the maximum total from top to bottom, moving
only to an adjacent number on the row below.

## Approach

- Work from the bottom row upward: replace each cell with itself plus the better of the two cells
  directly below it.
- After processing every row, the top cell holds the maximum path sum — no individual path is
  ever walked end to end.

Status: **Accepted**, 100% on HackerRank (submission 1410851758, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (the 4-row triangle → `23`) and 300 randomly generated
triangles (1–15 rows) cross-checked against an independent full path enumeration — exact match on
every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler018.md).

## The idea(s) behind it

**Dynamic programming** — the best path through the whole triangle is built from the best paths
through its smaller sub-triangles, bottom row first.
[`[method::DynamicProgramming]`](../../memory-bank/_terms.md#methoddynamicprogramming)

[![Dynamic programming](../../memory-bank/visualizations/build/dynamic-programming.png)](../../memory-bank/visualizations/build/dynamic-programming.html)

**In-place algorithm** — Each row is folded into the row above it, over the input itself.
[`[method::InPlaceAlgorithm]`](../../memory-bank/_terms.md#methodinplacealgorithm)

[![In-place algorithm](../../memory-bank/visualizations/build/in-place-algorithm.png)](../../memory-bank/visualizations/build/in-place-algorithm.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
