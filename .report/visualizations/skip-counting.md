# [viz::SkipCounting]

Standard name: Skip counting — счёт прыжками по числовой прямой
Class: visualization-technique
Domain: делимость, кратность
Approach: — (вне коллекции подходов: показывает само понятие «кратно», а не способ счёта;
подготовительный шаг перед любым из подходов `approaches.md`, не подход сам по себе)
Description: Числа на прямой отмечаются прыжками постоянной длины; точка приземления каждого
прыжка кратна длине прыжка.
Sequence:
  1. Problem — числа на прямой без пометок, неизвестно, какие из них обладают нужным свойством
  2. Transform — прыжки шагом A отмечают числа, кратные A
  3. Transform — прыжки шагом B отмечают числа, кратные B
  4. Solution — объединённая прямая: каждое число окрашено по итоговой принадлежности (A / B / A и B)
Applicability:
  - MUST: свойство чисел проверяется делением/остатком (кратность, чётность, делимость)
  - MUST: число одновременных условий — одно или два
Limits:
  - MUST NOT: применяться как буквальный ручной способ счёта для больших чисел (тысячи и больше) —
    сам приём верен для любых чисел, но рисовать прыжки вручную непрактично; для больших чисел ту же
    идею считают формулой
  - MUST NOT: применяться для трёх и более условий одновременно — число цветов на прямой превышает
    то, что различимо одним взглядом
Source: [SplashLearn](https://www.splashlearn.com/blog/how-to-teach-skip-counting/) ·
[WeAreTeachers](https://www.weareteachers.com/skip-counting/) ·
[Math and Movement](https://mathandmovement.com/product/skip-counting-hopping-mat-2s/)
Used in: euler001
Example: [examples/skip-counting.css](examples/skip-counting.css) · [examples/skip-counting.html](examples/skip-counting.html) · [examples/skip-counting.js](examples/skip-counting.js)
