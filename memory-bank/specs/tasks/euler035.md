---
status: draft
app: projecteuler
tags: [projecteuler, euler035, solution, draft]
---

# euler035 — Circular primes

## Vision
Given `N` (`10 ≤ N ≤ 10^6`), sum every circular prime below `N`, where rotations of a prime's
digits CAN exceed `N` (explicitly noted in the problem) and still need to be checked. Sieving only
up to `N` would leave those larger rotations unable to be tested at all; the sieve must instead
reach the largest value ANY rotation of an `(len(N)-1)`-digit number could take (an all-9s number
of the same digit count), so every rotation encountered is guaranteed to have a real primality
answer available.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes), and [method::PositionalNotation](../../_terms.md#methodpositionalnotation) (a rotation is an operation on the written form, not on the value).

## Scope
**In scope:** `problems/euler035/solution.cpp` — the extended sieve bound, the rotation check,
correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`sieveLimit` grows from `9` by repeatedly appending a `9` digit (`sieveLimit*10+9`) until it
reaches or exceeds `N-1` — the largest value with the same digit count as the largest candidate
prime, which safely bounds every possible rotation of it too. Per
[method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes), every composite up to
that bound is marked in one pass. For each prime `p` below `N`, every rotation of its decimal
digits is generated as a string, parsed back to an integer, and checked against the sieve; `p` is
added to the sum only if every rotation is prime.

### Data
- Input: one integer `N` (`10 ≤ N ≤ 10^6`).
- Output: one line — the sum of circular primes below `N`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent trial-division cross-check at `N=100, 1000, 10000` —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410852066, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`N=100→446`) plus `N=1000→6440, N=10000→50880` against an independently written trial-division
  rotation checker, exact match on every value).
- The sieve bound MUST cover every possible rotation of every candidate below `N`, not just `N`
  itself — **MUST-sieve-covers-rotations** — criterion: `sieveLimit` is grown independently of
  `N` via the all-9s construction, not set to `limit` directly. Status: done.
- A candidate's rotation check MUST stop at the first non-prime rotation found —
  **MUST-stop-at-first-failure** — criterion: `allCircular` breaks out of the rotation loop
  immediately on failure. Status: done.
- `problems/euler035/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler035/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation).
- Code: `problems/euler035/solution.cpp`; directory README: `problems/euler035/README.md`.
