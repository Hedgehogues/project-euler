---
status: draft
app: projecteuler
tags: [projecteuler, euler048, solution, draft]
---

# euler048 — Self powers

## Vision
Find the last ten digits of `sum_{i=1}^{N} i^i` for `N` up to `2×10^6`. The exact sum grows to
astronomically many digits (`N^N` alone for `N=2×10^6` vastly exceeds any fixed-width integer), so
every intermediate value must be reduced modulo `10^10` throughout — never computed exactly and
truncated at the end.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses two catalogued methods
(`../../_terms.md`): [method::FastExponentiation](../../_terms.md#methodfastexponentiation)
(computing each `i^i`) and [method::ModularArithmetic](../../_terms.md#methodmodulararithmetic)
(reducing every multiplication modulo `10^10`).

## Scope
**In scope:** `problems/euler048/solution.cpp` — the modular exponentiation, the running sum,
correctness criteria.

**Out of scope:** the visual explanation of either method (the catalog, not this task — see the
README's own table); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
For each `i` from 1 to `N`, `i^i mod 10^10` is computed by repeated squaring
([method::FastExponentiation](../../_terms.md#methodfastexponentiation)), with every
multiplication reduced modulo `10^10` immediately
([method::ModularArithmetic](../../_terms.md#methodmodulararithmetic), via `__int128` to hold the
intermediate product safely before the reduction). The running sum is likewise kept modulo `10^10`
throughout. The final value is printed as a plain integer, which naturally drops any leading
zeros.

### Data
- Input: one integer `N`.
- Output: one integer — the last ten digits of the sum (no leading zeros).

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The solution MUST match the official sample (`N=10 → 405071317`) — **MUST-match-sample** —
  criterion: zero difference against the given sample. Status: done (re-run live 2026-09-01).
- The solution MUST reproduce the classic Project Euler #48 answer (`N=1000 → 9110846700`) —
  **MUST-match-original-pe48** — criterion: exact match. Status: done (re-run live 2026-09-01,
  cross-checked against Python's exact big-integer `sum(i**i for i in range(1,N+1)) % 10**10` for
  both `N=10` and `N=1000` — exact match on both, including the full unmodded value for `N=10`
  matching the problem's own stated `10405071317`).
- Every multiplication inside the exponentiation and the running sum MUST be reduced modulo
  `10^10` immediately — **MUST-reduce-every-multiplication** — criterion: `mulmod` performs the
  reduction via `__int128`, and both `power`'s internal state and the accumulating `sum` are kept
  mod `10^10` at every step, never allowed to grow unmodded. Status: done.
- `problems/euler048/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler048/solution.cpp` is empty. Status: done (checked live).
- I/O MUST match HackerRank's format (a single integer `N`; one summed answer printed, no leading
  zeros) — **MUST-io-format**. Status: done.

## Links
- Methods: [method::FastExponentiation](../../_terms.md#methodfastexponentiation),
  [method::ModularArithmetic](../../_terms.md#methodmodulararithmetic).
- Code: `problems/euler048/solution.cpp`; directory README: `problems/euler048/README.md`.
