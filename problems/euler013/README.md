# euler013 — Large sum

Given `N` 50-digit numbers, print the first ten digits of their sum.

## Approach

- No native integer type holds a 50-digit number, let alone the sum of up to 1000 of them — store
  the running sum as an array of digits (least-significant first) and add each new number to it
  column by column, propagating carries, exactly like addition on paper.
- Print the first ten digits of the final digit array.

Status: **Accepted**, 100% on HackerRank (submission 1410851704, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (5 given 50-digit numbers → `2728190129`) and 500
randomized cases (2–20 random 50-digit numbers each) cross-checked against an independent
decimal-string adder — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler013.md).

## The idea(s) behind it

**Big-integer arithmetic** — represent a number too large for any native type as a digit array,
and add column by column with carries, the same way as on paper.
[`[method::BigIntegerArithmetic]`](../../memory-bank/_terms.md#methodbigintegerarithmetic)

[![Big-integer arithmetic](../../memory-bank/visualizations/build/big-integer-arithmetic.png)](../../memory-bank/visualizations/build/big-integer-arithmetic.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
