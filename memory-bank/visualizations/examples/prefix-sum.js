(function(){
  const values = [3,1,4,5,9,2,6,8];
  const rangeLo = 3, rangeHi = 6; // 1-indexed positions 3..6

  function buildRow(id, arr, classFn){
    const el = document.getElementById(id);
    arr.forEach((v, i) => {
      const d = document.createElement('div');
      d.className = 'ps-cell' + (classFn ? ' ' + classFn(i + 1) : '');
      d.textContent = v;
      el.appendChild(d);
    });
  }

  buildRow('rowA', values, pos => (pos >= rangeLo && pos <= rangeHi) ? 'range' : '');
  buildRow('rowB', values, pos => (pos >= rangeLo && pos <= rangeHi) ? 'range' : '');

  const prefixes = [];
  let running = 0;
  for (const v of values) { running += v; prefixes.push(running); }
  buildRow('rowP', prefixes, pos => pos === rangeHi ? 'good' : (pos === rangeLo - 1 ? 'bad' : ''));
})();
