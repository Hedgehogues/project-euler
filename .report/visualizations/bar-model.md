# [viz::BarModel]

Standard name: Bar model / tape diagram — методика Singapore Math
Class: visualization-technique
Spec: [memory-bank/specs/visualizations.md](../../memory-bank/specs/visualizations.md) · term `[viz::BarModel]`
Domain: включение-исключение, пересечение двух условий
Approach: [Включение-исключение](../approaches.md#включение-исключение) — арифметическая форма
(показывает, ИЗ КАКИХ чисел складывается каждая часть)
Description: Полоска фиксированной длины разбивается на непересекающиеся куски; длина каждого
куска равна количеству элементов этой части.
Sequence:
  1. Problem — два числа (сумма по условию A, сумма по условию B) складываются напрямую; итог
     помечен как неверный (двойной счёт общей части)
  2. Transform — те же два числа показаны перекрывающимися; общая, дважды учтённая часть выделена
     отдельно
  3. Solution — полоска разбита на три честных, непересекающихся куска (только A, и то и то,
     только B); их сумма равна верному ответу
Applicability:
  - MUST: в задаче есть «или» между двумя условиями, часть элементов удовлетворяет обоим сразу
Limits:
  - MUST NOT: применяться для трёх и более условий — полоска умеет показать только
    последовательность непересекающихся кусков подряд; при трёх и более пересекающихся условиях
    пересечения не выстраиваются в один ряд честно, сама раскладка перестаёт соответствовать
    реальной структуре
Source: [Third Space Learning](https://thirdspacelearning.com/us/blog/teach-bar-model-method/) ·
[Maths — No Problem!](https://mathsnoproblem.com/en/approach/bar-modelling)
Used in: euler001
Example: [examples/bar-model.css](examples/bar-model.css) · [examples/bar-model.html](examples/bar-model.html) (js не требуется — все значения статичны)
