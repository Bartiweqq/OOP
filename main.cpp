#include <iostream>
#include <algorithm>
#include "MARSH.h"
#include <limits>
#include <chrono>
using namespace std;
using namespace std::chrono;

bool testMARSH(); // Прототип функции тестирования
class LogDuration {
    public:
        LogDuration()
            : start(steady_clock::now())
        {
        }

        ~LogDuration() {
            auto finish = steady_clock::now();
            auto dur = finish - start;
            cerr << duration_cast<milliseconds>(dur).count()
                << " ms" << endl;
        }
    private:
        steady_clock::time_point start;
    };

int main() {
    setlocale(LC_ALL, "Russian");
    {
        LogDuration input;
        const int ARRAY_SIZE = 8;
        MARSH marshArray[ARRAY_SIZE]; // Создание массива объектов класса MARSH

        // Запуск тестов для проверки функциональности класса MARSH
        std::cout << "Running tests...\n";
        if (testMARSH()) { // Если тесты пройдены успешно
            std::cout << "All tests passed!\n"; // Вывести сообщение об успешном прохождении тестов
        }
        else {
            std::cout << "Tests failed!\n"; // Вывести сообщение об ошибке при выполнении тестов
        }

        // Заполнение массива marshArray данными от пользователя
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            std::cout << "Enter details for route " << i + 1 << ":\n";
            std::cin >> marshArray[i]; // Ввод данных о маршруте из консоли
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка символа новой строки
        }

        // Сортировка массива marshArray по номеру маршрута
        std::sort(marshArray, marshArray + ARRAY_SIZE, [](const MARSH& a, const MARSH& b) {
            return a.getRouteNumber() < b.getRouteNumber();
            });

        int routeToFind;
        std::cout << "\nEnter Route Number to find: ";
        std::cin >> routeToFind; // Ввод номера маршрута для поиска

        bool found = false;
        // Поиск маршрута в массиве и вывод информации о нем, если он найден
        for (int i = 0; i < ARRAY_SIZE; ++i) {
            if (marshArray[i].getRouteNumber() == routeToFind) {
                std::cout << "\nRoute details:\n";
                std::cout << marshArray[i]; // Вывод информации о найденном маршруте
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Route with number " << routeToFind << " not found.\n"; // Вывод сообщения об отсутствии маршрута
        }

        return 0; // Возврат из main() с успешным завершением программы
    }
}
