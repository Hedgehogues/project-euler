---
status: draft
app: projecteuler
tags: [projecteuler, euler004, solution, draft]
---

# euler004 — Largest palindrome product

## Vision
For each of `T` given values of `N` (`101101 < N < 1000000`, `T ≤ 100`), find the largest
palindrome, made from the product of two 3-digit numbers, that is strictly less than `N`. The set
of such palindromes never depends on `N` — recomputing it by scanning all ~500,000 pairs of
3-digit numbers on every one of up to 100 queries repeats identical work for nothing and risks
exceeding the time limit for no reason; the set only needs to be built once.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Uses these catalogued methods used
together, not one (`../../_terms.md`): [method::Precomputation](../../_terms.md#methodprecomputation),
[method::BinarySearch](../../_terms.md#methodbinarysearch), [method::SymmetryBreaking](../../_terms.md#methodsymmetrybreaking) (the inner factor starts at the outer one, so each unordered pair is formed once), [method::PositionalNotation](../../_terms.md#methodpositionalnotation) (a palindrome is a statement about the digits, checked on the digit sequence itself), and [method::LazyInitialization](../../_terms.md#methodlazyinitialization) (the table of palindromic products is built on the first query that needs it, not at the start).

## Scope
**In scope:** `problems/euler004/solution.cpp` — the model, the algorithm, the complexity argument,
correctness criteria.

**Out of scope:** the visual explanation of binary search as a general technique (the catalog, not
this task); repository-wide rules (I/O format, ASCII-only — see the root README).

## Architecture

### Overview (prose)
Every product of two 3-digit numbers (`100..999` × `100..999`) is generated exactly once, filtered
to the palindromic ones, deduplicated, and sorted
([method::Precomputation](../../_terms.md#methodprecomputation)) — there are only a few hundred
such palindromes regardless of how many queries follow. For each query `N`, `lower_bound`
([method::BinarySearch](../../_terms.md#methodbinarysearch)) finds the first entry `≥ N` in that
list, and stepping back one entry gives the largest palindrome strictly less than `N` — exactly
what the problem asks for, not "at most `N`".

### Data
- Input: `T`, then `T` lines with `N` (`101101 < N < 1000000`).
- Output: `T` lines — the largest palindrome product of two 3-digit numbers `< N`, per line.

## Requirements
> Statement — acceptance criterion — status.

### MUST
- `solve(n)` MUST match a direct scan of every product of two 3-digit numbers, filtered for
  palindromes and for being `< n`, on both official samples and 300+ random `n` across the real
  constraint range — **MUST-match-bruteforce** — criterion: zero difference across the checked
  range. Status: done (HackerRank Accepted 100%, submission 1410850869, 2026-07-12; re-checked
  live on 2026-09-01: official samples `n=101110→101101`, `n=800000→793397`, plus 300 random `n`
  in `101102..999999`, exact match on all).
- The palindrome-product list MUST be built exactly once, before reading any query —
  **MUST-precompute-once** — criterion: the build loop sits outside the `while (t--)` query loop.
  Status: done.
- Each query's answer MUST be found by binary search (`lower_bound`) over the precomputed list, not
  by rescanning the pairs of 3-digit numbers — **MUST-binary-search-per-query** — criterion: the
  query loop contains no pair enumeration, only `lower_bound` and indexing. Status: done.
- The lookup MUST return the palindrome strictly LESS than `N`, not `≤ N` — **MUST-strict-below** —
  criterion: `lower_bound` (first entry `≥ N`) is followed by `prev(it)`, never used directly; a
  version using `upper_bound`+`prev` would silently include `N` itself when `N` happens to be a
  palindrome product, which the problem's own wording ("less than `N`") forbids. Status: done.
- Every product and every value in the list MUST fit safely in the type used — **MUST-no-overflow**
  — criterion: the largest possible product (`999×999=998001`) and the largest possible `N`
  (`<1000000`) both fit comfortably in a 32-bit `int`. Status: done.
- `problems/euler004/solution.cpp` MUST be pure ASCII — **MUST-ascii-only** — criterion:
  `grep -nP '[^\x00-\x7F]' problems/euler004/solution.cpp` is empty. Status: done.
- I/O MUST match HackerRank's format — **MUST-io-format**. Status: done.

## Links
- Methods: [method::Precomputation](../../_terms.md#methodprecomputation),
  [method::BinarySearch](../../_terms.md#methodbinarysearch),
  [method::SymmetryBreaking](../../_terms.md#methodsymmetrybreaking),
  [method::PositionalNotation](../../_terms.md#methodpositionalnotation),
  [method::LazyInitialization](../../_terms.md#methodlazyinitialization).
- Code: `problems/euler004/solution.cpp`; directory README: `problems/euler004/README.md`.
