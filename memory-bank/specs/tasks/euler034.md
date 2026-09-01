---
status: draft
app: projecteuler
tags: [projecteuler, euler034, solution, draft]
---

# euler034 — Digit factorials

## Vision
Given `N` (`10 ≤ N ≤ 10^5`), sum every number below `N` that DIVIDES the sum of the factorials of
its own digits — not "equals" it, the condition the original Project Euler #34 asks for; the
fetched HackerRank problem text and the official sample (`N=20 → 19`) both confirm the divisibility
reading (`19`'s digit-factorial sum is `1! + 9! = 362881`, and `362881 / 19` is exact). At
`N ≤ 10^5` a direct scan checking every number's digit-factorial sum is already fast enough — no
further technique is needed.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses no catalogued method
(`../../_terms.md`) — the direct digit-factorial-sum check is already the whole computation; see
the Vision.

## Scope
**In scope:** `problems/euler034/solution.cpp` — the digit-factorial precomputation, the direct
scan, correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
`fact[0..9]` is precomputed once. For every `num` from `10` to `N-1`, the code sums `fact[digit]`
over `num`'s decimal digits and adds `num` to the running total when that sum is divisible by
`num` (`s % num == 0`). A defensive cap (`SAFE_CAP = 3,000,000`) bounds the scan even if `N` were
far larger than its actual constraint allows.

### Data
- Input: one integer `N` (`10 ≤ N ≤ 10^5`).
- Output: one line — the sum of every qualifying number below `N`.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match an independent Python search using the DIVIDES condition (not the
  original Project Euler's EQUALS condition) — **MUST-match-bruteforce** — criterion: zero
  mismatches. Status: done (HackerRank Accepted 100%, submission 1410852057, 2026-07-12;
  re-checked live on 2026-09-01: the official sample (`N=20→19`) plus `N=100000` against an
  independently written Python search using `sum % n == 0`, exact match on both, `19` and
  `99752`).
- The condition checked MUST be divisibility (`sum % num == 0`), never equality
  (`sum == num`) — **MUST-divisibility-not-equality** — criterion: verified directly against
  `problems/euler034/solution.cpp`'s own comparison operator, matching the fetched HackerRank
  problem statement's wording ("divide the sum of the factorial of their digits"). Status: done —
  this is the exact point where a memory-based assumption (the famous original PE34 answer,
  `40730`) would have been WRONG; the live-fetched statement and sample were checked instead.
- Digit factorials MUST be looked up from a precomputed table, not recomputed per digit —
  **MUST-precompute-once** — criterion: `fact[0..9]` is built once, before the scan. Status:
  done.
- `problems/euler034/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler034/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: none.
- Code: `problems/euler034/solution.cpp`; directory README: `problems/euler034/README.md`.
