(function(){
  // n^2 + n - 42, plotted over n in [-10, 8]; roots at n=-7 and n=6 (from -1 +/- 13, over 2)
  const f = x => x*x + x - 42;
  const xMin = -10, xMax = 8;
  const yMin = -42.25, yMax = 48; // vertex at x=-0.5 gives the minimum; endpoints give the max
  const W = 360, H = 220, PAD = 14;

  function px(x){ return PAD + (x - xMin) / (xMax - xMin) * (W - 2*PAD); }
  function py(y){ return PAD + (yMax - y) / (yMax - yMin) * (H - 2*PAD); }

  const svg = document.getElementById('qfPlot');
  let pts = [];
  for (let x = xMin; x <= xMax + 1e-9; x += 0.25) {
    pts.push(`${px(x).toFixed(1)},${py(f(x)).toFixed(1)}`);
  }
  const curve = `<path d="M${pts.join(' L')}" fill="none" stroke="var(--a)" stroke-width="2"/>`;
  const axis = `<line x1="${PAD}" y1="${py(0)}" x2="${W-PAD}" y2="${py(0)}" stroke="var(--rule)" stroke-width="1.5"/>`;

  function root(x, kept){
    const cx = px(x), cy = py(0);
    const color = kept ? 'var(--good)' : 'var(--b)';
    return `<circle cx="${cx}" cy="${cy}" r="4.5" fill="${color}"/>
            <text x="${cx}" y="${cy + (kept ? 20 : -10)}" text-anchor="middle" font-family="JetBrains Mono, monospace" font-size="12" font-weight="700" fill="${color}">${x}</text>`;
  }

  svg.innerHTML = axis + curve + root(-7, false) + root(6, true);
})();
