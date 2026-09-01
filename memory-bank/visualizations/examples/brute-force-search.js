(function(){
  const N = 36;      // 6x6 candidates
  const HIT = 23;    // the answer sits at cell 23 (1-based, reading order)

  function fill(id, cellFn){
    const el = document.getElementById(id);
    for (let i = 1; i <= N; i++) {
      const d = document.createElement('div');
      const spec = cellFn(i);
      d.className = 'bf-cell' + (spec.cls ? ' ' + spec.cls : '');
      d.textContent = spec.txt;
      el.appendChild(d);
    }
  }

  // frame 1: all unknown
  fill('bfUnknown', () => ({cls:'bf-q', txt:'?'}));

  // frame 2: the same candidates, still unopened -- counting does not look inside
  fill('bfCount', () => ({cls:'bf-q', txt:'?'}));

  // frame 2: the budget — 100 empty slots, countable
  const budget = document.getElementById('bfBudget');
  for (let i = 0; i < 100; i++) {
    const d = document.createElement('div');
    d.className = 'bf-slot';
    budget.appendChild(d);
  }

  // frame 3: walked in order, answer found at HIT
  fill('bfWalk', i => {
    if (i < HIT) return {cls:'bf-seen', txt:'✓'};
    if (i === HIT) return {cls:'bf-hit', txt:'★'};
    return {cls:'bf-q', txt:'?'};
  });
})();
