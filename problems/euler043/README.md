# euler043 — Sub-string divisibility

Given `N` (`3 ≤ N ≤ 9`), sum every `0` to `N` pandigital number (each digit `0..N` used exactly
once) whose 3-digit substrings starting at position 2 satisfy: `d_2d_3d_4` divisible by 2,
`d_3d_4d_5` by 3, `d_4d_5d_6` by 5, `d_5d_6d_7` by 7, `d_6d_7d_8` by 11, `d_7d_8d_9` by 13, and
`d_8d_9d_{10}` by 17 — as many of these rules as fit inside an `(N+1)`-digit number.

## Approach

- Generate every permutation of the digits `0..N` in lexicographic order.
- For each permutation, check as many of the (at most 7) substring-divisibility rules as its
  length actually admits, stopping at the first violation.
- Sum every permutation that passes all applicable rules.

Status: **Accepted**, 100% on HackerRank (submission 1410853218, 2026-07-13, `cpp20`). Re-verified
live on 2026-09-01: matches the official sample (`N=3 → 22212`), reproduces the classic Project
Euler #43 answer (`N=9 → 16695334890`), and cross-checked against an independent Python
permutation search for `N=3,4,5,6` — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler043.md).

## The idea(s) behind it

**Next permutation** — every permutation of the `N+1` digits is visited exactly once, in order.
[`[method::NextPermutation]`](../../memory-bank/_terms.md#methodnextpermutation)

[![Next permutation](../../memory-bank/visualizations/build/next-permutation.png)](../../memory-bank/visualizations/build/next-permutation.html)

**Brute-force search** — what the permutations feed is an exhaustive check: `N ≤ 9` bounds the
candidates to at most `10!` permutations, each tested by a handful of divisibility checks.
[`[method::BruteForceSearch]`](../../memory-bank/_terms.md#methodbruteforcesearch)

[![Brute-force search](../../memory-bank/visualizations/build/brute-force-search.png)](../../memory-bank/visualizations/build/brute-force-search.html)

**Positional notation** — each 3-digit substring is read as a number by place value
(`d·100 + d·10 + d`) before its divisibility is tested.
[`[method::PositionalNotation]`](../../memory-bank/_terms.md#methodpositionalnotation)

[![Positional notation](../../memory-bank/visualizations/build/positional-notation.png)](../../memory-bank/visualizations/build/positional-notation.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
