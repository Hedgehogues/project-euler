# Project Euler

C++ solutions to the [Project Euler](https://projecteuler.net/) problem set, as posed on the
[HackerRank Project Euler track](https://www.hackerrank.com/contests/projecteuler).

Each problem lives in its own directory (`euler001`, `euler002`, ...) with a single
`solution.cpp`. Solutions read multiple test cases from `stdin` — first line is the number of
cases `T`, followed by `T` lines of input — and print one answer per line.

## Build & run

```
g++ -O2 -std=c++20 -o solution eulerNNN/solution.cpp && ./solution < input.txt
```

## euler001 — Multiples of 3 and 5

For each given `N`, sum every natural number below `N` that's a multiple of 3 or 5.

The trick is not to loop over the range at all. A sum of evenly-spaced numbers (all the
multiples of 3 below `N`, say) can be added up with one multiplication instead of one at a
time — that's [Gauss's famous pairing trick](https://www.nctm.org/Publications/TCM-blog/Blog/The-Story-of-Gauss/).
Do that separately for multiples of 3 and multiples of 5, then subtract the multiples of 15 once
(they'd otherwise be counted in both sums) — that's
[inclusion–exclusion](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle). The
whole answer comes out of three multiplications, no matter how large `N` is.

**Status: Accepted, 100%.**

### Why it works, in pictures

<table>
<tr>
<td width="50%">

**Gauss's trick** — pair numbers from both ends of the run; every pair adds up to the same total.

[![Gauss's trick](memory-bank/visualizations/build/gauss-pairing.png)](memory-bank/visualizations/build/gauss-pairing.html)

</td>
<td width="50%">

**Inclusion–exclusion, as two overlapping bars** — add both sums, then take back what got
counted twice.

[![Bar model](memory-bank/visualizations/build/bar-model.png)](memory-bank/visualizations/build/bar-model.html)

</td>
</tr>
<tr>
<td width="50%">

**The same idea, as two circles** — the overlap is exactly what got double-counted.

[![Venn diagram](memory-bank/visualizations/build/venn.png)](memory-bank/visualizations/build/venn.html)

</td>
<td width="50%">

**"Multiple of", made visible** — hopping down a number line by 2, then by 3, is what "multiple"
actually means.

[![Skip counting](memory-bank/visualizations/build/skip-counting.png)](memory-bank/visualizations/build/skip-counting.html)

</td>
</tr>
</table>

Each picture is generated, not hand-drawn — click one to see it live in a browser. The write-ups
behind them (where each technique comes from, when it applies, its limits) live in
[`memory-bank/`](memory-bank/_terms.md), in Russian.
