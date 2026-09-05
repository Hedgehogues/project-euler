---
status: draft
app: projecteuler
tags: [projecteuler, euler043, solution, draft]
---

# euler043 — Sub-string divisibility

## Vision
Given `N` (`3..9`), sum every `0..N` pandigital number satisfying up to seven substring-divisibility
rules. The bound `N <= 9` keeps the whole search inside `10!` permutations, so a direct exhaustive
search with an early-exit divisibility check per candidate is already the intended approach; the
part that must not be gotten wrong is applying exactly the rules that fit an `(N+1)`-digit number,
not all seven regardless of length.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::NextPermutation](../../_terms.md#methodnextpermutation) (enumerating
every arrangement of `0..N`), [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)
(testing every permutation directly), and
[method::PositionalNotation](../../_terms.md#methodpositionalnotation) (reading each 3-digit
substring as a number by place value before testing it).

## Scope
**In scope:** `problems/euler043/solution.cpp` — the permutation enumeration, the substring
divisibility checks, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every permutation of `0..N` is generated in lexicographic order
([method::NextPermutation](../../_terms.md#methodnextpermutation)) and tested directly
([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)): for `k=1..min(N+1-3, 7)`,
the 3-digit substring starting at position `k` (0-indexed from the second digit) is read by place
value ([method::PositionalNotation](../../_terms.md#methodpositionalnotation)) and checked against
the `k`-th prime in `{2,3,5,7,11,13,17}`; the first failing rule stops the check. Every permutation
passing all applicable rules is added to a running sum.

### Data
- Input: one integer `N`.
- Output: one integer — the sum of every qualifying `0..N` pandigital number.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=3 → 22212`) — **MUST-match-sample** —
  criterion: zero difference against the given sample. Status: done (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #43 answer (`N=9 → 16695334890`) —
  **MUST-match-original-pe43** — criterion: exact match. Status: done (re-run live 2026-09-01, and
  cross-checked against an independent Python permutation search on `N=3,4,5,6` — exact match on
  every case).
- The number of divisibility rules applied MUST be exactly `min(max(N+1-3, 0), 7)`, never a fixed
  count of 7 regardless of `N` — **MUST-rule-count-by-length** — criterion:
  `numRules = M - 3` clamped to `[0, 7]`, `M = N+1`. Status: done.
- `problems/euler043/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler043/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (a single integer `N`; one summed answer printed) —
  **MUST-io-format**. Status: done.

## Links
- Methods: [method::NextPermutation](../../_terms.md#methodnextpermutation),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation).
- Code: `problems/euler043/solution.cpp`; directory README: `problems/euler043/README.md`.
