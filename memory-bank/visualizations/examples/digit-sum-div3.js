(function(){
  const ns = [1,2,3,4,5,6,7,8,9];
  const keep = new Set([4, 7]); // sum(n) = n(n+1)/2 not divisible by 3 only for n=4,7 (n<=9)

  const row1 = document.getElementById('dsRow1');
  ns.forEach(n => {
    const el = document.createElement('div');
    el.className = 'ds-n';
    el.textContent = n;
    row1.appendChild(el);
  });

  const table = document.getElementById('dsTable');
  ns.forEach(n => {
    const sum = n * (n + 1) / 2;
    const mod = sum % 3;
    const row = document.createElement('div');
    row.className = 'ds-trow ' + (keep.has(n) ? 'ds-keep' : 'ds-excl');
    row.innerHTML = `<span class="ds-tn">n=${n}</span><span class="ds-tsum">sum=${sum}</span><span class="ds-tmod">mod 3 = ${mod}</span>`;
    table.appendChild(row);
  });

  const row3 = document.getElementById('dsRow3');
  ns.forEach(n => {
    const el = document.createElement('div');
    el.className = 'ds-n' + (keep.has(n) ? ' ds-keep' : '');
    el.textContent = n;
    row3.appendChild(el);
  });
})();
