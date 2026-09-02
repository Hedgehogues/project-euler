---
name: document-problem
description: Writes the full catalog write-up for a solved problem under problems/euler{NNN}/ — README.md, memory-bank/specs/tasks/euler{NNN}.md, and any new memory-bank/_terms.md method entries the solution needs — by following the shape already established by euler001/002/003, not improvising a new one. Escalates to the user (AskUserQuestion) instead of guessing wherever the new problem doesn't fit that precedent cleanly.
---

# Documenting a solved problem

This skill produces the whole write-up for ONE problem — README, spec, and whichever method
entries it needs, including drawing a picture for a genuinely new method — reusing the catalog
wherever possible and extending it only when genuinely new.

Precondition: `problems/euler{NNN}/solution.cpp` already exists and is believed correct (Accepted
on HackerRank, or the user says it's ready). This skill does not derive the algorithm — it
documents one that already works. If no solution exists yet, that's a different task; say so and
stop.

The full formal requirements this skill's output must satisfy: `memory-bank/specs/tasks.md`
(spec format), `memory-bank/specs/approaches.md` (idea quality), `memory-bank/specs/visualizations.md`
(picture quality). This file is the mechanics of getting there by following precedent
(`problems/euler001`, `euler002`, `euler003` and their specs) rather than re-deriving the format
from the RFC documents each time.

## Steps (in order)

1. **Read the precedent.** Open one existing `problems/euler{NNN}/README.md` and its
   `memory-bank/specs/tasks/euler{NNN}.md` side by side — these are the actual template, not a
   description of one. **Read `memory-bank/_terms.md` in full** — mandatory first step, every
   invocation, never rely on memory of what's catalogued from an earlier session.

2. **Verify the solution actually works, live — never assert it from memory or from the fact that
   `solution.cpp` compiles.** Per `specs/tasks.md`'s MUST-status-is-evidence: compile it, run it
   against the official samples, and cross-check against an independent brute-force script (or, if
   one exists, the real HackerRank submission id/date via the REST API in `.env.hackerrank`). The
   README's and spec's `Status:`/verification lines must name what was ACTUALLY run this time, not
   repeat a claim from an earlier session.
   - **Escalate** if no independent verification is feasible for this problem's shape (no clean
     brute-force oracle exists, no submission id is available) — do not write a "done" status you
     couldn't actually check.

3. **Identify the technique(s) the solution uses**, then classify each one against the catalog:
   - **Already catalogued** (an existing `[method::Name]` block in `_terms.md` describes it) —
     reuse by reference. Per MUST-reuse-changes-nothing, this touches ZERO lines of `_terms.md`.
   - **Not catalogued** — add it properly, in this order, not as a shortcut inline description:
     (a) `WebSearch` for the established name and an encyclopedic source (Wikipedia, Britannica,
     cp-algorithms, a professional body — blogs are supplements only) BEFORE writing anything; if
     none exists, say so in the record rather than inventing a citation. This search covers the
     PICTURE too, not just the name — before writing `Picture: —`, actually check whether a
     standard visual exists for the quantity/goal this method computes, even under a DIFFERENT
     mechanism, rather than copying the "no picture" reasoning from a structurally similar prior
     record by inertia. If one exists for a different mechanism, say so explicitly and explain why
     it doesn't apply (drawing it would show the technique this method avoids, not the technique
     itself) — that is a real, specific reason; "no established form" asserted without having
     looked is not. Precedent: `[method::LCMViaGCD]`'s `Picture: —` first said "no established
     visual form of its own" without checking — Wikipedia's own Least Common Multiple article
     describes a real, standard Venn-diagram-via-prime-factorization visualization, just for a
     different (factoring) technique than this method's (gcd-arithmetic) one. Caught only when the
     user asked directly "where's the visualization for this one?" of two records in a row;

     (b) reuse the catalog's shared example ("multiples of 2 or 3, below 20"), or make a small one
     of your own and explain in the record why the shared one doesn't fit;
     (c) design the `Sequence:` from Problem to Solution, writing out every number of every frame
     to confirm no accidental coincidences between steps (principle 3);
     (d) write `visualizations/examples/<slug>.{css,html,js}` — overlay geometry (arcs, labels
     above elements) via `getBoundingClientRect`, never from assumed CSS constants (principle 2);
     (e) add a row to `cards()` in `memory-bank/visualizations/build.sh`, run
     `build.sh <slug>`, and **look at the resulting `build/<slug>.png` (Read it)** — the mandatory
     observation step before showing anything to the user, never skipped on the assumption the
     markup must be fine;
     (f) write the `[method::Name]` block in `_terms.md` — ONE block, idea and picture fields on
     the same record (Essence/Recognized by/General case/Source; Picture/Sequence/Example; a
     shared Limits marking which limit belongs to the idea and which only to the drawing) — never
     a separate "for the picture" block (principle 9);
     (g) **before calling the picture done, list every number that appears in the solution frame's
     caption and confirm each one is directly visible or countable in an EARLIER frame** — a
     number that only shows up in the final caption, with no earlier frame it can be checked
     against, means the picture doesn't carry its own causal chain (principle 5) no matter how
     polished it looks; go back and add the missing step, or find/build the frame that makes the
     number countable, before moving on. Precedent: this exact gap shipped twice in one session
     with two different records — `LCMViaGCD`'s second design asserted `3×35=7×15=105` in a
     caption with the 3 and 7 nowhere derivable earlier in the sequence, and `SumOfSquares`'s
     first design asserted `=4·5·9/6` the same way — both caught only by the user asking directly
     what in the picture explains how the result is obtained, not by this skill's own process.
     Having principle 5 written down did not, by itself, stop the violation from recurring; this
     explicit per-number check is the step that's supposed to catch it before the user has to.
     (h) **the same audit for every OPERATION, not just every number.** For each arrow between two
     frames, name the operation it performs (×6, ln, +ln ln, round up, ...) and point at the element
     of the PREVIOUS frame that makes a stranger expect exactly that operation next. No such element
     — the reader will experience the operation as a given, however correct the numbers are; add the
     frame or the visual mark BEFORE showing, not after the complaint. The number check (g) cannot
     catch this: numbers can all trace back cleanly while the reason for the step never appears.
     Precedent: two pictures in one session (`Precomputation`, `NthPrimeBound`) went through SEVEN
     rounds of "непонятно, в чём суть / откуда это берётся" — each round I patched exactly the one
     link the user had just stumbled on (why ×6, why ln, why ln ln, what the answer even is) and
     shipped, and the next link was missing. Every one of those links was obvious to me, which is
     precisely why a per-step audit has to be written down: the author cannot see them by looking.
     Cheap form: describe the picture to yourself frame by frame using ONLY what is drawn; every
     "and then we..." that needs a word not on the picture is a missing element.
   - **A formula is a composition until proven otherwise.** A method whose General case is a
     formula with two or more distinct operations inside (a log, a product, an iteration, a bound)
     gets the independence test run on EACH operation before anything is drawn: "is this operation
     recognized in another problem without the rest of the formula?" — yes → its own record, and
     the formula's picture only shows the parts meeting. Precedent: `NthPrimeBound` lived as one
     "atomic" record through four redesigns because a theorem read as one indivisible thing; the
     picture kept failing because it was trying to teach `PrimeNumberTheorem`,
     `FixedPointIteration` and `LogarithmProductRule` at once — split only when the user asked to
     "break it into parts and visualize each separately".
   - **Escalate** if the solution combines two or more techniques and it's unclear whether they are
     one atomic idea or should be split into independent records (per MUST-atomic-or-composed, the
     real test is "is each one recognizable in ANOTHER problem without the other" — if that test
     doesn't resolve cleanly, ask rather than pick one side). Precedent this session got wrong once
     before asking: euler002's precompute+binary-search were first fused into one record, then split
     after the user asked directly "is it really just one approach?".
   - **Escalate** if a candidate method's only findable source is a blog/teaching site with no
     encyclopedic citation (Wikipedia/Britannica/cp-algorithms/a professional body) — don't catalog
     it on a weak source and hope to fix it later.
   - **Escalate** if the technique matches two or more existing `[method::Name]` blocks about
     equally well — ask which one, don't guess.
   - **Determinism**: rebuilding an EXISTING method (no `examples/` edit) must yield a byte-for-byte
     identical page — if a rebuild differs, that's a bug in `build.sh`/`examples/`, not acceptable
     variance; fix the mismatch before moving on, don't just re-run and hope.

4. **Write `problems/euler{NNN}/README.md`**, matching the existing three's shape exactly:
   - Title line (`# euler{NNN} — <name>`), one-paragraph problem statement.
   - `## Approach` — bullet steps of the algorithm, then a `Status:` line naming the actual
     verification from step 2 (submission id + date, and/or the brute-force check just run, with
     the specific inputs checked).
   - `## The idea(s) behind it` — one short paragraph per method used, each linking
     `[\`[method::Name]\`](../../memory-bank/_terms.md#methodname)`, with the picture embedded
     (`[![Standard name](../../memory-bank/visualizations/build/<slug>.png)](.../build/<slug>.html)`)
     for every method that has one.
   - `## Build & run` — the standard `g++ -O2 -std=c++20 -o solution solution.cpp && ./solution <
     input.txt` block.
   - A line pointing at the spec: `Full requirements and acceptance criteria:
     [spec.md](../../memory-bank/specs/tasks/euler{NNN}.md).`

5. **Write `memory-bank/specs/tasks/euler{NNN}.md`**, following `specs/tasks.md`'s format
   requirement by requirement — six sections in this exact order (MUST-section-shape): Vision,
   Terms, Scope, Architecture, Requirements, Links.
   - Vision MUST name the specific constraint that rules out a naive approach
     (MUST-vision-names-constraint) — not just restate the statement.
   - Terms MUST link every method used via `[method::Name](../../_terms.md#methodname)`
     (MUST-methods-resolve) — verify each anchor actually exists in `_terms.md` before writing it.
   - Requirements MUST each be phrased statement — bold `**MUST-id**` — `criterion:` —
     `Status:` (MUST-requirement-shape), MUST include a correctness requirement whose `Status:`
     names real evidence from step 2 (MUST-status-is-evidence), and MUST include ASCII-only and
     I/O-format requirements naming the real `problems/euler{NNN}/solution.cpp` path
     (MUST-standard-requirements).
   - MUST NOT define a new `[method::*]` block inside this file (MUST-no-new-methods-here) — if
     step 3 found something uncatalogued, it was catalogued in `_terms.md` FIRST, in its own step.
   - **Escalate** if the Vision's "why naive fails" isn't obvious from the constraints given — this
     usually means the problem needs re-reading, not a guessed number.

6. **Update the shared surfaces**: add the problem's row to the root `README.md` table; if any new
   method was catalogued in step 3, verify `memory-bank/index.md`'s method list and
   `.claude/rules/visualization-principles.md`'s principle count are still current (they list exact
   counts — a stale count is a small, easy-to-miss drift, not a reason to skip the check).

7. **Escalate — folder taxonomy** (principle 16): if the number of problems under `problems/` is
   starting to make that single flat folder feel like it's mixing kinds again (a distinction not
   yet visible in the tree), name it explicitly rather than silently letting it re-accumulate — the
   fix pattern (a subfolder per kind) is established, but WHEN to apply it again is a judgement
   call for the user, not a threshold to guess at.

## What "escalate" means here

`AskUserQuestion` with the specific fork named (not "does this look right?") — e.g. "this solution
uses precomputation and binary search together; precedent says these are usually two independent
records, but here they're always used together in this problem family — split or keep as one?" A
question naming the actual fork, not a status update disguised as a question.

## Language

Everything this skill writes — README, spec, new `[method::*]` records, frame labels, anything
rendered into a picture — is English (principle 13). After any edit on the picture side, rebuild;
a translated source shipping with a stale, still-Russian PNG is a real, previously-hit bug.

## Verified-not-assumed discipline

Every claim this skill's output makes (Accepted status, a method being genuinely uncatalogued yet,
an anchor resolving, a source being encyclopedic) is checked live in the current session, the same
way every prior round in this catalog's history was — re-asserting an earlier session's claim
without re-running the check is exactly the mistake `specs/tasks.md`'s MUST-status-is-evidence
exists to prevent.
