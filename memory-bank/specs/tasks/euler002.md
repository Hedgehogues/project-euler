---
status: draft
app: projecteuler
tags: [projecteuler, euler002, solution, draft]
---

# euler002 — Even Fibonacci numbers

## Vision
For each of `T` given values of `N`, sum the even-valued terms of the Fibonacci sequence that do
not exceed `N`. `N` can be as large as `4·10^16` and `T` can be large too — regenerating the
Fibonacci sequence from scratch per query is wasted work, since the sequence itself doesn't depend
on the query.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods used
together, not one (`../../_terms.md`): [method::Precomputation](../../_terms.md#methodprecomputation),
[method::BinarySearch](../../_terms.md#methodbinarysearch), and [method::InPlaceAlgorithm](../../_terms.md#methodinplacealgorithm) (only the last two terms of the sequence are ever kept, and they are written over each other).

## Scope
**In scope:** `problems/euler002/solution.cpp` — the model, the algorithm, the complexity argument,
correctness criteria.

**Out of scope:** the visual explanation of binary search as a general technique (the catalog, not
this task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Even Fibonacci terms occur every third term (`F(0)=0` is even, then odd-odd-even repeating — two
odd terms sum to an even one). Instead of re-checking this on every term for every query, the
solution builds the list of ALL even Fibonacci terms up to `4·10^16`, together with a running sum,
exactly once ([method::Precomputation](../../_terms.md#methodprecomputation)) — this list is short
(an even term grows exponentially, so there are only a few dozen up to `4·10^16`). For each query
`N`, `upper_bound` ([method::BinarySearch](../../_terms.md#methodbinarysearch)) finds the last term
`≤ N` in that list, and the answer is its stored running sum.

### Data
- Input: `T`, then `T` lines with `N` (up to `4·10^16`).
- Output: `T` lines — the sum of even Fibonacci numbers `≤ N`, per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match a direct sum of even Fibonacci terms `≤ n` on boundary and characteristic
  `n` (0, 1, 2, 8, 10, 100, 4000000) — **MUST-match-bruteforce** — criterion: zero difference
  across the checked range, including `n=0`/`n=1` (answer 0 — no even term reached yet). Status:
  done (HackerRank Accepted 100%; re-checked live against a fresh brute-force script on
  2026-09-01: exact match on all seven values, including `n=4000000` → `4613732`).
- The even-Fibonacci list and its running sum MUST be built exactly once, before reading any query
  — **MUST-precompute-once** — criterion: the build loop sits outside the `while (t--)` query loop.
  Status: done.
- Each query's answer MUST be found by binary search (`upper_bound`) over the precomputed list, not
  by walking the Fibonacci sequence again — **MUST-binary-search-per-query** — criterion: the query
  loop contains no Fibonacci generation, only `upper_bound` and indexing. Status: done.
- Building the list MUST NOT overflow or loop forever for `N` up to `4·10^16` —
  **MUST-no-overflow-at-bound** — criterion: `N_MAX = 4·10^16` fits in `long long`
  (`< 2^63 ≈ 9.2·10^18`); the build loop stops on `a <= N_MAX`, not unconditionally. Status: done.
- `problems/euler002/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler002/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::BinarySearch](../../_terms.md#methodbinarysearch),
  [method::InPlaceAlgorithm](../../_terms.md#methodinplacealgorithm).
- Code: `problems/euler002/solution.cpp`; directory README: `problems/euler002/README.md`.
