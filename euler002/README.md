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

The lookup step is a standard, independently catalogued technique:

**Binary search** — narrow down to a value in a sorted list by repeatedly checking the middle
and discarding the half that can't contain the answer.

[![Binary search](../memory-bank/visualizations/build/binary-search.png)](../memory-bank/visualizations/build/binary-search.html)

(Building the list itself is a one-time setup step, not a separate technique — see
`[approach::PrecomputeAndBinarySearch]` in `_terms.md`.)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
