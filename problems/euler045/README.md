# euler045 — Triangular, pentagonal, and hexagonal

Triangle, pentagonal and hexagonal numbers are `T_n = n(n+1)/2`, `P_n = n(3n-1)/2`,
`H_n = n(2n-1)`. Given `N`, `a`, `b` (`a < b`, both in `{3, 5, 6}`), print every number below `N`
that is simultaneously of type `a` and type `b`, ascending.

## Approach

- Every hexagonal number is automatically triangular (`H_n = T_{2n-1}`), so the problem statement
  itself restricts real queries to `(a,b) = (3,5)` and `(5,6)` only — `(3,6)` never actually needs
  a triangularity filter, since listing hexagonal numbers directly already satisfies it.
- For `(3,5)`: generate pentagonal numbers `P_n` below `N` directly, keep the ones that are also
  triangular.
- For `(5,6)`: generate hexagonal numbers `H_n` below `N` directly, keep the ones that are also
  pentagonal.
- Both membership tests invert their respective closed form via the quadratic formula, using an
  exact integer square root.

Status: **Accepted**, 100% on HackerRank (submission 1410853239, 2026-07-13, `cpp20`). Re-verified
live on 2026-09-01: matches both official samples (`N=10000,a=3,b=5 → 1,210` and
`N=100000,a=5,b=6 → 1,40755`), reproduces the classic Project Euler #45 sequence — the
triangular-pentagonal-hexagonal chain `1, 40755, 1533776805` for `(5,6)` and the full
triangular-pentagonal sequence `1, 210, 40755, 7906276, 1533776805, 297544793910, 57722156241751`
for `(3,5)` up to `N=2×10^14` (matching OEIS A014979/A046180 term-for-term) — and cross-checked
against an independent Python re-implementation of the same formula-based check on both samples,
exact match.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler045.md).

## The idea(s) behind it

**Quadratic formula** — testing whether a number is triangular or pentagonal inverts its closed
form via the discriminant, the same technique used in euler042 and euler044.
[`[method::QuadraticFormula]`](../../memory-bank/_terms.md#methodquadraticformula)

[![Quadratic formula](../../memory-bank/visualizations/build/quadratic-formula.png)](../../memory-bank/visualizations/build/quadratic-formula.html)

**Binary search** — the discriminant's exact integer square root is found by binary search, not
floating-point `sqrt`.
[`[method::BinarySearch]`](../../memory-bank/_terms.md#methodbinarysearch)

[![Binary search](../../memory-bank/visualizations/build/binary-search.png)](../../memory-bank/visualizations/build/binary-search.html)

**Brute-force search** — the sparser sequence (`P_n` for `(3,5)`, `H_n` for `(5,6)`) is generated
directly term by term until it reaches `N`, filtered against the other membership test.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
