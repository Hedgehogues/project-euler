(function(){
  const bases = [2,3,4,5,6,7,8,9,10];
  const dupOf = {4:'2', 8:'2', 9:'3'};   // 4=2^2, 8=2^3, 9=3^2
  const dupExp = {4:'2²', 8:'2³', 9:'3²'};

  function fill(id, cellFn){
    const el = document.getElementById(id);
    bases.forEach(n => {
      const wrap = document.createElement('div');
      wrap.className = 'cz-cell';
      const spec = cellFn(n);
      wrap.innerHTML =
        '<div class="cz-tag' + (spec.tagCls ? ' ' + spec.tagCls : '') + '">' + (spec.tag || '') + '</div>' +
        '<div class="cz-box' + (spec.boxCls ? ' ' + spec.boxCls : '') + '">' + n + '</div>' +
        '<div class="cz-mark' + (spec.markCls ? ' ' + spec.markCls : '') + '">' + (spec.mark || '') + '</div>';
      el.appendChild(wrap);
    });
  }

  // frame 1: plain candidates, nothing known yet
  fill('czBases', () => ({}));

  // frame 2: mark the 3 that are a power of a smaller base already in the row
  fill('czRelate', n => {
    if (dupOf[n]) return {tag: '=' + dupExp[n], tagCls: 'cz-eq', boxCls: 'cz-dup'};
    return {};
  });

  // frame 3: canonical bases processed (checkmark), duplicates skipped (dash)
  fill('czSolved', n => {
    if (dupOf[n]) return {boxCls: 'cz-skip', mark: 'skip', markCls: 'cz-no'};
    return {boxCls: 'cz-canon', mark: '✓', markCls: 'cz-yes'};
  });
})();
