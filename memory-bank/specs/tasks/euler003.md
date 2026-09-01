---
status: draft
app: projecteuler
tags: [projecteuler, euler003, solution, draft]
---

# euler003 — Largest prime factor

## Vision
For each of `T` given values of `N`, find the largest prime factor of `N`. `N` can be large enough
that factoring by checking every integer up to `N` is out of the question — the algorithm must
strip out small factors as it goes so the remaining number shrinks fast, keeping the trial range
near `sqrt(N)`.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::TrialDivision](../../_terms.md#methodtrialdivision).

## Scope
**In scope:** `problems/euler003/solution.cpp` — the model, the algorithm, correctness and bound arguments.

**Out of scope:** the visual explanation of the ladder method as a general technique (the catalog,
not this task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
[method::TrialDivision](../../_terms.md#methodtrialdivision): first every factor of 2 is stripped out
(divide while even), then only odd divisors `p = 3, 5, 7, ...` are tried, each pulled out of `n` as
many times as it fits. The loop stops once `p·p > n` — if `n > 1` at that point, `n` itself is
prime and, since divisors were tried in increasing order, larger than any divisor already pulled
out, so it is the answer. If `n == 1`, the largest divisor already pulled out is the answer. The
property that keeps this fast: as soon as a divisor is pulled out, `n` SHRINKS, so the bound
`p·p ≤ n` falls as the loop runs — it never reaches `sqrt` of the original `N` unless `N` itself has
no small factors.

### Data
- Input: `T`, then `T` lines with `N`.
- Output: `T` lines — the largest prime factor of `N`, per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `largestPrimeFactor(n)` MUST match an independent scan ("for every `d` from 2 to `n`, check
  primality and divisibility") on characteristic and boundary `n` (2, 3, 4, 6, 13195, 997, 999983,
  600851475143) — **MUST-match-bruteforce** — criterion: zero difference across the checked range,
  including the classic Project Euler example (`13195 → 29`) and the original problem's full-size
  `N` (`600851475143 → 6857`). Status: done (HackerRank Accepted 100%, submission 1410850859,
  2026-07-12; re-checked live on 2026-09-01 by compiling and running against
  `13195, 2, 600851475143, 999983` → `29, 2, 6857, 999983`, exact match).
- The divisor loop MUST stop on `p·p ≤ n` where `n` is what REMAINS after divisors already pulled
  out, not the original `N` — **MUST-shrink-bound** — criterion: the loop condition is
  `p * p <= n`, and `n` is reassigned after every division inside that same loop. Status: done.
- The factor 2 MUST be stripped in its own loop before the odd-divisor loop —
  **MUST-strip-two-first** — criterion: `while (n % 2 == 0)` precedes `for (p = 3; ...; p += 2)`;
  the subsequent loop only tries odd `p`. Status: done.
- If `n > 1` remains after the divisor loop, it MUST be taken as a prime factor itself (and hence
  the answer, since the loop tried divisors in increasing order) — **MUST-remainder-is-prime** —
  criterion: `if (n > 1) largest = n;` after the loop. Status: done.
- `problems/euler003/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler003/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Method: [method::TrialDivision](../../_terms.md#methodtrialdivision).
- Code: `problems/euler003/solution.cpp`; directory README: `problems/euler003/README.md`.
