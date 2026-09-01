#!/usr/bin/env bash
# Deterministic build of the visualization catalog:
#   skeleton.html + examples/<slug>.{css,html,js}  ->  build/<slug>.html  ->  build/<slug>.png
# The PNG is a headless-Chrome screenshot of the assembled page, never hand-drawn.
# Usage: ./build.sh [slug ...]     (no args = all four)
set -euo pipefail
cd "$(dirname "$0")"

CHROME="${CHROME:-/Applications/Google Chrome.app/Contents/MacOS/Google Chrome}"
WIDTH=720

# slug | title | standard name | term (== the [method::*] block name in ../_terms.md, not the picture slug)
cards() {
  cat <<'EOF'
skip-counting|Skip counting|Skip counting|SkipCounting
bar-model|Bar model|Bar model / tape diagram — Singapore Math|InclusionExclusion
gauss-pairing|Gauss's pairing trick|Gauss's trick|ArithmeticProgressionSum
venn|Venn diagram|Venn diagram — John Venn, 1880|VennDiagram
binary-search|Binary search|Binary search|BinarySearch
ladder-method|Ladder method|Ladder method (division ladder)|TrialDivision
euclidean-algorithm|Euclidean algorithm|Euclidean algorithm (square-tiling)|EuclideanAlgorithm
lcm-via-gcd|LCM via GCD|Tile-count swap, from GCD|LCMViaGCD
precomputation|Precomputation|Build once, look up many times|Precomputation
sum-of-squares|Sum of squares|Square split into two triangular staircases|SumOfSquares
EOF
}

assemble() {  # $1 slug $2 title $3 stdname $4 term
  local slug=$1 title=$2 std=$3 term=$4
  local css="examples/$slug.css" html="examples/$slug.html" js="examples/$slug.js"
  [ -f "$js" ] || js=/dev/null
  [ -f qr-repo.svg ] || { echo "qr-repo.svg missing -- every visualization must carry the repo QR (principle 10)" >&2; exit 1; }
  awk -v title="$title" -v std="$std" -v slug="$slug" -v term="$term" \
      -v cssf="$css" -v htmlf="$html" -v jsf="$js" -v qrf="qr-repo.svg" '
    function dump(f,   line) { while ((getline line < f) > 0) print line; close(f) }
    {
      if ($0 ~ /^\{\{CSS\}\}$/)       { dump(cssf);  next }
      if ($0 ~ /^\{\{HTML\}\}$/)      { dump(htmlf); next }
      if ($0 ~ /^\{\{JS\}\}$/)        { dump(jsf);   next }
      if ($0 ~ /^\{\{QR\}\}$/)        { dump(qrf);   next }
      gsub(/\{\{TITLE\}\}/, title); gsub(/\{\{STDNAME\}\}/, std)
      gsub(/\{\{SLUG\}\}/, slug);   gsub(/\{\{TERM\}\}/, term)
      print
    }' skeleton.html > "build/$slug.html"
}

# Screenshot: a light-theme copy of the page (data-theme="light" pins the palette so the PNG does
# not depend on the machine's OS theme), height measured first with a probe (dump-dom after
# virtual time) so the PNG is exactly the card, not a tall empty viewport.
screenshot() {  # $1 slug
  local slug=$1 shot="build/.shot-$slug.html" probe="build/.probe-$slug.html"
  # Match <html ...> whatever its attributes are -- keying on lang="ru" once silently broke the
  # light pinning the moment the skeleton switched to lang="en", and the PNGs came out dark.
  sed -E 's#<html([^>]*)>#<html\1 data-theme="light">#' "build/$slug.html" > "$shot"
  sed 's#</body>#<script>window.addEventListener("load",()=>{document.body.setAttribute("data-h",Math.ceil(document.documentElement.scrollHeight))});</script></body>#' \
      "$shot" > "$probe"
  local h
  h=$("$CHROME" --headless=new --disable-gpu --hide-scrollbars --window-size=$WIDTH,600 \
        --virtual-time-budget=4000 --dump-dom "file://$PWD/$probe" 2>/dev/null \
        | grep -o 'data-h="[0-9]*"' | grep -o '[0-9]*' | head -1)
  rm -f "$probe"
  : "${h:?could not measure height for $slug}"
  "$CHROME" --headless=new --disable-gpu --hide-scrollbars --force-device-scale-factor=2 \
      --window-size=$WIDTH,"$h" --virtual-time-budget=4000 \
      --screenshot="$PWD/build/$slug.png" "file://$PWD/$shot" >/dev/null 2>&1
  rm -f "$shot"
  echo "build/$slug.html  build/$slug.png  (${WIDTH}x${h}@2x, light)"
}

mkdir -p build
want=("$@")
while IFS='|' read -r slug title std term; do
  if [ ${#want[@]} -gt 0 ]; then
    skip=1; for w in "${want[@]}"; do [ "$w" = "$slug" ] && skip=0; done; [ $skip = 1 ] && continue
  fi
  assemble "$slug" "$title" "$std" "$term"
  screenshot "$slug"
done < <(cards)
