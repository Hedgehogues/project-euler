---
status: draft
app: projecteuler
tags: [projecteuler, euler040, solution, draft]
---

# euler040 — Champernowne's constant

## Vision
For each of `T` (up to `10^5`) test cases, given seven indices up to `10^18` each, find the product
of the digits at those positions of `0.123456789101112...`. An index up to `10^18` rules out ever
materializing the concatenated string (it would need on the order of `10^18` characters); the digit
must be located directly via the block structure of how many digits each integer length
contributes.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::ChampernowneConstant](../../_terms.md#methodchampernowneconstant)
(locating the digit at an arbitrary position without building the string).

## Scope
**In scope:** `problems/euler040/solution.cpp` — the block-offset digit locator, the per-test-case
product, correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`digitAt(n)` ([method::ChampernowneConstant](../../_terms.md#methodchampernowneconstant)) walks
`d = 1, 2, 3, ...`, subtracting each block's digit count `9·10^(d-1)·d` from the remaining offset
until it fits inside the current block; the quotient and remainder of dividing what remains by `d`
then give which number and which of its own digits holds the position. All arithmetic uses
`__int128` (indices up to `10^18`, and intermediate products like `10^(d-1)·d` would overflow a
64-bit type well before `d` reaches the digit-count of `10^18`). Each test case reads seven indices
and multiplies their seven looked-up digits.

### Data
- Input: `T`, then `T` lines of seven integers `i_1..i_7`.
- Output: `T` lines — the product of `d_{i_1}..d_{i_7}` per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`i=1..7` → `5040`) — **MUST-match-sample** —
  criterion: zero difference against the given sample. Status: done (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #40 answer
  (`i=1,10,100,1000,10000,100000,1000000` → `210`) — **MUST-match-original-pe40** — criterion:
  exact match. Status: done (re-run live 2026-09-01).
- `digitAt(n)` MUST agree with the actual concatenated string for every tested `n` —
  **MUST-match-bruteforce** — criterion: cross-checked against an independent Python
  string-building computation for `n` in `{1,9,10,11,12,13,99,100,101,190,192,999,1000,1001,2000}`
  — exact match on every value. Status: done.
- All arithmetic in `digitAt` MUST use a type wide enough for `n` up to `10^18` and its
  intermediate block-size products — **MUST-wide-arithmetic** — criterion: `remaining`, `d`,
  `count9`, `blockStart`, `number`, `digitPos`, `divisor` are all `__int128`. Status: done.
- `problems/euler040/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler040/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (`T`, then `T` lines of seven integers; one product per
  line) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::ChampernowneConstant](../../_terms.md#methodchampernowneconstant).
- Code: `problems/euler040/solution.cpp`; directory README: `problems/euler040/README.md`.
