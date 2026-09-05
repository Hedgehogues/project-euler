(function(){
  const digits = [1, 8, 3, 6, 5, 4, 7, 2]; // "18365472" -- euler038's own N=100,K=8 sample answer m=18

  function buildDigitRow(id, hit){
    const row = document.getElementById(id);
    digits.forEach(d => {
      const el = document.createElement('div');
      el.className = 'pd-d' + (hit ? ' pd-hit' : '');
      el.textContent = d;
      row.appendChild(el);
    });
  }
  function buildSlotRow(id, hit){
    const row = document.getElementById(id);
    for (let i = 1; i <= 8; i++) {
      const el = document.createElement('div');
      el.className = 'pd-slot' + (hit ? ' pd-hit' : '');
      el.textContent = i;
      if (hit) {
        const mk = document.createElement('span');
        mk.className = 'pd-mk';
        mk.textContent = '✓';
        el.appendChild(mk);
      }
      row.appendChild(el);
    }
  }

  buildDigitRow('pdDigits1', false);
  buildSlotRow('pdSlots1', false);

  buildDigitRow('pdDigits2', true);
  buildSlotRow('pdSlots2', true);

  buildSlotRow('pdSlots3', true);

  // Connect each digit box (frame 2, top row) to the slot box of that same value (bottom row),
  // by measured position -- never assumed CSS layout constants (principle 2).
  const wrap = document.getElementById('pdWrap');
  const svg = document.getElementById('pdLinks');
  const wrapRect = wrap.getBoundingClientRect();
  svg.setAttribute('viewBox', `0 0 ${wrapRect.width} ${wrapRect.height}`);
  svg.setAttribute('width', wrapRect.width);
  svg.setAttribute('height', wrapRect.height);

  const digitEls = Array.from(document.getElementById('pdDigits2').children);
  const slotEls = Array.from(document.getElementById('pdSlots2').children);

  let paths = '';
  digitEls.forEach((el, i) => {
    const value = digits[i];
    const slotEl = slotEls[value - 1];
    const dr = el.getBoundingClientRect();
    const sr = slotEl.getBoundingClientRect();
    const x1 = (dr.left + dr.right) / 2 - wrapRect.left;
    const y1 = dr.bottom - wrapRect.top;
    const x2 = (sr.left + sr.right) / 2 - wrapRect.left;
    const y2 = sr.top - wrapRect.top;
    const midY = (y1 + y2) / 2;
    paths += `<path d="M${x1},${y1} C${x1},${midY} ${x2},${midY} ${x2},${y2}" fill="none" stroke="var(--a)" stroke-width="1.5" opacity="0.7"/>`;
  });
  svg.innerHTML = paths;
})();
