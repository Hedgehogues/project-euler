# Project Euler

C++ solutions to the [Project Euler](https://projecteuler.net/) problem set, as posed on the
[HackerRank Project Euler track](https://www.hackerrank.com/contests/projecteuler).

Each problem lives in its own directory under [`problems/`](problems/) (`problems/euler001`,
`problems/euler002`, ...) with a single `solution.cpp`. Solutions read multiple test cases from
`stdin` — first line is the number of cases `T`, followed by `T` lines of input — and print one
answer per line.

## Build & run

```
g++ -O2 -std=c++20 -o solution problems/eulerNNN/solution.cpp && ./solution < input.txt
```

## Problems

| # | Problem | Status |
|---|---|---|
| [001](problems/euler001) | Multiples of 3 and 5 | Accepted, 100% |
| [002](problems/euler002) | Even Fibonacci numbers | Accepted, 100% |
| [003](problems/euler003) | Largest prime factor | Accepted, 100% |
| [004](problems/euler004) | Largest palindrome product | Accepted, 100% |
| [005](problems/euler005) | Smallest multiple | Accepted, 100% |
| [006](problems/euler006) | Sum square difference | Accepted, 100% |
| [007](problems/euler007) | 10001st prime | Accepted, 100% |

Each problem's own directory README has the write-up — the approach, why it works, and (where one
exists) a picture of the idea — and links to its RFC-style spec (requirements and acceptance
criteria), which lives in [`memory-bank/specs/tasks/`](memory-bank/specs/tasks/). The format that
spec must follow is itself specified: see
[`memory-bank/specs/tasks.md`](memory-bank/specs/tasks.md). Shared write-ups that don't belong to
any single problem — the methods themselves, each with its own picture — live in
[`memory-bank/`](memory-bank/_terms.md).
