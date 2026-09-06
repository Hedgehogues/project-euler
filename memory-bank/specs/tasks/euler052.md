---
status: draft
app: projecteuler
tags: [projecteuler, euler052, solution, draft]
---

# euler052 — Permuted multiples

## Vision
Given `N` (up to `2×10^6`) and `K` (2 to 6), find every `x <= N` such that `x, 2x, ..., Kx` are
all digit-permutations of one another. `N` up to `2×10^6` keeps a direct scan of every `x` cheap;
the part that must not be gotten wrong is testing "same digits in some order" via a canonical
representative (sorted digits) compared directly, not via a more expensive pairwise check between
every pair of the `K` numbers.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::EquivalenceClass](../../_terms.md#methodequivalenceclass)
(comparing sorted-digit canonical representatives instead of checking the permutation relation
pairwise) and [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (trying every `x`
directly).

## Scope
**In scope:** `problems/euler052/solution.cpp` — the digit-signature computation, the per-`x`
check, correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For each `x` in `1..N` ([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)), its
sorted-digit string is computed once as its canonical representative
([method::EquivalenceClass](../../_terms.md#methodequivalenceclass)); every multiple `2x..Kx` is
accepted only if its OWN sorted-digit string equals `x`'s. Every `x` that survives all `K-1`
comparisons is printed along with its multiples.

### Data
- Input: one line, `N K`.
- Output: every qualifying `x` and its `K` multiples, one line per `x`, space-separated ascending
  multiples.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=125875, K=2 → 125874 251748`) —
  **MUST-match-sample** — criterion: zero difference against the given sample. Status: done
  (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #52 answer (`N=2000000, K=6` → first
  result starting `142857`) — **MUST-match-original-pe52** — criterion: exact match. Status: done
  (re-run live 2026-09-01).
- The solution MUST agree with an independent Python re-implementation of the same sorted-digit
  comparison — **MUST-match-bruteforce** — criterion: cross-checked on the official sample — exact
  match. Status: done.
- `problems/euler052/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler052/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N K`; every qualifying `x` and its multiples, one
  line per `x`) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::EquivalenceClass](../../_terms.md#methodequivalenceclass),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler052/solution.cpp`; directory README: `problems/euler052/README.md`.
