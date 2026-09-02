# euler007 — 10001st prime

For each of `T` given values of `N` (`1 ≤ N ≤ 10^4`), find the `N`th prime number. By listing the
first six primes `2, 3, 5, 7, 11, 13`, the 6th prime is `13`.

## Approach

Build the list of primes once, up front, and answer every query with a lookup:

- Take the largest `N` across all `T` queries; that is the only number that decides how many
  primes need to exist in the list at all.
- Estimate a safe upper bound on the value of the largest-needed prime with a proven inequality
  (Rosser, 1941): `p_n < n·(ln n + ln ln n)` for `n ≥ 6`, padded further for safety margin.
- Sieve every prime up to that bound in one pass.
- Answer each query by indexing straight into the sieved list — `primes[n-1]`.

Status: **Accepted**, 100% on HackerRank (submission 1410851645, 2026-07-12). Re-verified live on
2026-09-01: the official sample (`N=3 → 5`, `N=6 → 13`) and an exhaustive cross-check against an
independent brute-force sieve across the ENTIRE valid range `N = 1..10000` — exact match on every
value, including the boundary `N=10000 → 104729`.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler007.md).

## The ideas behind it

Two independently catalogued ideas, one to build the list, one to know how far to build it (full
write-ups: [`memory-bank/_terms.md`](../../memory-bank/_terms.md)) — plus the already-catalogued
build-once-answer-many pattern:

**Sieve of Eratosthenes** — cross out every multiple of each prime found so far; whatever survives
unmarked is exactly the primes. [`[method::SieveOfEratosthenes]`](../../memory-bank/_terms.md#methodsieveoferatosthenes)

[![Sieve of Eratosthenes](../../memory-bank/visualizations/build/sieve-of-eratosthenes.png)](../../memory-bank/visualizations/build/sieve-of-eratosthenes.html)

**Upper bound on the nth prime** — a proven inequality gives a numeric ceiling on how large the
`N`th prime can be, so the sieve knows exactly how far to reach instead of guessing or growing
open-endedly. [`[method::NthPrimeBound]`](../../memory-bank/_terms.md#methodnthprimebound)

[![Upper bound on the nth prime](../../memory-bank/visualizations/build/nth-prime-bound.png)](../../memory-bank/visualizations/build/nth-prime-bound.html)

That bound is a named composition of three smaller ideas, each with its own catalog record and
picture: the spacing of primes from
[`[method::PrimeNumberTheorem]`](../../memory-bank/_terms.md#methodprimenumbertheorem), one pass of
[`[method::FixedPointIteration]`](../../memory-bank/_terms.md#methodfixedpointiteration) (measure the
gap where the first guess landed, not where it started), and
[`[method::LogarithmProductRule]`](../../memory-bank/_terms.md#methodlogarithmproductrule) (which is
all the `ln ln n` term is).

The sieve is built once for the largest `N` across all `T` queries, not once per query — the same
[`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation) pattern already
catalogued.

**Offline algorithm** — Every query is read before any answer is produced, so one sieve is sized to the largest of them.
[`[method::OfflineAlgorithm]`](../../memory-bank/_terms.md#methodofflinealgorithm)

[![Offline algorithm](../../memory-bank/visualizations/build/offline-algorithm.png)](../../memory-bank/visualizations/build/offline-algorithm.html)

**Keeping a value in range** — The sieve bound is compared by division rather than by forming a product.
[`[method::IntegerOverflowAvoidance]`](../../memory-bank/_terms.md#methodintegeroverflowavoidance)

[![Keeping a value in range](../../memory-bank/visualizations/build/integer-overflow-avoidance.png)](../../memory-bank/visualizations/build/integer-overflow-avoidance.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
