---
status: draft
app: projecteuler
tags: [projecteuler, euler044, solution, draft]
---

# euler044 — Pentagon numbers

## Vision
Given `N` (up to `10^6`) and `K` (up to `9999`), find every `P_n` (`n < N`) for which `P_n -
P_{n-K}` or `P_n + P_{n-K}` is pentagonal. `N` up to `10^6` keeps a direct scan of every `n` cheap;
the part that must not be gotten wrong is testing pentagonality of the derived sum/difference
EXACTLY (an approximate square root at these sizes could misclassify a borderline case), not
whether the scan itself is fast enough.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::QuadraticFormula](../../_terms.md#methodquadraticformula) (inverting
`n(3n-1)/2=x` to test pentagonality), [method::BinarySearch](../../_terms.md#methodbinarysearch)
(the exact integer square root of the discriminant), and
[method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (trying every `n < N` directly).

## Scope
**In scope:** `problems/euler044/solution.cpp` — the pentagonal-number formula, the pentagonality
test, the enumeration, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For each `n` in `K+1..N-1` ([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)),
compute `P_n = n(3n-1)/2` and `P_{n-K}`. Test whether `P_n - P_{n-K}` or `P_n + P_{n-K}` is
pentagonal by inverting the formula
([method::QuadraticFormula](../../_terms.md#methodquadraticformula)): a value `x` is pentagonal
exactly when `disc = 1+24x` is a perfect square `s` (found via
[method::BinarySearch](../../_terms.md#methodbinarysearch), not floating-point `sqrt`) and
`(1+s) % 6 == 0`. Every `P_n` passing either check is printed, in ascending order (the loop already
runs `n` ascending, so `P_n` values come out sorted).

### Data
- Input: one line, `N K`.
- Output: every qualifying `P_n`, ascending, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=10, K=2 → 70`) — **MUST-match-sample** —
  criterion: zero difference against the given sample. Status: done (re-run live 2026-09-01).
- The pentagonality test MUST use an exact integer square root, never floating-point `sqrt` —
  **MUST-exact-sqrt** — criterion: `isPentagonal` computes it by integer binary search with a
  linear refinement pass. Status: done.
- The solution MUST agree with an independent Python re-implementation of the same check —
  **MUST-match-bruteforce** — criterion: cross-checked on `N=10,K=2` (→ `[70]`) and `N=100,K=1`
  (→ `[92, 852, 1001, 3577, 10292]`) — exact match on both. Status: done.
- `problems/euler044/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler044/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N K`; qualifying `P_n` values, ascending, one per
  line) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::QuadraticFormula](../../_terms.md#methodquadraticformula),
  [method::BinarySearch](../../_terms.md#methodbinarysearch),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler044/solution.cpp`; directory README: `problems/euler044/README.md`.
