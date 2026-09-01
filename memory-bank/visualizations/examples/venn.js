(function(){
  const only2 = 54, both = 36, only3 = 27, total = only2 + both + only3;
  document.getElementById('venn').innerHTML = `
    <svg viewBox="0 0 300 220" width="300" height="220">
      <circle cx="110" cy="106" r="70" style="fill:var(--a-bg); stroke:var(--a); stroke-width:2;" fill-opacity="0.8"/>
      <circle cx="190" cy="106" r="70" style="fill:var(--b-bg); stroke:var(--b); stroke-width:2;" fill-opacity="0.55"/>
      <text x="75" y="112" font-family="JetBrains Mono, monospace" font-size="17" font-weight="700" text-anchor="middle" style="fill:var(--a);">${only2}</text>
      <text x="150" y="112" font-family="JetBrains Mono, monospace" font-size="17" font-weight="700" text-anchor="middle" style="fill:var(--ab);">${both}</text>
      <text x="225" y="112" font-family="JetBrains Mono, monospace" font-size="17" font-weight="700" text-anchor="middle" style="fill:var(--b);">${only3}</text>
      <text x="150" y="205" font-family="JetBrains Mono, monospace" font-size="13" text-anchor="middle" style="fill:var(--ink);">${only2} + ${both} + ${only3} = ${total}</text>
    </svg>`;
})();
