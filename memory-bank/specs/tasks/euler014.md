---
status: draft
app: projecteuler
tags: [projecteuler, euler014, solution, draft]
---

# euler014 — Longest Collatz sequence

## Vision
For each of `T` given values of `N` (`1 ≤ T ≤ 10^4`, `1 ≤ N ≤ 5×10^6`), find the starting number
below `N` with the longest Collatz chain. Walking every starting number's chain fully and
independently, for every query, would repeat huge overlapping stretches of chain — most numbers'
chains merge into a shared tail quickly (e.g. every even chain eventually meets the one below it
via `n/2`). Stopping a chain walk as soon as it reaches an already-known length, and filling in
every number visited along the way, means each edge of the whole chain graph is walked once no
matter how many queries or starting points share it.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses one catalogued method
(`../../_terms.md`): [method::Memoization](../../_terms.md#methodmemoization).

## Scope
**In scope:** `problems/euler014/solution.cpp` — the memoized chain walk, the running-best
threshold table, correctness criteria.

**Out of scope:** the visual explanation of the method (the catalog, not this task);
repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Per [method::Memoization](../../_terms.md#methodmemoization), `length[i]` caches the Collatz chain
length starting at `i`. For each `i` from `2` upward, the code follows the chain (recording visited
numbers in `path`) until it reaches `1` or a number whose length is already cached, then walks
`path` backward assigning lengths built on that base — so a chain segment already covered by an
earlier starting number is read from the cache, not re-walked. A second array, `bestN`, tracks
which starting number below each threshold has produced the longest chain seen so far while
processing numbers in increasing order (monotonic in the threshold, so one forward pass fills
every possible query answer).

### Data
- Input: `T`, then `T` lines with `N` (`1 ≤ N ≤ 5×10^6`).
- Output: `T` lines — the starting number below `N` with the longest Collatz chain.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent memoized-recursion implementation across `N = 1..200000` —
  **MUST-match-bruteforce** — criterion: zero difference across all 200000 values. Status: done
  (HackerRank Accepted 100%, submission 1410851736, 2026-07-12; re-checked live on 2026-09-01: the
  official sample (`N=10→9, N=15→9, N=20→19`) plus the range `N=1..200000` against an independently
  written recursive memoized solver, exact match on every value).
- A chain walk MUST stop as soon as it reaches a number whose length is already cached, never
  continuing past it — **MUST-stop-on-cache-hit** — criterion: the `while` loop's condition
  includes `length[n] == 0` for `n` within the cached array's range. Status: done.
- Every intermediate and final value MUST fit in the type used — **MUST-no-overflow** — criterion:
  odd steps compute `3n+1` on numbers up to `5×10^6`, staying under `1.6×10^7`, comfortably inside
  the `long long` used for the chain walk. Status: done.
- `problems/euler014/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler014/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::Memoization](../../_terms.md#methodmemoization).
- Code: `problems/euler014/solution.cpp`; directory README: `problems/euler014/README.md`.
