# euler005 — Smallest multiple

For each of `T` given values of `N` (`1 ≤ N ≤ 40`), find the smallest positive number that is
evenly divisible by every number from `1` to `N`.

## Approach

Fold the least common multiple across the range one number at a time, using the Euclidean
algorithm to keep each step cheap and exact:

- Start with `lcm = 1`.
- For each `i` from `2` to `N`, update `lcm = lcm / gcd(lcm, i) * i` — the `gcd` (via the Euclidean
  algorithm) tells exactly how much of `i` is already covered by the running `lcm`, so only the
  uncovered part gets multiplied in. Dividing before multiplying keeps the running value as small
  as it can be at every step.

Status: **Accepted**, 100% on HackerRank (submission 1410850883, 2026-07-12). Verified
independently against a fresh, differently-implemented computation (`math.lcm`, folded the same
way) across the ENTIRE valid range `N = 1..40` — exact match on every value, including the largest
(`lcm(1..40) = 5342931457063200`, well within 64-bit range).

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler005.md).

## The ideas behind it

Two catalogued ideas — one is the mechanism, the other is what gets built with it (full write-ups:
[`memory-bank/_terms.md`](../../memory-bank/_terms.md)):

**Euclidean algorithm** — find the greatest common divisor of two numbers by repeatedly replacing
the larger one with the remainder of dividing it by the smaller. [`[method::EuclideanAlgorithm]`](../../memory-bank/_terms.md#methodeuclideanalgorithm)

[![Euclidean algorithm](../../memory-bank/visualizations/build/euclidean-algorithm.png)](../../memory-bank/visualizations/build/euclidean-algorithm.html)

**Least common multiple via GCD** — build the smallest number divisible by a whole list, one
number at a time, using the GCD to avoid ever overcounting shared factors. [`[method::LCMViaGCD]`](../../memory-bank/_terms.md#methodlcmviagcd)
— no picture of its own; this idea is what you build using the Euclidean algorithm's result, not a
separate thing to draw.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
