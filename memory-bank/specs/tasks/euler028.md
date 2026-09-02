---
status: draft
app: projecteuler
tags: [projecteuler, euler028, solution, draft]
---

# euler028 — Number spiral diagonals

## Vision
For each of `T` given odd values of `N` (`T ≤ 10^5`, `N < 10^18`), sum the spiral's diagonal
values mod `10^9+7`. `N` can be almost `10^18` — actually building the spiral (`O(N)` or even
`O(N²)` cells) is completely impossible; the diagonal sum must come from a closed-form formula in
`m = (N-1)/2` alone, evaluated in `O(log MOD)` per query for the modular inverse it needs.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods
(`../../_terms.md`): [method::SumOfSquares](../../_terms.md#methodsumofsquares),
[method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum),
[method::ModularInverseFermat](../../_terms.md#methodmodularinversefermat),
[method::FastExponentiation](../../_terms.md#methodfastexponentiation), and [method::IntegerOverflowAvoidance](../../_terms.md#methodintegeroverflowavoidance) (both factors are reduced before multiplying, so the product never leaves the range).

## Scope
**In scope:** `problems/euler028/solution.cpp` — the closed-form ring-sum derivation, correctness
criteria.

**Out of scope:** the visual explanation of any of the four methods (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Ring `k` (`k=1..m`, `m=(N-1)/2`) has four corners summing to `16k² + 4k + 4`. Summed over all
rings plus the center cell: `1 + 16·Σk² + 4·Σk + 4m`. `Σk²` is
[method::SumOfSquares](../../_terms.md#methodsumofsquares)'s `m(m+1)(2m+1)/6`; `Σk` is
[method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum)'s `m(m+1)/2`.
Division by 6 under the modulus uses a precomputed inverse
([method::ModularInverseFermat](../../_terms.md#methodmodularinversefermat), computed once via
[method::FastExponentiation](../../_terms.md#methodfastexponentiation)), so every query evaluates
the whole closed form in O(1) beyond that one shared setup step.

### Data
- Input: `T`, then `T` lines with `N` (odd, `1 ≤ N < 10^18`).
- Output: `T` lines — the diagonal sum mod `10^9+7`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent direct spiral simulation across a sampled range —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851942, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`N=3→25, N=5→101`) plus 1000 cases — every odd `N` from 1 to 1999 — against an independently
  written direct spiral-ring simulation, exact match on every case).
- Every division (by 6, inside the sum-of-squares term) MUST go through the modular inverse, never
  native integer division — **MUST-modular-division** — criterion: `inv6` is computed once via
  `power(6, MOD-2)` and used as a multiplication everywhere the formula divides by 6. Status:
  done.
- The modular inverse of 6 MUST be computed ONCE, not once per query — **MUST-precompute-once** —
  criterion: `inv6` is computed before the query loop, outside it. Status: done.
- Every intermediate value MUST stay reduced modulo `10^9+7` throughout, even for `N` up to
  `10^18` — **MUST-no-overflow** — criterion: `mulmod` reduces after every multiplication; `m`
  itself is reduced mod `MOD` (as `mm`) before entering any product. Status: done.
- `problems/euler028/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler028/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::SumOfSquares](../../_terms.md#methodsumofsquares),
  [method::ArithmeticProgressionSum](../../_terms.md#methodarithmeticprogressionsum),
  [method::ModularInverseFermat](../../_terms.md#methodmodularinversefermat),
  [method::FastExponentiation](../../_terms.md#methodfastexponentiation),
  [method::IntegerOverflowAvoidance](../../_terms.md#methodintegeroverflowavoidance).
- Code: `problems/euler028/solution.cpp`; directory README: `problems/euler028/README.md`.
