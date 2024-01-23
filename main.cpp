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
        system("chcp 1251"); // ��������� ��������� ������� � Windows-1251 ��� ��������� ���������.
        std::wstring rus = L"�������"; // �������� ���������� rus ���� wstring � ������������� �� ��������� "�������".
        std::wcout << rus << std::endl; // ����� ������ "�������" � �������.

        runTranslator(); // ����� �������, ������� ��������� ������ �����������.

        return 0; // ������� ����, ������������� �������� ���������� ���������.
    }
}
