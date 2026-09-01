---
name: visualize-approach
description: Показывает наглядную визуализацию математического/алгоритмического подхода (включение-исключение, трюк Гаусса, диаграмма Венна и т.п.) по каталогу .report/visualizations/. Один приём — один RFC-блочный .md-спек + отдельные файлы кода в examples/. Картинка собирается локально (без публикации в облако) из общего каркаса этого файла + файлов examples/<slug>.*. Вызов навыка на один и тот же приём даёт байт-в-байт один и тот же результат.
---

# Визуализация подхода

Принципы, которым подчиняется всё ниже (форма по понятности, картинка увидена до показа, числа
шагов не совпадают, применимость про класс задач, кадры проблема → преобразования → решение,
одинаковость файлами) — `.claude/rules/visualization-principles.md`. Этот файл — механика сборки,
тот — почему она такая.

Цель навыка — не изобретать новую картинку каждый раз, а КОНСИСТЕНТНО собирать уже
каталогизированный визуальный приём из трёх частей: общего каркаса страницы (этот файл, раздел
«Каркас страницы» ниже — константа, одна на все приёмы), спека приёма (`.report/visualizations/
<slug>.md` — что это за приём, откуда, где предел применимости) и его КОДА (`.report/
visualizations/examples/<slug>.{css,html,js}` — точная реализация кадров, на которую спек
только ссылается полем `Example:`). Спек и код — раздельные файлы намеренно: спек читается как
текст (описание, применимость, границы), код — вставляется дословно, без пересказа. Ничего не
пересобирается на глаз: если навык невольно даёт два разных результата на один и тот же запрос —
это баг навыка, не допустимая вариативность.

## Структура каталога

```
.report/visualizations/
  index.md              — таблица «приём -> файл», читается первым шагом
  <slug>.md             — один приём, RFC-блок [viz::Name]: Standard name / Class / Domain /
                           Description / Sequence / Applicability / Limits / Source / Used in /
                           Example (ссылки на examples/<slug>.*, не сам код)
  examples/<slug>.css   — приёмо-специфичные CSS-классы (общий каркас не дублируется)
  examples/<slug>.html  — разметка ВНУТРИ <div class="flow">...</div>, все кадры от Problem до
                           Solution
  examples/<slug>.js    — если кадрам нужна генерация DOM/измерение геометрии; может отсутствовать
                           (см. Example-поле в <slug>.md — тогда там явно написано «js не требуется»)
```

Один приём — ровно один `.md`-спек + до трёх файлов в `examples/`. Никаких отдельных `.png` —
картинка не публикуется в облако и не скриншотится, она рендерится живьём в браузере из
локального HTML-файла (см. «Сборка страницы» ниже). Задача, для которой приём применён повторно,
НЕ создаёт новый файл — в существующий `<slug>.md` дописывается строка в поле `Used in:`,
остальное не меняется.

## Схема поля `Example:` в `<slug>.md`

Не код, а ссылки на код — сам код живёт в `examples/`:

```
Example: [examples/<slug>.css](examples/<slug>.css) · [examples/<slug>.html](examples/<slug>.html) · [examples/<slug>.js](examples/<slug>.js)
```

Разметка кадров ВСЕГДА следует одной структуре — первый кадр «Problem», последний «Solution»,
между ними один и более «Transform» (то же деление, что в поле `Sequence:` этого файла):

```html
<div class="frame-tag">{символ шага, не предложение}</div>
<div class="frame"><div class="frame-inner">{сама картинка кадра}</div></div>
<div class="flow-arrow">↓</div>
{... следующий кадр ...}
<div class="frame-tag solved">=</div>
<div class="frame"><div class="frame-inner">{картинка решения}</div></div>
```

`frame-tag` — короткий символ (`?`, `×2`, `−`, `⌒`, `∩`, `=`), не текстовая подпись: картинка
обязана быть понятна БЕЗ чтения текста, `frame-tag` — минимальная навигационная метка «на каком
мы сейчас шаге», не объяснение.

## Вход

Свободное описание подхода/визуализации, например: «трюк Гаусса», «покажи включение-исключение»,
«диаграмма Венна», «как объяснить кратные 7 и 11» (описание задачи — навык сам сопоставляет его
с математическим ПОДХОДОМ, не с самой задачей). Может быть запрошено несколько подряд.

## Шаги (строго по порядку)

1. **Прочитать `.report/visualizations/index.md` целиком.** Обязательный первый шаг при каждом
   вызове — не полагаться на память о прошлом вызове, каталог мог пополниться.

2. **Сопоставить запрос с существующей строкой индекса** по сути (не по формулировке задачи
   пользователя, а по тому, какой ИЗ УЖЕ ЗАВЕДЁННЫХ приёмов подходит):
   - «двойной счёт», «пересекающиеся условия», «или» между свойствами → `bar-model.md`, либо
     `venn.md` (если пользователь явно просит «диаграмму»/«круги»/«Венна» — venn; если не
     уточнил — предложить оба, см. шаг 6).
   - «что входит в ответ», «какие числа», «на числовой прямой», «кратные» → `skip-counting.md`.
   - «сумма прогрессии», «Гаусс», «почему формула», «без перебора» → `gauss-pairing.md`.
   - Явного совпадения нет → см. шаг 5 (новый приём).

3. **Если совпадение найдено — прочитать `<slug>.md` целиком, затем файлы `examples/<slug>.*`,
   на которые ссылается его поле `Example:`**, и собрать страницу (см. «Сборка страницы» ниже) из
   общего каркаса + этих файлов. Ничего не перерисовывать и не пересчитывать — код `examples/`
   уже провалидирован один раз, это и есть весь смысл детерминизма. Показать пользователю:
   собранную картинку (открыть локальный HTML) + поля `Description` / `Applicability` / `Limits`
   из `<slug>.md` дословно, коротко.

4. **Если совпадения нет вообще — новый приём, полный цикл, не разовая картинка.**
   a. **`WebSearch` на устоявшееся название и источник** ДО написания файла — не изобретать
      своё название как будто оно общепринятое. Если находится — использовать его, с ссылкой на
      источник (поле `Source:`). Если честно не находится — так и записать в `Description:`:
      «отдельного названия нет», и назвать ближайшего реального родственника, явно отметив, что
      это НЕ то же самое.
   b. Придумать генерализованный пример, НЕ СВЯЗАННЫЙ с конкретной задачей пользователя (тот же
      принцип: сквозной случай «кратно 2 или 3, до 20» — переиспользовать его же, если новый
      приём совместим по смыслу; если нет — завести новый маленький сквозной случай и явно
      объяснить в файле, почему).
   c. Спроектировать `Sequence:` — от Problem до Solution, с явными Transform-кадрами между ними
      (см. «Схема поля Sequence» в `index.md`).
   d. Написать `<slug>.md` целиком по RFC-схеме (см. `index.md`) и файлы `examples/<slug>.css`/
      `.html`/`.js` — реальный код кадров, собранный и провалидированный в браузере (шаг «Сборка
      страницы» ниже) ДО того, как приём считается готовым; `Example:` в `<slug>.md` — только
      ссылки на эти три файла.
   e. Добавить строку в `index.md`.
   f. Только ПОСЛЕ того как всё сохранено на диск — показать результат пользователю. Это
      гарантирует, что следующий вызов навыка на тот же приём найдёт готовый файл на шаге 2 и
      соберёт байт-в-байт то же самое, не проходя весь цикл заново.

5. **Неоднозначность — решать явным вопросом пользователю** (`AskUserQuestion`), не угадывать
   молча, если запрос подходит под 2+ строки индекса одинаково хорошо.

6. **Явное противоречие в уже сохранённом примере** (числа в разных кадрах случайно совпадают и
   картинка перестаёт читаться однозначно — прецедент: `gauss-pairing.md` до перехода на
   парное сложение эта же ошибка была в шаге «лестница-в-прямоугольник», исправлена сменой всей
   раскладки) — чинится правкой файлов `examples/<slug>.*` + пересборкой страницы, не заменяется
   на объяснение без картинки.

## Каркас страницы — фиксированный, не пересобирать с нуля

Общий для ВСЕХ приёмов: шрифты, цветовые токены, layout карточки и потока кадров. Не содержит ни
одного приёмо-специфичного класса — те живут только в `examples/<slug>.css`.

```html
<!doctype html>
<html lang="ru">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>{Название приёма}</title>
<link rel="stylesheet" href="https://fonts.googleapis.com/css2?family=Newsreader:ital,opsz,wght@0,6..72,600;0,6..72,700;1,6..72,600&family=Public+Sans:wght@400;500;600;700&family=JetBrains+Mono:wght@400;500;700&display=swap">
<style>
  :root{
    --paper:#F1F3F6; --surface:#FFFFFF; --ink:#141821; --ink-soft:#565F6B; --rule:#DBE0E6;
    --a:#2F6FED; --a-bg:#DCE7FD; --a-faint:#B7CDF9;
    --b:#E0434B; --b-bg:#FBDEDF;
    --ab:#7C3FD6; --ab-bg:#EBE0FA;
    --good:#1E8F5F; --good-bg:#DCF2E6;
    --warn:#9A6B0A; --warn-bg:#F3E7C9;
    --shadow:0 1px 2px rgba(20,24,33,.06), 0 8px 24px -10px rgba(20,24,33,.18);
    --font-d:'Newsreader',Georgia,serif; --font-b:'Public Sans',-apple-system,sans-serif; --font-m:'JetBrains Mono',ui-monospace,Menlo,monospace;
  }
  @media (prefers-color-scheme: dark){
    :root{
      --paper:#111318; --surface:#181B21; --ink:#E7EAEE; --ink-soft:#A2A9B3; --rule:#2A2F37;
      --a:#6C9CF7; --a-bg:#1B2740; --a-faint:#33436B;
      --b:#F0787D; --b-bg:#3A1E20;
      --ab:#B18AF0; --ab-bg:#2B1F3F;
      --good:#5FCB94; --good-bg:#173226;
      --warn:#D9AC4E; --warn-bg:#3A2F16;
      --shadow:0 1px 2px rgba(0,0,0,.4), 0 10px 30px -10px rgba(0,0,0,.6);
    }
  }
  *{box-sizing:border-box;}
  body{background:var(--paper); color:var(--ink); font-family:var(--font-b); margin:0; padding:36px 18px 70px;}
  .wrap{max-width:680px; margin:0 auto;}
  h1{font-family:var(--font-d); font-style:italic; font-weight:700; text-align:center; font-size:clamp(28px,5vw,38px); margin:0 0 10px;}
  header p{text-align:center; color:var(--ink-soft); font-size:14px; max-width:540px; margin:0 auto 40px;}
  .eyebrow{display:block; text-align:center; font-family:var(--font-m); font-size:11px; letter-spacing:.1em; text-transform:uppercase; color:var(--ink-soft); margin-bottom:10px;}

  .card{background:var(--surface); border:1px solid var(--rule); border-radius:16px; padding:24px clamp(18px,4vw,32px); margin-bottom:20px; box-shadow:var(--shadow);}
  .card h2{font-family:var(--font-d); font-size:23px; font-weight:700; margin:0 0 2px;}
  .stdtag{font-family:var(--font-m); font-size:11px; margin-bottom:18px;}
  .stdtag.found{color:var(--good);}

  /* --- flow: problem -> transform(s) -> solution --- */
  .flow{background:var(--paper); border:1px solid var(--rule); border-radius:12px; padding:18px; display:flex; flex-direction:column; align-items:center;}
  .frame{width:100%; display:flex; justify-content:center;}
  .frame-inner{width:100%; max-width:560px;}
  .frame-tag{
    font-family:var(--font-m); font-size:11px; font-weight:700; letter-spacing:.04em;
    color:var(--surface); background:var(--ink-soft); border-radius:20px; padding:2px 10px;
    display:block; width:fit-content; margin:0 auto 8px;
  }
  .frame-tag.solved{background:var(--good);}
  .flow-arrow{color:var(--rule); font-size:20px; line-height:1; margin:6px 0; font-family:var(--font-m);}

  .filelink{margin-top:14px; font-size:11px; color:var(--ink-soft); font-family:var(--font-m); text-align:center;}

  .ans{background:var(--good-bg); color:var(--good); padding:2px 10px; border-radius:6px; font-weight:700;}
  .ans-big{display:block; text-align:center; font-family:var(--font-m); font-size:36px; font-weight:700; background:var(--good-bg); color:var(--good); border-radius:12px; padding:14px 10px; margin:0 auto; max-width:170px;}

  footer{max-width:680px; margin:30px auto 0; padding-top:20px; border-top:1px solid var(--rule); font-size:11.5px; color:var(--ink-soft); font-family:var(--font-m); text-align:center;}

  {examples/<slug>.css -- вставляется здесь, БЕЗ ИЗМЕНЕНИЙ}
</style>
</head>
<body>
<div class="wrap">
  <div class="card">
    <h2>{Название приёма}</h2>
    <div class="stdtag found">✓ {Standard name}</div>
    <div class="flow">
      {examples/<slug>.html -- вставляется здесь, БЕЗ ИЗМЕНЕНИЙ}
    </div>
    <div class="filelink">.report/visualizations/{slug}.md</div>
  </div>
</div>
<script>
{examples/<slug>.js -- вставляется здесь, БЕЗ ИЗМЕНЕНИЙ (может отсутствовать)}
</script>
</body>
</html>
```

## Сборка страницы (шаг 3/4d, инструмент)

1. Взять текст «Каркас страницы» выше буквально.
2. Подставить `{Название приёма}` = `Standard name` из `<slug>.md` (без ссылки/года — короткая
   форма для заголовка); `{Standard name}` в теге — та же строка.
3. Прочитать `Example:` в `<slug>.md`, по её ссылкам открыть `examples/<slug>.css`/`.html`/`.js`
   и вставить каждый в отмеченное место каркаса, ДОСЛОВНО (copy-paste, не пересказ и не новые
   числа/цвета/классы).
4. Записать собранный файл в scratchpad-директорию сессии (`open <путь>` — открывает в браузере
   локально, без публикации в облако — см. стандарт-инструкцию «Делай в локальных скретчпад
   html»).
5. Несколько приёмов в одном запросе — несколько `.card`-блоков внутри одного `.wrap`, каждый со
   своими `examples/<slug>.*`, общий каркас (head/CSS/`<script>`) — один на страницу, JS-файлы
   разных приёмов конкатенируются внутри одного `<script>`.

## Жёсткое правило детерминизма

Один и тот же приём — всегда один и тот же код в `examples/`, одна и та же собранная картинка,
один и тот же текст в `<slug>.md`. Единственное легитимное отличие между двумя вызовами —
обновление `<slug>.md` и/или `examples/<slug>.*`, если пользователь ПРЯМО попросил их изменить
(тогда сначала правятся файлы, потом страница пересобирается по «Сборка страницы» заново). Без
такой правки — байт-в-байт то же самое: код `examples/` переиспользуется, а не переписывается на
глаз при каждом вызове.
