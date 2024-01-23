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

extern void testFileOpening(); // ���������� ������� ������������

int main() {
    setlocale(LC_ALL, "Russian");
    {
        LogDuration input;
        std::string filename = "input.txt";
        processFile(filename); // ����� ������� ��� ��������� �����

        testFileOpening(); // ����� ������� ������������ �������� �����

        std::cout << "All tests passed!" << std::endl; // ����� ��������� � ���������� ���� ������
        return 0; // ����������� ����, ����� �������� �������� ���������� ���������
    }
}
