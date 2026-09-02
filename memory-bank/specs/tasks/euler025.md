---
status: draft
app: projecteuler
tags: [projecteuler, euler025, solution, draft]
---

# euler025 — N-digit Fibonacci number

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 5000`, `2 ≤ N ≤ 5000`), find the first Fibonacci
index with `N` digits. A 5000-digit Fibonacci number is far beyond any native integer type, so the
sequence must be built as digit arrays throughout. Recomputing the Fibonacci walk from scratch for
every query would also repeat the same growing addition chain up to 5000 times; walking it once
and recording every threshold's first-reaching index answers every query with a lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
[method::Precomputation](../../_terms.md#methodprecomputation), [method::PositionalNotation](../../_terms.md#methodpositionalnotation) (the terms are held as digit blocks, nine decimal digits to an element), [method::InPlaceAlgorithm](../../_terms.md#methodinplacealgorithm) (only the last two terms are kept and overwritten), [method::OfflineAlgorithm](../../_terms.md#methodofflinealgorithm) (the digit-length thresholds are all read first and filled in one ascending pass), and [method::IntegerOverflowAvoidance](../../_terms.md#methodintegeroverflowavoidance) (the block size is chosen so a product of two blocks stays inside a machine word).

## Scope
**In scope:** `problems/euler025/solution.cpp` — the digit-array Fibonacci walk, the
first-index table, correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic), each Fibonacci
term is kept as a little-endian digit array (base `10^9` per array entry for speed) and built by
adding the previous two terms' arrays with carries. Per
[method::Precomputation](../../_terms.md#methodprecomputation), the walk runs once: whenever a new
term's digit count exceeds the highest threshold filled so far, `firstIndex[k]` is recorded for
every threshold `k` up to the new count. Each query then reads `firstIndex[N]` directly.

### Data
- Input: `T`, then `T` lines with `N` (`2 ≤ N ≤ 5000`).
- Output: `T` lines — the index of the first Fibonacci number with `N` digits.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent Python big-integer Fibonacci walk across a sampled range —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851918, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`N=3→12, N=4→17`) plus 335 cases — every 3rd `N` from 2 to 1000, plus the boundaries 2 and 1000
  — against an independently written Python big-integer Fibonacci walk, exact match on every
  case).
- Fibonacci terms MUST be added as digit arrays throughout, never cast through a native integer
  type — **MUST-no-native-overflow-path** — criterion: `prev`/`curr`/`next` in `main`'s Fibonacci
  loop are `vector<long long>` digit-chunk arrays, never a single native integer. Status: done.
- The first-index table MUST be built ONCE during a single forward walk, not once per query —
  **MUST-precompute-once** — criterion: the `while (filled < MAXD)` loop runs exactly once, before
  the query loop. Status: done.
- `problems/euler025/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler025/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
  [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation),
  [method::InPlaceAlgorithm](../../_terms.md#methodinplacealgorithm),
  [method::OfflineAlgorithm](../../_terms.md#methodofflinealgorithm),
  [method::IntegerOverflowAvoidance](../../_terms.md#methodintegeroverflowavoidance).
- Code: `problems/euler025/solution.cpp`; directory README: `problems/euler025/README.md`.
