# euler024 — Lexicographic permutations

For each of `T` given values of `N` (`1 ≤ N ≤ 13!`), find the `N`th lexicographic permutation of
the letters `abcdefghijklm`.

## Approach

- `13! = 6,227,020,800` — far too many to list and count to.
- Build the permutation directly: with the 0-based index `N-1`, repeatedly divide by the
  factorial of the remaining pool size minus one; the quotient picks which letter comes next out
  of what's left, the remainder carries into the next, smaller round.

Status: **Accepted**, 100% on HackerRank (submission 1410851913, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=1 → abcdefghijklm`, `N=2 → abcdefghijkml`) and 717
cases (every 7th `N` up to 5000, plus `N=1` and `N=13!`) cross-checked against an independently
written Lehmer-code reconstruction — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler024.md).

## The idea(s) behind it

**Lehmer code** — the Nth permutation is built directly, one letter at a time, by dividing the
index by a shrinking factorial each round.
[`[method::LehmerCode]`](../../memory-bank/_terms.md#methodlehmercode)

[![Lehmer code](../../memory-bank/visualizations/build/lehmer-code.png)](../../memory-bank/visualizations/build/lehmer-code.html)

**Lookup table** — The factorials below the pool size are a small fixed table.
[`[method::LookupTable]`](../../memory-bank/_terms.md#methodlookuptable)

[![Lookup table](../../memory-bank/visualizations/build/lookup-table.png)](../../memory-bank/visualizations/build/lookup-table.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
