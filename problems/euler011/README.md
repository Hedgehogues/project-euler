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

**Brute-force search** — the grid is fixed at 20×20 and there are 4 directions per cell — 1600
starting points, each a 4-term product, so every candidate line is simply checked directly.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

**Symmetry breaking** — Four of the eight directions are scanned, because each line would otherwise be found twice.
[`[method::SymmetryBreaking]`](../../memory-bank/_terms.md#methodsymmetrybreaking)

[![Symmetry breaking](../../memory-bank/visualizations/build/symmetry-breaking.png)](../../memory-bank/visualizations/build/symmetry-breaking.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
