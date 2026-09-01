---
status: draft
app: projecteuler
tags: [projecteuler, euler032, solution, draft]
---

# euler032 — Pandigital products

## Vision
Given `N` (`4 ≤ N ≤ 9`), sum every distinct product `c` from a valid `a × b = c` pandigital split
of the digits `1..N`. There are `N!` permutations of the digits (up to `362880` at `N=9`) and only
`O(N)` ways to split each into three pieces — small enough at this size that the whole search is
the computation; the only real technique is generating every permutation without skipping or
duplicating any, in a fixed, well-defined order.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::NextPermutation](../../_terms.md#methodnextpermutation),
[method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).

## Scope
**In scope:** `problems/euler032/solution.cpp` — the permutation loop, the three-way split check,
correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
The digit string `"123...N"` is the lexicographically first permutation. Per
[method::NextPermutation](../../_terms.md#methodnextpermutation), `std::next_permutation`
transforms it into each following permutation in turn until none remain. For each permutation,
every split point pair `(i, j)` dividing it into three non-empty pieces `a`, `b`, `c` is tried
directly; whenever `a × b == c`, `c` is inserted into a `std::set` (deduplicating any `c` reached
by more than one split or permutation). The final answer is the sum of that set.

### Data
- Input: one integer `N` (`4 ≤ N ≤ 9`).
- Output: one line — the sum of every distinct pandigital product `c`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent Python permutation search across `N=4..7`, AND the classic
  known answer at `N=9` — **MUST-match-bruteforce** — criterion: zero mismatches. Status: done
  (HackerRank Accepted 100%, submission 1410852022, 2026-07-12; re-checked live on 2026-09-01: the
  official sample (`N=4→12`) plus `N=4..7` against an independently written Python
  itertools.permutations search, exact match on every case (`12, 52, 162, 0`); also confirmed the
  well-known original Project Euler #32 answer at `N=9`, `45228`).
- Every permutation of the `N` digits MUST be visited exactly once — **MUST-visit-every-permutation**
  — criterion: the `do { ... } while (std::next_permutation(...))` loop runs until it returns
  false, which happens exactly once all `N!` permutations have been produced. Status: done.
- A product `c` reached by more than one split or permutation MUST be counted only once —
  **MUST-deduplicate** — criterion: `products` is a `std::set`, and the final sum iterates it, not
  a running total incremented per match. Status: done.
- `problems/euler032/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler032/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::NextPermutation](../../_terms.md#methodnextpermutation),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler032/solution.cpp`; directory README: `problems/euler032/README.md`.
