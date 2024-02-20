#include <iostream>

#include <functional> // Для std::function
#include <cmath>

using namespace std;
double bisection(double a, double b, double eps, std::function<double(double)> func, int* iteration = nullptr);
double chord(double a, double b, double eps, std::function<double(double)> func, int* iteration = nullptr);

// Заданная функция f(x)
double f(double x) {
    return x * x - 4; // Пример: x^2 - 4 = 0
}

int main() {
    double X_min, X_max, eps, h;
    int iteration = 0;
    cout << "Введите левую границу: ";
    cin >> X_min;

    cout << "Введите правую границуb: ";
    cin >> X_max;

    cout << "Введите точность eps: ";
    cin >> eps;

    cout << "Введите шаг h: ";
    cin >> h;

    // Отделение корней: вычисляем таблицу значений функции на интервале
    // и определяем отрезки, на которых функция меняет знак
    for (double x = X_min; x <= X_max; x += h) {
        double next_x = x + h;
        if (f(x) * f(next_x) < 0) {
            // Найден отрезок, на котором функция меняет знак
            double root;

            // Уточнение корня с помощью различных методов
            root = bisection(x, next_x, eps, f, &iteration);
            cout << "bisection [" << x << ", " << next_x << "]: " << root << ", iteration:" << iteration << endl;
            cout << endl;
            root = chord(x, next_x, eps, f, &iteration);
            cout << "chord [" << x << ", " << next_x << "]: " << root << ", iteration:" << iteration << endl;
            cout << endl;
        }
    }
    return 0;
}

// Метод половинного деления
double bisection(double a, double b, double eps, std::function<double(double)> func, int* iteration) {
    double c = b; // Переменная для хранения середины отрезка
    // Пока длина отрезка больше заданной точности eps
    while ((b - a) >= eps) {
        if (iteration != nullptr)
        {
            (*iteration)++;
        }

        c = (a + b) / 2; // Находим середину отрезка

        // Если находим корень внутри левой половины отрезка
        if (func(c) == 0.0) {
            break;
        }
        // Если корень находится в левой половине отрезка
        else if (func(a) * func(c) < 0) {
            b = c; // Сдвигаем правую границу отрезка
        }
        // Если корень находится в правой половине отрезка
        else {
            a = c; // Сдвигаем левую границу отрезка
        }
    }

    return c; // Возвращаем найденное приближенное значение корня
}

// Метод хорд
double chord(double a, double b, double eps, std::function<double(double)> func, int* iteration) {
    double x = 0; // Переменная для хранения приближенного значения корня

    // Пока разница между a и b больше точности eps
    while (fabs(b - a) >= eps) {
        if (iteration != nullptr)
        {
            (*iteration)++;
        }
        // Находим точку пересечения прямой с осью ОХ
        x = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Проверяем условие сходимости
        if (fabs(func(x)) < eps) {
            break; // Если достигнута заданная точность, выходим из цикла
        }

        // Сужаем отрезок
        if (func(a) * func(x) < 0) {
            b = x;
        }
        else {
            a = x;
        }
    }

    return x; // Возвращаем найденное приближенное значение корня
}

