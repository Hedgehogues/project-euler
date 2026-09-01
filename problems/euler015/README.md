# euler015 — Lattice paths

For each of `T` given pairs `(N, M)`, find how many routes lead from the top-left to the
bottom-right corner of an `N × M` grid, moving only right or down, modulo `10^9 + 7`.

## Approach

- The number of routes is the binomial coefficient `C(N+M, N)`.
- Precompute factorials and their modular inverses once, up to the largest `N+M` needed, using
  Fermat's little theorem for the inverses.
- Answer each query as `fact[N+M] · invFact[N] · invFact[M] mod (10^9+7)`.

Status: **Accepted**, 100% on HackerRank (submission 1410851744, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`2×2 → 6`, `3×2 → 10`) and 2006 randomized/edge cases
cross-checked against an independent Pascal's-triangle DP — exact match on every case.

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler015.md).

## The idea(s) behind it

**Lattice paths** — the route count across a grid is a binomial coefficient: choose which of the
`N+M` moves are "right."
[`[method::LatticePaths]`](../../memory-bank/_terms.md#methodlatticepaths)

[![Lattice paths](../../memory-bank/visualizations/build/lattice-paths.png)](../../memory-bank/visualizations/build/lattice-paths.html)

**Modular inverse via Fermat** — dividing by a factorial modulo a prime is the same as
multiplying by that factorial raised to `p-2`.
[`[method::ModularInverseFermat]`](../../memory-bank/_terms.md#methodmodularinversefermat)

[![Modular inverse via Fermat](../../memory-bank/visualizations/build/modular-inverse-fermat.png)](../../memory-bank/visualizations/build/modular-inverse-fermat.html)

**Fast exponentiation** — the `p-2` power inside the modular inverse is computed by repeated
squaring, not by multiplying in one factor at a time.
[`[method::FastExponentiation]`](../../memory-bank/_terms.md#methodfastexponentiation)

[![Fast exponentiation](../../memory-bank/visualizations/build/fast-exponentiation.png)](../../memory-bank/visualizations/build/fast-exponentiation.html)

Every factorial and inverse factorial is built once, up to the largest `N+M` across all queries —
the same [`[method::Precomputation]`](../../memory-bank/_terms.md#methodprecomputation) pattern
already catalogued.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
