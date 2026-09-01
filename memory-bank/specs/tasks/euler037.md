---
status: draft
app: projecteuler
tags: [projecteuler, euler037, solution, draft]
---

# euler037 — Truncatable primes

## Vision
Given `N` (`100 ≤ N ≤ 10^6`), sum every truncatable prime below `N`. Testing each truncation's
primality by trial division from scratch, for every prime below `N` and every one of its
truncations, would repeat the same divisibility work over and over across overlapping candidates.
Sieving every prime below `N` once and reusing that table for every truncation check turns each
check into an O(1) lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes).

## Scope
**In scope:** `problems/euler037/solution.cpp` — the sieve, the two-directional truncation check,
correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes), every composite
below `N` is marked in one pass. For every prime `p ≥ 10`, the right-to-left truncations
(`substr(i)` for increasing `i`, dropping leftmost digits) and the left-to-right truncations
(`substr(0, len)` for decreasing `len`, dropping rightmost digits) are each looked up in the sieve
directly; `p` is summed only if every truncation in both directions is prime. `2, 3, 5, 7` are
excluded by starting the outer loop at `p = 10`.

### Data
- Input: one integer `N` (`100 ≤ N ≤ 10^6`).
- Output: one line — the sum of truncatable primes below `N`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent trial-division search at `N=100` and the classic known
  answer at `N=1000000` — **MUST-match-bruteforce** — criterion: zero mismatches. Status: done
  (HackerRank Accepted 100%, submission 1410852083, 2026-07-12; re-checked live on 2026-09-01: the
  official sample (`N=100→186`) plus the well-known original Project Euler #37 answer at
  `N=1000000`, `748317` (the sum of all eleven truncatable primes), against an independently
  written trial-division truncation checker, exact match on both).
- Both truncation directions MUST be checked, and either failing MUST exclude the prime —
  **MUST-check-both-directions** — criterion: `truncatable` is set false and the corresponding
  loop breaks the moment either direction's truncation fails. Status: done.
- The single-digit primes `2, 3, 5, 7` MUST be excluded — **MUST-exclude-single-digit** —
  criterion: the outer loop starts at `p = 10`. Status: done.
- `problems/euler037/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler037/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes).
- Code: `problems/euler037/solution.cpp`; directory README: `problems/euler037/README.md`.
