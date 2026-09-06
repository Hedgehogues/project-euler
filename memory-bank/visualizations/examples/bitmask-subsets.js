(function(){
  const N = 3;
  const K = 2;
  const labels = ['p0', 'p1', 'p2'];

  function popcount(m){ let c=0; while(m){ c+=m&1; m>>=1; } return c; }
  function setName(m){
    const names = [];
    for (let i = 0; i < N; i++) if (m & (1 << i)) names.push(labels[i]);
    return names.length ? '{' + names.join(',') + '}' : '{}';
  }

  function buildTable(id, onlyHits){
    const table = document.getElementById(id);
    for (let m = 0; m < (1 << N); m++) {
      const pc = popcount(m);
      if (onlyHits && pc !== K) continue;
      const row = document.createElement('div');
      row.className = 'bm-row' + (pc === K ? ' bm-hit' : '');
      let bits = '';
      for (let i = N - 1; i >= 0; i--) {
        bits += `<span class="bm-bit ${(m & (1<<i)) ? 'on' : ''}">${(m & (1<<i)) ? 1 : 0}</span>`;
      }
      row.innerHTML = `<span class="bm-dec">${m}</span><span class="bm-bits">${bits}</span><span class="bm-set">${setName(m)}</span><span class="bm-pc">popcount=${pc}</span>`;
      table.appendChild(row);
    }
  }

  buildTable('bmTable', false);
  buildTable('bmTable2', true);
})();
