#include "Translator.h"
#include <fstream> 
#include <iostream> 
#include <locale> 
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

int main() {
    setlocale(LC_ALL, "Russian");
    {
        LogDuration input;
        system("chcp 1251"); // Установка кодировки консоли в Windows-1251 для поддержки кириллицы.
        std::wstring rus = L"Русский"; // Создание переменной rus типа wstring и инициализация ее значением "Русский".
        std::wcout << rus << std::endl; // Вывод строки "Русский" в консоль.

        runTranslator(); // Вызов функции, которая запускает работу переводчика.

        return 0; // Возврат нуля, обозначающего успешное завершение программы.
    }
}
