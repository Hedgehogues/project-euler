---
status: draft
app: projecteuler
tags: [projecteuler, euler047, solution, draft]
---

# euler047 — Distinct primes factors

## Vision
Given `N` (up to `2×10^6`) and `K` (2 to 4), find every run of `K` consecutive integers starting
at or below `N`, each with exactly `K` distinct prime factors. Factoring each of up to `2×10^6`
numbers by trial division per query would repeat work across overlapping candidates; sieving the
distinct-prime-factor count for every number up to the limit once, up front, turns each candidate
check into `K` array reads.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::SievingOverMultiples](../../_terms.md#methodsievingovermultiples)
(filling in the distinct-prime-factor count for every number at once),
[method::Precomputation](../../_terms.md#methodprecomputation) (the table built once, before any
candidate is tested), and [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)
(checking every candidate starting point directly).

## Scope
**In scope:** `problems/euler047/solution.cpp` — the distinct-prime-factor sieve, the
consecutive-run check, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`omega[]`, sized to `N+K`, is filled once
([method::Precomputation](../../_terms.md#methodprecomputation)) by walking every prime `p` up to
the bound (`p` is prime exactly when its own cell is still 0 upon reaching it) and incrementing
every multiple of `p`'s cell by one
([method::SievingOverMultiples](../../_terms.md#methodsievingovermultiples)) — since each prime
contributes at most once per multiple regardless of its power, this counts DISTINCT prime factors,
not their multiplicities. For each `m` in `2..N`
([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)), the run `m..m+K-1` qualifies
exactly when every one of those `K` cells equals `K`.

### Data
- Input: one line, `N K`.
- Output: every qualifying starting `m`, ascending, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match both official samples (`N=20,K=2 → 14,20`; `N=644,K=3 → 644`) —
  **MUST-match-sample** — criterion: zero difference against both given samples. Status: done
  (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #47 answer (`N=2000000,K=4` → first
  result `134043`) — **MUST-match-original-pe47** — criterion: exact match. Status: done (re-run
  live 2026-09-01).
- The solution MUST agree with an independent Python computation using direct trial-division
  factorization (not the sieve) — **MUST-match-bruteforce** — criterion: cross-checked on both
  official samples — exact match. Status: done.
- The sieve MUST count each prime factor at most once per number regardless of its multiplicity
  (distinct count, not total with multiplicity) — **MUST-distinct-not-total** — criterion: the
  inner loop increments `omega[m]` once per multiple of `p`, never once per power of `p` dividing
  `m`. Status: done.
- `problems/euler047/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler047/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N K`; qualifying starting points, ascending, one
  per line) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SievingOverMultiples](../../_terms.md#methodsievingovermultiples),
  [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler047/solution.cpp`; directory README: `problems/euler047/README.md`.
