---
status: draft
app: projecteuler
tags: [projecteuler, euler050, solution, draft]
---

# euler050 — Consecutive prime sum

## Vision
For each of `T` (up to 10) given `N` (up to `10^12`), find the prime `<= N` that is the sum of the
longest run of consecutive primes. `N` up to `10^12` rules out sieving primality of the candidate
sums directly (far too large to sieve), and rules out testing every possible chain length and
starting point naively; the primes actually summed stay small (bounded by where their prefix sum
first exceeds `10^12`), so sieving THOSE and testing only the SUMS for primality (via Miller-Rabin)
keeps the search small.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses four catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)
(finding every prime up to the global limit), [method::PrefixSum](../../_terms.md#methodprefixsum)
(summing any window of consecutive primes in one subtraction),
[method::BinarySearch](../../_terms.md#methodbinarysearch) (finding the longest chain length that
could fit under `N` before searching), and
[method::MillerRabinPrimalityTest](../../_terms.md#methodmillerrabinprimalitytest) (testing each
candidate window sum, too large to sieve, for primality).

## Scope
**In scope:** `problems/euler050/solution.cpp` — the sieve, the prefix sum, the chain-length
search, the Miller-Rabin primality test, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every prime up to `6×10^6` is sieved once
([method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes)), with a prefix-sum
array built over them ([method::PrefixSum](../../_terms.md#methodprefixsum)). For each query `N`,
binary search ([method::BinarySearch](../../_terms.md#methodbinarysearch)) finds the largest chain
length `Lmax` whose prefix sum from the start could still be `<= N`. Starting from `Lmax` down to
1, every window of that length is tried via prefix-sum subtraction, and its sum tested for
primality with the deterministic Miller-Rabin test
([method::MillerRabinPrimalityTest](../../_terms.md#methodmillerrabinprimalitytest)); the first hit
found (longest length, then smallest starting point, hence smallest sum for that length) is the
answer.

### Data
- Input: `T`, then `T` lines with `N`.
- Output: `T` lines — `<sum> <length>` per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`100 → 41 6`, `1000 → 953 21`) —
  **MUST-match-sample** — criterion: zero difference against the given sample. Status: done
  (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #50 answer (`N=1000000 → 997651 543`) —
  **MUST-match-original-pe50** — criterion: exact match. Status: done (re-run live 2026-09-01).
- The solution MUST run comfortably within budget at the constraint maximum (`N=10^12`) —
  **MUST-perform-at-scale** — criterion: measured wall time ~0.03s for a single query at
  `N=10^12`. Status: done.
- The global sieve limit MUST be large enough that the prime prefix sum can reach every `N` up to
  `10^12` — **MUST-sieve-limit-sufficient** — criterion: the sum of primes below `6×10^6` exceeds
  `10^12` (verified: the solution's own binary search never runs out of prefix-sum range for
  `N=10^12` in testing). Status: done.
- `problems/euler050/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler050/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (`T`, then `T` lines of `N`; one `<sum> <length>` line per
  query) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::PrefixSum](../../_terms.md#methodprefixsum),
  [method::BinarySearch](../../_terms.md#methodbinarysearch),
  [method::MillerRabinPrimalityTest](../../_terms.md#methodmillerrabinprimalitytest).
- Code: `problems/euler050/solution.cpp`; directory README: `problems/euler050/README.md`.
