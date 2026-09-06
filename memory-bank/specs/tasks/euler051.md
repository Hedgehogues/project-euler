---
status: draft
app: projecteuler
tags: [projecteuler, euler051, solution, draft]
---

# euler051 — Prime digit replacements

## Vision
Given `N` (2 to 7), `K` (1 to `N`), `L` (1 to 8), find the smallest `N`-digit prime whose `K`
digit positions, replaced by a shared digit, yield a family of `>= L` primes. `N <= 7` keeps both
the candidate range (`10^N`) and the number of digit-position choices (`2^N <= 128`) small enough
for direct exhaustive search per candidate; the part that must not be gotten wrong is the
tie-break (lexicographically smallest family among all valid masks for the smallest qualifying
prime), not the search's raw feasibility.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)
(primality of every `N`-digit number), [method::BitmaskSubsetEnumeration](../../_terms.md#methodbitmasksubsetenumeration)
(every choice of `K` digit positions out of `N`), and
[method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (trying every candidate prime
and mask directly).

## Scope
**In scope:** `problems/euler051/solution.cpp` — the sieve, the mask enumeration, the family
search and tie-break, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every `N`-digit number's primality is sieved once
([method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)). Every `K`-of-`N`
digit-position choice is precomputed as a bitmask
([method::BitmaskSubsetEnumeration](../../_terms.md#methodbitmasksubsetenumeration)), filtered by
population count `== K`. For each prime `P` in ascending order
([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)), every mask is checked: if
`P`'s digits at the mask's positions already agree on one value, that shared digit is replaced by
each of `0..9` (skipping a leading zero at the most-significant position) and every resulting
prime forms the candidate family for that mask. Among every mask giving a family of size `>= L`
for this `P`, the lexicographically smallest `L`-member family is kept; the search stops at the
first `P` with any such family, since `P` is always a member of its own family and any smaller `P`
would already dominate lexicographically.

### Data
- Input: one line, `N K L`.
- Output: the `L` smallest members of the found family, space-separated, ascending.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match both official samples (`5 2 7 → 56003 56113 56333 56443 56663 56773
  56993`; `2 1 3 → 11 13 17`) — **MUST-match-sample** — criterion: zero difference against both
  given samples. Status: done (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #51 answer (`6 3 8 → 121313 222323 323333
  424343 525353 626363 828383 929393`) — **MUST-match-original-pe51** — criterion: exact match.
  Status: done (re-run live 2026-09-01).
- The solution MUST agree with an independent Python re-implementation that tries every
  digit-position combination directly (not bitmasks) and compares candidate families
  lexicographically — **MUST-match-bruteforce** — criterion: cross-checked on both official
  samples plus the classic answer case — exact match on every case (the first independent attempt
  had a real bug — returning the first mask meeting the length requirement instead of comparing
  all valid masks for the same `P` lexicographically — caught by disagreement on the second
  sample, fixed, then re-verified). Status: done.
- `problems/euler051/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler051/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N K L`; the `L` family members, ascending,
  space-separated) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::BitmaskSubsetEnumeration](../../_terms.md#methodbitmasksubsetenumeration),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler051/solution.cpp`; directory README: `problems/euler051/README.md`.
