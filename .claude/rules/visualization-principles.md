# Principles for visualizing methods — catalog `memory-bank/`

Source: the retro of the "visualization catalog" cycle, 2026-09-01 (session: euler001 → catalog →
the `document-problem` skill). Every principle below is not a platitude but a rule derived from a
concrete round of revisions in which it was violated and fixed. It applies to anything that shows a
solution as a picture: catalog records, per-problem infographics, frames in reports.

The RFC-style specs (requirements with ids, findings, acceptance criteria):
`memory-bank/specs/visualizations.md`, `memory-bank/specs/approaches.md`; terms —
`memory-bank/_terms.md`. Each principle below corresponds to a MUST requirement there; this file is
the short, auto-loaded form.

Related files: `memory-bank/index.md` (how the catalog is extended),
`.claude/skills/document-problem/SKILL.md` (page assembly), `design-source-fidelity.md`
("a static check is not a render" — the same as principle 2 below, for mockups).

## 1. Form by understandability, name by form

The visual form is chosen by how understandable it is at a glance to someone with no preparation
(the simplicity level of skip counting, a bar, pairing from both ends, circles), NOT by whether it
has a well-known name. The standard name is looked up AFTER the form is chosen — for that exact
form — and recorded in its own field.

- MUST: form first, then a `WebSearch` for its standard name and source.
- MUST NOT: bend a method to fit a known name for the sake of a citation (precedent: the Sieve of
  Eratosthenes with its purpose inverted — a real name on a foreign form).
- MUST NOT: mention children or school in the text — simplicity is a level, not an addressee.

## 2. The picture is seen before it is shown

"Done" is not declared until the render has been observed. Counting opening and closing tags checks
the integrity of the markup, not the picture; those are two different questions.

- MUST: before showing the user — open and look (screenshot/zoom), not just validate structure.
- MUST: geometry for overlays (arcs, arrows, labels above elements) is measured from already
  rendered elements (`getBoundingClientRect`), never computed from assumed CSS sizes.
- Precedent: in one session, four times running the user was the first to see the defect from a
  screenshot — twice a coincidence of numbers in adjacent steps, twice arcs drifted out of place.
- Precedent 2: a later language switch (`lang="ru"` → `lang="en"`) silently broke the light-theme
  pinning in the build script, and the PNGs came out dark. No text check would have caught it —
  looking at the picture did.

## 3. Numbers in adjacent steps do not coincide by accident

If the same number shows up in two steps for different reasons (a rectangle's area of 30 and a total
of 30), the explanation reads as circular. The example is chosen so that all intermediate numbers
are distinguishable.

- MUST: before fixing an example — write out every number of every step and confirm there are no
  coincidences.
- Precedent: step 2 → step 4 in the Gauss method; the error came back on a rebuild because it was
  checked by eye rather than against a list of numbers.

## 4. Applicability describes a class of problems, not the example's parameters

The "when to apply" field says which problems the method covers at all; the demonstration example's
parameters (below 20, multiples of 2 and 3, five bars) must not leak into it. If the example has its
own bound (drawing by hand is only convenient over a short stretch), that goes into "limits",
explicitly marked as a limit of the drawing rather than of the method.

- MUST: the check is "does this wording exclude a case the method actually covers?"; if yes, it is a
  restatement of the example.
- MUST: limits name the real cause (a bar cannot show three-way intersections in one row; four
  circles provably cannot cover every intersection), not "it gets crowded / confuses the eye".
- MUST: a wording fix in one record is checked against all the others at once — a rule, not an
  instance (precedent: it took a second remark, "now apply that generalization to the rest").

## 5. The picture carries the causal chain itself; text only supplements

A visualization is a sequence of frames: the first is the problem (an unsolved situation, marked
wrong or unknown), the last is the solution, and the ones between are transformations. Labels on the
picture are symbolic marks (`?`, `×2`, `−`, `↔`, `∩`, `=`), not sentences. Everything meant to be
read lives in the record, not on the picture.

- MUST: one static "solution" frame plus paragraphs of "why" underneath is a violation — the move
  from problem to answer must be seen, not read.
- MUST: the reference part (name, source, applicability, limits) is a markdown record in RFC blocks
  (`[method::Name]`, MUST/MUST NOT fields), not text under the picture.
- MUST: every transition between frames has its cause visible in the frame BEFORE it — for each
  arrow, name the operation (×6, ln, +ln ln, round up) and point at the drawn element that makes a
  stranger expect it; if none exists, add it before showing. Tracing every NUMBER back to an earlier
  frame is necessary but not sufficient: the numbers can all check out while the reason for each
  step never appears on the picture.
- Precedent: `Precomputation` and `NthPrimeBound` took seven rounds of "непонятно, в чём суть /
  откуда это берётся" in one session. Each round fixed exactly the link the reader had just tripped
  on and shipped; the next link was still missing. All of them were obvious to the author, which is
  the point — the author cannot find them by looking, only by auditing each step against what is
  drawn.

## 6. Sameness is held by files, not by intention

Showing a method again is assembled from three version-controlled inputs — the shared shell
(`memory-bank/visualizations/skeleton.html`), the description (the `[method::*]` block in
`_terms.md`) and the exact frame code (`examples/<slug>.{css,html,js}`) — by `build.sh`, with no
paraphrasing; the picture `build/<slug>.png` is the output of that same script (headless browser,
light theme), never a hand drawing. If the real numbers and layout live in a temporary file while
the record holds only the idea of the frames in words, a rebuild will not match the previous one, no
matter how strict the record looks.

- MUST: the record references the code, the code lives separately; a change in how the work is done
  (cloud artifact → local html, one file → record + examples) is accompanied by the check "will the
  same thing come out of what has been saved?".
- Precedent: the sameness requirement was in the skill from the start and was violated at exactly
  the moment the records started to look stricter — the user caught it by asking "will it come out
  the same?".

## 7. The shared example runs through the whole catalog and is not tied to a problem

Every method is illustrated with one case ("numbers below 20, multiples of 2 or 3"), never a
specific problem's numbers (not euler001's 3 and 5). That proves the method is general and makes the
records comparable with one another. A new method incompatible with the shared case introduces its
own small one and explains why in the record.

## 8. One record per method; a redirect only where the old name is already linked

Renaming or replacing a method leaves the old file as a redirect stub ONLY if the old name is
already committed or something links to it (logs, specs, other people's files) — otherwise links
would dangle. If nothing links to it (the name lived only inside a working session and never made it
into the repository), the old file is simply deleted: a stub with no inbound link reads as an extra
method in the catalog (precedent: three stubs shipped to the public repository and made four
techniques look like seven). Before choosing — grep for the old name, do not rely on memory.

## 9. One method, one record: the idea and the picture are not split across two lists

The idea ("what it is, when it is recognized") and its picture ("how to show it") are not two
parallel catalogs but FIELDS OF ONE `[method::*]` record: `Essence`/`Recognized by`/`General case`/
`Source` for the idea, `Picture`/`Sequence`/`Example` for the drawing, `Limits` for the bounds of
both, marking which limit belongs to the idea and which only to the drawing.

Two lists look reasonable ("the layers really are different"), but in practice they degenerate into
duplication: identical names in both contexts, the same picture embedded twice, the same source, a
description that paraphrases its neighbour. Precedent: the catalog lived with the contexts
`[viz::*]` and `[approach::*]`; a grep showed two `VennDiagram` blocks, two `BinarySearch`, and five
pictures with two occurrences each. This split was defended twice ("they are different layers",
"they have different fields") — the argument is wrong: layers are distinguished by fields inside a
record, not by separate records. Found by the user ("there are duplicates again"), not on my own.

- MUST: `grep -oE '^## \[\w+::\w+\]' _terms.md | sort | uniq -d` is empty — no identical names.
- MUST: every `build/*.png` is mentioned in `_terms.md` exactly once.
- MUST NOT: introduce cross-reference fields such as `Approach:` ↔ `Visualized by:` — they are only
  needed when there are two lists; with one record there is nothing to bridge.
- MUST: the presence or absence of a picture does NOT decide whether to create a separate record —
  those are two different questions. "Is this idea recognized in other problems apart from its
  neighbours" decides the record. "Does the idea have an established visual form" decides the
  picture. An idea may legitimately have a record with NO picture (precedent: "Precomputation" is
  independently recognizable, but "compute it ahead of time" has no visual form, unlike what you
  then do with the result — "binary search", which has one).
- MUST NOT: give a picture to the aggregate/index concept (the catalog as a whole, described in
  `visualizations.md`'s Architecture section, not a `_terms.md` block of its own) — an aggregate has
  no single picture, it has a list; a copy of the image "for visibility at the top" is the same file
  shown twice (precedent: a gallery on the aggregate duplicated what the records below already
  showed).
- MUST: the term name in the `cards()` table (`build.sh`) matches the block name — it is substituted
  into the caption ON THE PICTURE ITSELF; renaming blocks silently turns those captions into dead
  references (precedent: after merging the contexts the pictures would have read
  `[method::BarModel]` and `[method::LadderMethod]`, which no longer exist — caught only by
  reconciling the table against the file).

## 10. Every visualization carries a QR code to the repository

A picture lives apart from its text (it gets forwarded, pasted into chats, shown on a screen) — so
the way back to the sources, records and other methods has to be on the picture itself, not in a
caption beside it. Every built page and every snapshot therefore carries a QR code to
`https://github.com/Hedgehogues/project-euler` plus the address in text (for those who do not scan).

- MUST: the QR is part of the shell (`skeleton.html`, the `.repo` block), not of an individual
  method; a method cannot switch it off.
- MUST: the QR is a static file `memory-bank/visualizations/qr-repo.svg`, generated once with error
  correction level M and committed; `build.sh` refuses to build without it.
- MUST: after generating or changing the QR — decode it from the BUILT png (not from the svg) and
  check the URL; a QR that cannot be read off the snapshot is not a QR.
- MUST NOT: cover the QR with other elements, shrink it below ~70px on the built page, or recolor it
  into something with low contrast against the background.

## 11. A method is an atom, a named composition of atoms, or a family generalizing atoms along a named axis; at most one picture per method

The method catalog is not a pile of formulas but an algebra: each record is either an indivisible
idea (it does not decompose further into something simpler and reusable), an explicitly named
composition of two or more indivisible ideas used together, or a family — one idea that several
catalogued atoms are specializations OF, differing only along an axis the family itself names. The
forbidden middle state is "an indivisible idea plus an extra that is not named separately" — a
composition without admitting that it is one.

A family is the only record allowed to sit ABOVE others, and it earns that place solely by naming
ONE axis — the single thing that differs between its specializations and nothing else: the sieve
skeleton is one idea and what gets written into the cells is the axis; the positional representation
of a number is one idea and the base is the axis, which is exactly what separates a big integer in
base a billion from a permutation index in the factorial system. A family that cannot name its axis
is not a generalization — it is a retelling of its children, and that is the duplication principle 9
forbids, arriving from above instead of from the side. Two or three axes at once is the
`NthPrimeBound` failure in new clothing: a picture teaching several ideas at once, and a record
whose children differ along whichever axis the reader happens to look at. Choices made INSIDE one
specialization (which end of the array holds the low digit, what carries the digits) are not axes
of the family — an axis must be what distinguishes one child from another.

A direct consequence: a record cannot have two pictures. If a record tries to point at two or more
visualizations at once, that is almost always a signal that TWO different ideas are hiding under one
name — ideas that are simply often applied together, not one idea with two equal portraits. Splitting
them into separate records is not bureaucracy but an honest acknowledgement of the structure; nothing
is lost — both pictures stay, each with its own record.

- MUST: no more than one `Picture:` field and one `build/*.png` link per record.
- MUST: before fusing two ideas into one record — ask whether each is recognized in ANOTHER problem
  WITHOUT the other (the independence test); if so, that is 2 records, not 1.
- MUST NOT: fuse an idea-with-a-picture and an idea-without-one into a single record merely because
  the second has no visual form of its own — the absence of a picture is not an argument against a
  separate record (principle 9).
- MUST: treat a record whose General case is a formula with two or more distinct operations inside
  as a composition until proven otherwise — run the independence test on each operation before
  drawing. A theorem or a bound reads as one indivisible thing, and that is exactly how a
  composition hides.
- MUST: a family record carry `Class: family`, an `Axis:` field naming what varies between its
  specializations, and a `Specializations:` field linking two or more existing records; each of
  those records carries `Family:` pointing back. A family whose `Specializations:` holds fewer than
  two links is an atom that has not met its siblings yet, not a family.
- MUST NOT: let a family's `General case` restate any specialization's own mechanism — the family
  states what all of them share plus the axis, and nothing that belongs to one child only. The
  test: delete every specialization from the catalog and the family still reads as one idea; keep
  them and the family adds no sentence they already carry.
- MUST: draw a family's picture as the axis itself — one skeleton held fixed while the varying part
  changes across frames — never as one specialization's mechanism. A family whose axis has no
  visual form carries `Picture: —` with the reason, rather than borrowing a child's picture.
- Precedent 4: an audit of all 37 solved problems found 48 techniques in use with no record at all.
  Twenty-two are non-trivial, and they group into thirteen families — and seven records already in
  the catalog (`SieveOfEratosthenes`, `PrefixSum`, `Canonicalization`, `TrialDivision`,
  `ModularInverseFermat`, `FastExponentiation`, `CycleDetectionViaRemainders`) turned out to be
  specializations of a family rather than independent atoms. With only two relations available, each
  of those families would have had to restate its children to exist at all; the third relation is
  what lets the generalization be recorded once instead of nine times.
- Precedent 3: `NthPrimeBound` — n(ln n + ln ln n) — was catalogued as one atom and redesigned four
  times, failing each time because the picture was teaching three ideas at once. Split into the
  composition of `PrimeNumberTheorem`, `FixedPointIteration` and `LogarithmProductRule` (the latter
  two new records) only when the user asked to break it into parts.
- Precedent 1: euler002's `Precomputation` + `BinarySearch` were fused into one
  `PrecomputeAndBinarySearch` record out of exactly this confusion — separated after a direct
  question from the user.
- Precedent 2: `InclusionExclusion` carried BOTH pictures (the bar and the Venn diagram) — an honest
  review showed these are two independently standard ideas with different origins (counting
  arithmetic vs. representing logical propositions with circles, John Venn, 1880, for an entirely
  different purpose) — separated into `InclusionExclusion` (the bar) and `VennDiagram` (the
  diagram); nothing lost.
- Distinguish from principle 9: there, "one idea must not be SPREAD across two records"
  (duplication); here, "two ideas must not be FUSED into one record" (noise). Both errors occurred
  in this catalog, and the user found both.

## 12. The memory bank holds reusable knowledge, not specific problems — and no links to them

The method catalog is about what transfers between problems, like a textbook: it carries no numbers
of the particular homework assignments where a formula once got used. A specific problem (its
statement, solution, correctness criteria) has already been checked once by a real submission — that
is a one-off fact, not knowledge worth keeping in a shared catalog. The link is one-directional: the
problem itself points at the block it needs by name
(`../memory-bank/_terms.md#methodname`); the catalog keeps no reverse "used in" pointer at all —
that would be a second, duplicating and drift-prone source of the same fact, needing an edit on every
problem rename.

- MUST: the DICTIONARY (`_terms.md`) contains no `[euler::*]` blocks.
- MUST NOT: a field such as `Used in:` (or any other naming a specific problem) in `_terms.md`
  blocks — neither as a spec nor as a single line with a link. The only permissible mention runs the
  other way: in `problems/euler{NNN}/README.md`, linking TO the primitive, not back.
- Precedent 1: `specs/euler001.md`/`euler002.md`/`euler003.md` duplicated what was already in the
  problems' READMEs, plus formal MUST criteria nobody will revisit for a finished routine problem —
  found and removed at the user's direct request.
- Precedent 2: even after the specs were deleted, every block still carried a `Used in: euler001`
  line — also a mention of a problem, just a single line. The user caught it with the next question
  ("these are supposed to be just the primitives, no?") — the "no problems" rule had been declared
  but not applied all the way; the lines were removed entirely.

**Amended (2026-09-01):** the two bullets forbidding a `specs/euler{NNN}.md` PATH and requiring
verification facts to live only in the README, one line, no RFC machinery — both from the ORIGINAL
version of this principle — are reversed by the user's own later, explicit choice: applied per-task
specs (`memory-bank/specs/tasks/euler{NNN}.md`, format governed by `specs/tasks.md`) are legitimate.
What did NOT reverse: the dictionary itself. The distinction the original version of this principle
missed — a dictionary entry is reusable knowledge that must never change on reuse; a task's own spec
is the opposite by nature, a fixed one-time acceptance record — is why forbidding one doesn't have
to forbid the other. See `specs/approaches.md`'s finding F9 for the full account.

## 13. The whole repository is in English

Everything that ships in the public repository is written in English: records, specs, build scripts,
the page shell, frame labels, and therefore the text rendered into the pictures themselves.

- MUST: a grep for Cyrillic across the tracked files of the public repository is empty.
- MUST: after changing anything on the picture side, rebuild — a translated source with stale PNGs
  means the pictures still speak the old language.
- MUST NOT: key any build-script substitution on a language-specific string (`lang="ru"`) — such a
  match breaks silently on translation (precedent: the light-theme pinning did exactly that, and the
  rebuilt PNGs came out dark; caught by looking at the picture, per principle 2).

## 14. Layers depend one way only: problems → pictures → ideas

The catalog is layered, and the dependency arrow never reverses:

```
problems (problems/euler{NNN}/README.md)  →  pictures (specs/visualizations.md)  →  ideas (specs/approaches.md)
```

Each layer may reference the one below it and MUST NOT reference the one above. The idea layer is
the foundation: it knows nothing of pictures, of the build, or of problems, and its spec must be
readable and applicable with every other spec closed.

The practical consequence people get wrong: **a rule about the RELATIONSHIP between two layers
belongs to the upper (dependent) one**, because that is the only side allowed to know both. "How
many pictures may an idea have", "what if it has none", "a picture must not spawn an idea" — all
of these live in the picture spec, never in the idea spec, even though they constrain ideas.

- MUST: the idea spec contains no link to the picture spec and no requirement whose subject is a
  picture, a build step or a problem.
- MUST: relationship rules are written once, in the dependent layer — not mirrored into both (a
  mirrored rule is the same duplication principle 9 forbids, one level up).
- MUST: a record's `Spec:` field points at the layer that actually governs it — a record with no
  picture points only at the idea spec.
- Precedent: the idea spec used to open by calling itself "one half of a pair", list picture fields
  in its own scope, and carry four picture-facing requirements — a cycle that made the base layer
  unreadable on its own. Named by the user ("the requirements on visualizations and on ideas must
  be independent"), not noticed while the two specs were being written side by side.

## 15. A term-block that only restates a spec's own requirements does not exist

A `[method::*]` block earns its place by carrying a fact the specs don't already state formally —
domain fields (`Essence`/`Recognized by`/`Source`) for an entity, or genuinely new information for
anything else. A block whose every bullet is a second, informal copy of a MUST requirement that
already lives in `approaches.md`/`visualizations.md` (with its own acceptance criterion and status)
is not a term, it is the same fact written twice — the same failure principles 9 and 14 name, one
level up: not two records for one idea, and not one rule mirrored into two specs, but one rule
mirrored into a spec AND a dictionary entry.

- MUST: before adding a `[method::*]` block that is not an entity (no Essence/Recognized by/
  Source) — an aggregate, a shared shell, any piece of infrastructure — check whether every
  invariant it would carry already exists as a MUST requirement in one of the two specs. If so, the
  block adds nothing; describe the thing in the spec's own Architecture section instead.
- MUST: a field with nothing to point at (a base record `Depends on:`, a record with no picture)
  states the reason in place of the value — never leaves the field blank (precedent below).
- Precedent: `[method::Catalog]` (ten invariants) and `[method::PageSkeleton]` (four) sat in
  `_terms.md` for the whole life of the catalog; every one of those fourteen bullets was already a
  formal MUST requirement, split correctly between the two specs. Found only when the user asked
  where they should move to, not while either spec was being written.

## 16. A folder holding two distinguishable kinds of content splits into subfolders, one per kind

Grouping by physical location is itself a claim: everything under one folder reads as "the same
kind of thing." When a folder actually holds two conceptually different kinds — a rule that
governs any record vs. one applied instance of it, a handful of published problems vs. everything
else at the repo root — leaving them flat is not neutral, it hides a real distinction inside prose
that a reader has to already know to look for. The fix is a subfolder per kind, so the distinction
shows up in the file listing itself, not only in a README paragraph.

- MUST: before adding a second, genuinely different kind of file to an existing folder — check
  whether the existing content is homogeneous; if not, give the new kind (or the old one) its own
  subfolder rather than letting the folder accumulate a mix.
- Precedent: `memory-bank/specs/` mixed two meta-specs (govern any method record) with three
  per-task specs (govern one solved problem) as a flat list — split into `specs/*.md` (meta) and
  `specs/tasks/*.md` (applied) only after the user asked to separate them explicitly. The repo root
  mixed three published, documented problems with everything else in the repository — split into
  `problems/euler{NNN}` only after a second, separately worded request ("gather them in one
  folder") that was, in substance, the exact same fix applied to a different pair.

## 17. A reviewed render carries its own version identity

A screenshot travels without its commit. When the same page is re-rendered several times in a
session, a reviewer looking at a cached copy has no way to tell it from the current one — and
neither does the author reading the screenshot, until the content is compared line by line.

- MUST: every built page (and so every PNG) prints a short stamp next to the record name in its
  footer — a hash of exactly the inputs that produced it (`skeleton.html` + the method's
  `examples/` files). Same inputs, same stamp; any edit, a new stamp.
- MUST NOT: stamp a commit id or a timestamp — both change on a page whose inputs did not, which
  would break the byte-identical rebuild principle 6 requires. The stamp identifies CONTENT.
- Precedent: twice in one session the user's screenshot showed the version before the fix just
  pushed (browser and GitHub image caches), and a review round each time went to establishing which
  version was being discussed. With the stamp, the footer answers that at a glance.

Trigger: any request to show a solution or a method as a picture — a new catalog record, a
per-problem infographic, an edit to an existing visualization; an invocation of the
`document-problem` skill; adding or editing any method record.
Mechanization: `PASSIVE — risk logged`. Principles 1, 4, 7, 11 are judgement calls and are not
script-checkable. Principle 5 — partly `LIGHTWEIGHT-GATE — memory-bank/visualizations/check-
captions.py` (`python3 memory-bank/visualizations/check-captions.py`): flags a frame label reading
as a full sentence (6+ real words, 2+ common English connectives) rather than a symbolic mark —
added after an audit found 20 of the 28 pictures in this catalog carrying full-sentence captions,
including one (`VariableElimination`) authored in the very session that had just fixed
`BruteForceSearch` for the same fault; a single hand-corrected picture does not hold the standard
for the rest of the catalog without something that measures every one of them. Not wired into
`build.sh` or CI — a judgement call still decides what SHORT symbolic replacement text to use, the
script only flags that the old text was too long/prose-like to be one. Principle 2 —
`LIGHTWEIGHT-GATE — memory-bank/visualizations/build.sh` always
produces a png and SKILL.md steps 3/4e require reading it before showing (there is no mechanical
block on showing without looking — the risk is accepted); principle 3 — a list of numbers in the
record (not implemented); principle 6 — `MECHANIZED — build.sh` (assembly only from
`skeleton.html` + `examples/`); principle 17 — `MECHANIZED — build.sh` (the content-hash stamp is substituted into every page);
principle 10 — `MECHANIZED — build.sh` (the QR is baked into the
shell and the build fails without `qr-repo.svg`; decoding from the snapshot is a manual step when
the QR changes); principle 12 — partly `LIGHTWEIGHT-GATE` (`grep -r 'specs/euler\|\[euler::\|^Used
in:' memory-bank/` must be empty — not wired into a script, checked by hand); principle 13 —
partly `LIGHTWEIGHT-GATE` (a Cyrillic grep over tracked files — also by hand); principle 15 — not
mechanized (checking whether a block's content is already covered elsewhere is a judgement call,
same class as principles 1/4/5/7/11); principle 16 — same as 15, judgement-only. The risk of a
principle not being applied at the moment a picture ships or a record is added is accepted
explicitly; the compensation has been the user's own questions, which caught these violations —
which is exactly what should not be the mechanism.
