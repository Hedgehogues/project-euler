---
name: visualize-approach
description: Shows a visualization of a mathematical/algorithmic method (inclusion-exclusion, Gauss's trick, Venn diagram and so on) from the catalog in memory-bank/. Method descriptions are [method::*] blocks in memory-bank/_terms.md (idea and picture in one record); frame code lives in visualizations/examples/<slug>.*; the picture is built by build.sh from the shared shell skeleton.html (locally, no cloud). Invoking the skill on the same method yields a byte-identical result every time.
---

# Visualizing a method

The principles behind everything below: `.claude/rules/visualization-principles.md`; the full
requirements with acceptance criteria: `memory-bank/specs/visualizations.md` (picture) and
`memory-bank/specs/approaches.md` (idea). This file is the mechanics.

The point of the skill is not to invent a new picture each time but to CONSISTENTLY assemble an
already-catalogued method from three version-controlled parts: the shell (`skeleton.html`), the
frame code (`examples/<slug>.{css,html,js}`) and the description (the `[method::<Term>]` block in
`_terms.md`). Assembly is a script, not a hand. If the skill inadvertently produces two different
results for the same request, that is a bug in the skill, not acceptable variance.

## Catalog layout

```
memory-bank/
  _terms.md                          — [method::*] blocks: ONE record per method, idea and picture
                                        as fields of the same record (Essence/Recognized by/
                                        General case/Source + Picture/Sequence/Example/Limits),
                                        not two lists (principle 9); not a single mention of a
                                        specific problem (principle 12) — a problem links HERE
                                        from its own README, never the other way round
  specs/visualizations.md            — requirements on the picture (MUST/SHALL/SHOULD)
  specs/approaches.md                — requirements on the idea
  visualizations/
    skeleton.html                    — shared shell, placeholders {{TITLE}} {{STDNAME}} {{SLUG}}
                                        {{TERM}} {{CSS}} {{HTML}} {{JS}} {{QR}}
    qr-repo.svg                      — repository QR, baked into every page (principle 10);
                                        build.sh refuses to build without it
    examples/<slug>.{css,html,js}    — the method's frame code (js may be absent)
    build.sh                         — build: skeleton + examples -> build/<slug>.html,
                                        then headless Chrome -> build/<slug>.png (light theme)
    build/<slug>.{html,png}          — output; the png is embedded in _terms.md
```

One method — one block in `_terms.md` + files in `examples/` + a row in the `cards()` table inside
`build.sh` (slug | title | standard name | term name). The term name in `cards()` MUST match the
`[method::*]` block name — it is substituted into the caption on the picture itself; the picture
slug may differ (`ladder-method` ↔ `TrialDivision`). No hand-made pictures: `build/*.png` is only
ever the output of `build.sh`.

## Frames — a fixed structure

The first frame is Problem, the last is Solution, with one or more Transform frames between (the
same division as in the record's `Sequence:` field):

```html
<div class="frame-tag">{a symbol for the step, not a sentence}</div>
<div class="frame"><div class="frame-inner">{the frame's picture}</div></div>
<div class="flow-arrow">↓</div>
{... next frame ...}
<div class="frame-tag solved">=</div>
<div class="frame"><div class="frame-inner">{the solution's picture}</div></div>
```

`frame-tag` is a short symbol (`?`, `×2`, `−`, `↔`, `∩`, `=`), not a caption: the picture must be
understandable WITHOUT reading any text.

## Input

A free-form description of a method or visualization: "Gauss's trick", "show inclusion-exclusion",
"Venn diagram", "how do I explain multiples of 7 and 11" (the skill matches it against a METHOD,
not against a problem).

## Steps (strictly in order)

1. **Read `memory-bank/_terms.md` in full** — mandatory first step of every invocation.

2. **Match the request against a `[method::*]` block** by substance:
   - "double counting", "overlapping conditions", "or" → `InclusionExclusion`, or `VennDiagram`
     (if circles/Venn are asked for explicitly; if unspecified — offer both, step 5).
   - "what goes into the answer", "which numbers", "on a number line", "multiples" → `SkipCounting`.
   - "sum of a progression", "Gauss", "why the formula", "without iterating" →
     `ArithmeticProgressionSum`.
   - "find in a sorted list", "log n lookup" → `BinarySearch`.
   - "prime factors", "largest prime factor", "factorize" → `TrialDivision`.
   - No match → step 4.

3. **Match found:** take the slug from the record's `Example:` field, run
   `memory-bank/visualizations/build.sh <slug>`, **look at `build/<slug>.png` (Read)** — the
   mandatory observation step before showing anything — then `open build/<slug>.html` and show the
   user the picture plus the record's `Essence` / `Limits` fields verbatim and briefly. Redraw
   nothing: the `examples/` code has already been validated.

4. **No match — a new method, the full cycle, not a one-off picture:**
   a. `WebSearch` for the established name and a source BEFORE writing anything. If none is found,
      say so in the record: "no established name of its own", plus the closest real relative marked
      as "not the same thing". At least one source must be encyclopedic (Wikipedia, Britannica,
      cp-algorithms, a professional body) — blogs are supplements only.
   b. Reuse the catalog's shared example ("multiples of 2 or 3, below 20"); if incompatible, make a
      small one of your own and explain in the record why.
   c. Design the `Sequence:` from Problem to Solution; write out EVERY number of every frame and
      confirm there are no accidental coincidences between steps.
   d. Write `examples/<slug>.{css,html,js}`; take overlay geometry (arcs, labels above elements)
      via `getBoundingClientRect`, never from CSS constants.
   e. Add a row to `cards()` in `build.sh`; run `build.sh <slug>`; **look at the png**; if anything
      drifted — fix `examples/`, rebuild, look again.
   f. Write the `[method::<Term>]` block in `_terms.md` — ONE block per method, all fields modelled
      on the existing ones (idea: Essence/Recognized by/General case/Source; picture:
      Picture/Sequence/Example; shared: Limits, marking which limit belongs to the idea and which
      only to the drawing). Do not create a separate "for the picture" block — that is duplication
      (principle 9).
   g. Only THEN show the result.

5. **Ambiguity** (two or more blocks fit equally well) — `AskUserQuestion`, do not guess.

6. **A contradiction in a stored example** (numbers coincide, a label is clipped, an arc drifted) —
   is fixed by editing `examples/` + `build.sh` + looking at the png, never by replacing it with an
   explanation without a picture.

## Language

Everything in the repository is in English (principle 13): records, specs, scripts, the shell,
frame labels — and therefore the text rendered into the pictures. After any change on the picture
side, rebuild, otherwise translated sources ship with stale PNGs.

## The hard determinism rule

The same method — the same code in `examples/`, the same shell, the same `build.sh` → the same page
and the same picture. The only legitimate difference between two invocations is an edit to
`examples/`/`_terms.md` at the user's explicit request, which is always followed by a rebuild.
Without such an edit — byte-for-byte the same thing.
