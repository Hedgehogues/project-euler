---
status: draft
app: projecteuler
tags: [projecteuler, euler001, solution, draft]
---

# euler001 — Multiples of 3 and 5

## Vision
For each of `T` given values of `N`, return the sum of every natural number below `N` that is a
multiple of 3 or 5 — without looping over the range. HackerRank raises `N` and `T` specifically to
rule out the naive sum, so the solution must be `O(1)` per query.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods (`../memory-bank/_terms.md`):
[method::InclusionExclusion](../memory-bank/_terms.md#methodinclusionexclusion),
[method::ArithmeticProgressionSum](../memory-bank/_terms.md#methodarithmeticprogressionsum).

## Scope
**In scope:** `solution.cpp` — the model, the formula, the `O(1)` argument, correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
The sum of multiples of `k` strictly below `n` is a sum of an arithmetic progression
([method::ArithmeticProgressionSum](../memory-bank/_terms.md#methodarithmeticprogressionsum)):
`m = (n-1)/k` such multiples exist and they sum to `k · m·(m+1)/2` — implemented as
`sumMultiplesBelow(n, k)`. The answer to "multiple of 3 OR 5" is inclusion–exclusion
([method::InclusionExclusion](../memory-bank/_terms.md#methodinclusionexclusion)) over that
formula: `solve(n) = sumMultiplesBelow(n,3) + sumMultiplesBelow(n,5) − sumMultiplesBelow(n,15)`
(15 = lcm(3,5) — the overlap, counted twice, subtracted once). Each query costs three calls to the
formula, no loop over `[0, n)`.

### Data
- Input: `T`, then `T` lines with `N`.
- Output: `T` lines — `solve(N)` per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match a direct sum `sum(i for i in 1..n-1 if i%3==0 or i%5==0)` on every official
  sample and boundary `n` (0, 1, 3, 5, 15, 16) — **MUST-match-bruteforce** — criterion: zero
  difference across the checked range. Status: done (HackerRank Accepted 100%; re-checked live
  against a fresh brute-force script on 2026-09-01: `n=0,1,3,5,15,16` → `0,0,3,8,45,60`, exact
  match on both sides).
- The cost per query MUST be `O(1)` — no loop over `[0, n)` — **MUST-o1-per-query** — criterion:
  `sumMultiplesBelow`/`solve` contain no loop, only arithmetic. Status: done.
- `sumMultiplesBelow(n, k)` MUST count multiples of `k` strictly BELOW `n` (not `<= n`) —
  **MUST-strict-below** — criterion: `m = (n-1)/k` (integer division), not `n/k`; the discrepancy
  at `n` itself a multiple of `k` (`n=15, k=3` would count one extra multiple under `n/k`) is
  caught by the `n=15` test. Status: done.
- `solve(n)` MUST subtract the sum of multiples of 15, derived as lcm(3,5) — not "3·5" as a
  coincidental product — **MUST-lcm-not-product** — criterion: the third term is tied explicitly
  to [method::InclusionExclusion](../memory-bank/_terms.md#methodinclusionexclusion)'s overlap
  term, not to multiplication in general. Status: done.
- `solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format (first line `T`, then `T` lines of `N`; one answer line per
  query) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::InclusionExclusion](../memory-bank/_terms.md#methodinclusionexclusion),
  [method::ArithmeticProgressionSum](../memory-bank/_terms.md#methodarithmeticprogressionsum).
- Code: `euler001/solution.cpp`; directory README: `euler001/README.md`.
