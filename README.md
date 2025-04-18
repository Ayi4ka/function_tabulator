# Function Tabulator / Табулятор функции

📌 This program tabulates the function `C(x, p)` using mathematical expressions and constraints, outputs the results in a formatted table, and identifies the most negative result in absolute value.

📌 Эта программа табулирует функцию `C(x, p)` по заданным диапазонам `x` и `p`, учитывает математические условия и отображает результаты в виде таблицы с легендой ошибок.

---

## 🔢 Formula

A = |sin((p / 2) - x + 3)| + 2p / x²
B = |ln(x + π) + p| - √(x + 3)
C = A / B


---

## ✅ Features / Особенности

- User-defined input ranges for `x` and `p`
- Error checks for invalid math operations
- Neatly printed result matrix with error legend
- Finds largest negative value by absolute magnitude

---

## ❗ Error Codes / Коды ошибок

| Code | Description (EN)                  | Описание (RU)                     |
|------|----------------------------------|-----------------------------------|
| a    | x = 0                             | деление на 0                      |
| b    | x + 3 < 0                         | подкоренное выражение < 0        |
| c    | x + π ≤ 0                         | логарифм от неположительного     |
| d    | Denominator equals zero (B = 0)  | знаменатель равен 0              |

---

## ▶️ How to Run / Как запустить

1. Compile the code with a C compiler (GCC, MinGW, etc.)
2. Run in terminal/console:
   ```bash
   gcc function_tabulator.c -o tabulator
   ./tabulator

📚 Topics Covered / Затронутые темы
- Dynamic memory allocation
- Pointer arithmetic
- Mathematical error handling
- Matrix formatting
- Floating-point precision

## Example/Пример 
![image](https://github.com/user-attachments/assets/edb495e2-74f4-43de-baf8-6d2f317ebb08)

## Verification/Верификация
![image](https://github.com/user-attachments/assets/8520aab5-38da-4bdf-960a-83961af2c125)
