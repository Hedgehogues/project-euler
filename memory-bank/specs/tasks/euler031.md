---
status: draft
app: projecteuler
tags: [projecteuler, euler031, solution, draft]
---

# euler031 — Coin sums

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 10^4`, `1 ≤ N ≤ 10^5`), count the ways to make `N`
pence from the 8 English coins, mod `10^9+7`. Enumerating every combination of coins directly is
combinatorially explosive, and recomputing the count from scratch for every query would repeat
the same buildup up to `10^4` times. The unbounded-knapsack coin-change recurrence, built once for
every amount up to the largest queried `N`, answers every query with a lookup.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::DynamicProgramming](../../_terms.md#methoddynamicprogramming),
[method::Precomputation](../../_terms.md#methodprecomputation).

## Scope
**In scope:** `problems/euler031/solution.cpp` — the coin-DP buildup, correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`dp[0] = 1` (one way to make zero: no coins). Per
[method::DynamicProgramming](../../_terms.md#methoddynamicprogramming), for each coin value `c` in
turn, every amount `i` from `c` upward absorbs `dp[i-c]` — the ways to make `i` using coins
considered SO FAR (including `c` itself, since `i-c` may itself have already used `c`). Processing
coins in a fixed outer loop, amounts in an inner loop, counts each combination of coins exactly
once (order-independent), not each ordered sequence. Built once
([method::Precomputation](../../_terms.md#methodprecomputation)) up to the largest `N` across all
queries; each query then reads `dp[N]` directly.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 10^5`).
- Output: `T` lines — the number of ways to make `N` pence, mod `10^9+7`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent re-implementation of the same coin-DP across `n=1..2000`,
  AND the classic known answer at `n=200` — **MUST-match-bruteforce** — criterion: zero
  mismatches. Status: done (HackerRank Accepted 100%, submission 1410852016, 2026-07-12;
  re-checked live on 2026-09-01: the official sample (`10→11, 15→22, 20→41`) plus `n=1..2000`
  against an independently written coin-DP, exact match on every case; also confirmed the
  well-known original Project Euler #31 answer at `N=200`, `73682`).
- Coins MUST be processed in the OUTER loop and amounts in the INNER loop — **MUST-coin-outer-loop**
  — criterion: `for (int c : coins) { for (int i = c; ...) ... }`, not the reverse order (which
  would count ordered sequences of coins, not combinations). Status: done.
- The DP table MUST be built ONCE up to the largest `N`, not once per query —
  **MUST-precompute-once** — criterion: both loops over `coins`/`i` run before the query loop.
  Status: done.
- `problems/euler031/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler031/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::DynamicProgramming](../../_terms.md#methoddynamicprogramming),
  [method::Precomputation](../../_terms.md#methodprecomputation).
- Code: `problems/euler031/solution.cpp`; directory README: `problems/euler031/README.md`.
