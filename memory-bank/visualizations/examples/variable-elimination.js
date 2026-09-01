(function(){
  const N = 6; // values 1..6 for each unknown

  function buildGrid(id, classFn){
    const el = document.getElementById(id);
    for (let b = N; b >= 1; b--) {          // rows: b from 6 down to 1
      for (let a = 1; a <= N; a++) {        // columns: a from 1 to 6
        const d = document.createElement('div');
        const cls = classFn(a, b);
        d.className = 've-cell' + (cls ? ' ' + cls : '');
        el.appendChild(d);
      }
    }
  }

  buildGrid('gridAll', () => '');
  buildGrid('gridKept', (a, b) => (a + b === 7) ? 've-kept' : 've-dropped');
})();
