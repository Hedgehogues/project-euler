# euler032 — Pandigital products

Find the sum of every product `c` for which some split of the digits `1..N` into three groups
`a`, `b`, `c` (concatenated, `a × b = c`) uses each digit exactly once.

## Approach

- Generate every permutation of the digits `1..N` in lexicographic order, one at a time.
- For each permutation, try every way of splitting it into three contiguous pieces `a`, `b`, `c`
  and check `a × b == c`.
- Collect every valid `c` into a set (so a `c` reachable more than one way is only counted once)
  and sum it.

Status: **Accepted**, 100% on HackerRank (submission 1410852022, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=4 → 12`), the classic known answer at `N=9` (`45228`,
the original Project Euler #32 answer), and `N=4..7` cross-checked against an independent Python
permutation search — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler032.md).

## The idea(s) behind it

**Next permutation** — every permutation of the `N` digits is visited exactly once, in order, via
repeated in-place transformation, not by any other listing method.
[`[method::NextPermutation]`](../../memory-bank/_terms.md#methodnextpermutation)

[![Next permutation](../../memory-bank/visualizations/build/next-permutation.png)](../../memory-bank/visualizations/build/next-permutation.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
