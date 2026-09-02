---
status: draft
app: projecteuler
tags: [projecteuler, euler017, solution, draft]
---

# euler017 — Number to Words

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 10`, `0 ≤ N ≤ 10^12`), write `N` in English words.
There is no arithmetic shortcut here — the cost is entirely in correctly reproducing English's
irregular naming rules (nineteen distinct words below twenty, a separate multiples-of-ten table,
where "Hundred" and the scale words attach) across numbers up to a trillion, not in performance;
`T ≤ 10` makes even a slow implementation fast enough.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses no catalogued method
(`../../_terms.md`) — the digit-group-to-English mapping is specific to this problem's language
rules, not a general reusable technique; see the Vision, [method::LookupTable](../../_terms.md#methodlookuptable) (the irregular names below twenty and the tens are given, not derived, so they are tabulated).

## Scope
**In scope:** `problems/euler017/solution.cpp` — the digit-grouping, the word tables, correctness
criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`N` is split into up to five groups by scale (`10^12, 10^9, 10^6, 10^3`, then the remaining
`0-999`), largest first. `underThousand` converts one 0-999 group: the hundreds digit (if any) is
looked up and followed by "Hundred"; the remaining 0-99 is either a direct lookup (`0-19`) or a
tens word optionally followed by a ones word (`20-99`). Non-zero groups are joined with their
scale name ("Thousand", "Million", ...) and a single space.

### Data
- Input: `T`, then `T` lines with `N` (`0 ≤ N ≤ 10^12`).
- Output: `T` lines — `N` written in English words, Title Case.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent re-implementation of the same digit-group rules across a
  large sample — **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank
  Accepted 100%, submission 1410851749, 2026-07-12; re-checked live on 2026-09-01: the official
  sample (`10→Ten, 17→Seventeen`) plus 4015 cases — every value 0-1999, assorted round-number edge
  cases (100, 1000, 1000000000000, ...), and 2000 random values up to `10^12` — against an
  independently written converter following the same rules, exact match on every case).
- `N=0` MUST print `"Zero"`, never an empty string — **MUST-zero-case** — criterion:
  `numberToWords(0)` returns `"Zero"` explicitly before the group-splitting logic runs. Status:
  done.
- Every group's word MUST be joined with exactly one space, with no stray space when a scale group
  is zero and skipped — **MUST-spacing** — criterion: the `if (!result.empty())` guard before each
  join. Status: done.
- `problems/euler017/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler017/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: none,
  [method::LookupTable](../../_terms.md#methodlookuptable).
- Code: `problems/euler017/solution.cpp`; directory README: `problems/euler017/README.md`.
