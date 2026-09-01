---
status: draft
app: projecteuler
tags: [projecteuler, euler015, solution, draft]
---

# euler015 — Lattice paths

## Vision
For each of `T` given pairs `(N, M)` (`1 ≤ T ≤ 10^3`, `1 ≤ N, M ≤ 500`), count the routes across
an `N×M` grid moving only right/down, mod `10^9+7`. Building the route-count grid cell by cell for
every query independently costs `O(N·M)` per query and `O(T·N·M)` overall — at the worst case that
is `10^3 × 500 × 500 = 2.5×10^8`, and it still needs big-number handling since raw route counts
grow combinatorially. The binomial-coefficient closed form, with factorials and modular inverses
precomputed once, answers every query in `O(1)`.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses four catalogued methods
(`../../_terms.md`): [method::LatticePaths](../../_terms.md#methodlatticepaths),
[method::ModularInverseFermat](../../_terms.md#methodmodularinversefermat),
[method::FastExponentiation](../../_terms.md#methodfastexponentiation),
[method::Precomputation](../../_terms.md#methodprecomputation).

## Scope
**In scope:** `problems/euler015/solution.cpp` — the factorial/inverse-factorial precomputation,
the binomial coefficient formula, correctness criteria.

**Out of scope:** the visual explanation of any of the four methods (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::LatticePaths](../../_terms.md#methodlatticepaths), the route count for `(N,M)` is
`C(N+M, N) = (N+M)! / (N! · M!)`. Factorials up to the largest possible `N+M` (`1000`) are built
once ([method::Precomputation](../../_terms.md#methodprecomputation)). Their modular inverses are
built top-down, seeded by a single [method::ModularInverseFermat](../../_terms.md#methodmodularinversefermat)
call on the largest factorial (`fact[MAXN-1]^(MOD-2) mod MOD`, computed via
[method::FastExponentiation](../../_terms.md#methodfastexponentiation)) and then unwound
downward (`invFact[i-1] = invFact[i] · i mod MOD`) — cheaper than one Fermat inversion per
factorial. Each query is then answered by `fact[N+M] · invFact[N] · invFact[M] mod MOD`.

### Data
- Input: `T`, then `T` lines with `N M` (`1 ≤ N, M ≤ 500`).
- Output: `T` lines — `C(N+M, N) mod (10^9+7)`, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n, m)` MUST match an independent Pascal's-triangle DP across randomized and edge cases —
  **MUST-match-bruteforce** — criterion: zero mismatches. Status: done (HackerRank Accepted 100%,
  submission 1410851744, 2026-07-12; re-checked live on 2026-09-01: the official sample
  (`2×2→6, 3×2→10`) plus 2006 cases — 2000 random `(N,M)` pairs plus edge cases `(1,1), (500,500),
  (1,500), (500,1), (2,2), (2,3)` — against an independently written Pascal's-triangle DP mod
  `10^9+7`, exact match on every case).
- The modular inverse MUST be derived via Fermat's little theorem, never by searching for an x
  with `a·x ≡ 1` — **MUST-fermat-inverse** — criterion: `invFact[MAXN-1]` is computed via `power(...,
  MOD-2, MOD)`. Status: done.
- Factorials and inverse factorials MUST be built ONCE, not once per query —
  **MUST-precompute-once** — criterion: both arrays are filled before the query loop runs.
  Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  `power`'s multiplications use `__int128` for the intermediate product before reducing mod
  `10^9+7`, so no overflow of `long long`'s range occurs. Status: done.
- `problems/euler015/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler015/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::LatticePaths](../../_terms.md#methodlatticepaths),
  [method::ModularInverseFermat](../../_terms.md#methodmodularinversefermat),
  [method::FastExponentiation](../../_terms.md#methodfastexponentiation),
  [method::Precomputation](../../_terms.md#methodprecomputation).
- Code: `problems/euler015/solution.cpp`; directory README: `problems/euler015/README.md`.
