# euler003 — Largest prime factor

For each of `T` given values of `N`, find the largest prime factor of `N`.

## Approach

Trial division, but shrinking as it goes:

- Strip out every factor of 2 first (divide while even).
- Then try odd divisors `3, 5, 7, ...`, dividing each one out of `N` as many times as it fits.
- Stop as soon as the divisor squared exceeds what's *left* of `N` — not the original `N`. Every
  factor pulled out shrinks the remaining number, so this bound keeps falling as you go; numbers
  with small factors get resolved almost instantly, and the trial range only approaches
  `sqrt(N)` in the worst case (`N` itself prime).
- Whatever's left after that, if greater than 1, is prime — and since divisors were tried in
  increasing order, it's the largest one.

Status: **Accepted**, 100% on HackerRank (submission 1410850859, 2026-07-12). Verified
independently against a brute-force scan (check every `d<=n` for primality and divisibility) on
`n=2..20000` plus the classic Project Euler checkpoints (`13195 → 29`,
`600851475143 → 6857`, the full-size original `N`).

## The idea behind it

One catalogued idea (full write-up: [`memory-bank/_terms.md`](../memory-bank/_terms.md)):

**Trial division** — check candidate divisors starting from the smallest, pulling each one out
of the number as it's found. Shown here as the **ladder method** (also called the birthday cake
method), the way it's taught in school: write the divisor to the side, the running quotient
below, and stop once what's left is already prime. `[approach::TrialDivision]`

[![Ladder method](../memory-bank/visualizations/build/ladder-method.png)](../memory-bank/visualizations/build/ladder-method.html)

## Build & run

```
g++ -O2 -std=c++20 -o solution solution.cpp && ./solution < input.txt
```
