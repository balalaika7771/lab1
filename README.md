# Лабораторная работа 1: Методы вычисления корней уравнений

Этот репозиторий содержит реализацию лабораторной работы №1 по теме "Методы вычисления корней уравнений", в которой рассматриваются численные методы нахождения корней нелинейных алгебраических и трансцендентных уравнений.

## Структура проекта

Проект включает в себя следующие файлы:

- `lab1.sln` - файл решения для Microsoft Visual Studio.
- `/lab1/lab1.cpp` - исходный код программы на C++, реализующей методы бисекции и хорд для нахождения корней уравнений.

## Компиляция и запуск

Проект разработан и протестирован в среде Microsoft Visual Studio. Для компиляции и запуска проекта необходимо:

1. Открыть файл решения `lab1.sln` в Microsoft Visual Studio.
2. Скомпилировать проект, используя средства среды разработки.
3. Запустить исполняемый файл через среду разработки или из командной строки.

## Реализованные методы

### Метод бисекции

Метод бисекции используется для нахождения корня функции путем последовательного деления интервала пополам и выбора подинтервала, на котором функция меняет знак.

### Метод хорд

Метод хорд (или метод секущих) приближает корень функции за счет использования линейной интерполяции для выбора следующего приближения корня на основе предыдущих приближений.

## Использование

При запуске программы пользователю предлагается ввести границы интервала поиска корня, точность вычислений и шаг для изоляции корней. Программа вычисляет и выводит приближенные значения корней уравнения на заданном интервале, используя указанные методы.

## Лицензия

Этот проект распространяется под лицензией MIT [LICENSE](LICENSE) .