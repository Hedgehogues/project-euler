---
status: draft
app: projecteuler
tags: [projecteuler, euler023, solution, draft]
---

# euler023 — Non-abundant sums

## Vision
For each of `T` given values of `N` (`0 ≤ N ≤ 10^5`), report whether `N` is a sum of two abundant
numbers. Checking every pair of abundant numbers up to `N` for every query independently would
cost `O(N²)` per query. Since every integer above `28123` is provably a sum of two abundant
numbers, only that fixed, small range needs a precomputed answer table at all — built once, it
answers both the bounded case and (trivially, `YES`) the unbounded case for any `N` up to `10^5`.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::Precomputation](../../_terms.md#methodprecomputation). The
divisor-sum accumulation itself is a plain variant of the "touch every multiple" sieve mechanism
(see `problems/euler021/README.md`) — not independently catalogued (no encyclopedic source found
for this specific summing variant, only blogs/teaching sites).

## Scope
**In scope:** `problems/euler023/solution.cpp` — the divisor-sum accumulation, the abundant-sum
table, correctness criteria.

**Out of scope:** the visual explanation of the catalogued method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every number's divisor sum up to `28123` is accumulated in one pass (as in euler021). Numbers
whose divisor sum exceeds themselves are collected as `abundant`; every pairwise sum of two
abundant numbers up to `28123` is marked in `isSum`. All of this is
[method::Precomputation](../../_terms.md#methodprecomputation): built once, before any query.
Each query then reads `isSum[N]` directly when `N ≤ 28123`, or answers `YES` unconditionally
above that proven bound.

### Data
- Input: `T`, then `T` lines with `N` (`0 ≤ N ≤ 10^5`).
- Output: `T` lines — `YES` or `NO`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent trial-division divisor-sum computation across `n =
  0..30000` — **MUST-match-bruteforce** — criterion: zero difference across all values checked.
  Status: done (HackerRank Accepted 100%, submission 1410851880, 2026-07-12; re-checked live on
  2026-09-01: the official sample (`24→NO, 49→NO`) plus `n=0..30000` against an independently
  written trial-division divisor-sum checker, exact match on every value).
- The abundant-sum table MUST be built ONCE up to `28123`, not once per query —
  **MUST-precompute-once** — criterion: the divisor-sum, abundant-collection, and pairwise-sum
  loops all run before the query loop. Status: done.
- Every `N` above `28123` MUST be answered `YES` directly, without touching the precomputed table
  — **MUST-use-proven-bound** — criterion: `result = (N > LIMIT) || ...` short-circuits before any
  table access. Status: done.
- `problems/euler023/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler023/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::Precomputation](../../_terms.md#methodprecomputation).
- Code: `problems/euler023/solution.cpp`; directory README: `problems/euler023/README.md`.
