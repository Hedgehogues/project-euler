# euler009 — Special Pythagorean triplet

For each given `N`, find natural numbers `a < b < c` with `a + b + c = N` and `a² + b² = c²`, and
report the maximum possible `a·b·c` among all such triplets (`-1` if none exists).

## Approach

- Substitute `c = N - a - b` into `a² + b² = c²` and solve for `b` in terms of `a` and `N`:
  `b = N(N - 2a) / (2(N - a))`.
- Scan `a` from `1` while `3a < N` (forced by `a < b < c`), compute `b` directly from the formula
  (only when it comes out as a whole number, `b > a`, and the derived `c > b`), and keep the best
  `a·b·c`.
- This turns a two-variable search into a single loop over `a` — no nested search over `b` needed.

Status: **Accepted**, 100% on HackerRank (submission 1410851669, 2026-07-12). Re-verified live on
2026-09-01: matches the official sample (`N=12 → 60`, `N=4 → -1`).

Full requirements and acceptance criteria: [spec.md](../../memory-bank/specs/tasks/euler009.md).

## The idea(s) behind it

None of this repository's catalogued methods apply — solving the second equation for `b` once
`c` is substituted out is a one-off algebraic manipulation specific to this problem's two
equations, not a general, independently reusable technique.

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
