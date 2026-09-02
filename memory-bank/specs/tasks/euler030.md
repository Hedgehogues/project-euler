---
status: draft
app: projecteuler
tags: [projecteuler, euler030, solution, draft]
---

# euler030 — Digit Nth powers

## Vision
Given `N` (`3 ≤ N ≤ 6`), sum every number equal to the sum of the `N`th powers of its own digits.
There is no given upper bound to search up to — without one, the search would have no stopping
point. Comparing the fastest-possible growth of a `d`-digit number (`10^(d-1)`) against the
LARGEST possible digit-power sum for `d` digits (`d · 9^N`, achieved only if every digit were 9)
gives the point past which no number can qualify, since `10^(d-1)` overtakes `d · 9^N`
permanently once `d` is large enough.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) — the derived digit-growth bound caps the candidate range before the scan starts, [method::DigitalInvariantBound](../../_terms.md#methoddigitalinvariantbound) (the largest reachable digit total is weighed against the smallest number of each length, which ends the search), [method::PositionalNotation](../../_terms.md#methodpositionalnotation) (the candidate is taken apart into digits, which is what the condition is about), and [method::LookupTable](../../_terms.md#methodlookuptable) (each digit own power is a ten-entry table computed once).

## Scope
**In scope:** `problems/euler030/solution.cpp` — the bound derivation, the direct digit-power
search, correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Starting from `digits=1`, the code grows `digits` while `(digits+1) · 9^N` still reaches or
exceeds the smallest `(digits+1)`-digit number (`10^digits`) — the point where it stops is the
largest digit-count that could possibly still qualify, and `limit = digits · 9^N` is the search's
upper bound. Every number from `10` to `limit` is then checked directly: sum its digits' `N`th
powers (looked up from a precomputed `digitPow` table) and compare to the number itself.

### Data
- Input: one integer `N` (`3 ≤ N ≤ 6`).
- Output: one line — the sum of all qualifying numbers.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent search over the same derived bound for the ENTIRE valid
  range `N = 3..6` — **MUST-match-bruteforce** — criterion: zero difference across all four
  values. Status: done (HackerRank Accepted 100%, submission 1410852010, 2026-07-12; re-checked
  live on 2026-09-01: the official sample (`N=4→19316`) plus `N=3..6` against an independently
  written Python search, exact match on every value: `1301, 19316, 443839, 548834`).
- The search bound MUST be derived from the digit-count growth comparison, not a hand-picked
  constant — **MUST-derived-bound** — criterion: `limit` is computed from the `while` loop
  comparing `candidateLimit` against `minWithDigitsPlus1`, not asserted as a literal. Status:
  done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at `N=6`, the bound stays under `7 × 9^6 ≈ 3.7×10^6`, and the sum of all qualifying numbers
  stays comfortably inside `long long`. Status: done.
- `problems/euler030/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler030/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch),
  [method::DigitalInvariantBound](../../_terms.md#methoddigitalinvariantbound),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation),
  [method::LookupTable](../../_terms.md#methodlookuptable).
- Code: `problems/euler030/solution.cpp`; directory README: `problems/euler030/README.md`.
