# euler006 — Sum square difference

For each of `T` given values of `N` (`1 ≤ N ≤ 10^4`), find the absolute difference between the
sum of the squares of the first `N` natural numbers and the square of their sum.

## Approach

Two closed-form formulas, no loop over `1..N`:

- The sum of the first `N` natural numbers is `N·(N+1)/2` — the plain arithmetic-progression sum.
- The sum of the first `N` squares is `N·(N+1)·(2N+1)/6` — a different, cubic closed form.
- The answer is `(sum)^2 − sumSquares`.

Status: **Accepted**, 100% on HackerRank (submission 1410850893, 2026-07-12). Verified
independently against both official samples (`N=3 → 22`, `N=10 → 2640`) and an exhaustive
brute-force check across the ENTIRE valid range `N = 1..10000` — exact match on every value.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler006.md).

## The ideas behind it

Two independently catalogued ideas — the linear sum and the sum of squares are genuinely
different, easily confused closed forms (full write-ups:
[`memory-bank/_terms.md`](../../memory-bank/_terms.md)):

**Sum of an arithmetic progression** — a run of evenly-spaced numbers, added by one
multiplication instead of one at a time. [`[method::ArithmeticProgressionSum]`](../../memory-bank/_terms.md#methodarithmeticprogressionsum)

[![Gauss's trick](../../memory-bank/visualizations/build/gauss-pairing.png)](../../memory-bank/visualizations/build/gauss-pairing.html)

**Sum of squares formula** — the sum of the first `N` squares has its own closed-form cubic
formula, visualized as stacked square layers (a square pyramidal number). [`[method::SumOfSquares]`](../../memory-bank/_terms.md#methodsumofsquares)

[![Sum of squares](../../memory-bank/visualizations/build/sum-of-squares.png)](../../memory-bank/visualizations/build/sum-of-squares.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
