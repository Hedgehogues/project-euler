# [viz::GaussPairing]

Standard name: Gauss's trick — парное сложение («радуга»)
Class: visualization-technique
Domain: сумма арифметической прогрессии
Approach: [Замкнутая формула суммы арифметической прогрессии](../approaches.md#замкнутая-формула-суммы-арифметической-прогрессии)
Description: Числа складываются не по порядку, а парами с двух концов ряда; каждая пара даёт одну
и ту же сумму.
Sequence:
  1. Problem — числа ряда стоят по порядку, соединены знаками «+»; сумма не подсчитана
  2. Transform — числа сцеплены в пары с двух концов дугами; над каждой дугой — сумма пары
  3. Solution — итоговая сумма: число пар × сумма одной пары (плюс середина, если число элементов
     нечётное)
Applicability:
  - MUST: числа идут подряд с постоянным шагом (арифметическая прогрессия)
Limits:
  - MUST NOT: применяться при переменном шаге между числами — тогда пары с двух концов дают разные
    суммы, приём не работает
Source: [eduSeed](https://eduseed.in/2025/12/04/gauss-method-of-addition-the-day-a-10-year-old-outsmarted-his-teacher/) ·
[NCTM — The Story of Gauss](https://www.nctm.org/Publications/TCM-blog/Blog/The-Story-of-Gauss/)
Used in: euler001
Example: [examples/gauss-pairing.css](examples/gauss-pairing.css) · [examples/gauss-pairing.html](examples/gauss-pairing.html) · [examples/gauss-pairing.js](examples/gauss-pairing.js)
