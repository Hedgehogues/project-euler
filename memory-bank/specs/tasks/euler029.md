---
status: draft
app: projecteuler
tags: [projecteuler, euler029, solution, draft]
---

# euler029 — Distinct powers

## Vision
Given `N` (`2 ≤ N ≤ 10^5`), count distinct values of `aᵇ` for `2 ≤ a,b ≤ N`. `Nᴺ` for `N=10^5` has
around half a million digits — computing or storing any actual power value, let alone hashing
`(N-1)² ≈ 10^10` of them into a set, is completely infeasible. The count must be derived from the
EXPONENTS alone: grouping bases by their primitive root turns the problem into counting distinct
values in a small set of integer products per primitive base, never touching an actual big
integer.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::Canonicalization](../../_terms.md#methodcanonicalization) — skipping
a base that is itself a power of a smaller, already-processed base is exactly picking one canonical
representative per equivalence class of bases. The exponent deduplication within a single
primitive base's own `k=2..maxK` sweep is specific to counting distinct powers, not a separately
catalogued technique.

## Scope
**In scope:** `problems/euler029/solution.cpp` — the primitive-base grouping, the exponent
deduplication, correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`isPower[a]` marks every perfect power of a smaller base as it is discovered, so the outer loop
over `a` only processes "primitive" bases (not themselves a power of anything smaller) — per
[method::Canonicalization](../../_terms.md#methodcanonicalization), each such primitive base is
the canonical representative of the equivalence class of bases that produce the same set of
exponent values, and every non-primitive base is skipped outright rather than reprocessed. For each
primitive `a`, `maxK` is the largest power of `a` still `≤ N`. The `b=2..N` case (`k=1`) always
contributes exactly `N-1` new exponent values. For `k=2..maxK`, an exponent `k·b` is only counted
if it exceeds `N` (anything `≤ N` necessarily duplicates some `k=1` exponent) AND has not already
been marked `reach` during this primitive base's processing; `reach` is cleared for exactly the
indices touched, so the same array is reused across every primitive base without a fresh
allocation each time.

### Data
- Input: one integer `N` (`2 ≤ N ≤ 10^5`).
- Output: one line — the count of distinct `aᵇ` values.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent brute-force set of the actual `aᵇ` values across `N =
  2..200`, AND the classic known answer at `N=100` — **MUST-match-bruteforce** — criterion: zero
  mismatches. Status: done (HackerRank Accepted 100%, submission 1410851995, 2026-07-12;
  re-checked live on 2026-09-01: the official sample (`N=5→15`) plus `N=2..200` against an
  independently written Python big-integer set-based brute force, exact match on every case; also
  confirmed the well-known original Project Euler #29 answer at `N=100`, `9183`).
- A base `a` that is a perfect power of a smaller already-processed base MUST be skipped entirely
  — **MUST-skip-non-primitive** — criterion: `if (isPower[a]) continue;` runs before any other
  work for that `a`. Status: done.
- An exponent `k·b` at or below `N` MUST NOT be counted for `k ≥ 2` — **MUST-skip-duplicate-exponents**
  — criterion: the `if (idx > n && !reach[idx])` guard excludes `idx ≤ n`. Status: done.
- The `reach` array MUST be restored to all-zero after each primitive base's processing, so it can
  be reused for the next one — **MUST-clear-reach** — criterion: every index pushed to `touched`
  is reset to `0` in the cleanup loop immediately after. Status: done.
- `problems/euler029/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler029/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::Canonicalization](../../_terms.md#methodcanonicalization).
- Code: `problems/euler029/solution.cpp`; directory README: `problems/euler029/README.md`.
