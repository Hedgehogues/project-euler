---
status: draft
app: projecteuler
tags: [projecteuler, euler036, solution, draft]
---

# euler036 — Double-base palindromes

## Vision
Given `N` (`10 ≤ N ≤ 10^6`) and `K` (`2 ≤ K ≤ 9`), sum every number below `N` palindromic in both
base 10 and base `K`. At `N ≤ 10^6`, checking each number directly in both bases — converting to
base `K` costs only `O(log_K N)` digits — is already fast enough; there is no shortcut being taken
that a named technique would explain.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses no catalogued method
(`../../_terms.md`) — the direct two-base palindrome check is already the whole computation; see
the Vision.

## Scope
**In scope:** `problems/euler036/solution.cpp` — the base-10 and base-`K` palindrome checks,
correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`isPalindromeBase10` compares a number's decimal string to its own reverse.
`isPalindromeBaseK` extracts base-`K` digits (least-significant first) into a vector and compares
it against itself reversed, via a two-pointer scan. A number is summed only when both checks
pass.

### Data
- Input: two integers `N K` (`10 ≤ N ≤ 10^6`, `2 ≤ K ≤ 9`).
- Output: one line — the sum of numbers below `N` palindromic in both bases.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n, k)` MUST match an independent Python search — **MUST-match-bruteforce** — criterion:
  zero mismatches. Status: done (HackerRank Accepted 100%, submission 1410852077, 2026-07-12;
  re-checked live on 2026-09-01: the official sample (`N=10,K=2→25`) plus `N=1000000,K=2→872187`
  — the well-known original Project Euler #36 answer — against an independently written Python
  double-base palindrome checker, exact match on both).
- The base-`K` palindrome check MUST compare digits extracted least-significant-first against
  their own reverse, not the base-10 string — **MUST-separate-base-check** — criterion:
  `isPalindromeBaseK` builds its own `digits` vector via `% K`/`/ K`, independent of the base-10
  string used by `isPalindromeBase10`. Status: done.
- `problems/euler036/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler036/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: none.
- Code: `problems/euler036/solution.cpp`; directory README: `problems/euler036/README.md`.
