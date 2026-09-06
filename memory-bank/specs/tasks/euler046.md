---
status: draft
app: projecteuler
tags: [projecteuler, euler046, solution, draft]
---

# euler046 — Goldbach's other conjecture

## Vision
For each of `T` (up to 100) given odd composite `N` (up to `5×10^5`), count how many ways
`N = p + 2k²`. Testing primality by trial division per candidate `p = N - 2k²` across `T` queries
would repeat the same primality work; sieving every number up to the global limit once up front
makes each query's inner loop a handful of O(1) lookups.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)
(primality of every number up to the limit), [method::Precomputation](../../_terms.md#methodprecomputation)
(the sieve built once, independent of any query), and
[method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (trying every `k` per query).

## Scope
**In scope:** `problems/euler046/solution.cpp` — the sieve, the per-query count, correctness
criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
A sieve up to `5×10^5` ([method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
[method::Precomputation](../../_terms.md#methodprecomputation)) marks composites once, before any
query is read. For each `N`, every `k>=1` with `2k²<N`
([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)) is tried: if `N-2k²>=2` and
not marked composite, it counts as one representation. The total count is printed per query.

### Data
- Input: `T`, then `T` lines with `N`.
- Output: `T` lines — the count of representations `N = p + 2k²`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`9,15 → 1,2`) — **MUST-match-sample** —
  criterion: zero difference against the given sample. Status: done (re-run live 2026-09-01).
- The solution MUST reproduce the historically known smallest counterexample to Goldbach's other
  conjecture (`5777 → 0`) — **MUST-match-known-counterexample** — criterion: exact match. Status:
  done (re-run live 2026-09-01).
- The solution MUST agree with an independent Python re-implementation of the same sieve-and-count
  — **MUST-match-bruteforce** — criterion: cross-checked on `N ∈ {9, 15, 21, 33, 5777}` — exact
  match on every value. Status: done.
- `problems/euler046/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler046/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (`T`, then `T` lines of `N`; one count per line) —
  **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler046/solution.cpp`; directory README: `problems/euler046/README.md`.
