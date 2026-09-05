---
status: draft
app: projecteuler
tags: [projecteuler, euler041, solution, draft]
---

# euler041 — Pandigital prime

## Vision
For each of `T` (up to `10^5`) given `N` (up to `10^10-1`), find the largest pandigital prime
`<= N`. Testing every number up to `N` for pandigitality and primality is infeasible at this scale;
instead, a digit-sum argument first proves only 4-digit and 7-digit pandigital numbers can ever be
prime, shrinking the candidate space to two small, enumerable permutation sets checked once.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses four catalogued methods
(`../../_terms.md`): [method::DigitSumDivisibilityRule](../../_terms.md#methoddigitsumdivisibilityrule)
(ruling out every length except 4 and 7 before generating anything),
[method::NextPermutation](../../_terms.md#methodnextpermutation) (enumerating the candidates of
each surviving length), [method::TrialDivision](../../_terms.md#methodtrialdivision) (testing each
candidate for primality), [method::Precomputation](../../_terms.md#methodprecomputation) and
[method::BinarySearch](../../_terms.md#methodbinarysearch) (building the sorted candidate list once
and answering each query against it).

## Scope
**In scope:** `problems/euler041/solution.cpp` — the length filter, the candidate enumeration, the
per-query lookup, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
The digit sum of any `1..n` pandigital number is `n(n+1)/2`
([method::DigitSumDivisibilityRule](../../_terms.md#methoddigitsumdivisibilityrule)); for `n=1..9`
only `n=4` (sum 10) and `n=7` (sum 28) give a sum not divisible by 3, so every other length is
excluded before any candidate is built (`n=1`'s only candidate, "1", is excluded separately by not
being prime). For `n` in `{4, 7}`, every permutation of `1..n`
([method::NextPermutation](../../_terms.md#methodnextpermutation)) is tested for primality by
trial division up to its square root
([method::TrialDivision](../../_terms.md#methodtrialdivision)). The surviving candidates (at most
`4!+7!=5064`) are collected and sorted once
([method::Precomputation](../../_terms.md#methodprecomputation)); each query then finds the
largest candidate `<= N` with one `upper_bound`
([method::BinarySearch](../../_terms.md#methodbinarysearch)), or `-1` if none exists.

### Data
- Input: `T`, then `T` lines with `N`.
- Output: `T` lines — the largest pandigital prime `<= N`, or `-1`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=100 → -1`, `N=10000 → 4231`) —
  **MUST-match-sample** — criterion: zero difference against the given sample. Status: done
  (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #41 answer (largest pandigital prime
  overall, `N=9999999999 → 7652413`) — **MUST-match-original-pe41** — criterion: exact match.
  Status: done (re-run live 2026-09-01).
- The candidate generation MUST be restricted to exactly `n=4` and `n=7` — **MUST-length-filter** —
  criterion: an independent Python re-implementation enumerating permutations of `1..n` for
  `n=1..9` and filtering by primality directly confirms no prime pandigital number exists at any
  other length up to 9 digits, matching the digit-sum argument. Status: done (checked live for
  every `n=1..9` implicitly via the digit-sum table; explicit permutation search re-run for
  `n=4,7` against the C++ output on `N=100,10000,9999999999,7652413,7652412` — exact match on
  every case, including the boundary `7652413`/`7652412`).
- `problems/euler041/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler041/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (`T`, then `T` lines of `N`; one answer per line) —
  **MUST-io-format**. Status: done.

## Links
- Methods: [method::DigitSumDivisibilityRule](../../_terms.md#methoddigitsumdivisibilityrule),
  [method::NextPermutation](../../_terms.md#methodnextpermutation),
  [method::TrialDivision](../../_terms.md#methodtrialdivision),
  [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::BinarySearch](../../_terms.md#methodbinarysearch).
- Code: `problems/euler041/solution.cpp`; directory README: `problems/euler041/README.md`.
