---
status: draft
app: projecteuler
tags: [projecteuler, euler009, solution, draft]
---

# euler009 — Special Pythagorean triplet

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 3000`, `1 ≤ N ≤ 3000`), find `a < b < c` with
`a+b+c=N` and `a²+b²=c²`, maximizing `a·b·c`. A naive search over both `a` and `b` independently
costs up to `O(N²)` per query and `O(T·N²)` overall — at `T=N=3000` that is on the order of
`3000 × 3000² ≈ 2.7×10^10` operations, far past the time limit. Eliminating `c` and solving the
second equation for `b` directly turns the search into a single `O(N)` loop over `a` per query.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::VariableElimination](../../_terms.md#methodvariableelimination) — one equation is solved for an unknown and substituted away, dropping the search to a single loop.

## Scope
**In scope:** `problems/euler009/solution.cpp` — the substitution, the search over `a`,
correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
From `a+b+c=N`, `c = N-a-b`. Substituting into `a²+b²=c²` and solving for `b` gives
`b = N(N-2a) / (2(N-a))`. For each `a` from `1` while `3a < N` (the smallest possible `c` needs
`a<b<c`, so `3a<a+b+c=N`), the code evaluates the numerator and denominator directly, keeps `b`
only when the division is exact and `a<b<c`, and tracks the best `a·b·c` seen.

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 3000`).
- Output: `T` lines — the maximum `a·b·c`, or `-1` if no triplet exists.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent brute-force search (`a,b,c` all enumerated directly,
  checked against `a²+b²=c²` and `a+b+c=n`) across the ENTIRE valid range `n = 1..3000` —
  **MUST-match-bruteforce** — criterion: zero difference across all 3000 values. Status: done
  (HackerRank Accepted 100%, submission 1410851669, 2026-07-12; re-checked live on 2026-09-01:
  both official samples (`n=12→60`, `n=4→-1`) plus the full exhaustive range against an
  independently written O(n²) brute force, exact match on every value).
- `b` MUST be accepted only when the derived value is an exact integer division, not rounded —
  **MUST-exact-division** — criterion: the code checks `num % den != 0` before accepting. Status:
  done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  at `N=3000`, `num = N(N-2a)` stays under `N² = 9×10^6` and `a·b·c` stays under `N³/27 ≈
  1.2×10^9` at worst — both comfortably inside `long long`. Status: done.
- `problems/euler009/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler009/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::VariableElimination](../../_terms.md#methodvariableelimination).
- Code: `problems/euler009/solution.cpp`; directory README: `problems/euler009/README.md`.
