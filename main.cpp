// Подключение заголовочных файлов для работы с классами и стандартными библиотеками
#include "HexString.h"
#include <iostream>
#include <chrono>

// Прототип функции для тестирования вычитания из UnitTest.cpp
bool TestSubtraction();

// Используемые пространства имен для удобства
using namespace std;
using namespace std::chrono;

// Класс для измерения времени выполнения кода в блоке
class LogDuration {
public:
    // Конструктор класса, инициализирующий начальное время
    LogDuration()
        : start(steady_clock::now())
    {
    }

    // Деструктор класса, выводящий затраченное время при уничтожении объекта
    ~LogDuration() {
        auto finish = steady_clock::now(); // Получаем текущее время
        auto dur = finish - start; // Вычисляем разницу времени
        cerr << duration_cast<milliseconds>(dur).count()
            << " ms" << endl; // Выводим время в миллисекундах
    }
private:
    steady_clock::time_point start; // Начальное время измерения
};

// Главная функция программы
int main() {
    setlocale(LC_ALL, "Russian"); // Устанавливаем русскую локаль для корректного вывода

    {
        LogDuration input; // Создаем объект класса LogDuration для измерения времени ввода данных
        bool passed = TestSubtraction(); // Вызываем тесты

        // Проверка прохождения тестов и вывод результата
        if (passed) {
            std::cout << "All tests passed successfully!" << std::endl;
        }
        else {
            std::cout << "Tests failed!" << std::endl;
        }

        // Ввод двух шестнадцатеричных чисел для вычисления
        std::string input1, input2;
        std::cout << "Введите первое шестнадцатеричное число: ";
        std::cin >> input1;
        std::cout << "Введите второе шестнадцатеричное число: ";
        std::cin >> input2;

        // Проверка, что вычитаемое число больше числа, из которого вычитают
        HexString hexInput1(input1);
        HexString hexInput2(input2);

        // Проверка условия для правильного выполнения операции вычитания
        if (hexInput2.GetHexValue() > hexInput1.GetHexValue()) {
            std::cout << "Ошибка: вычитаемое число должно быть больше числа, из которого производится вычитание." << std::endl;
            return 1;
        }

        // Вычитание введенных чисел и вывод результата
        HexString subtractionResult = hexInput1 - hexInput2;
        std::cout << "Результат вычитания: " << subtractionResult.GetHexValue() << std::endl;
    }

    return 0; // Возвращаемый код завершения программы
}
