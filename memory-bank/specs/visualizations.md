---
status: draft
app: projecteuler
tags: [projecteuler, visualization, catalog, explanation, draft]
---

# Explanation method: requirements on the PICTURE

## Layer

This layer sits **above the ideas** and depends on them one-way:

```
problems (problems/euler{NNN}/README.md)  →  pictures (this spec)  →  ideas (specs/approaches.md)
```

This spec may — and does — reference [approaches](approaches.md); that spec references nothing
here, and must stay readable with this one closed. Because this is the dependent layer, it is also
where every rule ABOUT THE RELATIONSHIP between an idea and its picture lives: how many pictures an
idea may have, what happens when it has none, and when a picture may not be used as an argument
about an idea. Those rules touch both sides, and only the side that is allowed to know both can
carry them.

## Vision
Someone with no preparation looks at the picture and, without reading any text, understands which
problem the method leads out of and into which solution: the first frame is what is wrong, the last
is the answer, the ones between are the steps. The same request for a method always yields the same
picture — a catalog, not an improvisation.

The requirements come from the revision cycle of 2026-09-01 on euler001 (retro: 13 rounds, 5
escalation points); each requirement below is tied to the round in which it was violated.

## Terms
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY as in RFC 2119. Domain terms live in `_terms.md`,
context `method`: [method::SkipCounting](../_terms.md#methodskipcounting),
[method::InclusionExclusion](../_terms.md#methodinclusionexclusion),
[method::ArithmeticProgressionSum](../_terms.md#methodarithmeticprogressionsum),
[method::VennDiagram](../_terms.md#methodvenndiagram),
[method::Precomputation](../_terms.md#methodprecomputation),
[method::BinarySearch](../_terms.md#methodbinarysearch),
[method::TrialDivision](../_terms.md#methodtrialdivision),
[method::EuclideanAlgorithm](../_terms.md#methodeuclideanalgorithm),
[method::LCMViaGCD](../_terms.md#methodlcmviagcd),
[method::SumOfSquares](../_terms.md#methodsumofsquares),
[method::SieveOfEratosthenes](../_terms.md#methodsieveoferatosthenes),
[method::NthPrimeBound](../_terms.md#methodnthprimebound),
[method::PrimeNumberTheorem](../_terms.md#methodprimenumbertheorem),
[method::PrefixSum](../_terms.md#methodprefixsum),
[method::DivisorCountFormula](../_terms.md#methoddivisorcountformula),
[method::BigIntegerArithmetic](../_terms.md#methodbigintegerarithmetic),
[method::Memoization](../_terms.md#methodmemoization),
[method::FastExponentiation](../_terms.md#methodfastexponentiation),
[method::ModularInverseFermat](../_terms.md#methodmodularinversefermat),
[method::LatticePaths](../_terms.md#methodlatticepaths),
[method::DynamicProgramming](../_terms.md#methoddynamicprogramming),
[method::DayOfWeekFormula](../_terms.md#methoddayofweekformula),
[method::LehmerCode](../_terms.md#methodlehmercode),
[method::CycleDetectionViaRemainders](../_terms.md#methodcycledetectionviaremainders),
[method::NextPermutation](../_terms.md#methodnextpermutation),
[method::BruteForceSearch](../_terms.md#methodbruteforcesearch),
[method::VariableElimination](../_terms.md#methodvariableelimination).

## Scope
**In scope:** the layout of `memory-bank/visualizations/` (shell, frame code, build, output); the
picture fields of `[method::*]` records (`Picture` / `Sequence` / `Example` and the part of
`Limits` that bounds the drawing); the rules for choosing a form; frame structure; determinism of
rebuilds; the builder skill `.claude/skills/document-problem/SKILL.md`; and every rule about how
a picture relates to its idea.

**Out of scope:** the idea fields themselves — see [approaches](approaches.md); speedup techniques
(`TRICKS.md`); publishing pictures to the cloud (deliberately rejected — the build is local only);
and the problems themselves, which live in `problems/euler{NNN}/README.md`.

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
  MUST-frame-sequence, MUST-symbolic-labels, MUST-text-in-record.
- **F5** After the texts were moved into markdown, only the idea of the frames remained there while
  the real numbers and layout lived in a temporary file — a rebuild would not have matched. Traces
  to: MUST-deterministic-rebuild, MUST-code-separate.
- **F6** Three redirect stubs from old working names shipped to the public repository with no
  inbound link at all — they read as seven techniques instead of four. Traces to:
  MUST-redirect-only-if-linked.
- **F7** An idea with no established visual form (skip counting for "multiple of", later
  precomputation) kept being treated as if the missing picture said something about the idea — once
  as "then it is not a technique", once as "then it is not a separate record". It says nothing
  about the idea: it is a fact about this layer only. Traces to: MUST-picture-optional,
  MUST-picture-absence-says-nothing, MUST-no-invented-idea.
- **F8** (euler003) Before choosing a form for trial division, two standard candidates were
  compared — the free-form "factor tree" (any factor pair at each step) and the "ladder method"
  (strictly the smallest prime divisor, dividing until what remains is itself prime). The ladder
  was chosen as the only one of the two that literally mirrors the implemented algorithm's
  mechanics (all the 2s first, then odd divisors ascending) rather than merely illustrating the
  general idea of factoring. Traces to: MUST-form-before-name.
- **F9** (user: "one approach — one picture") Inclusion–exclusion carried TWO pictures (the bar and
  the Venn diagram). An honest review showed these are two independently standard ideas often used
  together — counting arithmetic versus representing logical propositions with circles (John Venn,
  1880, for an entirely different purpose) — so the right fix was two records, not one record with
  two portraits. Both pictures kept, each with its own record. Traces to: MUST-one-picture-max.
- **F10** (user: "there are duplicates again") The two contexts `[viz::*]` and `[approach::*]`
  turned out to be duplication: two blocks with identical names (`VennDiagram`, `BinarySearch`),
  each of five pictures embedded twice, sources and descriptions repeated. Merged into one `method`
  context: a picture is a set of fields on a method record, not a record of its own. Side finding
  while fixing it: the `cards()` table in `build.sh` feeds the term name into the caption ON THE
  PICTURE ITSELF — after renaming the records the captions would have pointed at names that no
  longer exist (`[method::LadderMethod]`), so the table is edited together with `_terms.md` and the
  pictures rebuilt. Traces to: MUST-single-record-per-method, MUST-term-name-matches-record.
- **F11** (user request: the whole repository strictly in English) Translating the shell's
  `<html lang="ru">` to `lang="en"` silently broke the light-theme pinning in `build.sh`, whose
  `sed` keyed on the exact Russian-language tag — the rebuilt PNGs came out dark. Caught by looking
  at the rendered picture (F2's rule), not by any check of the text. The substitution now matches
  `<html ...>` regardless of attributes. Traces to: MUST-render-observed,
  MUST-theme-pinning-language-agnostic, MUST-english-only.
- **F12** (user: "the requirements on pictures and on ideas must be independent") The idea spec
  used to carry the picture-facing requirements (how many pictures, what if none, when a picture
  may not spawn an idea) and to reference this spec — a cycle that made the base layer unreadable
  on its own. Those requirements moved here, where both sides may be known; the idea spec now
  references nothing above it. Traces to: the Layer section above,
  MUST-picture-absence-says-nothing.
- **F13** (user: "[method::Catalog] and [method::PageSkeleton] need to move out of `_terms.md` —
  where's better?") Both blocks were pure restatement: `PageSkeleton`'s four bullets (no
  method-specific class, substitution without paraphrasing, theme pinning, the QR block) already
  existed as this spec's own MUST-theme-pinning-language-agnostic / MUST-qr-repo-link / the build
  requirements below; `Catalog`'s ten bullets were split, word for word, between this spec's own
  MUST requirements and `approaches.md`'s (idea-side ones there, picture-side ones here). Neither
  block was a method (no Essence/Recognized by/Source) and neither added a fact the two specs
  didn't already state formally. Deleted from `_terms.md`; their one non-redundant content — that
  the shell has no separate context and the catalog has no root record of its own — folded into
  the Architecture section below. Traces to: the Bounded Context section below.
- **F14** (user: "the picture doesn't answer how the result is obtained in the approach") The
  first `SumOfSquares` picture stacked the four square layers, counted each honestly (16, 9, 4,
  1), and then simply asserted "= 4·5·9/6" — the exact same violation F-class as the earlier
  LCMViaGCD round: a number appearing in a caption with no visible route to it in the picture.
  Investigated the source before redesigning: Wikipedia's own Square pyramidal number article
  states the closed form is "proved by mathematical induction" — algebraic, not geometric — and
  no encyclopedic source anywhere gives a geometric derivation of it. Rather than force an
  unsourced/unverified 3D dissection (a real risk considered and rejected — a wrong geometric
  claim shown as fact is worse than an honest gap), the picture was rebuilt around a real,
  independently verified identity that IS fully showable: k² = T(k) + T(k−1) (a square splits into
  two triangular numbers), summed over k=1..n — one honest step short of the final algebraic
  simplification into the cubic form, not a fabricated full derivation. Traces to:
  MUST-frame-sequence, MUST-picture-optional (the record's Note is explicit about exactly how far
  the picture's derivation goes and where it hands off to a cited algebraic fact).

## Architecture

### Overview (prose)
Three separate sources, assembled by a script: the shared page shell
(`visualizations/skeleton.html` — fonts, color tokens, card and frame-flow layout, the
`.repo`/QR block, placeholders `{{TITLE}} {{STDNAME}} {{SLUG}} {{TERM}} {{CSS}} {{HTML}} {{JS}}
{{QR}}`; one shell for every method, no method-specific class inside it), the method's record
(the `[method::*]` block in `memory-bank/_terms.md`) and the frame code
(`visualizations/examples/<slug>.{css,html,js}`). `visualizations/build.sh` substitutes the code
into the shell → `build/<slug>.html`, then a headless browser (light theme, width 720, height
measured from the card) → `build/<slug>.png`; the png is embedded in the record via `Picture:`.
The skill finds the record → runs `build.sh <slug>` → looks at the png → opens the html. No
rendering "by eye", no cloud, no hand-made pictures.

### Bounded Context and Aggregate Root
- `method` — the only context, and it has no separate aggregate-root/value-object records: the
  shell just described (formerly `[method::PageSkeleton]`) and the catalog-level invariants
  (formerly `[method::Catalog]`) are exactly this Architecture section plus the MUST requirements
  below — a block restating them a second time in `_terms.md` was the same fact twice (F13). There
  is no separate context for pictures either (F10) — a picture is a set of fields on a method
  record. `_terms.md` holds only the twenty-seven entities.

## Requirements
> Statement — acceptance criterion — status.

### MUST — the picture itself
- The visual form MUST be chosen by how understandable it is at a glance to someone with no
  preparation; the standard name is looked up AFTER the form is chosen, and for that form —
  **MUST-form-before-name** — criterion: the record's `Standard name:` and the picture half of
  `Source:` refer to the form actually drawn, not to a relative with a different purpose. Status:
  done (skip counting, bar model, Gauss pairing, Venn, binary search, ladder method).
- The picture MUST be a sequence of frames: the first is Problem (an unsolved situation, marked
  wrong or unknown), the last is Solution, with one or more Transform frames between —
  **MUST-frame-sequence** — criterion: the record's `Sequence:` field and the markup of
  `examples/<slug>.html` contain the same frames in the same order; a single static frame is a
  violation. Status: done (6/6).
- Labels on the picture MUST be symbolic marks (`?`, `×2`, `−`, `↔`, `∩`, `=`) and MUST NOT be
  sentences — **MUST-symbolic-labels** — criterion: inside `frame-tag` in `examples/<slug>.html`
  there is no text longer than one character or short token. Status: done.
- Everything meant to be read MUST live in the record, not under the picture —
  **MUST-text-in-record** — criterion: the built page has no paragraphs below `.flow`, only a link
  to the record. Status: done.
- "Done" MUST NOT be declared until the render has been observed (screenshot/zoom); counting tags
  MUST NOT count as checking the picture — **MUST-render-observed** — criterion: there is an
  observation step before showing the owner, and the owner is not the first to see the picture.
  Status: partial — `build.sh` always produces a png and the skill requires reading it (steps
  3/4e), but there is no mechanical block on showing without looking (violated 4 times in the
  originating session; on the first `build.sh` run, looking at the png immediately caught a clipped
  label on the Gauss arc, and later it caught the dark-theme regression of F11).
- The geometry of overlays (arcs, arrows, labels above elements) MUST be measured from the rendered
  elements and MUST NOT be computed from assumed CSS sizes — **MUST-geometry-measured** —
  criterion: `examples/*.js` take coordinates via `getBoundingClientRect` and contain no hardcoded
  cell widths. Status: done (skip-counting.js, gauss-pairing.js).
- Every intermediate number in an example MUST be distinguishable between steps —
  **MUST-distinct-step-numbers** — criterion: the list of numbers across all frames contains no
  coincidences arising for different reasons (30 as an area and 30 as the total is a violation).
  Status: done (Gauss: 4..20, pairs of 24, total 60).
- The applicability wording MUST describe a class of problems and MUST NOT restate the example's
  parameters — **MUST-applicability-is-class** — criterion: the wording excludes no case the method
  actually covers; the example's own constraints, where they bind, go into `Limits` marked as a
  limit of the drawing rather than of the idea. Status: done.
- Limits MUST name the real cause of the limit — **MUST-limits-are-causal** — criterion: no
  formulations like "it gets crowded / confuses the eye"; there is a mechanism (three conditions do
  not line up in one row; four circles provably cannot cover every intersection). Status: done.
- A wording fix in one record MUST be checked against all the others at once —
  **MUST-fix-propagates** — criterion: a class of error is closed in one round, not one record per
  remark. Status: process-level, PASSIVE.
- The shared example MUST be one for the whole catalog ("numbers below 20, multiples of 2 or 3")
  and MUST NOT coincide with a specific problem's numbers — **MUST-shared-example** — criterion: no
  record contains euler001's 3 and 5; a new method incompatible with the example introduces its own
  and explains why. Status: done.
- Every built page and every png MUST carry a QR code to the repository
  (`https://github.com/Hedgehogues/project-euler`) plus the address in text — a picture travels
  separately from its text, so the way back to the sources has to be on the picture itself —
  **MUST-qr-repo-link** — criterion: the QR is a block of the shell `skeleton.html` (`.repo`), not
  of a method; `build.sh` fails without `visualizations/qr-repo.svg`; after generating a QR it is
  decoded from the built png and yields exactly this URL. Status: done.

### MUST — how a picture relates to its idea
> These live here, not in [approaches](approaches.md): they touch both sides, and this is the layer
> allowed to know both.

- One method MUST be described by ONE `[method::*]` record; the idea and its picture MUST NOT be
  split across two parallel blocks or contexts — **MUST-single-record-per-method** — criterion:
  `grep -oE '^## \[\w+::\w+\]' _terms.md | sort | uniq -d` is empty and only the `method` context
  appears; every `build/*.png` is referenced exactly once. Status: done (found by the user — F10).
- A record MUST have at most one picture — **MUST-one-picture-max** — criterion: no more than one
  `Picture:` field and one `build/*.png` link per record. An idea with two independently standard
  visual forms is two records (F9), not one with two portraits. Status: done.
- A record without a picture MUST state the reason rather than leaving the field blank —
  **MUST-picture-optional** — criterion: any `Picture: —` value is accompanied by an explanation of
  why no visual form exists, checked live (a real search across the sources named in
  MUST-canonical-source), not asserted from an earlier session's memory or copied from a
  structurally similar record. Status: done — currently vacuously true (every record in the
  catalog has a picture as of `EuclideanAlgorithm`/`LCMViaGCD`/`Precomputation`; the rule stays
  binding for the next record that genuinely has none).
- The absence of a picture MUST NOT be used as an argument about the idea — not about whether it is
  a technique, and not about whether it deserves its own record —
  **MUST-picture-absence-says-nothing** — criterion: no record is merged into another, and none is
  denied, on the grounds that it has no picture. Status: done (violated twice — F7 — and corrected
  both times by the user; historically demonstrated by `Precomputation`, which stood picture-less
  beside `BinarySearch` for exactly this reason before a picture was later found for it too).
- A record MUST NOT be created just to give an existing picture something to point at —
  **MUST-no-invented-idea** — criterion: a picture with no self-standing idea produces no record.
  Status: done.
- The term name in the `cards()` table (`build.sh`) MUST match the `[method::*]` record name — it is
  substituted into the caption ON THE PICTURE ITSELF — **MUST-term-name-matches-record** —
  criterion: for every `cards()` row the anchor `#method<term>` resolves to a real heading in
  `_terms.md`; the picture slug may differ from the method name (`ladder-method` ↔
  `TrialDivision`). Status: done (after F10 — renaming the records would have left the captions
  dead).

### MUST — build and repository
- Rebuilding a method MUST yield a byte-identical picture — **MUST-deterministic-rebuild** —
  criterion: the page is assembled by copying the shell + `examples/<slug>.*`; no number, color or
  class lives outside version-controlled files. Status: done.
- The frame code MUST be stored separately from the record, which references it via `Example:` —
  **MUST-code-separate** — criterion: the record contains no code, only an `Example:` field with
  paths; `examples/<slug>.{css,html,js}` exist and match what the builder inserts. Status: done.
- The light-theme pinning in `build.sh` MUST NOT depend on the page's language or any other shell
  attribute — **MUST-theme-pinning-language-agnostic** — criterion: the `sed` matches `<html ...>`
  with any attributes; a language switch does not change the theme of the output. Status: done
  (after F11, where exactly this produced dark PNGs).
- Everything in the repository — records, specs, build scripts, page shell, frame labels and the
  text rendered into the pictures — MUST be in English — **MUST-english-only** — criterion: a grep
  for Cyrillic across all tracked files of the public repository is empty. Status: done (F11; the
  pictures were rebuilt so their captions are English too).
- A redirect stub from an old name MUST be left only when inbound links exist; without them the old
  file is deleted — **MUST-redirect-only-if-linked** — criterion: a grep for the old name was run
  before choosing. Status: done (three stubs deleted after the grep).
- The text of records and specs MUST NOT name children or school as the audience — the simplicity
  level is set by the requirement, not by an addressee — **MUST-no-audience-mention** — criterion: a
  case-insensitive grep for those words across the catalog is empty. Status: done.

### SHALL
- The builder skill SHALL read `_terms.md` as the first step of every invocation and SHALL NOT rely
  on memory of a previous one — **SHALL-terms-first**. Status: done
  (`document-problem/SKILL.md`, step 1).
- A new method SHALL go through the full cycle (standard-name lookup → shared example → `Sequence`
  → record + `examples/` + `cards()` row) BEFORE being shown to the owner —
  **SHALL-full-cycle-before-show**. Status: done (`document-problem/SKILL.md`, step 3).
- An ambiguous match against two or more records SHALL be resolved by asking the owner rather than
  guessing — **SHALL-ask-on-ambiguity**. Status: done (`document-problem/SKILL.md`, step 3,
  "matches two or more existing blocks about equally well").

### SHOULD
- The render-observation step (MUST-render-observed) SHOULD be mechanized in the skill as a
  mandatory screenshot step rather than prose — **SHOULD-mechanize-render-check**. Status: not done.
- The distinct-numbers check (MUST-distinct-step-numbers) SHOULD be performed against a list of
  numbers in the record rather than by eye — **SHOULD-number-list-check**. Status: not done.

## Links
- The layer below, which this spec may reference and which never references back:
  [approaches](approaches.md) (requirements on the idea).
- Rules (short auto-loaded form): `.claude/rules/visualization-principles.md` (principles 1–16).
- Skill: `.claude/skills/document-problem/SKILL.md` (shell + build).
- Records: `memory-bank/_terms.md`; index — `memory-bank/index.md`.
