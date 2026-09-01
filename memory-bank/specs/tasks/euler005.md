---
status: draft
app: projecteuler
tags: [projecteuler, euler005, solution, draft]
---

# euler005 — Smallest multiple

## Vision
For each of `T` given values of `N` (`1 ≤ N ≤ 40`), find the smallest positive number that every
number from `1` to `N` divides evenly. Multiplying all of `1..N` together grossly overcounts
shared factors (e.g. both `4` and `8` contribute a factor of `2`, but only the larger power is
ever needed) — the smallest such multiple must be built by combining numbers one at a time and
subtracting out what's already covered, not by blind multiplication.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods, one the
mechanism and one what's built with it (`../../_terms.md`):
[method::EuclideanAlgorithm](../../_terms.md#methodeuclideanalgorithm),
[method::LCMViaGCD](../../_terms.md#methodlcmviagcd).

## Scope
**In scope:** `problems/euler005/solution.cpp` — the model, the algorithm, correctness and bound
arguments.

**Out of scope:** the visual explanation of the Euclidean algorithm as a general technique (the
catalog, not this task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
[method::LCMViaGCD](../../_terms.md#methodlcmviagcd): starting from `lcm = 1`, each number `i`
from `2` to `N` is folded in via `lcm = lcm / gcd(lcm, i) * i`. The
[method::EuclideanAlgorithm](../../_terms.md#methodeuclideanalgorithm) computes `gcd(lcm, i)` —
exactly the part of `i` already present in the running `lcm` — so dividing it out before
multiplying by `i` adds only the genuinely new part. Repeating this across the whole range gives
the least common multiple of `1..N` in a single pass, with no intermediate value ever larger than
the final answer.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 40`).
- Output: `T` lines — the smallest number divisible by every number in `1..N`, per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independently computed least common multiple of `1..n` for the ENTIRE
  valid range `n = 1..40` — **MUST-match-bruteforce** — criterion: zero difference across all 40
  values. Status: done (HackerRank Accepted 100%, submission 1410850883, 2026-07-12; re-checked
  live on 2026-09-01 against a fresh, differently-implemented computation (`math.lcm`, folded
  pairwise) across the full range — exact match, including `n=40` → `5342931457063200`).
- The running `lcm` MUST be reduced by the shared factor (`gcd(lcm, i)`) before multiplying by the
  next number, not multiplied in directly — **MUST-divide-before-multiply** — criterion: the update
  is `lcm = lcm / gcd(lcm, i) * i`, in that order, never `lcm = lcm * i` alone. Status: done.
- The GCD MUST be computed by the Euclidean algorithm (`std::gcd`, a direct implementation of it),
  not by factoring — **MUST-use-euclidean-algorithm** — criterion: the standard library `gcd` call
  is the only GCD computation in the file. Status: done.
- Every intermediate and final `lcm` value MUST fit in the type used — **MUST-no-overflow** —
  criterion: `lcm(1..40) = 5342931457063200` requires 53 bits, comfortably inside `unsigned long
  long` (64 bits) — verified by direct computation, not assumed. Status: done.
- `problems/euler005/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler005/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::EuclideanAlgorithm](../../_terms.md#methodeuclideanalgorithm),
  [method::LCMViaGCD](../../_terms.md#methodlcmviagcd).
- Code: `problems/euler005/solution.cpp`; directory README: `problems/euler005/README.md`.
