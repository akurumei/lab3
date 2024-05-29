# lab3
1. Гуща Ярослав Степанович ОМ-3 
Варіант 10 Реалізувати лексичний аналізатор мови програмування. Для зберігання класів лексем організувати таблиці. Вивести вміст таблиць після оброблення тексту програми.

Мова виконання C, C++.

Розрізняти щонайменше такі класи лексем:
 числа (десяткові, з плаваючою крапкою, шістнадцяткові);
 рядкові та символьні константи;
 директиви препроцесора;
 коментарі;
 зарезервовані слова;
 оператори;
 розділові знаки;
 ідентифікатори.
Позначати ситуації з помилками. Наприклад, нерозпізнавані символи.
Можливі варіанти виведення результату роботи програми:
 «розфарбовування» тексту програми;
 виведення пар <лексема, тип лексеми>;
 виведення лексем, що зустрічались в програмі, розбитими на класи.
3. Алгоритм починається з відкриття файлу з вихідним кодом і читання його в рядок. Потім створюється об'єкт класу Lexer, який розбиває вхідний рядок на токени за допомогою методу tokenize(). Метод tokenize() аналізує кожен символ вхідного рядка, визначаючи тип токена (ключове слово, ідентифікатор, число, символ, рядок або коментар) і зберігає їх у вектор. Після завершення токенізації, вектор токенів виводиться на екран у форматі <значення, тип токена>.
