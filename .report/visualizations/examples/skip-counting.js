(function(){
  const N = 20; // numbers 1..19

  function buildRow(id, colorFn){
    const el = document.getElementById(id);
    for (let i = 1; i < N; i++) {
      const d = document.createElement('div');
      const cls = colorFn(i);
      d.className = 'ncell' + (cls ? ' ' + cls : '');
      d.textContent = i;
      el.appendChild(d);
    }
  }
  buildRow('rowPlain', () => 'plain');
  buildRow('row2', i => i % 2 === 0 ? 'a' : '');
  buildRow('row3', i => i % 3 === 0 ? 'b' : '');
  buildRow('rowBoth', i => {
    const div2 = i % 2 === 0, div3 = i % 3 === 0;
    if (div2 && div3) return 'both';
    if (div2) return 'a';
    if (div3) return 'b';
    return '';
  });

  function cellCenters(rowEl){
    const rowRect = rowEl.getBoundingClientRect();
    return Array.from(rowEl.children).map(c => {
      const r = c.getBoundingClientRect();
      return (r.left + r.right) / 2 - rowRect.left;
    });
  }

  function drawHops(svgId, rowId, divisor, colorVar){
    const svg = document.getElementById(svgId);
    const row = document.getElementById(rowId);
    const rowRect = row.getBoundingClientRect();
    const centers = cellCenters(row);
    const width = rowRect.width;
    const height = 24;
    svg.setAttribute('viewBox', `0 0 ${width} ${height}`);
    svg.setAttribute('width', width);
    svg.setAttribute('height', height);
    const baseline = height - 2;
    const multiples = [];
    for (let i = divisor; i < N; i += divisor) multiples.push(i);
    let path = '';
    for (let k = 0; k < multiples.length - 1; k++) {
      const x1 = centers[multiples[k] - 1];
      const x2 = centers[multiples[k + 1] - 1];
      const midx = (x1 + x2) / 2;
      path += `M${x1},${baseline} Q${midx},2 ${x2},${baseline} `;
    }
    svg.innerHTML = `<path d="${path}" fill="none" stroke="var(${colorVar})" stroke-width="2"/>`;
  }
  drawHops('hops2', 'row2', 2, '--a');
  drawHops('hops3', 'row3', 3, '--b');
})();
