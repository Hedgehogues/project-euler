(function(){
  const nums = [4, 8, 12, 16, 20]; // m=5, step=4 -- multiples of 4, 1st..5th

  const plainRow = document.getElementById('rowPlainGauss');
  nums.forEach((n, i) => {
    if (i > 0) {
      const sym = document.createElement('span');
      sym.className = 'psym';
      sym.textContent = '+';
      plainRow.appendChild(sym);
    }
    const d = document.createElement('span');
    d.className = 'pnum plain';
    d.textContent = n;
    plainRow.appendChild(d);
  });

  const cls = ['p1', 'p2', 'mid', 'p2', 'p1'];
  const row = document.getElementById('pairsRow');
  nums.forEach((n, i) => {
    const d = document.createElement('div');
    d.className = 'pnum ' + cls[i];
    d.textContent = n;
    row.appendChild(d);
  });

  const svg = document.getElementById('pairArcs');
  const rowRect = row.getBoundingClientRect();
  const centers = Array.from(row.children).map(c => {
    const r = c.getBoundingClientRect();
    return (r.left + r.right) / 2 - rowRect.left;
  });
  const width = rowRect.width;
  const height = 50;
  svg.setAttribute('viewBox', `0 0 ${width} ${height}`);
  svg.setAttribute('width', width);
  svg.setAttribute('height', height);
  const baseline = height - 2;
  function arc(i1, i2, h, colorVar){
    const x1 = centers[i1], x2 = centers[i2], midx = (x1 + x2) / 2;
    const peakY = height - h;
    return `<path d="M${x1},${baseline} Q${midx},${peakY} ${x2},${baseline}" fill="none" stroke="var(${colorVar})" stroke-width="2"/>
            <text x="${midx}" y="${peakY - 4}" text-anchor="middle" font-family="JetBrains Mono, monospace" font-size="11" font-weight="700" fill="var(${colorVar})">24</text>`;
  }
  svg.innerHTML = arc(0, 4, 44, '--a') + arc(1, 3, 28, '--b');
})();
