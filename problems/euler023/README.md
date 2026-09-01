# euler023 — Non-abundant sums

For each of `T` given values of `N`, report whether `N` can be written as the sum of two abundant
numbers (numbers whose proper divisors sum to more than the number itself).

## Approach

- It is a known fact that every integer above `28123` can be written as the sum of two abundant
  numbers, so only `N ≤ 28123` needs to be checked directly.
- Accumulate every number's divisor sum up to `28123` in one pass (the same "touch every
  multiple" mechanism as the Sieve of Eratosthenes, summing instead of marking), collect the
  abundant numbers, and mark every reachable pairwise sum.
- Answer each query with a direct lookup: `YES` above `28123`, otherwise the marked-sum table.

Status: **Accepted**, 100% on HackerRank (submission 1410851880, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`24 → NO`, `49 → NO`) and an exhaustive cross-check
(independent trial-division divisor sum) across `N = 0..30000` — exact match on every value.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler023.md).

## The idea(s) behind it

None of this repository's catalogued methods apply on their own here — the divisor-sum
accumulation is the same uncatalogued "sieve, but summing" variant used in
[euler021](../euler021/README.md) (no encyclopedic source found for it specifically, only
blogs/teaching sites), and every abundant number's divisor sum is still built once for every
query, the same [`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation)
pattern already catalogued.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
