(function(){
  const LO = 2, HI = 19; // numbers 2..19

  function buildRow(id, classFn){
    const el = document.getElementById(id);
    for (let i = LO; i <= HI; i++) {
      const d = document.createElement('div');
      const cls = classFn(i);
      d.className = 'ncell' + (cls ? ' ' + cls : '');
      d.textContent = i;
      el.appendChild(d);
    }
  }

  buildRow('rowPlain', () => 'plain');

  buildRow('row2', i => {
    if (i === 2) return 'prime';
    if (i % 2 === 0) return 'a';
    return 'plain';
  });

  buildRow('row3', i => {
    if (i === 2 || i === 3) return 'prime';
    if (i % 2 === 0) return 'a';
    if (i % 3 === 0) return 'b';
    return 'plain';
  });

  buildRow('rowFinal', i => {
    const div2 = i % 2 === 0, div3 = i % 3 === 0;
    if (i === 2 || i === 3) return 'prime';
    if (div2) return 'a';
    if (div3) return 'b';
    return 'prime';
  });

  function cellCenters(rowEl){
    const rowRect = rowEl.getBoundingClientRect();
    return Array.from(rowEl.children).map(c => {
      const r = c.getBoundingClientRect();
      return (r.left + r.right) / 2 - rowRect.left;
    });
  }

  function drawHops(svgId, rowId, start, step, colorVar){
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
    for (let i = start; i <= HI; i += step) multiples.push(i);
    let path = '';
    for (let k = 0; k < multiples.length - 1; k++) {
      const x1 = centers[multiples[k] - LO];
      const x2 = centers[multiples[k + 1] - LO];
      const midx = (x1 + x2) / 2;
      path += `M${x1},${baseline} Q${midx},2 ${x2},${baseline} `;
    }
    svg.innerHTML = `<path d="${path}" fill="none" stroke="var(${colorVar})" stroke-width="2"/>`;
  }
  drawHops('hops2', 'row2', 2, 2, '--a');
  drawHops('hops3', 'row3', 3, 3, '--b');
})();
