---
status: draft
app: projecteuler
tags: [projecteuler, euler016, solution, draft]
---

# euler016 — Power digit sum

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 100`, `1 ≤ N ≤ 10^4`), find the digit sum of `2^N`.
`2^10000` has over 3000 digits — far beyond any native integer type, so `2^N` cannot be computed
as a single native power at all; it must be built as a digit array, doubled step by step with
carries. Recomputing `2^N` from scratch for every query would also repeat the same doubling chain
up to 100 times; building every digit sum once up to the largest queried `N` answers every query
with a lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
[method::Precomputation](../../_terms.md#methodprecomputation).

## Scope
**In scope:** `problems/euler016/solution.cpp` — the digit-array doubling, the digit-sum cache,
correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic), `2^n` is kept as a
little-endian digit array. Starting from `2^0 = [1]`, each step doubles every digit and propagates
carries — one native operation per digit, exactly like the carry-propagation used for addition,
just with the per-column rule swapped to "multiply by 2." The digit sum after each doubling is
recorded into `digitSum[n]`, built once
([method::Precomputation](../../_terms.md#methodprecomputation)) up to the largest `N` across all
queries. Each query is then a single array lookup.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 10^4`).
- Output: `T` lines — the digit sum of `2^N`, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent big-integer power computation across a sampled range —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851745, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`N=3→8, N=4→7, N=7→11`) plus 275 cases — every 37th `N` from 0 to 10000, plus the boundaries 0,
  1, 9999, 10000 — against an independently computed `2^n`'s digit sum, exact match on every case).
- `2^n` MUST be doubled as a digit array throughout, never cast through a native integer type —
  **MUST-no-native-overflow-path** — criterion: `digits` in `computeDigitSums` is `vector<int>`
  throughout, never `long long`. Status: done.
- The digit sums MUST be built ONCE up to the largest `N`, not once per query —
  **MUST-precompute-once** — criterion: `computeDigitSums` is called exactly once, before the
  query loop. Status: done.
- `problems/euler016/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler016/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
  [method::Precomputation](../../_terms.md#methodprecomputation).
- Code: `problems/euler016/solution.cpp`; directory README: `problems/euler016/README.md`.
