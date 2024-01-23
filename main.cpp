#include "functions.h" 
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;
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

extern void testFileOpening(); // Объявление функции тестирования

int main() {
    setlocale(LC_ALL, "Russian");
    {
        LogDuration input;
        std::string filename = "input.txt";
        processFile(filename); // Вызов функции для обработки файла

        testFileOpening(); // Вызов функции тестирования открытия файла

        std::cout << "All tests passed!" << std::endl; // Вывод сообщения о завершении всех тестов
        return 0; // Возвращение нуля, чтобы показать успешное завершение программы
    }
}
