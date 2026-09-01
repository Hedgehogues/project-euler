# euler025 — N-digit Fibonacci number

For each of `T` given values of `N` (`2 ≤ N ≤ 5000`), find the index of the first Fibonacci number
with `N` digits.

## Approach

- Fibonacci numbers with thousands of digits are far beyond any native integer type — each new
  term is added as a digit array, the same carry mechanism as any big-integer addition.
- Walk the sequence forward, and the first time a new term's digit count exceeds every threshold
  reached so far, record the current index for every threshold up to that count at once.

Status: **Accepted**, 100% on HackerRank (submission 1410851918, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=3→12`, `N=4→17`) and 335 cases (every 3rd `N` from 2
to 1000, plus the boundaries) cross-checked against an independent Python big-integer Fibonacci
walk — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler025.md).

## The idea(s) behind it

**Big-integer arithmetic** — each new Fibonacci term is built by adding two digit arrays with
carries, the same mechanism as any other big-integer addition.
[`[method::BigIntegerArithmetic]`](../../memory-bank/_terms.md#methodbigintegerarithmetic)

[![Big-integer arithmetic](../../memory-bank/visualizations/build/big-integer-arithmetic.png)](../../memory-bank/visualizations/build/big-integer-arithmetic.html)

Every threshold's first-reaching index is recorded once during a single forward walk, not
recomputed per query — the same
[`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation) pattern already
catalogued.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
