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

Status: **Accepted**, 100% on HackerRank. Verified independently against a brute-force sum over
`n=0..n-1` on the official samples and boundary `N` (0, 1, 3, 5, 15, 16), including the `n=15`
case that would silently break a `<=` vs `<` off-by-one in `sum_multiples`.

## The ideas behind it

Three independently catalogued ideas — each recognizable in other problems on its own, not
specific to this one (full write-ups: [`memory-bank/_terms.md`](../memory-bank/_terms.md)):

| | |
|---|---|
| **Arithmetic progression sum** — a run of evenly-spaced numbers, added by one multiplication instead of one at a time. `[approach::ArithmeticProgressionSum]` [![Gauss's trick](../memory-bank/visualizations/build/gauss-pairing.png)](../memory-bank/visualizations/build/gauss-pairing.html) | **Inclusion–exclusion** — count/sum by condition, subtract what's double-counted. `[approach::InclusionExclusion]` [![Bar model](../memory-bank/visualizations/build/bar-model.png)](../memory-bank/visualizations/build/bar-model.html) |
| **Venn diagram** — the same overlap, seen as regions instead of arithmetic (a distinct idea from inclusion–exclusion, not just its picture — Venn invented it for logic, not counting). `[approach::VennDiagram]` [![Venn diagram](../memory-bank/visualizations/build/venn.png)](../memory-bank/visualizations/build/venn.html) | **Skip counting** — what "multiple of" actually looks like, hopping down a number line. Not tied to either approach above — a notion, not a technique. `[viz::SkipCounting]` [![Skip counting](../memory-bank/visualizations/build/skip-counting.png)](../memory-bank/visualizations/build/skip-counting.html) |

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
