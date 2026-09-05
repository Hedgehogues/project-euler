---
status: draft
app: projecteuler
tags: [projecteuler, euler042, solution, draft]
---

# euler042 — Coded triangle numbers

## Vision
For each of `T` (up to `10^5`) given integers up to `10^18`, determine whether it is a triangle
number `t_n = n(n+1)/2` and if so print `n`. The value `1+8t` needed by the inversion formula can
reach nearly `8×10^18`, past the 53 bits of exact integer precision a `double` provides — so the
square root must be computed as an exact integer (binary search), not via floating-point `sqrt`,
or a large legitimate triangle number could be missed or misreported by one.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::QuadraticFormula](../../_terms.md#methodquadraticformula) (inverting
`n(n+1)/2=t`) and [method::BinarySearch](../../_terms.md#methodbinarysearch) (the exact integer
square root of the discriminant).

## Scope
**In scope:** `problems/euler042/solution.cpp` — the inversion formula, the integer square root,
the acceptance checks, correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For each `t`, compute the discriminant `disc = 1+8t`
([method::QuadraticFormula](../../_terms.md#methodquadraticformula)), then find its integer square
root `s` by binary search over `mid*mid >= disc`
([method::BinarySearch](../../_terms.md#methodbinarysearch)), refining with a linear correction in
case the search's upper bound was too tight. If `s*s == disc` and `(s-1)` is even, `t` is the
`n = (s-1)/2`-th triangle number; otherwise it is not a triangle number and the answer is `-1`.

### Data
- Input: `T`, then `T` lines with one integer each.
- Output: `T` lines — `n` or `-1`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`2,3,55 → -1,2,10`) — **MUST-match-sample** —
  criterion: zero difference against the given sample. Status: done (re-run live 2026-09-01).
- The solution MUST agree with an independent computation (`math.isqrt`) on small, boundary and
  near-`10^18` values — **MUST-match-bruteforce** — criterion: cross-checked on `t ∈ {1, 2, 6, 10,
  21, 45, 999999999999999978, 1000000000000000000, 500000000500000000, 999999999999999999}` —
  exact match on every value, including the large triangular number `500000000500000000 →
  1000000000` and several large NON-triangular values correctly rejected. Status: done.
- The square root of the discriminant MUST be computed exactly (never via floating-point `sqrt`) —
  **MUST-exact-sqrt** — criterion: `solution.cpp` computes it by integer binary search
  (`mid*mid >= disc`) with a linear refinement pass, not `std::sqrt`. Status: done.
- `problems/euler042/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler042/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (`T`, then `T` lines of one integer; one answer per line) —
  **MUST-io-format**. Status: done.

## Links
- Methods: [method::QuadraticFormula](../../_terms.md#methodquadraticformula),
  [method::BinarySearch](../../_terms.md#methodbinarysearch).
- Code: `problems/euler042/solution.cpp`; directory README: `problems/euler042/README.md`.
