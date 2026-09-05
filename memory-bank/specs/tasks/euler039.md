---
status: draft
app: projecteuler
tags: [projecteuler, euler039, solution, draft]
---

# euler039 — Integer right triangles

## Vision
For each of `T` (up to `10^5`) given `N` (up to `5*10^6`), find the perimeter `p <= N` maximising
the count of integer right triangles with that perimeter. Checking every `(a, b, c)` triple
directly per query is infeasible at this scale; instead, every right triangle up to the global
limit is generated once via Euclid's formula and its multiples, folded into a per-perimeter count,
and the answer to any `N` becomes a single lookup into a precomputed running-best table.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses three catalogued methods
(`../../_terms.md`): [method::EuclidsFormula](../../_terms.md#methodeuclidsformula) (generating
every primitive right triangle up to the limit),
[method::SievingOverMultiples](../../_terms.md#methodsievingovermultiples) (crediting every
multiple of a found primitive perimeter), [method::Precomputation](../../_terms.md#methodprecomputation)
(building the whole count/best table once, independent of any query), and
[method::PrefixSum](../../_terms.md#methodprefixsum) (the running-maximum sweep filling the
best-perimeter table).

## Scope
**In scope:** `problems/euler039/solution.cpp` — the triple enumeration, the counting sieve, the
running-best table, correctness criteria.

**Out of scope:** the visual explanation of any method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For every `m` with `2*m*(m+1) <= MAXP` (`MAXP = 5*10^6`) and every `n < m` with `(m-n)` odd and
`gcd(m,n)=1` ([method::EuclidsFormula](../../_terms.md#methodeuclidsformula)), compute the
primitive perimeter `2m(m+n)`; if it exceeds `MAXP`, stop early (increasing `n` only grows the
perimeter). For every multiple of that perimeter up to `MAXP`
([method::SievingOverMultiples](../../_terms.md#methodsievingovermultiples)), increment
`count[multiple]`. This whole pass happens once, before any query is read
([method::Precomputation](../../_terms.md#methodprecomputation)). A single ascending sweep over
`count[1..MAXP]` then fills `bestP[p]` with the smallest perimeter `<= p` having the highest count
so far ([method::PrefixSum](../../_terms.md#methodprefixsum), running-maximum instance, tie-broken
to the earlier perimeter by updating only on a strictly greater count). Each of the `T` queries is
then answered by one read, `bestP[N]`.

### Data
- Input: `T`, then `T` lines with `N`.
- Output: `T` lines — `bestP[N]` per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`T=2, N=12/80` → `12, 60`) —
  **MUST-match-sample** — criterion: zero difference against the given sample. Status: done
  (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #39 worked example (`N=120` → `120`, the
  perimeter with exactly the stated three solutions `{20,48,52}, {24,45,51}, {30,40,50}`) —
  **MUST-match-original-pe39** — criterion: exact match. Status: done (re-run live 2026-09-01,
  and cross-checked against an independent Python brute-force enumerating every `a<=b<LIMIT` and
  testing `a²+b²` for a perfect square, on `N=12,80,120,150,300,500` — exact match on every case).
- The primitive-triple enumeration MUST filter by both `gcd(m,n)=1` and `(m-n)` odd — not either
  alone — **MUST-primitive-filter-both** — criterion: both conditions present in the inner loop
  guard (`(m-n)%2==0 → skip`, `gcd(m,n)!=1 → skip`). Status: done.
- The counting sweep MUST credit every multiple of a found primitive perimeter, not only the
  perimeter itself — **MUST-credit-multiples** — criterion: the inner `for (p = perimeter; p <=
  MAXP; p += perimeter)` loop is present and unconditional. Status: done.
- The running-best sweep MUST tie-break to the SMALLEST perimeter on equal counts —
  **MUST-tiebreak-smallest** — criterion: `bestP` is only overwritten on `count[p] >
  curBestCount` (strict), never on `>=`, so an earlier (smaller) perimeter with an equal count is
  kept. Status: done.
- `problems/euler039/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler039/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (`T`, then `T` lines of `N`; one answer per line) —
  **MUST-io-format**. Status: done.

## Links
- Methods: [method::EuclidsFormula](../../_terms.md#methodeuclidsformula),
  [method::SievingOverMultiples](../../_terms.md#methodsievingovermultiples),
  [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::PrefixSum](../../_terms.md#methodprefixsum).
- Code: `problems/euler039/solution.cpp`; directory README: `problems/euler039/README.md`.
