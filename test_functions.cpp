#include "functions.h"
#include <cassert>
#include <fstream> // ��������� ������������ ���� ��� ������ � �������

void testFileOpening() {
    // ������� ������� ����
    std::ifstream file("input.txt");

    // ���������, ������ �� ���� �������
    assert(file.is_open());

    // ��������� ����
    file.close();
}
