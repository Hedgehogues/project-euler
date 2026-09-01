---
status: draft
app: projecteuler
tags: [projecteuler, euler008, solution, draft]
---

# euler008 — Largest product in a series

## Vision
For each of `T` given digit strings (`1 ≤ T ≤ 100`), each of length `N` (`N ≤ 1000`), and a window
size `K` (`K ≤ 7`), find the greatest product of `K` consecutive digits. The window is small enough
(`K ≤ 7`) that scanning every one of the up to `N` starting positions and multiplying its `K`
digits directly costs at most `1000 × 7 = 7000` operations per query — no closed form or
precomputation is needed to stay inside the time limit; the direct definition IS the solution.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) — the candidate count follows straight from the limits (at most 1000 positions x 7 digits x 100 queries).

## Scope
**In scope:** `problems/euler008/solution.cpp` — the direct window scan, correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For every starting position `i` from `0` to `N-K`, multiply the `K` digits `digits[i..i+K-1]` and
keep a running maximum. No digit array is reused between windows; each window is recomputed from
scratch, which is cheap enough given `K ≤ 7`.

### Data
- Input: `T`, then for each test case a line `N K` followed by a line with the `N`-digit string.
- Output: `T` lines — the greatest product of `K` consecutive digits, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(digits, K)` MUST match the official sample — **MUST-match-sample** — criterion: matches
  HackerRank's given sample exactly. Status: done (HackerRank Accepted 100%, submission
  1410851654, 2026-07-12; re-checked live on 2026-09-01: `N=10,K=5` on `3675356291` → `3150`, on
  `2709360626` → `0`, both exact).
- Every window's product MUST be computed from the digits actually at that position, not an
  incremental update that could drift — **MUST-direct-window** — criterion: the inner loop
  re-reads `digits[i..i+K-1]` fresh for every `i`, no carried partial product. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  the largest possible product is `9^7 ≈ 4.78×10^6`, comfortably inside `long long`. Status: done.
- `problems/euler008/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler008/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler008/solution.cpp`; directory README: `problems/euler008/README.md`.
