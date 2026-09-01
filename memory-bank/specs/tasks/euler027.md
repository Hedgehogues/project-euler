---
status: draft
app: projecteuler
tags: [projecteuler, euler027, solution, draft]
---

# euler027 — Quadratic primes

## Vision
Given `N` (`42 ≤ N ≤ 2000`), find `|a| < N` and prime `b ≤ N` maximizing the run of consecutive
primes produced by `n² + an + b` for `n = 0, 1, 2, ...`. There is no closed form for which `(a,b)`
maximizes this run — the search itself (`O(N)` candidates for `a` times `O(N)` primes for `b`,
each tested for a run of primes) is the whole computation; the only real efficiency question is
how each candidate value is tested for primality, and trial division up to its square root is
already fast enough at this scale.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::TrialDivision](../../_terms.md#methodtrialdivision),
[method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).

## Scope
**In scope:** `problems/euler027/solution.cpp` — the `(a,b)` search, the primality test,
correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Primes `b ≤ N` are collected first (`n=0` forces `b` itself to be prime). For every such `b` and
every `a` from `-N` to `N`, the code counts consecutive primes from `n=0` upward, per
[method::TrialDivision](../../_terms.md#methodtrialdivision)'s mechanism (`isPrime` trial-divides
by odd numbers up to `sqrt(x)`), stopping at the first non-prime value. The `(a,b)` pair reaching
the longest run is kept.

### Data
- Input: one integer `N` (`42 ≤ N ≤ 2000`).
- Output: one line — `a b`, the coefficients producing the longest prime run.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match the official sample AND the classic known answer at `N=1000` —
  **MUST-match-known-answers** — criterion: both checked directly. Status: done (HackerRank
  Accepted 100%, submission 1410851936, 2026-07-12; re-checked live on 2026-09-01: the official
  sample (`N=42 → -1 41`) and the well-known original Project Euler #27 answer at `N=1000`
  (`a=-61, b=971`, 71 consecutive primes), exact match on both).
- Only prime `b` MUST be tried — **MUST-prime-b-only** — criterion: `primesB` is filtered by
  `isPrime(b)` before the search loop runs. Status: done.
- The consecutive-prime count MUST stop at the FIRST non-prime value, never continue past it —
  **MUST-stop-at-first-failure** — criterion: the inner `while (true)` loop `break`s immediately
  when `isPrime(val)` is false. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at `N=2000`, `n² + an + b` stays under `n² + 2 × 2000 × n + 2000`, comfortably inside `long
  long` for the `n` ranges actually reached. Status: done.
- `problems/euler027/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler027/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::TrialDivision](../../_terms.md#methodtrialdivision),
  [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch).
- Code: `problems/euler027/solution.cpp`; directory README: `problems/euler027/README.md`.
