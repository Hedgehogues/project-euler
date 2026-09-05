# euler042 — Coded triangle numbers

The `n`-th triangle number is `t_n = n(n+1)/2`. For each of `T` given integers (up to `10^18`),
print the `n` for which it equals `t_n`, or `-1` if it is not a triangle number at all.

## Approach

- Invert `n(n+1)/2 = t` via the quadratic formula: `n = (-1 + sqrt(1+8t)) / 2`.
- Compute the integer square root of `1+8t` by binary search (not floating-point `sqrt`, which
  loses precision at this size — `1+8t` can reach nearly `8×10^18`).
- Accept only when the square root is exact AND the resulting numerator is evenly divisible by 2;
  otherwise the given number is not a triangle number.

Status: **Accepted**, 100% on HackerRank (submission 1410853197, 2026-07-13, `cpp20`). Re-verified
live on 2026-09-01: matches the official sample (`2,3,55 → -1,2,10`) and cross-checked against an
independent Python computation (`math.isqrt`) on boundary and large values (`1`, `45`,
`500000000500000000` → `1000000000`, and near-`10^18` non-triangular values correctly rejected) —
exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler042.md).

## The idea(s) behind it

**Quadratic formula** — inverting `n(n+1)/2 = t` to recover `n` directly from the discriminant,
instead of searching for it.
[`[method::QuadraticFormula]`](../../memory-bank/_terms.md#methodquadraticformula)

[![Quadratic formula](../../memory-bank/visualizations/build/quadratic-formula.png)](../../memory-bank/visualizations/build/quadratic-formula.html)

**Binary search** — the discriminant's exact integer square root (needed because `1+8t` can exceed
what a `double` represents precisely) is found by binary search over the monotonic sequence of
squares, not by floating-point `sqrt`.
[`[method::BinarySearch]`](../../memory-bank/_terms.md#methodbinarysearch)

[![Binary search](../../memory-bank/visualizations/build/binary-search.png)](../../memory-bank/visualizations/build/binary-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
