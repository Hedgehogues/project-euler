# euler011 — Largest product in a grid

Given a 20×20 grid of integers, find the greatest product of four adjacent numbers in the same
direction — horizontal, vertical, or either diagonal.

## Approach

- For every cell and each of the 4 direction vectors (right, down, and the two diagonals), check
  whether a run of 4 cells starting there stays inside the grid, and if so multiply them.
- The grid is fixed at 20×20, so this is `20 × 20 × 4 = 1600` starting points, each a 4-term
  product — small enough to scan directly.

Status: **Accepted**, 100% on HackerRank (submission 1410851723, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample grid and its answer (`73812150`) exactly.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler011.md).

## The idea(s) behind it

None of this repository's catalogued methods apply — the grid's fixed 20×20 size makes checking
every direction from every cell directly already fast enough; there is no shortcut being taken
that a named technique would explain.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
