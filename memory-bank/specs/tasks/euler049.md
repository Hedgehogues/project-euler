---
status: draft
app: projecteuler
tags: [projecteuler, euler049, solution, draft]
---

# euler049 — Prime permutations

## Vision
Given `N` (up to `10^6`) and `K` (3 or 4), find every `K`-term arithmetic progression of mutually
digit-permutation primes with first term `< N`. Checking every pair of primes up to `10^6` for the
digit-permutation relation directly would be quadratic in the prime count; bucketing primes by a
key that IS that invariant (sorted digits + digit count) means only primes already known to be
permutations of each other are ever compared.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)
(finding every prime up to the limit), [method::HashGrouping](../../_terms.md#methodhashgrouping)
(bucketing primes by their digit-permutation class), and
[method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (trying every pair within a
bucket as the progression's first two terms).

## Scope
**In scope:** `problems/euler049/solution.cpp` — the sieve, the grouping key, the progression
search, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every prime up to `999999` is found once
([method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)) and grouped by a key
built from its sorted digits and digit count
([method::HashGrouping](../../_terms.md#methodhashgrouping)) — two primes land in the same bucket
exactly when they are digit-permutations of each other. Within each bucket of size `>= K`, every
pair `(arr[i], arr[j])`, `i<j`, is tried directly
([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)) as the first two terms of an
arithmetic progression with common difference `d = arr[j]-arr[i]`; the remaining `K-2` terms are
checked for membership in the same bucket's set. Every progression whose first term is `< N` is
recorded as its `K`-term concatenation, then all results are sorted by first term then by the
concatenation string.

### Data
- Input: one line, `N K`.
- Output: every qualifying progression's concatenation, sorted, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=2000, K=3 → 148748178147`) —
  **MUST-match-sample** — criterion: zero difference against the given sample. Status: done
  (re-run live 2026-09-01).
- The solution MUST reproduce BOTH classic Project Euler #49 3-term answers
  (`148748178147` and `296962999629`) when `N=1000000, K=3` — **MUST-match-original-pe49** —
  criterion: both concatenations present in the output. Status: done (re-run live 2026-09-01).
- The solution MUST agree with an independent Python re-implementation of the same
  grouping-and-extension approach — **MUST-match-bruteforce** — criterion: cross-checked on the
  official sample — exact match. Status: done.
- The grouping key MUST combine sorted digits AND digit count, not sorted digits alone —
  **MUST-key-includes-length** — criterion: `key = sortedDigits + "#" + length`, since two numbers
  of different lengths can never be permutations of each other even if a naive digit-only sort
  collided by coincidence (not possible for digits alone without the separator, but the explicit
  length suffix removes any ambiguity). Status: done.
- `problems/euler049/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler049/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N K`; qualifying concatenations, sorted, one per
  line) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::HashGrouping](../../_terms.md#methodhashgrouping),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler049/solution.cpp`; directory README: `problems/euler049/README.md`.
