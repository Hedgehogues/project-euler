---
status: draft
app: projecteuler
tags: [projecteuler, euler033, solution, draft]
---

# euler033 — Digit canceling fractions

## Vision
Given `N` (`2 ≤ N ≤ 4`) and `K` (`1 ≤ K ≤ N-1`), find every non-trivial `N`-digit "curious
fraction" where cancelling `K` matching digits preserves the fraction's value. `N ≤ 4` keeps the
number of `N`-digit numbers small enough (`≤ 9000`) that checking every pair directly, filtered by
which digits each removal-mask produces, is already fast; the search itself — not a formula — is
the whole computation at this scale.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) — N <= 4 bounds the candidates to at most 9000 numbers times at most 6 removal masks, [method::HashGrouping](../../_terms.md#methodhashgrouping) (every number is keyed by its sorted removed digits, and only numbers sharing a key are ever compared against each other — not [method::SymmetryBreaking](../../_terms.md#methodsymmetrybreaking): no candidate is skipped or left ungenerated here, every number is produced and grouped, only the PAIRWISE COMPARISON is restricted to within-group pairs), [method::CrossMultiplication](../../_terms.md#methodcrossmultiplication) (the two fractions are compared by multiplying across, with no division anywhere), and [method::PositionalNotation](../../_terms.md#methodpositionalnotation) (the digits are what the condition removes and compares).

## Scope
**In scope:** `problems/euler033/solution.cpp` — the digit-mask enumeration, the grouping, the
fraction check, correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every `K`-subset of the `N` digit positions is precomputed as a bitmask. For every `N`-digit
number, and every such mask, the code splits its digits into "removed" (sorted, forming a key) and
"remaining" (forming a number), skipping any split that removes a `0` (the trivial case). Numbers
sharing the same removed-digit key are grouped together; every pair within a group is checked for
`numerator × remaining_denominator == denominator × remaining_numerator`. Valid pairs are
deduplicated in a `std::set` before summing.

### Data
- Input: two integers `N K` (`2 ≤ N ≤ 4`, `1 ≤ K ≤ N-1`).
- Output: one line — the sum of numerators and the sum of denominators of every valid fraction.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n, k)` MUST match an independent brute-force search at `N=2,K=1` —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410852044, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`N=2,K=1 → 110 322`, the classic four curious fractions 16/64, 19/95, 26/65, 49/98) against an
  independently written Python brute-force search over all digit-removal combinations, exact
  match).
- A digit-removal that removes a `0` MUST be excluded — **MUST-exclude-trivial-zero** —
  criterion: `if (hasZero) continue;` runs before a candidate is grouped. Status: done.
- A candidate pair MUST NOT be counted when its two original numbers are equal —
  **MUST-exclude-equal-pair** — criterion: `if (a == b) continue;` inside the pairwise check.
  Status: done.
- Every valid pair MUST be counted only once even if reached via more than one removal mask —
  **MUST-deduplicate** — criterion: `valid` is a `std::set<std::pair<int,int>>`, summed only after
  the full search completes. Status: done.
- `problems/euler033/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler033/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch),
  [method::HashGrouping](../../_terms.md#methodhashgrouping),
  [method::CrossMultiplication](../../_terms.md#methodcrossmultiplication),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation).
- Code: `problems/euler033/solution.cpp`; directory README: `problems/euler033/README.md`.
