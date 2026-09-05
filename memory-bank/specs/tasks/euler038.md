---
status: draft
app: projecteuler
tags: [projecteuler, euler038, solution, draft]
---

# euler038 — Pandigital multiples

## Vision
Given `N` (up to `10^5`) and `K` (8 or 9), find every multiplier `m < N` whose concatenated product
with `(1, 2, 3, ...)` is exactly `K`-pandigital. The constraint `N <= 10^5` keeps a direct scan of
every candidate cheap — the naive check itself (build the concatenation, verify pandigitality) is
already the intended approach; the only thing that must not be gotten wrong is the pandigitality
test itself (length, range, and no-repeat all three, not just "the digits look right").

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch) (trying
every multiplier below `N` directly) and
[method::PandigitalCheck](../../_terms.md#methodpandigitalcheck) (verifying the built concatenation
is exactly `K`-pandigital via a presence array).

## Scope
**In scope:** `problems/euler038/solution.cpp` — the enumeration, the pandigitality check,
correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For each `m` in `2..N-1` ([method::BruteForceSearch](../../_terms.md#methodbruteforcesearch)),
build the string `concat(m*1) + concat(m*2) + ...`, stopping as soon as its length reaches `K`.
Verify it is `K`-pandigital ([method::PandigitalCheck](../../_terms.md#methodpandigitalcheck)): the
string's length must equal `K` exactly, and a presence array of size `K+1` must end with every
slot `1..K` marked exactly once, with no digit `0` or `> K` ever appearing. Collect every passing
`m`, sort ascending, print one per line.

### Data
- Input: one line, `N K`.
- Output: every valid `m < N`, ascending, one per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=100, K=8` → `18, 78`) —
  **MUST-match-sample** — criterion: zero difference against the given sample. Status: done
  (re-run live 2026-09-01: `printf "100 8\n" | ./solution` → `18` then `78`).
- The solution MUST reproduce the classic single Project Euler #38 answer at `K=9`
  (`N=10, K=9` → `9`, concatenated product `918273645`) — **MUST-match-original-pe38** —
  criterion: exact match against the historically known answer. Status: done (re-run live
  2026-09-01, and cross-checked against an independent Python re-implementation of the same
  brute-force enumeration on both `(100,8)` and `(10,9)` — exact match on both).
- `isPandigital` MUST reject a candidate whose length differs from `K`, whose digits fall outside
  `1..K`, or that repeats any digit — **MUST-pandigital-all-three-checks** — criterion: all three
  checks are present in the guard clause (`d < 1 || d > K || seen[d]`) plus the separate length
  check before scanning. Status: done.
- `problems/euler038/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler038/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (one line, `N K`; one answer per line, ascending) —
  **MUST-io-format**. Status: done.

## Links
- Methods: [method::BruteForceSearch](../../_terms.md#methodbruteforcesearch),
  [method::PandigitalCheck](../../_terms.md#methodpandigitalcheck).
- Code: `problems/euler038/solution.cpp`; directory README: `problems/euler038/README.md`.
