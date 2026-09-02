---
status: draft
app: projecteuler
tags: [projecteuler, euler011, solution, draft]
---

# euler011 — Largest product in a grid

## Vision
Given a fixed 20×20 grid, find the greatest product of four adjacent numbers in a straight line
(horizontal, vertical, or either diagonal). The grid size is fixed and small (`20×20`), so
checking every cell against all 4 direction vectors costs only `20×20×4 = 1600` starting points —
small enough that no closed form or precomputation is needed; the direct scan already fits
comfortably inside the time limit.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) — the fixed 20x20 grid times 4 directions bounds the candidates to 1600 lines, and [method::SymmetryBreaking](../../_terms.md#methodsymmetrybreaking) (four of the eight directions are scanned, because each line would otherwise be found twice).

## Scope
**In scope:** `problems/euler011/solution.cpp` — the direction scan, correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Four direction vectors cover every distinct line through a cell without double-counting the
reverse of each (right, down, diagonal-down-right, diagonal-down-left already cover their own
opposite directions when scanned from every starting cell). For each cell and each direction, the
code checks the run of 4 cells stays inside the 20×20 bounds, multiplies them, and keeps the best
product seen.

### Data
- Input: 20 lines of 20 integers each (`0 ≤ value ≤ 100`).
- Output: one line — the greatest product of 4 adjacent numbers in a line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(grid)` MUST match the official sample — **MUST-match-sample** — criterion: matches
  HackerRank's given 20×20 grid and its stated answer exactly. Status: done (HackerRank Accepted
  100%, submission 1410851723, 2026-07-12; re-checked live on 2026-09-01: the official sample
  grid produces `73812150`, exact match).
- Every one of the 4 direction vectors MUST be bounds-checked before multiplying — **MUST-bounds-checked**
  — criterion: `ri`/`ci` are checked against `[0, N)` before the inner product loop runs. Status:
  done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  the largest possible product is `100^4 = 10^8`, comfortably inside `long long`. Status: done.
- `problems/euler011/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler011/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch),
  [method::SymmetryBreaking](../../_terms.md#methodsymmetrybreaking).
- Code: `problems/euler011/solution.cpp`; directory README: `problems/euler011/README.md`.
