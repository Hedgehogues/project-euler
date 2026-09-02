---
status: draft
app: projecteuler
tags: [projecteuler, euler022, solution, draft]
---

# euler022 — Names scores

## Vision
Given `N` names (`N ≤ 5200`) and `Q` queried words (`Q ≤ 100`), sort the names alphabetically and
report each queried name's score (its 1-based alphabetical position times its letters' summed
alphabet values). Sorting `N` names costs `O(N log N)`, and scoring each is `O(length)` — both
already fast enough at these sizes that no further technique is needed; the cost of naively
re-scanning the full name list per query (rather than caching scores in a lookup table) is the
only real inefficiency worth avoiding, and a single hash map removes it.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses no catalogued method
(`../../_terms.md`) — sorting and direct scoring are already the whole computation; see the
Vision, [method::LookupTable](../../_terms.md#methodlookuptable) (the scores are answered from a dictionary keyed by the name itself).

## Scope
**In scope:** `problems/euler022/solution.cpp` — the sort, the scoring, the lookup table,
correctness criteria.

**Out of scope:** repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
All `N` names are read, sorted alphabetically, and each is scored as
`(sum of letter values) × (1-based position)` in the sorted order; every name's score is stored in
a hash map keyed by the name itself. Each of the `Q` queries is then answered by a direct map
lookup, not a re-scan of the name list.

### Data
- Input: `N`, then `N` names, then `Q`, then `Q` queried words.
- Output: `Q` lines — each queried word's score.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(names, query)` MUST match the official sample — **MUST-match-sample** — criterion:
  matches HackerRank's given sample exactly. Status: done (HackerRank Accepted 100%, submission
  1410851776, 2026-07-12; re-checked live on 2026-09-01: the official sample list scores
  `PAMELA` as `240`, exact match).
- Every name's score MUST be computed from its position in the SORTED order, not its input order
  — **MUST-sorted-position** — criterion: `score[names[i]]` is assigned after `std::sort`, using
  the post-sort index `i+1`. Status: done.
- Every query MUST be answered by a lookup, not a re-scan of the name list —
  **MUST-lookup-not-rescan** — criterion: the query loop reads `score[word]` directly from the
  `unordered_map`. Status: done.
- `problems/euler022/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler022/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: none,
  [method::LookupTable](../../_terms.md#methodlookuptable).
- Code: `problems/euler022/solution.cpp`; directory README: `problems/euler022/README.md`.
