---
status: draft
app: projecteuler
tags: [projecteuler, euler024, solution, draft]
---

# euler024 — Lexicographic permutations

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 1000`, `1 ≤ N ≤ 13!`), find the `N`th lexicographic
permutation of 13 letters. `13! = 6,227,020,800` rules out generating and counting through
permutations one at a time — even at a billion permutations a second that is several seconds for
a SINGLE query, let alone 1000. The Lehmer-code reconstruction builds the answer directly in
`O(k²)` (`k=13`) per query, regardless of how large `N` is.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::LehmerCode](../../_terms.md#methodlehmercode), and [method::LookupTable](../../_terms.md#methodlookuptable) (the factorials below the pool size are a small fixed table).

## Scope
**In scope:** `problems/euler024/solution.cpp` — the factorial precomputation, the digit-peeling
reconstruction, correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Factorials `0!` through `13!` are precomputed once. Per
[method::LehmerCode](../../_terms.md#methodlehmercode), the 0-based index `N-1` is peeled apart
from the largest place down: at each of the 13 rounds, the index is divided by the factorial of
the remaining pool size minus one; the quotient indexes into the still-shrinking letter pool
(`pool.erase` removes the picked letter), and the remainder carries into the next round.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 13!`).
- Output: `T` lines — the `N`th lexicographic permutation of `abcdefghijklm`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independently written Lehmer-code reconstruction across a sampled
  range — **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank
  Accepted 100%, submission 1410851913, 2026-07-12; re-checked live on 2026-09-01: the official
  sample (`N=1→abcdefghijklm, N=2→abcdefghijkml`) plus 717 cases — every 7th `N` up to 5000, plus
  the boundaries `N=1` and `N=13!` — against an independently written Python reconstruction of the
  same Lehmer-code process, exact match on every case).
- The index MUST be converted to 0-based (`N-1`) before any division — **MUST-zero-based-index**
  — criterion: `idx = N - 1` runs before the peeling loop. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  `13! = 6227020800` exceeds 32-bit range but fits comfortably in `long long` (used throughout for
  `fact` and `idx`). Status: done.
- `problems/euler024/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler024/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::LehmerCode](../../_terms.md#methodlehmercode),
  [method::LookupTable](../../_terms.md#methodlookuptable).
- Code: `problems/euler024/solution.cpp`; directory README: `problems/euler024/README.md`.
