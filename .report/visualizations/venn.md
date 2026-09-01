# [viz::VennDiagram]

Standard name: Venn diagram — John Venn, 1880
Class: visualization-technique
Spec: [memory-bank/specs/visualizations.md](../../memory-bank/specs/visualizations.md) · term `[viz::VennDiagram]`
Domain: пересечение двух (или трёх) условий
Approach: [Включение-исключение](../approaches.md#включение-исключение) — пространственная
форма (показывает, ЧТО есть общая часть, до чисел)
Description: Два (или три) пересекающихся круга; каждая непересекающаяся область соответствует
своей комбинации условий.
Sequence:
  1. Problem — два круга раздельно, не пересекаются; неясно, как условия связаны между собой
  2. Transform — круги сближаются, появляется общая область без подписанных чисел
  3. Solution — круги пересекаются; каждая из трёх областей подписана числом
Applicability:
  - MUST: важно увидеть саму структуру пересечения (есть общая часть или нет), не только точный
    размер
Limits:
  - MUST NOT: применяться для четырёх и более условий одними кругами — доказано, что четыре круга
    не могут отобразить все возможные пересечения; для двух-трёх условий работает без ограничений
Source: [Britannica — John Venn](https://www.britannica.com/biography/John-Venn) ·
[ReadWriteThink](https://www.readwritethink.org/classroom-resources/lesson-plans/introducing-venn-diagram-kindergarten) ·
[Science Sparks](https://www.science-sparks.com/make-venn-diagram-hula-hoop/)
Used in: euler001
Example: [examples/venn.css](examples/venn.css) · [examples/venn.html](examples/venn.html) · [examples/venn.js](examples/venn.js)
