# euler020 — Factorial digit sum

For each of `T` given values of `N` (`0 ≤ N ≤ 1000`), find the sum of the digits of `N!`.

## Approach

- `1000!` has over 2500 digits — far beyond any native integer type — so the running factorial is
  kept as a digit array, multiplied by the next `n` each step with carries propagated, the same
  carry mechanism as digit-array addition, just with the per-column operation swapped to
  "multiply by `n`."
- Every step's digit sum is cached, so each query is a single array lookup.

Status: **Accepted**, 100% on HackerRank (submission 1410851762, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=3→6`, `N=6→9`) and 204 cases (every 5th `N` from 0 to
1000, plus the boundaries) cross-checked against Python's own arbitrary-precision `factorial` —
exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler020.md).

## The idea(s) behind it

**Big-integer arithmetic** — `N!` is kept as a digit array throughout; multiplying it by the next
`n` means multiplying every digit by `n` and carrying, the same mechanism as column addition, just
with a different per-column operation.
[`[method::BigIntegerArithmetic]`](../../memory-bank/_terms.md#methodbigintegerarithmetic)

[![Big-integer arithmetic](../../memory-bank/visualizations/build/big-integer-arithmetic.png)](../../memory-bank/visualizations/build/big-integer-arithmetic.html)

Every digit sum from `0!` up to `1000!` is built once, not once per query — the same
[`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation) pattern already
catalogued.

**In-place algorithm** — One digit array is multiplied in place, since only the last factorial is wanted.
[`[method::InPlaceAlgorithm]`](../../memory-bank/_terms.md#methodinplacealgorithm)

[![In-place algorithm](../../memory-bank/visualizations/build/in-place-algorithm.png)](../../memory-bank/visualizations/build/in-place-algorithm.html)

**Positional notation** — The factorial is held as a digit sequence and its digits are what is summed.
[`[method::PositionalNotation]`](../../memory-bank/_terms.md#methodpositionalnotation)

[![Positional notation](../../memory-bank/visualizations/build/positional-notation.png)](../../memory-bank/visualizations/build/positional-notation.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
