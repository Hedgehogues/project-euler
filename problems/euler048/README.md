# euler048 — Self powers

Find the last ten digits of `1¹ + 2² + 3³ + ... + N^N`, for `N` up to `2×10^6`.

## Approach

- Each term `i^i` is computed by fast exponentiation, reducing modulo `10^10` at every
  multiplication so the intermediate values never grow past what fits safely in a 64-bit product
  (via `__int128`).
- Accumulate the sum modulo `10^10` as each term is added.
- Print the running total directly — the note that leading zeros are not needed matches C++
  printing an integer with none.

Status: **Accepted**, 100% on HackerRank (submission 1410853261, 2026-07-13, `cpp20`). Re-verified
live on 2026-09-01: matches the official sample (`N=10 → 405071317`, from the given full value
`10405071317`) and reproduces the classic Project Euler #48 answer (`N=1000 → 9110846700`), both
cross-checked against exact (unmodded) Python big-integer sums — exact match on both.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler048.md).

## The idea(s) behind it

**Fast exponentiation** — each `i^i` is computed by repeated squaring instead of `i` multiplications.
[`[method::FastExponentiation]`](../../memory-bank/_terms.md#methodfastexponentiation)

[![Fast exponentiation](../../memory-bank/visualizations/build/fast-exponentiation.png)](../../memory-bank/visualizations/build/fast-exponentiation.html)

**Modular arithmetic** — every multiplication (inside the exponentiation and in the running sum) is
reduced modulo `10^10` immediately, since only the last ten digits are ever wanted.
[`[method::ModularArithmetic]`](../../memory-bank/_terms.md#methodmodulararithmetic)

[![Modular arithmetic](../../memory-bank/visualizations/build/modular-arithmetic.png)](../../memory-bank/visualizations/build/modular-arithmetic.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
