#!/usr/bin/env python3
"""Flags full-sentence prose in a visualization's frame labels.

Principle 5 (.claude/rules/visualization-principles.md): "Labels on the picture are symbolic
marks (?, x2, -, <->, n, =), not sentences. Everything meant to be read lives in the record, not
on the picture." Until this check existed, that rule was judgement-only, and it drifted: an audit
found 20 of the 28 pictures in this catalog carrying full-sentence captions -- including one
(VariableElimination) authored in the same session that had just fixed BruteForceSearch for the
exact same fault. A correction applied to one picture by hand does not hold for the next one
without something that measures every picture, old and new.

A "sentence" here is a short, cheap heuristic, not a parser: a text node (between HTML tags) of
4+ words that also contains a common English connective ("is", "the", "and", ...). This catches
prose ("the exponent halves every row -- 4 rows instead of 12 multiplications") while passing
pure formulas ("6 x 6 = 36", "1 x 3 = 3") whose "words" are numbers and operators, not sentences --
both shapes exist throughout this catalog and only one of them is the fault this check is for.

Run from the repo root:
    python3 memory-bank/visualizations/check-captions.py
"""

import glob
import re
import sys

WS_RE = re.compile(r"\s+")
TAG_RE = re.compile(r"<[^>]+>")
ENTITIES = [
    ("&mdash;", "-"), ("&ndash;", "-"), ("&rarr;", "->"), ("&darr;", "v"),
    ("&nbsp;", " "), ("&minus;", "-"), ("&times;", "x"), ("&le;", "<="),
    ("&ge;", ">="), ("&asymp;", "~"), ("&middot;", "."), ("&equiv;", "="),
    ("&divide;", "/"), ("&lt;", "<"), ("&gt;", ">"), ("&sect;", ""),
]
CONNECTIVES = {
    "is", "for", "before", "after", "the", "and", "so", "that", "with",
    "once", "again", "than", "when", "if", "not", "are", "was", "were",
    "an", "does", "gets", "still", "instead", "because", "into", "from",
}


def looks_like_prose(text: str) -> bool:
    # Single-letter tokens are almost always variable names (a, b, x) in this catalog, not the
    # English article/pronoun they happen to spell -- excluded from both the length count and the
    # connective match, or every algebra formula ("a + b = 7") would misread as a sentence.
    words = [w for w in text.split() if len(w.strip(".,:;()")) > 1]
    if len(words) < 6:
        return False
    lowered = [w.lower().strip(".,:;()") for w in words]
    return sum(1 for w in lowered if w in CONNECTIVES) >= 2


def main() -> int:
    failed = 0
    for path in sorted(glob.glob("memory-bank/visualizations/examples/*.html")):
        html = open(path, encoding="utf-8").read()
        for part in TAG_RE.split(html):
            text = WS_RE.sub(" ", part).strip()
            for ent, rep in ENTITIES:
                text = text.replace(ent, rep)
            if not text:
                continue
            if looks_like_prose(text):
                failed += 1
                print(f'FAIL  {path}: "{text}"')

    if failed:
        print(f"\n{failed} caption(s) read as prose -- see principle 5.")
        return 1
    print(f"All example files carry only symbolic labels (principle 5).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
