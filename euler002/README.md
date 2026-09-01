# euler002 — Even Fibonacci numbers

For each of `T` given values of `N`, sum the even-valued terms of the Fibonacci sequence that
don't exceed `N` (`N` up to `4·10^16`).

## Approach

Build the list once, then look each query up — no work repeated across queries:

- Generate the Fibonacci sequence once, up front, keeping only the even terms and a running
  (prefix) sum of them. Because Fibonacci numbers grow exponentially, this list is short — a few
  dozen entries cover every `N` up to `4·10^16`.
- For each query, binary-search (`upper_bound`) the precomputed list for the largest even term
  `≤ N`; its stored prefix sum is the answer.

Status: **Accepted**, 100% on HackerRank.

## Spec

Full requirements, correctness criteria and the link to the underlying technique:
[`memory-bank/specs/euler002.md`](../memory-bank/specs/euler002.md) (term:
[`memory-bank/_terms.md`](../memory-bank/_terms.md), `[euler::Problem002]`).

This is two independently catalogued ideas, used together — not one:

**Precomputation** — build whatever doesn't depend on the query once, before answering any
query, instead of redoing that work on every single one. (`[approach::Precomputation]` — no
picture of its own; there isn't a standard visual for "compute it ahead of time" the way there
is for a specific lookup.)

**Binary search** — narrow down to a value in a sorted list by repeatedly checking the middle
and discarding the half that can't contain the answer. (`[approach::BinarySearch]`.)

[![Binary search](../memory-bank/visualizations/build/binary-search.png)](../memory-bank/visualizations/build/binary-search.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
