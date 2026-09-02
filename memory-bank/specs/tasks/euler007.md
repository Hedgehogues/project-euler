---
status: draft
app: projecteuler
tags: [projecteuler, euler007, solution, draft]
---

# euler007 — 10001st prime

## Vision
For each of `T` given values of `N` (`1 ≤ N ≤ 10^4`, `T ≤ 10^3`), find the `N`th prime number.
Rediscovering the primes from scratch for every query — trial-dividing upward until the `N`th one
is found, repeated independently up to `T=1000` times — repeats the same growing search up to
`10^3` times over, each one needing to reach as far as the 10000th prime (104729). A single sieve,
built once for the largest `N` actually asked for and reused by every query, replaces up to `10^3`
independent searches with one.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
[method::NthPrimeBound](../../_terms.md#methodnthprimebound),
[method::Precomputation](../../_terms.md#methodprecomputation). NthPrimeBound is itself a named
composition, and its parts are used here through it, not separately:
[method::PrimeNumberTheorem](../../_terms.md#methodprimenumbertheorem) (primes near x sit about
ln x apart), [method::FixedPointIteration](../../_terms.md#methodfixedpointiteration) (one pass of
p &larr; n&middot;ln p) and
[method::LogarithmProductRule](../../_terms.md#methodlogarithmproductrule) (which is what the
ln ln n term is), [method::OfflineAlgorithm](../../_terms.md#methodofflinealgorithm) (every query is read before any answer is produced, so one sieve is sized to the largest of them), and [method::IntegerOverflowAvoidance](../../_terms.md#methodintegeroverflowavoidance) (the sieve bound is compared by division rather than by forming a product).

## Scope
**In scope:** `problems/euler007/solution.cpp` — the model, the sieve, the bound used to size it,
correctness criteria.

**Out of scope:** the visual explanation of any of the three methods (the catalog, not this
task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
The largest `N` across all `T` queries is found first. An upper bound on the value of that `N`th
prime is computed via [method::NthPrimeBound](../../_terms.md#methodnthprimebound) — `n·(ln n +
ln ln n)` for `n ≥ 6`, padded with an extra safety margin against floating-point rounding right at
the boundary. [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes) then sieves
every prime up to that bound in a single pass, per
[method::Precomputation](../../_terms.md#methodprecomputation): built once, not once per query.
Each query is then answered by indexing directly into the sieved list, `primes[n-1]`.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 10^4`).
- Output: `T` lines — the `N`th prime, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent brute-force sieve across the ENTIRE valid range `n =
  1..10000` — **MUST-match-bruteforce** — criterion: zero difference across all 10000 values.
  Status: done (HackerRank Accepted 100%, submission 1410851645, 2026-07-12; re-checked live on
  2026-09-01: the official sample (`n=3→5`, `n=6→13`) plus the full exhaustive range against an
  independently written sieve, exact match on every value, including `n=10000→104729`).
- The prime list MUST be built ONCE for the largest `N` across all queries, not once per query —
  **MUST-precompute-once** — criterion: the sieve loop runs before, and outside of, the
  per-query answer loop. Status: done.
- The sieve bound MUST be derived from
  [method::NthPrimeBound](../../_terms.md#methodnthprimebound)'s inequality, not a hand-picked
  constant — **MUST-bound-derived** — criterion: `nthPrimeUpperBound` evaluates `n·(ln n + ln ln
  n)` from the actual queried `n`, with an explicit safety margin added on top, rather than a
  magic literal sized to the constraints table by hand. Status: done.
- The computed bound MUST actually contain the needed prime for every `n` in the valid range —
  **MUST-bound-sufficient** — criterion: for `n=10000`, the bound evaluates to `114306` (before
  the further `+10` margin in code, giving a sieve limit of `114316`), safely above the true
  10000th prime, `104729`; verified by direct computation, not assumed. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at the largest valid `n=10^4`, the sieve limit stays under `1.2×10^5` and the largest prime
  returned, `104729`, is comfortably inside `long long` (64 bits, max `~9.2×10^18`); verified by
  direct computation. Status: done.
- `problems/euler007/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler007/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SieveOfEratosthenes](../../_terms.md#methodsieveoferatosthenes),
  [method::NthPrimeBound](../../_terms.md#methodnthprimebound) (= composition of
  [method::PrimeNumberTheorem](../../_terms.md#methodprimenumbertheorem),
  [method::FixedPointIteration](../../_terms.md#methodfixedpointiteration),
  [method::LogarithmProductRule](../../_terms.md#methodlogarithmproductrule)),
  [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::OfflineAlgorithm](../../_terms.md#methodofflinealgorithm),
  [method::IntegerOverflowAvoidance](../../_terms.md#methodintegeroverflowavoidance).
- Code: `problems/euler007/solution.cpp`; directory README: `problems/euler007/README.md`.
