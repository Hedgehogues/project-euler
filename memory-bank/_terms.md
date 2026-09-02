# Ubiquitous Language Index — projecteuler (explaining solutions)

> Canonical dictionary of explanation methods. Format: `## [context::TermName]` · links are plain
> markdown links into this same file, `[context::Name](#anchor)` (not `[[wikilink]]` — GitHub does
> not render those as links in ordinary `.md`, only inside its own Wiki). One context: `method` —
> an explanation method (the idea and its picture in ONE block).
>
> **One method, one block.** The idea ("what it is, when you recognize it") and its picture ("how
> to show it") are not two parallel catalogs but FIELDS OF ONE RECORD: `Essence`/`Recognized by`/
> `General case`/`Source` describe the idea, `Picture`/`Sequence`/`Example` describe the drawing,
> and `Limits` covers both — each bullet marking whether the limit belongs to the idea or only to
> the drawing. A method has at most one picture; a method with no picture is legitimate when the
> idea has no established visual form.
>
> **Not a single mention of a specific problem lives here** — no statement, no solution, not even
> a "used in" backlink. These are the primitives themselves. The link runs ONE way: a problem
> (`euler{NNN}/README.md`) points at the block it needs by name (`[method::Name]` →
> `_terms.md#methodname`); there is no reverse pointer. A problem reusing an already-described
> method simply links to the existing block — this file does not change at all.
>
> Each method's picture is `visualizations/build/<slug>.png`, produced by
> `visualizations/build.sh` from `visualizations/skeleton.html` + `visualizations/examples/<slug>.*`;
> after any edit to `examples/`, rerun the build — pictures are never touched by hand.

## [method::SkipCounting]
Class: entity
Standard name: Skip counting
Essence: Move along the numbers in equal hops — wherever you land is a multiple of the hop length.
Recognized by: you need to see or show which numbers have the multiple-of property BEFORE any computation — to eyeball it, to check a hunch, to explain what "multiple" even means from scratch
General case: hops of length k mark exactly the multiples of k; several hop lengths give several groups, and the numbers that are multiples of more than one are those where the landings coincide
Picture: ![Skip counting](visualizations/build/skip-counting.png)
Sequence:
  1. Problem — numbers on the line with no marks; which ones have the property is unknown
  2. Transform ×2 — hops of 2 mark the multiples of 2
  3. Transform ×3 — hops of 3 mark the multiples of 3
  4. Solution — the combined line, each number colored by what it belongs to (2 / 3 / both)
Limits:
  - MUST NOT: be used as a literal by-hand counting method for large numbers (thousands and up) — a limit of PRACTICE, not of the idea: the idea holds for any numbers, but there you compute the same multiples with a formula instead of drawing hops
  - MUST NOT: be used for three or more conditions at once — a limit of the PICTURE: the number of colors on the line exceeds what one glance can separate
Source: [Wikipedia — Skip counting](https://en.wikipedia.org/wiki/Skip_counting) · [Wikipedia — Number line](https://en.wikipedia.org/wiki/Number_line) · teaching practice: [SplashLearn](https://www.splashlearn.com/blog/how-to-teach-skip-counting/) · [WeAreTeachers](https://www.weareteachers.com/skip-counting/)
Example: `visualizations/examples/skip-counting.{css,html,js}` → `visualizations/build/skip-counting.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::InclusionExclusion]
Class: entity
Standard name: Inclusion–exclusion principle · picture — bar model / tape diagram (Singapore Math)
Essence: Count each part separately, then subtract whatever got counted twice.
Recognized by: the statement has an "or" between two or more properties of a number/object, and the exact count or sum matters ("a multiple of A OR a multiple of B")
General case: for k conditions — an alternating sum over all intersections (pairwise, triple, …); "A+B−AB" is only the k=2 case
Picture: ![Bar model](visualizations/build/bar-model.png)
Sequence:
  1. Problem — the two per-condition sums are added directly; the total is struck through (the shared part is double-counted)
  2. Transform − — the same two numbers shown overlapping; the twice-counted part is highlighted
  3. Solution — the bar split into three honest pieces (only 2, both, only 3); their sum is the right answer
Limits:
  - MUST NOT: be used for three or more conditions — a limit of the PICTURE: a bar can only show a row of non-overlapping pieces, and with three overlapping conditions the intersections do not line up honestly in one row. The idea itself works for any k (at the cost of the term count growing as 2^k)
Source: [Wikipedia — Inclusion–exclusion principle](https://en.wikipedia.org/wiki/Inclusion%E2%80%93exclusion_principle) · picture: [Wikipedia — Tape diagram](https://en.wikipedia.org/wiki/Tape_diagram) · [Maths — No Problem!](https://mathsnoproblem.com/en/approach/bar-modelling)
Example: `visualizations/examples/bar-model.{css,html}` (no js needed — the values are static) → `visualizations/build/bar-model.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::VennDiagram]
Class: entity
Standard name: Venn diagram — John Venn, 1880 (the term was coined by C. I. Lewis, 1918)
Essence: Show how two (or three) conditions relate using circles — the shape of the overlap is visible before any numbers are.
Recognized by: what matters is whether the conditions overlap AT ALL and how the regions relate; the exact count in each is secondary
General case: each non-overlapping region corresponds to its own combination of conditions; the diagram still makes sense with no numbers written in it at all — it is about structure, not counting
Picture: ![Venn diagram](visualizations/build/venn.png)
Sequence:
  1. Problem — two separate circles; how the conditions relate is unclear
  2. Transform ∩ — the circles move together, a shared region appears with no number in it
  3. Solution — all three regions labeled with numbers
Limits:
  - MUST NOT: be used for four or more conditions with plain circles — here the limit of the idea and of the picture coincide (the idea is inherently visual): four circles are provably unable to show every possible intersection; for two or three it works without reservation
Source: [Wikipedia — Venn diagram](https://en.wikipedia.org/wiki/Venn_diagram) · [Britannica — John Venn](https://www.britannica.com/biography/John-Venn) · [ReadWriteThink](https://www.readwritethink.org/classroom-resources/lesson-plans/introducing-venn-diagram-kindergarten) · [Science Sparks](https://www.science-sparks.com/make-venn-diagram-hula-hoop/)
Example: `visualizations/examples/venn.{css,html,js}` → `visualizations/build/venn.html`
Note: closely related to [method::InclusionExclusion](#methodinclusionexclusion) and often used together with it, but a separate method by origin: the diagram was invented in 1880 to represent logical propositions, not to count.
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::ArithmeticProgressionSum]
Class: entity
Standard name: Sum of an arithmetic progression · picture — Gauss's trick, pairing from both ends
Essence: A run of evenly spaced numbers can be added with one multiplication instead of one term at a time.
Recognized by: you need the sum (not the count) of numbers spaced at a constant step — multiples of something over a range, any evenly spaced run
General case: the sum of the first m terms of a progression with step k is `k · m·(m+1)/2`, where m is how many such numbers fall in the range; any k, m, N
Picture: ![Gauss pairing](visualizations/build/gauss-pairing.png)
Sequence:
  1. Problem — the run stands in order joined by "+", the sum not computed
  2. Transform ↔ — the numbers are linked into pairs from both ends by arcs; each arc is labeled with the pair's sum
  3. Solution — the total (number of pairs × pair sum, plus the middle term when the count is odd)
Limits:
  - MUST NOT: be used when the step between numbers varies — a limit of the IDEA: pairs from both ends stop summing to the same value and the formula does not apply
  - MUST: every intermediate number in the example must be distinct (the example uses 4·8·12·16·20, pairs of 24, total 60) — a limit of the PICTURE: in an earlier version the rectangle area and the final answer were both 30, and the explanation read as circular
Source: [Wikipedia — Arithmetic progression](https://en.wikipedia.org/wiki/Arithmetic_progression) · [BetterExplained — Techniques for Adding the Numbers 1 to 100](https://betterexplained.com/articles/techniques-for-adding-the-numbers-1-to-100/) · picture: [NCTM — The Story of Gauss](https://www.nctm.org/Publications/TCM-blog/Blog/The-Story-of-Gauss/)
Example: `visualizations/examples/gauss-pairing.{css,html,js}` → `visualizations/build/gauss-pairing.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::Precomputation]
Class: entity
Standard name: Precomputation · picture — build-once fan-in/fan-out (this catalog's own construction, not an independently named historical device — see Picture note)
Essence: Build everything that does not depend on the individual query once, up front — each query then only reads the ready result instead of recomputing it.
Recognized by: the same structure (list, table, running sum) is used many times over with different queries and does not itself depend on the query; rebuilding it per query repeats identical work T times for nothing
General case: lift the construction of the shared structure out of the query loop — its cost is paid once instead of T times; HOW a query is then answered from the ready structure (search, indexing, range sum) is a separate method, not part of precomputation
Picture: ![Precomputation](visualizations/build/precomputation.png)
Sequence:
  1. Problem — three queries: is 16 / 25 / 30 a perfect square? Nothing is built yet
  2. Transform prepare — before answering any query, the squares &le; 30 are computed once, in
     order (1&sup2;, 2&sup2;, ... 5&sup2;), into the set {1,4,9,16,25}
  3. Solution — each query navigates straight to its answer in that one ready set: 16 and 25 land
     on a matching cell (found), 30 is checked against every cell and matches none (not found)
Limits:
  - MUST NOT: be used when the structure depends on the query — then there is nothing to precompute
  - MUST: remember the build cost is always paid, even for a single query — with only one query there is no gain
Note: no encyclopedic source describes a named, standard PICTURE for this idea (checked: Wikipedia's Precomputation and Memoization articles contain zero diagrams; cp-algorithms has no page on it) — the idea itself is standard and sourced below, but the picture is this catalog's own construction, honestly not attributed to an established visual tradition the way the other pictures in this catalog are.
Source: [Wikipedia — Precomputation](https://en.wikipedia.org/wiki/Precomputation) · [Wikipedia — Lookup table](https://en.wikipedia.org/wiki/Lookup_table) · [GeeksforGeeks — Precomputation Techniques for Competitive Programming](https://www.geeksforgeeks.org/dsa/precomputation-techniques-for-competitive-programming/)
Example: `visualizations/examples/precomputation.{css,html}` (no js needed — the values are static) → `visualizations/build/precomputation.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::BinarySearch]
Class: entity
Standard name: Binary search
Essence: Find where a value sits in an already sorted list by repeatedly discarding the half that cannot contain it.
Recognized by: you need to find an element or a position in a list that is already sorted (or grows in order by construction)
General case: compare the target against the middle of the remaining stretch and drop the half where the answer cannot be — O(log m) comparisons instead of scanning all m elements
Picture: ![Binary search](visualizations/build/binary-search.png)
Sequence:
  1. Problem — a list of numbers and a target; where it sits is unknown
  2. Transform ½ — the middle is compared with the target, the half that cannot contain it is discarded
  3. Transform ½ — the same repeats on what is left
  4. Solution — one element remains — that is the answer
Limits:
  - MUST NOT: be used on an unsorted list — a limit of the IDEA: halving stops guaranteeing anything
Source: [cp-algorithms — Binary Search](https://cp-algorithms.com/num_methods/binary_search.html) · [Wikipedia — Binary search algorithm](https://en.wikipedia.org/wiki/Binary_search_algorithm)
Example: `visualizations/examples/binary-search.{css,html}` (no js needed — the values are static) → `visualizations/build/binary-search.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::TrialDivision]
Class: entity
Standard name: Trial division · picture — ladder method (division ladder), a.k.a. birthday cake method
Essence: Try the small numbers in turn, starting at 2 — see what divides — and peel off the prime factors that way.
Recognized by: you need to factor a number into primes or to find one particular (say, the largest) prime factor
General case: try divisors d from 2 while d·d ≤ what REMAINS of the number; at each divisor peel it out while it divides evenly — the remainder shrinks and the trial bound falls with it; if what is left after the loop exceeds 1, it is itself prime (and with divisors tried in increasing order, it is the largest factor)
Picture: ![Ladder method](visualizations/build/ladder-method.png)
Sequence:
  1. Problem — the number 30, not yet broken down
  2. Transform ÷2 — divide by 2, quotient 15 written below
  3. Transform ÷3 — divide 15 by 3, quotient 5 written below
  4. Solution — 5 is already prime and divides no further — that is the largest prime factor
Limits:
  - MUST NOT: be used on large numbers with no small factors — a limit of the IDEA by cost: the loop runs to the square root, which is impractical for a semiprime of tens of digits (other factorization methods belong there)
  - MUST: in the picture, divide by primes starting from the smallest — a limit of the PICTURE: the ladder must mirror the loop's mechanics (all the 2s first, then odd divisors in increasing order), not an arbitrary split into any two factors as in a free-form factor tree
Source: [Wikipedia — Trial division](https://en.wikipedia.org/wiki/Trial_division) · picture: [Math = Love — Birthday Cake Method](https://mathequalslove.net/prime-factorization-using-birthday-cake-method/) · [Scaffolded Math and Science — Ladder Method](https://www.scaffoldedmath.com/2019/02/finding-gcf-and-lcm-with-upside-down-cake-method.html)
Example: `visualizations/examples/ladder-method.{css,html}` (no js needed — the values are static) → `visualizations/build/ladder-method.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::SumOfSquares]
Class: entity
Standard name: Sum of squares formula · picture — square split into two triangular staircases (this catalog's own construction, verified but not independently sourced as a named device — see Picture note)
Essence: The sum of the first n squares has a closed-form cubic formula, computed directly instead of adding n terms one at a time.
Recognized by: you need 1² + 2² + ... + n² — the terms being added are themselves squares, not the plain numbers ([method::ArithmeticProgressionSum](#methodarithmeticprogressionsum) is for that, plain-number, case)
General case: sum of the first n squares = n(n+1)(2n+1) / 6, for any positive integer n
Picture: ![Sum of squares](visualizations/build/sum-of-squares.png)
Sequence:
  1. Problem — a 4×4 square of unit cells, unlabeled; split it along the diagonal into two staircases?
  2. Transform ⊿ — the growing staircase (T(4)=10 cells) and the rest (T(3)=6 cells): every k² splits into T(k) + T(k−1), the triangular numbers on either side of k
  3. Solution — each of the four layers (k=1..4) split the same way; summing every blue staircase (1+3+6+10=20) and every red one (0+1+3+6=10) gives 30 = 1²+2²+3²+4²
Limits:
  - MUST NOT: be confused with the LINEAR sum 1+2+...+n — that is [method::ArithmeticProgressionSum](#methodarithmeticprogressionsum), a different, lower-degree closed form; the two are easy to conflate because both apply to "the first n numbers"
Note: no encyclopedic source gives a geometric derivation of the closed form n(n+1)(2n+1)/6 — Wikipedia's own Square pyramidal number article states it directly and says it "may be proved by mathematical induction" (an algebraic technique, not a picture). The picture therefore does NOT claim to derive the cubic closed form; what it DOES show, honestly and completely, is the real, checkable identity k² = T(k) + T(k−1) (T being the triangular number, already this catalog's own [method::ArithmeticProgressionSum](#methodarithmeticprogressionsum) at n=k) — summing that identity over k=1..n is a genuine, verifiable route to the same total, one level short of the final algebraic simplification into the cubic form. An earlier version of this picture stacked the four layers, counted each (16, 9, 4, 1), and then simply asserted "= 4·5·9/6" with no visible connection between the count and the formula — caught by the user asking directly what in the picture explains how the approach's result is obtained.
Source: [Wikipedia — Square pyramidal number](https://en.wikipedia.org/wiki/Square_pyramidal_number)
Example: `visualizations/examples/sum-of-squares.{css,html}` (no js needed — the values are static) → `visualizations/build/sum-of-squares.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::EuclideanAlgorithm]
Class: entity
Standard name: Euclidean algorithm
Essence: To find the greatest common divisor of two numbers, keep replacing the larger one by the remainder of dividing it by the smaller — repeat until nothing is left over; what remains is the answer.
Recognized by: you need the greatest common divisor of two numbers, or need to reduce a fraction/ratio to lowest terms, or need to check whether two numbers share no common factor at all
General case: gcd(a, 0) = a; gcd(a, b) = gcd(b, a mod b) for b > 0 — holds for any two non-negative integers, and always terminates (the number of steps is at most about 5 times the number of decimal digits of the smaller number)
Picture: ![Euclidean algorithm](visualizations/build/euclidean-algorithm.png)
Sequence:
  1. Problem — a 35×15 rectangle; what size of square tiles it exactly is unknown
  2. Transform ÷15 — two 15×15 squares tile part of the rectangle, leaving a 5×15 strip over
  3. Solution — that strip is exactly covered by three 5×5 squares with nothing left over; 5 is the greatest common divisor
Limits:
  - MUST NOT: be applied to negative numbers without first taking absolute values — a limit of the IDEA: the remainder step assumes both numbers are non-negative
Source: [Wikipedia — Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm) · [cp-algorithms — Euclidean algorithm for computing GCD](https://cp-algorithms.com/algebra/euclid-algorithm.html)
Example: `visualizations/examples/euclidean-algorithm.{css,html}` (no js needed — the values are static) → `visualizations/build/euclidean-algorithm.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::LCMViaGCD]
Class: entity
Standard name: Least common multiple via GCD · picture — tile-count swap (this catalog's own construction, not an independently named historical device — see Picture note)
Essence: Build the smallest number divisible by a whole list of numbers, one at a time — each new number only ever contributes the part of itself not already covered by what came before.
Recognized by: you need the smallest number that every number in a set or range divides into evenly ("smallest number divisible by all of 1..N") — the smallest common MULTIPLE, not the greatest common divisor
General case: lcm(a, b) = a·b / gcd(a, b); for a list or range of more than two numbers, fold this pairwise across every element in turn — lcm(a, b, c, ...) = lcm(lcm(a, b), c, ...)
Picture: ![LCM via GCD](visualizations/build/lcm-via-gcd.png)
Sequence:
  1. Problem — 35 shown tiled by 7 units of 5 (their gcd), 15 shown tiled by 3 units of 5 — the same unit exactly fits both, a different number of times each
  2. Transform ⇄ — swap the counts: the 7 tiles counted inside 35 become how many times 15 repeats, and the 3 tiles counted inside 15 become how many times 35 repeats
  3. Solution — 3 × 35 = 7 × 15 = 105 = lcm(35, 15); both rows reach the exact same length, because that is precisely what the swap guarantees
Limits:
  - MUST NOT: be computed by just multiplying every number together — that overcounts factors the numbers already share; dividing by the gcd at each step is exactly what keeps the running result minimal
Note: a standard LCM picture exists for a DIFFERENT technique — a Venn diagram of each number's prime factors, shared primes in the overlap — but drawing it here would show the factoring approach this method exists specifically to avoid (factoring is expensive, gcd is cheap). The picture used instead is not independently famous by its own name: it is this catalog's own construction, deliberately drawn to differ from [method::EuclideanAlgorithm](#methodeuclideanalgorithm)'s square-tiling in both composition (linear tile-count-and-swap, not a shrinking rectangle) and in what it visibly derives (WHY the repeat counts 3 and 7 are what they are, shown by literally counting tiles, not asserted in a caption) — even though the same gcd, 5, anchors both pictures. This idea's entire mechanism runs through EuclideanAlgorithm — unlike Precomputation and BinarySearch (independently useful without each other), this one cannot even be stated without the gcd it depends on.
Source: [Wikipedia — Least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple)
Example: `visualizations/examples/lcm-via-gcd.{css,html}` (no js needed — the values are static) → `visualizations/build/lcm-via-gcd.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::SieveOfEratosthenes]
Class: entity
Standard name: Sieve of Eratosthenes
Essence: To list every prime up to a limit, start with all numbers unmarked, then repeatedly take the next unmarked number as a prime and cross out all of its multiples — whatever survives unmarked all the way through is exactly the primes.
Recognized by: you need ALL the primes up to some bound N at once, not a yes/no test or a factorization of one single given number ([method::TrialDivision](#methodtrialdivision) is for that, one-number case)
General case: for a limit N, it suffices to cross multiples of each prime p starting at p&sup2; and only for p &le; sqrt(N) — every composite below p&sup2; was already crossed by a smaller prime factor; runs in O(N log log N)
Picture: ![Sieve of Eratosthenes](visualizations/build/sieve-of-eratosthenes.png)
Sequence:
  1. Problem — numbers 2 to 19, none checked yet
  2. Transform ×2 — 2 is the first unmarked number, a prime; cross out every multiple of it (4, 6, 8, 10, 12, 14, 16, 18)
  3. Transform ×3 — 3 is the next unmarked number, a prime; cross out its multiples (6, 9, 12, 15, 18) — 9 and 15 are newly crossed, the rest were already gone
  4. Solution — nothing past 3 needs checking (the next candidate, 5, has 5&sup2;=25 &gt; 19); the 8 numbers never crossed out are exactly the primes below 20
Limits:
  - MUST NOT: be used to test or factor one single large number in isolation — a limit of the IDEA: building the whole array up to that number costs memory and time nobody needs for one query ([method::TrialDivision](#methodtrialdivision) is for that case)
  - MUST: the picture only crosses multiples of primes up to sqrt(limit) — a limit of the PICTURE: showing every divisor's hops instead of stopping at the square root would draw marks already covered by a smaller prime, obscuring why the sieve is allowed to stop early
Source: [Wikipedia — Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) · [cp-algorithms — Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)
Example: `visualizations/examples/sieve-of-eratosthenes.{css,html,js}` → `visualizations/build/sieve-of-eratosthenes.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::NthPrimeBound]
Class: entity
Standard name: Upper bound on the nth prime · picture — number-line ceiling (this catalog's own construction, not an independently named historical device — see Picture note)
Essence: Before searching for the Nth prime, get an explicit numeric ceiling on how large it can possibly be from a proven inequality, instead of guessing a limit or growing the search open-endedly.
Recognized by: you are told only the INDEX N of a prime (not any bound on the prime's own size) and need to know in advance how far a search or a sieve must reach to be certain of finding it
General case: for n &ge; 6, the nth prime p<sub>n</sub> satisfies n(ln n + ln ln n &minus; 1) &lt; p<sub>n</sub> &lt; n(ln n + ln ln n) — the upper half alone is enough to size a sieve safely; this inequality is a sharpened, explicit-for-every-n form of [method::PrimeNumberTheorem](#methodprimenumbertheorem)'s limit statement
Picture: ![Upper bound on the nth prime](visualizations/build/nth-prime-bound.png)
Sequence:
  1. Problem — find the 6th prime; the number line has no marked end, only a "?"
  2. Transform gaps — the real primes up to 20 on a number line (2, 3, 5, 7 packed on the left;
     11, 13, 17, 19 spread out on the right), with two rulers under it: the typical gap near 6 is
     ln 6 &asymp; 1.8 long, near 13 it is ln 13 &asymp; 2.6 — the ruler grows the way the spacing
     does. This is where the logarithm comes from: it is the observed thinning-out of primes
     ([method::PrimeNumberTheorem](#methodprimenumbertheorem)), shown, not derived. Counting six
     dots along this strip also lands on 13 — the target the next two frames measure against
  3. Transform guess — 6 equal hops of the ruler measured at 6 (ln 6 &asymp; 1.792), walked out from
     0: the 6th hop lands at 10.75, visibly short of the 13 mark
  4. Transform refine — the hop was measured in the wrong place: at 6, where primes are still
     dense, not near where the walk ends. Re-measure the ruler at the landing point instead —
     ln 10.75 &asymp; 2.375 — and walk the same 6 hops: the 6th lands at 14.25, past 13, rounded up
     to a ceiling of 15. The "log of a log" is only this: 10.75 is itself 6 &times; ln 6, so
     ln 10.75 = ln(6 &times; ln 6) = ln 6 + ln ln 6
  5. Solution — the 6th prime, 13, lands safely inside that corrected ceiling of 15
Limits:
  - MUST NOT: be used for n &lt; 6 — a limit of the IDEA: the inequality is proven only from n=6 upward; smaller n are checked directly instead
  - MUST: pad the computed bound rather than use it exactly at the boundary — a limit of PRACTICE, not of the theorem: the inequality is proven exact, but floating-point evaluation of ln/ln ln can round down by a hair right at the boundary
  - MUST NOT: present the guess-then-refine picture as the actual 1941 proof — a limit of the PICTURE: it shows the standard HEURISTIC motivation for the formula's shape (self-consistent substitution: p&#8776;n&middot;ln(p), then ln(p)&asymp;ln(n&middot;ln n)), not Rosser's real analytic argument, which is more careful and is what actually makes the inequality a proven ceiling rather than just a plausible guess
Note: No encyclopedic source draws a picture for this inequality (checked: Wikipedia's Prime-counting function article states the bound as a formula only, no diagram; no published plot comparing p_n against the bound was found anywhere encyclopedic) — the idea itself is standard and sourced below; the picture is this catalog's own construction, honestly not attributed to an established visual tradition the way [method::SieveOfEratosthenes](#methodsieveoferatosthenes)'s grid is. Three earlier designs did not survive direct user feedback: a formula-in-a-box with no derivation at all ("doesn't answer how it's obtained, no geometry"), 6 tiles laid end to end each just labeled with the formula itself ("useless" — restates the arithmetic, explains nothing about where the formula comes from), and a version with the guess/refine formulas but no geometry at all ("how is the log of a log obtained — visualize this without text so the problem and the fix are both clear"). This version walks the SAME 6-hop step out on a number line twice, once per guess, both against the same fixed mark for the real 6th prime (13): the first walk's equal hops (size ln 6) visibly land short of 13; the second walk's bigger hops (size ln 6 + ln ln 6) visibly clear it — the correction is a comparison a reader counts by eye (hop spacing, landing position), not a formula they have to parse to believe.
Source: [Wikipedia — Prime-counting function](https://en.wikipedia.org/wiki/Prime-counting_function) (bounds section, upper bound attributed to Rosser, 1941)
Example: `visualizations/examples/nth-prime-bound.{css,html}` (no js needed — the values are static) → `visualizations/build/nth-prime-bound.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::PrimeNumberTheorem]
Class: entity
Standard name: Prime number theorem
Essence: As numbers grow, the fraction of them that are prime keeps shrinking, in a way one explicit formula — a number divided by its own natural logarithm — predicts increasingly accurately.
Recognized by: you need to estimate how many primes lie below some bound, or how far apart primes typically run near a given size, without counting them one by one, and an approximate/asymptotic answer is acceptable
General case: pi(x), the count of primes up to x, satisfies pi(x) / (x &divide; ln x) &rarr; 1 as x &rarr; infinity; equivalently, near a number of size x, roughly one integer in every ln(x) is prime — [method::NthPrimeBound](#methodnthprimebound) is this same fact turned around (given the COUNT n, bound the SIZE of the nth prime) and sharpened into an explicit inequality that holds at every n, not just in the limit
Picture: ![Prime number theorem](visualizations/build/prime-number-theorem.png)
Sequence:
  1. Problem — how many primes lie at or below 100? Below 10,000? Below 1,000,000? Unknown.
  2. Transform count vs x&divide;ln x — the real, counted totals (25, 1229, 78498) next to the formula's guess (21.7, 1086, 72382) at each of the three scales
  3. Solution — the guess undershoots by 15.1%, then 13.2%, then 8.4% — the relative gap shrinks as the numbers grow
Limits:
  - MUST NOT: be read as an exact formula, or as increasingly accurate at every individual scale without exception — a limit of the IDEA: it is a LIMIT statement (exact only as x &rarr; infinity); the true count is known to run persistently a little above the guess at accessible scales (Littlewood proved the sign of the gap even flips infinitely often much further out)
  - MUST: the three example scales are real, independently counted primes, not invented or interpolated — a limit of the PICTURE keeping it honest, not of the idea
Source: [Wikipedia — Prime number theorem](https://en.wikipedia.org/wiki/Prime_number_theorem) · [Wikipedia — Prime-counting function](https://en.wikipedia.org/wiki/Prime-counting_function) (the standard "ratio of &pi;(x) to x/log x and Li(x)" graph — this picture is this catalog's own discretized rendering of that same comparison at three concrete, verified scales, not a copy of the continuous plot)
Example: `visualizations/examples/prime-number-theorem.{css,html}` (no js needed — the values are static) → `visualizations/build/prime-number-theorem.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::PrefixSum]
Class: entity
Standard name: Prefix sum · picture — running-total row plus subtraction (this catalog's own construction, the array/running-total idea sourced, the two-row picture not independently attributed — see Source)
Essence: Build a running-total array once — each cell holding everything added up to that point — so the sum of ANY range afterward is a single subtraction, not a re-added loop.
Recognized by: many queries each ask for the sum (or count) over a range of a fixed array, and re-adding the range from scratch every time would repeat the same work across overlapping queries
General case: prefix[i] = prefix[i-1] + value[i] (prefix[0] = 0); the sum of positions L..R is prefix[R] - prefix[L-1], for any L &le; R
Picture: ![Prefix sum](visualizations/build/prefix-sum.png)
Sequence:
  1. Problem — 8 numbers in a row (3,1,4,5,9,2,6,8); the sum of the highlighted range (positions 3-6) is unknown
  2. Transform running total — a second row underneath, each cell the running total up to that position (3,4,8,13,22,24,30,38)
  3. Solution — the range sum is just two of those cells subtracted: 24 &minus; 4 = 20
Limits:
  - MUST NOT: be used when the underlying array changes between queries — a limit of the IDEA: every update would force rebuilding every prefix cell after it (a Fenwick/segment tree is the structure for that case, not covered here)
  - MUST: read the LOWER prefix cell one position before the range starts (prefix[L-1], not prefix[L]) — a limit of PRACTICE: off-by-one here is the single most common bug in this technique
Source: [Wikipedia — Prefix sum](https://en.wikipedia.org/wiki/Prefix_sum) (definition) · [GeeksforGeeks — Understanding Prefix Sums](https://www.geeksforgeeks.org/dsa/understanding-prefix-sums/) (the range-query-via-subtraction application)
Example: `visualizations/examples/prefix-sum.{css,html,js}` → `visualizations/build/prefix-sum.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::DivisorCountFormula]
Class: entity
Standard name: Divisor function &tau;(n) (also written d(n) or &sigma;<sub>0</sub>(n))
Essence: The number of divisors of n depends only on the EXPONENTS in its prime factorization — pick, independently for each prime, how many copies of it to include, and multiply the counts of choices together.
Recognized by: you need HOW MANY divisors a number has (not the divisors themselves, and not their sum) — often for many numbers, or for one number too large to just list divisors of directly
General case: if n = p<sub>1</sub><sup>e<sub>1</sub></sup> &times; p<sub>2</sub><sup>e<sub>2</sub></sup> &times; ... &times; p<sub>k</sub><sup>e<sub>k</sub></sup>, then &tau;(n) = (e<sub>1</sub>+1)(e<sub>2</sub>+1)...(e<sub>k</sub>+1); the function is multiplicative, so &tau;(a&middot;b) = &tau;(a)&middot;&tau;(b) whenever gcd(a,b)=1 — useful for splitting a number into coprime pieces before counting
Picture: ![Divisor count formula](visualizations/build/divisor-count-formula.png)
Sequence:
  1. Problem — the number 20; how many divisors it has is unknown
  2. Transform factor — 20 = 2&sup2; &times; 5&sup1;; the exponent of 2 gives 3 independent choices (2&#8304;, 2&sup1;, 2&sup2;), the exponent of 5 gives 2 (5&#8304;, 5&sup1;)
  3. Solution — a 3&times;2 grid of every combination, each cell an actual divisor (1, 2, 4, 5, 10, 20) — 6 cells, so 6 divisors
Limits:
  - MUST NOT: be applied by picking exponents that are NOT independent — a limit of the IDEA: the formula relies on the Fundamental Theorem of Arithmetic giving a UNIQUE factorization, so every combination of exponent-choices names a genuinely different divisor exactly once
  - MUST: the grid's two axes must be genuinely independent prime factors — a limit of the PICTURE: with three or more distinct primes the grid becomes a cube or higher, no longer drawable flat (the formula itself keeps working for any number of factors; only the two-axis picture is limited to two)
Source: [Wikipedia — Divisor function](https://en.wikipedia.org/wiki/Divisor_function) · [cp-algorithms — Number of divisors / sum of divisors](https://cp-algorithms.com/algebra/divisors.html)
Example: `visualizations/examples/divisor-count-formula.{css,html}` (no js needed — the values are static) → `visualizations/build/divisor-count-formula.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::BigIntegerArithmetic]
Class: entity
Standard name: Arbitrary-precision arithmetic (big-integer / "long" arithmetic)
Essence: When a number has more digits than a native integer type can hold, store it as an array of digits and operate on it the same way a person does on paper — column by column, carrying the overflow into the next column.
Recognized by: a number in the problem is too large for any fixed-width integer type (dozens or hundreds of digits, or growing without any given bound), and only a small piece of the result is actually needed (its value, its first/last few digits, its digit sum)
General case: represent the number least-significant-digit-first in a fixed base (usually 10, or a larger power of 10 for speed); addition and multiplication-by-a-small-constant both propagate a carry left exactly like grade-school column arithmetic, just with the per-column operation swapped (add two digits, or multiply one digit by the constant) — the carry-propagation mechanism is identical either way
Picture: ![Big-integer arithmetic](visualizations/build/big-integer-arithmetic.png)
Sequence:
  1. Problem — 187 + 259 stacked, too many digits to add as one native number (illustrative only — the technique is for numbers with far more digits than this)
  2. Transform carry — right to left: 7+9=16, write 6 carry 1; 8+5+1=14, write 4 carry 1; 1+2+1=4
  3. Solution — 446, read off column by column, no native integer ever held the full sum until the very last digit was written
Limits:
  - MUST NOT: be reached for a number that already fits in a native 64-bit (or 128-bit) integer — a limit of the IDEA: the whole point is avoiding overflow that a native type would already handle
  - MUST: propagate a carry that can exceed a single digit when multiplying by a constant bigger than 9 — a limit of PRACTICE: unlike addition (carry always 0 or 1), multiplying a digit by a two-digit constant can carry a two-digit amount into the next column
Source: [Wikipedia — Arbitrary-precision arithmetic](https://en.wikipedia.org/wiki/Arbitrary-precision_arithmetic) · [cp-algorithms — Arbitrary-Precision Arithmetic](https://cp-algorithms.com/algebra/big-integer.html)
Example: `visualizations/examples/big-integer-arithmetic.{css,html}` (no js needed — the values are static) → `visualizations/build/big-integer-arithmetic.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::Memoization]
Class: entity
Standard name: Memoization
Essence: The first time a recursive call is answered, write the answer down; every later call asking the exact same question reads the answer back instead of doing the work again.
Recognized by: a recursive definition is called on the SAME input more than once across different branches of the recursion (overlapping subproblems), and computing it fresh each time would repeat identical work
General case: wrap the recursive function with a cache (array or hash map) keyed by its argument(s); on entry, return the cached value if present, otherwise compute normally and store the result before returning — the recursion's own structure is untouched, only entry/exit is intercepted
Picture: ![Memoization](visualizations/build/memoization.png)
Sequence:
  1. Problem — computing fib(4) needs fib(3) and fib(2); fib(3) itself ALSO needs fib(2) — the same call twice
  2. Transform expand — the first fib(2) is computed fully (fib(1)+fib(0)=1+0=1) and stored; the second fib(2), needed directly by fib(4), just reads that stored 1 back instead of expanding again
  3. Solution — fib(4) = fib(3) + fib(2) = 2 + 1 = 3, with fib(2)'s work paid for only once
Limits:
  - MUST NOT: be used when a call's result depends on more than just its own arguments (e.g. it also reads or mutates outside state) — a limit of the IDEA: a cache keyed only by arguments would return a stale answer for a call whose true result has since changed
  - MUST: cache on the exact arguments that determine the result, no more and no fewer — a limit of PRACTICE: caching on too few argument bits collapses genuinely different calls onto one stored answer; caching on irrelevant extra bits never lets the cache hit at all
Source: [Wikipedia — Memoization](https://en.wikipedia.org/wiki/Memoization) · [Wikipedia — Overlapping subproblems](https://en.wikipedia.org/wiki/Overlapping_subproblems)
Example: `visualizations/examples/memoization.{css,html}` (no js needed — the values are static) → `visualizations/build/memoization.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::FastExponentiation]
Class: entity
Standard name: Exponentiation by squaring (binary exponentiation, "square-and-multiply")
Essence: To raise a number to the power n, halve n and square the base at every step instead of multiplying by the base n times — the exponent shrinks by half each round, so the whole thing finishes in about log2(n) multiplications, not n.
Recognized by: you need base^exponent for a LARGE exponent (thousands, millions, or a variable up to some big bound), especially under a modulus, and multiplying one factor in at a time is too slow
General case: while exponent &gt; 0 — if the exponent is odd, multiply the running result by the current base; square the base; halve the exponent (integer division) — repeat; works identically under a modulus by reducing after every multiplication
Picture: ![Fast exponentiation](visualizations/build/fast-exponentiation.png)
Sequence:
  1. Problem — 3<sup>13</sup>; multiplying by 3 thirteen times is 12 multiplications
  2. Transform halve &amp; square — 4 rows, the exponent halving each time (13&rarr;6&rarr;3&rarr;1&rarr;0); the base squares every row, and the running result only picks up the base on the rows where the exponent is odd
  3. Solution — 3<sup>13</sup> = 1594323, reached in 4 rows instead of 12 multiplications
Limits:
  - MUST NOT: be applied to a non-associative operation — a limit of the IDEA: squaring the base and combining partial results relies on `(a&middot;a)&middot;a = a&middot;(a&middot;a)`, which fails for operations without that property
  - MUST: reduce modulo the modulus after EVERY multiplication when working modularly, not just at the end — a limit of PRACTICE: the base and result both grow every squaring step and overflow a fixed-width integer type within a handful of rounds otherwise
Source: [Wikipedia — Exponentiation by squaring](https://en.wikipedia.org/wiki/Exponentiation_by_squaring)
Example: `visualizations/examples/fast-exponentiation.{css,html}` (no js needed — the values are static) → `visualizations/build/fast-exponentiation.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::ModularInverseFermat]
Class: entity
Standard name: Modular multiplicative inverse via Fermat's little theorem
Essence: There is no division in modular arithmetic, but under a PRIME modulus, dividing by a is the same as multiplying by a fixed power of a — a<sup>p&minus;2</sup> — a proven fact, not a search.
Recognized by: you need to divide by a number modulo a prime (most often as part of a formula with a factorial or a binomial coefficient in the denominator, mod 10^9+7 or similar)
General case: for prime p and a not a multiple of p, a<sup>p&minus;1</sup> &equiv; 1 (mod p) (Fermat's little theorem); multiplying both sides by a<sup>&minus;1</sup> gives a<sup>&minus;1</sup> &equiv; a<sup>p&minus;2</sup> (mod p) — computed with [method::FastExponentiation](#methodfastexponentiation), never by searching for the inverse
Picture: ![Modular inverse via Fermat](visualizations/build/modular-inverse-fermat.png)
Sequence:
  1. Problem — 1 &divide; 3 (mod 7): no direct division exists
  2. Transform Fermat — x = 3<sup>7&minus;2</sup> mod 7 = 3<sup>5</sup> mod 7 = 5, by the proven theorem, not trial and error
  3. Solution — verify: 3 &times; 5 = 15 = 7 + 7 + 1 &equiv; 1 (mod 7); the division really does check out
Limits:
  - MUST NOT: be used when the modulus is not prime — a limit of the IDEA: Fermat's little theorem itself requires a prime modulus (Euler's theorem with &phi;(m) is the generalization for composite m, and needs m's factorization)
  - MUST NOT: be used when a is a multiple of p — a limit of the IDEA: a has no inverse at all mod p in that case (gcd(a,p)=p, not 1)
Source: [Wikipedia — Fermat's little theorem](https://en.wikipedia.org/wiki/Fermat's_little_theorem) · [cp-algorithms — Modular Inverse](https://cp-algorithms.com/algebra/module-inverse.html)
Example: `visualizations/examples/modular-inverse-fermat.{css,html}` (no js needed — the values are static) → `visualizations/build/modular-inverse-fermat.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::LatticePaths]
Class: entity
Standard name: Lattice path counting (grid paths / binomial coefficient)
Essence: The number of shortest routes across a grid, moving only right or down, is a binomial coefficient — choosing WHICH steps are "right" (or equivalently which are "down") out of the whole sequence of moves.
Recognized by: you need to count routes/paths through a grid that only move in two fixed directions (right and down, or equivalently any two perpendicular directions), from one corner to another
General case: across an N&times;M grid of squares (an (N+1)&times;(M+1) grid of points), the number of shortest routes from one corner to the opposite one is C(N+M, N) — out of N+M total moves, choose which N of them are "right" (the rest are forced to be "down")
Picture: ![Lattice paths](visualizations/build/lattice-paths.png)
Sequence:
  1. Problem — a 2&times;2 grid of points to fill in; how many routes from top-left to bottom-right?
  2. Transform build up — each point's route count is the point above it plus the point to its left (the only two ways to arrive there); filling the grid this way reaches 6 in the bottom-right corner
  3. Solution — C(2+2, 2) = 6 routes, matching the filled-in grid exactly
Limits:
  - MUST NOT: be used when some cells are blocked/forbidden — a limit of the IDEA: the closed-form binomial coefficient counts EVERY monotone path; a grid with holes needs the cell-by-cell build-up (or inclusion-exclusion) instead, not the closed form
  - MUST: the grid pictured is deliberately tiny (2&times;2) — a limit of the PICTURE: for a real N&times;M grid the same build-up table would need (N+1)&times;(M+1) cells, impractical to draw much larger than this
Source: [Wikipedia — Lattice path](https://en.wikipedia.org/wiki/Lattice_path) · [Wikipedia — Binomial coefficient](https://en.wikipedia.org/wiki/Binomial_coefficient)
Example: `visualizations/examples/lattice-paths.{css,html}` (no js needed — the values are static) → `visualizations/build/lattice-paths.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::DynamicProgramming]
Class: entity
Standard name: Dynamic programming (bottom-up / tabulation)
Essence: Build the optimal answer to the whole problem from the already-solved optimal answers to its smaller pieces, smallest first, instead of exploring every whole path from scratch.
Recognized by: the best choice at any point can be expressed using only the best answers to the smaller subproblems it leads to (optimal substructure), and those subproblems recur across many different larger problems (overlapping subproblems)
General case: order the subproblems from smallest/base case to largest; for each one, combine the already-computed answers of the subproblems it depends on (often via a min/max/sum) into its own answer, storing it as it is computed; the final answer is the entry for the whole problem, built without exploring any path twice
Picture: ![Dynamic programming](visualizations/build/dynamic-programming.png)
Sequence:
  1. Problem — a number triangle; moving only to an adjacent number below, which top-to-bottom path scores highest is unclear
  2. Transform bottom-up — the bottom row is already optimal (nowhere left to go); every row above adds itself to the BETTER of the two cells directly below it, e.g. 2 + max(8,5) = 10, all the way up
  3. Solution — the top cell, 23, IS the best total — no path was ever explored end to end
Limits:
  - MUST NOT: be used when the optimal choice at a point depends on more than just the optimal values of its subproblems (e.g. the actual path taken matters, not just its score) — a limit of the IDEA: optimal substructure can fail for constraints that couple choices non-locally
  - MUST: combine subproblems with the SAME combining rule the problem actually asks for (max here; it would be sum, count, or min for a different problem) — a limit of PRACTICE: reusing "the DP idea" without checking which combining rule applies is a common source of wrong answers
Source: [Wikipedia — Dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) · [Wikipedia — Optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure)
Example: `visualizations/examples/dynamic-programming.{css,html}` (no js needed — the values are static) → `visualizations/build/dynamic-programming.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::DayOfWeekFormula]
Class: entity
Standard name: Determination of the day of the week (Sakamoto's algorithm)
Essence: The day of the week is a single sum of a few pieces (a leap-year correction, a fixed per-month offset, the day itself), taken modulo 7 — no calendar simulation needed.
Recognized by: you need the day of the week for a date, possibly a huge or far-future one, without stepping through the calendar day by day or month by month
General case: treating January and February as months 13 and 14 of the PREVIOUS year (so the leap-day correction only has to look at whole years), the weekday index is `(y + y/4 - y/100 + y/400 + t[m-1] + d) mod 7`, where `t = {0,3,2,5,0,3,5,1,4,6,2,4}` is a fixed per-month offset table and 0..6 maps Sunday..Saturday
Picture: ![Day-of-week formula](visualizations/build/day-of-week-formula.png)
Sequence:
  1. Problem — 1 Jan 2000: which day of the week?
  2. Transform sum the terms — the adjusted year 1999, plus leap-year corrections (+499, &minus;19, +4), plus January's month offset (0), plus the day (1): total 2484
  3. Solution — 2484 mod 7 = 6 &rarr; Saturday, counted off on the 7-day strip; 1 Jan 2000 really was a Saturday
Limits:
  - MUST NOT: be used for dates before the Gregorian calendar's adoption (the formula assumes the modern leap-year rule throughout) — a limit of the IDEA: the Julian calendar's leap-year rule differs, and adoption dates vary by country
  - MUST: reduce the year modulo 2800 first for very large years before evaluating the formula — a limit of PRACTICE: the Gregorian calendar's weekday pattern repeats every `lcm(400, 7) = 2800` years, and reducing first keeps every intermediate value small regardless of how large the input year is
Source: [Wikipedia — Determination of the day of the week](https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week) (Sakamoto's algorithm section)
Example: `visualizations/examples/day-of-week-formula.{css,html}` (no js needed — the values are static) → `visualizations/build/day-of-week-formula.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::LehmerCode]
Class: entity
Standard name: Lehmer code (factorial number system)
Essence: The Nth permutation in lexicographic order can be built directly, one element at a time, by repeatedly dividing the (0-based) index by a shrinking factorial — no need to list any of the permutations before it.
Recognized by: you need the Nth permutation of a sequence directly (by index, possibly a huge one), not all permutations up to it, and not just "some" permutation
General case: with a pool of k remaining elements and a 0-based index, divide the index by (k&minus;1)! — the quotient selects which of the k remaining elements comes next (remove it from the pool), the remainder becomes the index for the next, one-smaller round; repeating until the pool is empty reconstructs the whole permutation
Picture: ![Lehmer code](visualizations/build/lehmer-code.png)
Sequence:
  1. Problem — the 15th permutation of "abcd"; listing all 24 to count to it doesn't scale (13 letters would mean 6,227,020,800 of them)
  2. Transform peel off digits — index 14, divided by shrinking factorials (3!, 2!, 1!, 0!), picks one letter from the shrinking pool each round: c, then b, then a, then d
  3. Solution — c b a d, built directly, without ever listing the 14 permutations that come before it
Limits:
  - MUST NOT: be used with a 1-based index without first converting it to 0-based — a limit of PRACTICE: "the Nth permutation" is usually asked 1-indexed, but the divide-by-factorial process itself is defined on the 0-based position in the lexicographic list
  - MUST: use the LARGEST leftover factorial first, walking it down by one element each round — a limit of the IDEA: choosing factorials out of order breaks the correspondence between the digit sequence and an actual base with each place's radix shrinking by one
Source: [Wikipedia — Lehmer code](https://en.wikipedia.org/wiki/Lehmer_code) · [Wikipedia — Factorial number system](https://en.wikipedia.org/wiki/Factorial_number_system)
Example: `visualizations/examples/lehmer-code.{css,html}` (no js needed — the values are static) → `visualizations/build/lehmer-code.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::CycleDetectionViaRemainders]
Class: entity
Standard name: Cycle detection via remainder tracking (why decimal expansions repeat)
Essence: There are only finitely many possible remainders in a division — so stepping through it and remembering every remainder already seen is guaranteed to find a repeat, and exactly where it starts.
Recognized by: you need the length (or existence) of a repeating pattern produced by an iterated process with a fixed, small number of possible internal states — most directly, the repeating block of a fraction's decimal expansion
General case: run the process (here, long division: multiply the remainder by 10, divide by the denominator to get the next digit, keep the new remainder) while recording the step index at which each remainder first appeared; the moment a remainder repeats, the cycle length is the CURRENT step minus the step it was first recorded at — guaranteed to happen within (denominator) steps, since there are only that many possible remainders
Picture: ![Cycle detection via remainders](visualizations/build/cycle-detection-remainders.png)
Sequence:
  1. Problem — 1/7 = 0.? ; how long is the repeating block?
  2. Transform track remainders — step by step, the remainder after each digit: 1, 3, 2, 6, 4, 5, then 1 again — already seen at step 0
  3. Solution — 1/7 = 0.(142857); cycle length = 6 &minus; 0 = 6
Limits:
  - MUST NOT: be used expecting a repeat to appear beyond (number of possible states) steps — a limit of the IDEA: the pigeonhole guarantee is exactly this bound, not an estimate
  - MUST: record the step at which EACH remainder first appears (not just the most recent one) — a limit of PRACTICE: without a per-remainder record, detecting that "this remainder happened before" is possible, but recovering exactly how long ago is not
Source: [Wikipedia — Repeating decimal](https://en.wikipedia.org/wiki/Repeating_decimal) (the remainder-tracking algorithm section)
Example: `visualizations/examples/cycle-detection-remainders.{css,html}` (no js needed — the values are static) → `visualizations/build/cycle-detection-remainders.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::NextPermutation]
Class: entity
Standard name: Next permutation in lexicographic order (Narayana Pandita's algorithm)
Essence: To get from one permutation to the very next one in dictionary order, find the last place the sequence still climbs, swap in the smallest later value big enough to keep climbing there, then flip the now-falling tail back into its own smallest order.
Recognized by: you need to generate ALL permutations of a sequence, one at a time, in lexicographic order — not the Nth one directly, and not one arbitrary permutation
General case: scan from the right for the last index i with a[i] &lt; a[i+1] (the "pivot"; if none exists, the sequence is already the last permutation); scan from the right again for the last index j &gt; i with a[j] &gt; a[i]; swap a[i] and a[j]; reverse the whole suffix after position i (it was strictly falling, so reversing makes it the smallest possible ordering of those same values)
Picture: ![Next permutation](visualizations/build/next-permutation.png)
Sequence:
  1. Problem — 1 3 5 4 2; what permutation comes right after it?
  2. Transform find &amp; swap — 3 is the last climb (3&lt;5); scanning from the right, 4 is the last value still bigger than 3; swap them, giving 1 4 5 3 2
  3. Solution — everything after the swapped-in 4 (5, 3, 2) was falling; reversing it gives 2 3 5, so the answer is 1 4 2 3 5
Limits:
  - MUST NOT: be used to jump directly to a specific far-away Nth permutation — a limit of the IDEA: each call only advances by one step; reaching the Nth permutation this way costs O(N) steps ([method::LehmerCode](#methodlehmercode) reaches it directly instead)
  - MUST: reverse the suffix, never just re-sort it — a limit of PRACTICE: the suffix is already guaranteed strictly decreasing at that point, so reversing it is the same as sorting it ascending, but a general sort would hide (and needlessly cost more than) that guarantee
Source: [Wikipedia — Permutation](https://en.wikipedia.org/wiki/Permutation) (&sect; Generation in lexicographic order)
Example: `visualizations/examples/next-permutation.{css,html}` (no js needed — the values are static) → `visualizations/build/next-permutation.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::BruteForceSearch]
Class: entity
Standard name: Brute-force search (exhaustive search, "generate and test")
Essence: Check every candidate the problem allows — but only after counting, from the given limits alone, that there are few enough of them to get through in the time available.
Recognized by: the constraints bound how many candidates exist, that count multiplied by the cost of checking one fits the time budget, and no structure in the problem is needed beyond testing each candidate against the definition
General case: multiply out the candidate count implied by the constraints (ranges times queries times per-candidate work); compare it against what the machine can do in the allowed time; if it fits, enumerate directly — the check itself is just the problem's own definition. The count is what decides, and it is computable before a line of code is written
Picture: ![Brute-force search](visualizations/build/brute-force-search.png)
Sequence:
  1. Problem — a 6&times;6 field of "?" cells: one of them is the answer, and nothing distinguishes it from the outside
  2. Transform &times; — the cells are counted without being opened (6 &times; 6 = 36) and set against a countable capacity of 100 empty slots: 36 &le; 100, so walking them all is affordable — decided before any cell is looked into
  3. Solution — the cells are opened in order, each getting a &#10003;, until the answer (&#9733;) turns up at the 23rd; the rest are never touched
Limits:
  - MUST NOT: be chosen because no better idea came to mind — a limit of the IDEA: without the count against the budget it is a guess, and the count is exactly what makes it a decision. At real scale the same comparison runs in real units: e.g. 1000 positions &times; 7 digits &times; 100 queries = 700,000 checks against a budget of roughly 100,000,000 simple steps per second — under 1% of it, so enumeration is safe
  - MUST NOT: be applied when the candidate count grows factorially or exponentially in the input size unless the input is tiny — a limit of PRACTICE: every ordering of just 20 items is already 20! &asymp; 2.4&times;10<sup>18</sup>, tens of billions of times past any per-second budget; counts of that shape pass any budget within a few steps of growth
  - MUST: the picture's 36 cells and 100 slots are deliberately toy-sized so both sides of the comparison stay literally countable — a limit of the PICTURE: real candidate counts and budgets (the 700,000 and 100,000,000 above) don't fit in a drawable grid, so the record's text carries them instead
Source: [Wikipedia — Brute-force search](https://en.wikipedia.org/wiki/Brute-force_search) ("systematically checking all possible candidates"; the article makes candidate count versus available resources the deciding factor) · [Wikipedia — Enumeration algorithm](https://en.wikipedia.org/wiki/Enumeration_algorithm)
Example: `visualizations/examples/brute-force-search.{css,html,js}` → `visualizations/build/brute-force-search.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::VariableElimination]
Class: entity
Standard name: Elimination by substitution (solving a system of equations)
Essence: When the unknowns are tied together by an equation, one of them can be written in terms of the others and substituted away — the search then runs over one fewer unknown.
Recognized by: you are searching over two or more unknowns that must satisfy given equations, and at least one of those equations can be solved for one unknown in terms of the rest
General case: solve one constraint for one unknown; substitute that expression into the remaining constraints; the search space loses a whole dimension per unknown eliminated. Works for non-linear systems too, as long as the chosen unknown can actually be isolated — and each substituted value must still be checked for validity (a whole number, inside range, in the required order)
Picture: ![Variable elimination](visualizations/build/variable-elimination.png)
Sequence:
  1. Problem — two unknowns with 6 possible values each: 36 pairs to try
  2. Transform substitute — they are tied by a + b = 7, so b = 7 &minus; a; b stops being free
  3. Solution — 6 pairs left instead of 36, one per value of a; the square of candidates has collapsed to a line through it
Limits:
  - MUST NOT: be treated as removing the need to CHECK the substituted value — a limit of PRACTICE: the derived value can come out fractional, negative, or out of the required order, and each of those still has to be rejected explicitly
  - MUST: isolate an unknown that the constraint actually determines uniquely — a limit of the IDEA: if the constraint leaves two possible values (a square root, say), the substitution branches instead of eliminating, and the dimension does not drop
Source: [Wikipedia — System of equations](https://en.wikipedia.org/wiki/System_of_equations) · [Wikipedia — System of linear equations](https://en.wikipedia.org/wiki/System_of_linear_equations) (&sect; substitution: "solve the top equation for x in terms of y... substitute this expression... results in a single equation involving only the variable y" — stated there for a linear system; the same move is what eliminates an unknown in a non-linear one)
Example: `visualizations/examples/variable-elimination.{css,html,js}` → `visualizations/build/variable-elimination.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)

## [method::Canonicalization]
Class: entity
Standard name: Canonicalization (via a canonical/equivalence-class representative)
Essence: When several different starting points can produce overlapping results, pick exactly one canonical starting point per group that produces the same results, and only ever start from that one — every other member of the group is a known duplicate and is skipped outright, never processed.
Recognized by: distinct outputs are generated from a set of starting points (bases, seeds), and one starting point's whole output is provably a subset of another, smaller starting point's output — so processing both would recount the smaller one's results
General case: define which starting points are equivalent (one is expressible as a fixed transform of a smaller one); for each equivalence class pick the smallest/simplest member as the canonical representative; scan all starting points in order, and skip any that is not canonical the moment it is recognized as a transform of an already-seen smaller one — only representatives ever get processed
Picture: ![Canonicalization](visualizations/build/canonicalization.png)
Sequence:
  1. Problem — 9 candidate bases, 2 through 10, nothing known about them yet
  2. Transform &#61; — 3 of them are a smaller base raised to a power already in the row (4&#61;2&sup2;, 8&#61;2&sup3;, 9&#61;3&sup2;) &mdash; marked as duplicates of that smaller base
  3. Solution — the 6 canonical bases (2, 3, 5, 6, 7, 10) get processed; the 3 duplicates are skipped, never touched again
Limits:
  - MUST NOT: be applied unless the "is-a-transform-of" relation between starting points is actually provable ahead of time — a limit of the IDEA: guessing at equivalence without proof can silently drop a starting point that was not really a duplicate
  - MUST: recognize a starting point as non-canonical BEFORE doing any of its own work — a limit of PRACTICE: checking after the fact defeats the purpose, since the duplicate work has already been paid for
  - MUST: the picture's 9 bases are deliberately small enough to read every relation by eye — a limit of the PICTURE: real equivalence classes (e.g. every power of 2 up to a large N) can have far more than 3 members, which a row this size cannot show without the reader losing count
Source: [Wikipedia — Canonicalization](https://en.wikipedia.org/wiki/Canonicalization) (lead section: canonicalization is used "to compare different representations for equivalence, to count the number of distinct data structures... and to make it possible to build efficient algorithms by regularizing... redundant information") · [Wikipedia — Equivalence class](https://en.wikipedia.org/wiki/Equivalence_class) (&sect; representative) · [Wikipedia — Canonical form](https://en.wikipedia.org/wiki/Canonical_form) ("for a class of objects on which an equivalence relation is defined, a canonical form consists in the choice of a specific object in each class")
Example: `visualizations/examples/canonicalization.{css,html,js}` → `visualizations/build/canonicalization.html`
Spec: [approaches](specs/approaches.md) · [visualizations](specs/visualizations.md)
