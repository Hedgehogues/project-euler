---
status: draft
app: projecteuler
tags: [projecteuler, euler002, solution, draft]
---

# euler002 — Even Fibonacci numbers

## Vision
For each of `T` given values of `N`, sum the even-valued terms of the Fibonacci sequence that
do not exceed `N`. `N` can be as large as `4·10^16` and `T` can be large too — regenerating the
Fibonacci sequence from scratch per query is wasted work, since the sequence itself doesn't
depend on the query.

## Термины
MUST/MUST NOT/SHALL/SHOULD/SHOULD NOT/MAY — как в RFC 2119. Термин задачи:
[euler::Problem002](../_terms.md#eulerproblem002). Использует один каталогизированный подход:
[approach::PrecomputeAndBinarySearch](../_terms.md#approachprecomputeandbinarysearch).

## Скоуп
**В скоупе:** `euler002/solution.cpp` — модель задачи, алгоритм, обоснование сложности, критерии
корректности.

**Вне скоупа:** визуальное объяснение бинарного поиска как общей техники (не привязано к этой
задаче — [visualizations](visualizations.md)); общие правила репозитория (формат ввода-вывода,
ASCII-only — см. корневой README).

## Architecture

### Обзор (прозой)
Чётные числа Фибоначчи встречаются раз в три члена (`F(0)=0` чётно, дальше нечётно-нечётно-чётно
по кругу — сумма двух нечётных чётна). Вместо того чтобы проверять это на каждом члене заново на
каждый запрос, решение один раз строит список ВСЕХ чётных членов Фибоначчи до `4·10^16` вместе с
накопленной суммой ([approach::PrecomputeAndBinarySearch](../_terms.md#approachprecomputeandbinarysearch))
— такой список короткий (чётный член растёт экспоненциально, поэтому членов до `4·10^16` всего
десятки). На каждый запрос `N` — `upper_bound` по этому списку находит последний член `≤ N`, ответ
— его накопленная сумма.

### Данные
- Вход: `T`, затем `T` строк с `N` (до `4·10^16`).
- Выход: `T` строк — сумма чётных чисел Фибоначчи `≤ N`, на строку.

## Requirements
> Формулировка — критерий приёмки — статус.

### MUST
- `solve(n)` MUST совпадать с прямым суммированием чётных членов Фибоначчи `≤ n` для граничных и
  характерных `n` (0, 1, 2, 8, 10, 100, 4000000) — **MUST-match-bruteforce** — критерий: разница
  нулевая на всём проверенном диапазоне, включая `n=0` и `n=1` (ответ 0 — ни один чётный член ещё
  не достигнут). Статус: реализовано (Accepted 100% на HackerRank; независимо перепроверено
  прямым суммированием на этих `n`).
- Список чётных членов Фибоначчи и накопленная сумма по нему MUST строиться один раз, до чтения
  запросов — **MUST-precompute-once** — критерий: цикл построения списка находится вне цикла
  `while (t--)`. Статус: реализовано.
- Ответ на каждый запрос MUST находиться бинарным поиском (`upper_bound`) по готовому списку, не
  повторным проходом по последовательности Фибоначчи — **MUST-binary-search-per-query** —
  критерий: внутри цикла запросов нет генерации чисел Фибоначчи, только `upper_bound` и
  индексация. Статус: реализовано.
- Построение списка MUST не переполняться и не зацикливаться при `N` до `4·10^16` включительно —
  **MUST-no-overflow-at-bound** — критерий: `N_MAX = 4·10^16` умещается в `long long`
  (`< 2^63 ≈ 9.2·10^18`), цикл построения списка останавливается по условию `a <= N_MAX`, не
  бесконечен. Статус: реализовано.
- `solution.cpp` MUST быть чистым ASCII — **MUST-ascii-only** — критерий:
  `grep -nP '[^\x00-\x7F]' solution.cpp` пуст. Статус: реализовано.
- Ввод-вывод MUST соответствовать формату HackerRank — **MUST-io-format**. Статус: реализовано.

## Связи
- Подход: [approach::PrecomputeAndBinarySearch](../_terms.md#approachprecomputeandbinarysearch).
- Визуальное объяснение (не дублируется здесь):
  [viz::BinarySearch](../_terms.md#vizbinarysearch) — общая техника, не завязанная на числа
  Фибоначчи; сквозной пример каталога, не числа этой задачи.
- Код: `euler002/solution.cpp`; директорийный README: `euler002/README.md`.
- Термин: [euler::Problem002](../_terms.md#eulerproblem002).
