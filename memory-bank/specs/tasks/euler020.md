---
status: draft
app: projecteuler
tags: [projecteuler, euler020, solution, draft]
---

# euler020 — Factorial digit sum

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 100`, `0 ≤ N ≤ 1000`), find the digit sum of `N!`.
`1000!` has over 2500 digits — far beyond any native integer type, so `N!` cannot be computed as a
single native product at all; it must be built as a digit array, multiplied step by step with
carries. Recomputing `N!` from scratch for every query would also repeat the same multiplication
chain up to 100 times; building every digit sum once up to the largest queried `N` answers every
query with a lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
[method::Precomputation](../../_terms.md#methodprecomputation).

## Scope
**In scope:** `problems/euler020/solution.cpp` — the digit-array factorial, the digit-sum cache,
correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic), the running
factorial is kept as a little-endian digit array, starting at `0! = [1]`. Each step from `n-1!` to
`n!` multiplies every digit by `n` and propagates carries — the same carry-propagation mechanism as
addition, with the per-column rule swapped to "multiply by `n`, then carry the tens." The digit sum
after each step is recorded into `digitSum[n]`, built once
([method::Precomputation](../../_terms.md#methodprecomputation)) up to the largest `N` across all
queries. Each query is then a single array lookup.

### Data
- Input: `T`, then `T` lines with `N` (`0 ≤ N ≤ 1000`).
- Output: `T` lines — the digit sum of `N!`, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match Python's arbitrary-precision `factorial` across a sampled range —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851762, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`N=3→6, N=6→9`) plus 204 cases — every 5th `N` from 0 to 1000, plus the boundaries 0, 1, 1000 —
  against Python's `math.factorial`, exact match on every case).
- `N!` MUST be multiplied as a digit array throughout, never cast through a native integer type —
  **MUST-no-native-overflow-path** — criterion: `num` in `main`'s factorial loop is `vector<int>`
  throughout, never `long long`. Status: done.
- The digit sums MUST be built ONCE up to the largest `N`, not once per query —
  **MUST-precompute-once** — criterion: the factorial loop runs exactly once, before the query
  loop. Status: done.
- `problems/euler020/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler020/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
  [method::Precomputation](../../_terms.md#methodprecomputation).
- Code: `problems/euler020/solution.cpp`; directory README: `problems/euler020/README.md`.
