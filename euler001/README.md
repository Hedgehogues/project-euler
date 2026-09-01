# euler001 — Multiples of 3 and 5

For each of `T` given values of `N`, sum every natural number below `N` that is a multiple of 3
or 5.

## Approach

Closed-form, `O(1)` per query — no loop over `[0, N)`:

- Sum of multiples of `k` below `N` is a sum of an arithmetic progression:
  `m = (N-1)/k` such multiples exist, and they sum to `k · m·(m+1)/2`.
- Numbers divisible by both 3 and 5 (i.e. by 15) get counted in both the "multiples of 3" and
  "multiples of 5" sums, so they're subtracted once (inclusion–exclusion):
  `answer(N) = sum_multiples(N,3) + sum_multiples(N,5) - sum_multiples(N,15)`

Status: **Accepted**, 100% on HackerRank.

## Spec

Full requirements, correctness criteria and links to the underlying math ideas:
[`memory-bank/specs/euler001.md`](../memory-bank/specs/euler001.md) (term:
[`memory-bank/_terms.md`](../memory-bank/_terms.md), `[euler::Problem001]`).

The two ideas behind the closed form are catalogued on their own, independent of this problem:
- **Inclusion–exclusion** — count/sum by condition, subtract what's double-counted.
- **Arithmetic progression sum** — a run of evenly-spaced numbers, added by one multiplication.

Both are described in [`memory-bank/specs/approaches.md`](../memory-bank/specs/approaches.md)
(`[approach::InclusionExclusion]`, `[approach::ArithmeticProgressionSum]`), each with a picture
showing the idea without the code:

| | |
|---|---|
| [![Bar model](../memory-bank/visualizations/build/bar-model.png)](../memory-bank/visualizations/build/bar-model.html) | [![Venn diagram](../memory-bank/visualizations/build/venn.png)](../memory-bank/visualizations/build/venn.html) |
| [![Gauss's trick](../memory-bank/visualizations/build/gauss-pairing.png)](../memory-bank/visualizations/build/gauss-pairing.html) | [![Skip counting](../memory-bank/visualizations/build/skip-counting.png)](../memory-bank/visualizations/build/skip-counting.html) |

(Skip counting shows the underlying notion "multiple of" itself — it isn't tied to either
approach above; see its own entry in `_terms.md`.)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
