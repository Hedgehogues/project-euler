# euler017 — Number to Words

For each of `T` given values of `N` (`0 ≤ N ≤ 10^12`), write `N` out in English words, Title Case.

## Approach

- Split `N` into groups of three digits by scale (trillion, billion, million, thousand, then the
  final `0-999` group), largest first.
- Convert each three-digit group to words directly (hundreds place, then a lookup table for
  `0-19`, then a separate tens-word for `20-99`).
- Join the non-zero groups with their scale name.

Status: **Accepted**, 100% on HackerRank (submission 1410851749, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`10→Ten`, `17→Seventeen`) and 4015 cases (every value
0–1999, assorted round-number edge cases, and 2000 random values up to `10^12`) cross-checked
against an independent re-implementation of the same digit-group rules — exact match on every
case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler017.md).

## The idea(s) behind it

None of this repository's catalogued methods apply — converting a number to English words is a
direct, ad-hoc mapping specific to how English names numbers (irregular words below twenty, a
separate tens table, "Hundred"/"Thousand"/... scale words), not a general reusable algorithmic
technique.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
