---
status: draft
app: projecteuler
tags: [projecteuler, visualization, catalog, explanation, draft]
---

# Explanation method: requirements on the PICTURE

## Vision
Someone with no preparation looks at the picture and, without reading any text, understands which
problem the method leads out of and into which solution: the first frame is what is wrong, the last
is the answer, the ones between are the steps. The same request for a method always yields the same
picture — a catalog, not an improvisation.

This spec and its sibling [approaches](approaches.md) describe THE SAME set of `[method::*]`
records in `_terms.md` from two sides: here, the requirements on the picture; there, on the idea
itself. Not two catalogs — two aspects of one.

The requirements come from the revision cycle of 2026-09-01 on euler001 (retro: 13 rounds, 5
escalation points); each requirement below is tied to the round in which it was violated.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Domain terms live in `_terms.md`,
context `method`: [method::Catalog](../_terms.md#methodcatalog),
[method::PageSkeleton](../_terms.md#methodpageskeleton),
[method::SkipCounting](../_terms.md#methodskipcounting),
[method::InclusionExclusion](../_terms.md#methodinclusionexclusion),
[method::ArithmeticProgressionSum](../_terms.md#methodarithmeticprogressionsum),
[method::VennDiagram](../_terms.md#methodvenndiagram),
[method::BinarySearch](../_terms.md#methodbinarysearch),
[method::TrialDivision](../_terms.md#methodtrialdivision).

## Scope
**In scope:** the layout of `memory-bank/visualizations/` (shell, frame code, build, output) and
the picture fields of `[method::*]` blocks (`Picture` / `Sequence` / `Example` / the drawing half
of `Limits`), the rules for choosing a form, frame structure, determinism of rebuilds, and the
builder skill `.claude/skills/visualize-approach/SKILL.md`.

**Out of scope:** the idea fields of those same blocks (`Essence` / `Recognized by` /
`General case` / `Source`) — see [approaches](approaches.md); speedup techniques (`TRICKS.md`);
publishing pictures to the cloud (deliberately rejected — the build is local only); and the
problems themselves (statement, solution, correctness criteria), which live in
`euler{NNN}/README.md`, not here (see MUST-no-task-specifics).

## Findings this is built on
- **F1** Cards were chosen by whether a canonical name existed rather than by how understandable
  they were — which led as far as adopting the Sieve of Eratosthenes with its purpose inverted.
  Traces to: MUST-form-before-name.
- **F2** Four times running, a defect in a picture was first spotted by the owner from a screenshot
  (twice a coincidence of the numbers 30/30, twice arcs drifting out of place); verification
  amounted to counting tags, and arc coordinates were computed from assumptions about the layout.
  Traces to: MUST-render-observed, MUST-geometry-measured, MUST-distinct-step-numbers.
- **F3** The "when to apply" field restated the example's parameters ("one or two small numbers, a
  short stretch") instead of the class of problems; after the first remark one card was fixed
  rather than the principle. Traces to: MUST-applicability-is-class, MUST-fix-propagates.
- **F4** A single static "solution" frame plus paragraphs of prose — the move from problem to
  answer lived only in the text ("pretty, but it isn't clear what leads to what"). Traces to:
  MUST-frame-sequence, MUST-symbolic-labels, MUST-text-in-spec.
- **F5** After the texts were moved into markdown, only the idea of the frames remained there while
  the real numbers and layout lived in a temporary file — a rebuild would not have matched. Traces
  to: MUST-deterministic-rebuild, MUST-code-separate.
- **F6** Three redirect stubs from old working names shipped to the public repository with no
  inbound link at all — they read as seven techniques instead of four. Traces to:
  MUST-redirect-only-if-linked.
- **F7** Approaches and pictures existed as two disconnected lists, then were connected by
  cross-links. Later it turned out that having two lists was itself the duplication — see F12.
- **F8** (euler002) For the second time running, one of the two halves of a solution (building the
  list) got no visualization — the same class as F1's skip counting: a preparatory step, not a
  technique. It confirms MUST-applicability-is-class from the other side: not every half of an
  algorithm deserves a picture, only what is a recognizable technique in its own right (here,
  binary search).
- **F9** (euler003) Before choosing a form for trial division, two standard candidates were
  compared — the free-form "factor tree" (any factor pair at each step) and the "ladder method"
  (strictly the smallest prime divisor, dividing until what remains is itself prime). The ladder
  was chosen as the only one of the two that literally mirrors the implemented algorithm's
  mechanics (all the 2s first, then odd divisors ascending) rather than merely illustrating the
  general idea of factoring. Traces to: MUST-form-before-name.
- **F10** (user request: "the memory bank must not contain specific problems")
  `specs/euler001.md`/`euler002.md`/`euler003.md` and the `[euler::*]` blocks in `_terms.md` held
  the statements and correctness criteria of specific problems — not reusable knowledge, since a
  solved problem has already been checked once by a real submission. Deleted. The intermediate step
  — turning `Used in:` into a real link instead of plain text — proved incomplete: see F11.
- **F11** (user's next question: "these are supposed to be just the primitives, no?") The `Used in:`
  field itself, even as a link, is a mention of a specific problem in a file that is supposed to say
  nothing about problems at all. Removed from every record; the link is one-directional — the
  problem points at the primitive from its own README, and the catalog knows nothing of problems.
  Traces to: MUST-no-task-specifics (tightened).
- **F12** (user: "there are duplicates again") The two contexts `[viz::*]` and `[approach::*]`
  turned out to be duplication: two blocks with identical names (`VennDiagram`, `BinarySearch`),
  each of five pictures embedded twice, sources and descriptions repeated. Merged into one `method`
  context: a picture is a set of fields on a method record, not a record of its own. The card's
  `Approach:` field and the approach's `Visualized by:` field (the cross-links between the lists)
  disappeared as unnecessary. Side finding while fixing it: the `cards()` table in `build.sh` feeds
  the term name into the caption ON THE PICTURE ITSELF — after renaming the blocks the captions
  would have pointed at names that no longer exist (`[method::LadderMethod]`), so the table is
  edited together with `_terms.md` and the pictures rebuilt. Traces to:
  MUST-single-entry-per-method (in [approaches](approaches.md)), MUST-term-name-matches-block.
- **F13** (user request: the whole repository strictly in English) Translating the shell's
  `<html lang="ru">` to `lang="en"` silently broke the light-theme pinning in `build.sh`, whose
  `sed` keyed on the exact Russian-language tag — the rebuilt PNGs came out dark. Caught by looking
  at the rendered picture (principle 2), not by any check of the text. The substitution now matches
  `<html ...>` regardless of attributes. Traces to: MUST-render-observed,
  MUST-theme-pinning-language-agnostic, MUST-english-only.

## Architecture

### Overview (prose)
Three separate sources, assembled by a script: the shared page shell
([method::PageSkeleton](../_terms.md#methodpageskeleton), `visualizations/skeleton.html`), the
method's description (the `[method::*]` block in `memory-bank/_terms.md`: what it is, where it
comes from, applicability, limits, picture) and the frame code
(`visualizations/examples/<slug>.{css,html,js}`). `visualizations/build.sh` substitutes the code
into the shell → `build/<slug>.html`, then a headless browser (light theme, width 720, height
measured from the card) → `build/<slug>.png`; the png is embedded in the term block via `Picture:`.
The skill finds the block → runs `build.sh <slug>` → looks at the png → opens the html. No
rendering "by eye", no cloud, no hand-made pictures.

### Bounded Context and Aggregate Root
- `method` — the only context: [method::Catalog](../_terms.md#methodcatalog) (root): Method, Frame;
  [method::PageSkeleton](../_terms.md#methodpageskeleton) (VO). There is no separate context for
  ideas — idea and picture are fields of one record (see F12).

## Requirements
> Statement — acceptance criterion — status.

### MUST
- The visual form MUST be chosen by how understandable it is at a glance to someone with no
  preparation; the standard name is looked up AFTER the form is chosen, and for that form —
  **MUST-form-before-name** — criterion: the record's `Standard name:` and `Source:` refer to the
  form actually drawn, not to a relative with a different purpose. Status: done (skip counting, bar
  model, Gauss pairing, Venn, binary search, ladder method).
- The picture MUST be a sequence of frames: the first is Problem (an unsolved situation, marked
  wrong or unknown), the last is Solution, with one or more Transform frames between —
  **MUST-frame-sequence** — criterion: the record's `Sequence:` field and the markup of
  `examples/<slug>.html` contain the same frames in the same order; a single static frame is a
  violation. Status: done (6/6).
- Labels on the picture MUST be symbolic marks (`?`, `×2`, `−`, `↔`, `∩`, `=`) and MUST NOT be
  sentences — **MUST-symbolic-labels** — criterion: inside `frame-tag` in `examples/<slug>.html`
  there is no text longer than one character or short token. Status: done.
- Everything meant to be read (description, applicability, limits, source) MUST live in the record,
  not under the picture — **MUST-text-in-spec** — criterion: the built page has no paragraphs below
  `.flow`, only a link to the record. Status: done.
- "Done" MUST NOT be declared until the render has been observed (screenshot/zoom); counting tags
  MUST NOT count as checking the picture — **MUST-render-observed** — criterion: there is an
  observation step before showing the owner, and the owner is not the first to see the picture.
  Status: partial — `build.sh` always produces a png and the skill requires reading it (steps
  3/4e), but there is no mechanical block on showing without looking (violated 4 times in the
  originating session; on the first `build.sh` run, looking at the png immediately caught a clipped
  label on the Gauss arc and a dark theme; later it caught the dark-theme regression of F13).
- The geometry of overlays (arcs, arrows, labels above elements) MUST be measured from the rendered
  elements and MUST NOT be computed from assumed CSS sizes — **MUST-geometry-measured** —
  criterion: `examples/*.js` take coordinates via `getBoundingClientRect` and contain no hardcoded
  cell widths. Status: done (skip-counting.js, gauss-pairing.js).
- Every intermediate number in an example MUST be distinguishable between steps —
  **MUST-distinct-step-numbers** — criterion: the list of numbers across all frames contains no
  coincidences arising for different reasons (30 as an area and 30 as the total is a violation).
  Status: done (Gauss: 4..20, pairs of 24, total 60).
- The applicability field MUST describe a class of problems and MUST NOT restate the example's
  parameters — **MUST-applicability-is-class** — criterion: the wording excludes no case the method
  actually covers; the example's own constraints, where they bind, go into `Limits` marked as a
  limit of the drawing rather than of the method. Status: done.
- Limits MUST name the real cause of the limit — **MUST-limits-are-causal** — criterion: no
  formulations like "it gets crowded / confuses the eye"; there is a mechanism (three conditions do
  not line up in one row; four circles provably cannot cover every intersection). Status: done.
- A wording fix in one record MUST be checked against all the others at once —
  **MUST-fix-propagates** — criterion: a class of error is closed in one round, not one record per
  remark. Status: process-level, PASSIVE.
- Rebuilding a method MUST yield a byte-identical picture — **MUST-deterministic-rebuild** —
  criterion: the page is assembled by copying the shell + `examples/<slug>.*`; no number, color or
  class lives outside version-controlled files. Status: done.
- The frame code MUST be stored separately from the record, which references it via `Example:` —
  **MUST-code-separate** — criterion: the `[method::*]` block contains no code, only an `Example:`
  field with paths; `examples/<slug>.{css,html,js}` exist and match what the builder inserts.
  Status: done.
- The term name in the `cards()` table (`build.sh`) MUST match the `[method::*]` block name — it is
  substituted into the caption ON THE PICTURE ITSELF — **MUST-term-name-matches-block** —
  criterion: for every `cards()` row the anchor `#method<term>` resolves to a real heading in
  `_terms.md`; the picture slug may differ from the method name (`ladder-method` ↔
  `TrialDivision`). Status: done (after F12 — renaming the blocks would have left the captions
  dead).
- The light-theme pinning in `build.sh` MUST NOT depend on the page's language or any other shell
  attribute — **MUST-theme-pinning-language-agnostic** — criterion: the `sed` matches `<html ...>`
  with any attributes; a language switch does not change the theme of the output. Status: done
  (after F13, where exactly this produced dark PNGs).
- The shared example MUST be one for the whole catalog ("numbers below 20, multiples of 2 or 3")
  and MUST NOT coincide with a specific problem's numbers — **MUST-shared-example** — criterion: no
  record contains euler001's 3 and 5; a new method incompatible with the example introduces its own
  and explains why. Status: done.
- A redirect stub from an old name MUST be left only when inbound links exist; without them the old
  file is deleted — **MUST-redirect-only-if-linked** — criterion: a grep for the old name was run
  before choosing. Status: done (three stubs deleted after the grep).
- Every built page and every png MUST carry a QR code to the repository
  (`https://github.com/Hedgehogues/project-euler`) plus the address in text — a picture travels
  separately from its text, so the way back to the sources has to be on the picture itself —
  **MUST-qr-repo-link** — criterion: the QR is a block of the shell `skeleton.html` (`.repo`), not
  of a method; `build.sh` fails without `visualizations/qr-repo.svg`; after generating a QR it is
  decoded from the built png and yields exactly this URL. Status: done.
- The text of records and specs MUST NOT name children or school as the audience — the simplicity
  level is set by the requirement, not by an addressee — **MUST-no-audience-mention** — criterion: a
  case-insensitive grep for those words across the catalog is empty. Status: done.
- Everything in the repository — records, specs, build scripts, page shell, frame labels and the
  text rendered into the pictures — MUST be in English — **MUST-english-only** — criterion: a grep
  for Cyrillic across all tracked files of the public repository is empty. Status: done (the
  translation pass is F13; the pictures were rebuilt so their captions are English too).
- The catalog MUST NOT hold ANYTHING about a specific problem — no statement, no solution, no
  correctness criteria, not even a "used in" backlink — **MUST-no-task-specifics** — criterion:
  `memory-bank/` contains no `specs/euler{NNN}.md`, no `[euler::*]` blocks and no `Used in:` field;
  the link is one-directional — the problem references the block here by name. Status: done (in two
  passes — F10, then F11).

### SHALL
- The builder skill SHALL read `_terms.md` as the first step of every invocation and SHALL NOT rely
  on memory of a previous one — **SHALL-terms-first**. Status: done (SKILL.md, step 1).
- A new method SHALL go through the full cycle (standard-name lookup → shared example → `Sequence`
  → `[method::*]` block + `examples/` + `cards()` row) BEFORE being shown to the owner —
  **SHALL-full-cycle-before-show**. Status: done (SKILL.md, step 4).
- An ambiguous match against two or more records SHALL be resolved by asking the owner rather than
  guessing — **SHALL-ask-on-ambiguity**. Status: done (SKILL.md, step 5).

### SHOULD
- The render-observation step (MUST-render-observed) SHOULD be mechanized in the skill as a
  mandatory screenshot step rather than prose — **SHOULD-mechanize-render-check**. Status: not done.
- The distinct-numbers check (MUST-distinct-step-numbers) SHOULD be performed against a list of
  numbers in the record rather than by eye — **SHOULD-number-list-check**. Status: not done.

## Links
- Rules: `.claude/rules/visualization-principles.md` (principles 1–12, each ↔ a MUST above).
- Skill: `.claude/skills/visualize-approach/SKILL.md` (shell + build).
- Records: `memory-bank/_terms.md`; index — `memory-bank/index.md`.
- The other aspect of the same records: [approaches](approaches.md) (requirements on the idea).
