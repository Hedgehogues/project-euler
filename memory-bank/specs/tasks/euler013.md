---
status: draft
app: projecteuler
tags: [projecteuler, euler013, solution, draft]
---

# euler013 — Large sum

## Vision
Given `N` (`1 ≤ N ≤ 10^3`) 50-digit numbers, print the first ten digits of their sum. A 50-digit
number is far beyond any native integer type (`long long` holds under 19 digits, `__int128` under
39) — even a SINGLE input number cannot be read into a native type, let alone the sum of up to
1000 of them. The sum must be built as an array of digits, added to column by column with carries,
never as a single native arithmetic operation.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic), and [method::PositionalNotation](../../_terms.md#methodpositionalnotation) (the addends are held as digit sequences because no native type holds them).

## Scope
**In scope:** `problems/euler013/solution.cpp` — the digit-array addition, correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic), the running sum is
kept as a little-endian digit array. Each of the `N` input numbers is read as a string and added
into that array column by column with carry propagation, growing the array when a carry extends
past its current length. The final array's leading digits (after stripping trailing — i.e.
most-significant — zero entries) are printed, truncated to the first ten.

### Data
- Input: `N`, then `N` lines each a 50-digit decimal string.
- Output: one line — the first ten digits of the sum.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(numbers)` MUST match an independent decimal-string adder across randomized cases —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851704, 2026-07-12; re-checked live on 2026-09-01: the official sample (5 given
  50-digit numbers → `2728190129`) plus 500 randomized cases, 2-20 random 50-digit numbers each,
  cross-checked against an independently written decimal-string adder, exact match on every case).
- The sum MUST be accumulated as a digit array throughout, never cast through a native integer
  type at any point — **MUST-no-native-overflow-path** — criterion: `sum` and every intermediate
  value in `main`'s addition loop are `vector<int>` digit arrays, never `long long`/`__int128`.
  Status: done.
- Leading (most-significant) zero digits MUST be stripped before printing, but the result MUST
  never print as an empty string — **MUST-trim-leading-zeros** — criterion: `len` stops shrinking
  at `len > 1`, so a genuinely zero sum still prints `"0"`. Status: done.
- `problems/euler013/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler013/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::BigIntegerArithmetic](../../_terms.md#methodbigintegerarithmetic),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation).
- Code: `problems/euler013/solution.cpp`; directory README: `problems/euler013/README.md`.
