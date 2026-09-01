# euler004 — Largest palindrome product

For each of `T` given values of `N` (`101101 < N < 1000000`), find the largest palindrome, made
from the product of two 3-digit numbers, that is strictly less than `N`.

## Approach

Build the list once, then look each query up — no work repeated across queries:

- Generate every product of two 3-digit numbers once, up front, keep only the palindromic ones,
  and sort the (deduplicated) list. There are only a few hundred such palindromes, so the list is
  short regardless of how many queries follow.
- For each query, binary-search (`lower_bound`) the precomputed list for the first entry `≥ N`,
  then step back one — the entry just before it is the largest palindrome strictly below `N`.

Status: **Accepted**, 100% on HackerRank (submission 1410850869, 2026-07-12). Verified
independently against a fresh brute-force scan (every product of two 3-digit numbers, filtered for
palindromes) on both official samples plus 300+ random `N` across the real constraint range
(`101102..999999`) — exact match throughout.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler004.md).

## The ideas behind it

Two independently catalogued ideas, used together — not one (full write-ups:
[`memory-bank/_terms.md`](../../memory-bank/_terms.md)):

**Precomputation** — build whatever doesn't depend on the query once, before answering any
query, instead of redoing that work on every single one. [`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation)

[![Precomputation](../../memory-bank/visualizations/build/precomputation.png)](../../memory-bank/visualizations/build/precomputation.html)

**Binary search** — narrow down to a value in a sorted list by repeatedly checking the middle
and discarding the half that can't contain the answer. [`[method::BinarySearch]`](../../memory-bank/_terms.md#methodbinarysearch)

[![Binary search](../../memory-bank/visualizations/build/binary-search.png)](../../memory-bank/visualizations/build/binary-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
