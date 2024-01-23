#include "MARSH.h"
#include <iostream>

// ���������� �������������� ��������� ������ ������� ������ MARSH � �����
std::ostream& operator<<(std::ostream& out, const MARSH& marsh) {
    out << "Route Number: " << marsh.getRouteNumber() << "\n";
    out << "Start Point: " << marsh.getStartPoint() << "\n";
    out << "End Point: " << marsh.getEndPoint() << "\n";
    return out;
}

// ���������� �������������� ��������� ����� ������� ������ MARSH �� ������
std::istream& operator>>(std::istream& in, MARSH& marsh) {
    int routeNum;
    std::string startPoint, endPoint;

    std::cout << "Enter Route Number: ";
    in >> routeNum;
    marsh.setRouteNumber(routeNum);

    std::cout << "Enter Start Point: ";
    in.ignore(); // ������������ ������ ����� ������ �� ������� ������
    std::getline(in, startPoint);
    marsh.setStartPoint(startPoint);

    std::cout << "Enter End Point: ";
    std::getline(in, endPoint);
    marsh.setEndPoint(endPoint);

    return in;
}
// ����������� ������ MARSH, ���������������� ���� ������� ���������� �� ���������
MARSH::MARSH() {
    startPoint = ""; // ������������� ��������� ����� ��� ������ ������
    endPoint = ""; // ������������� �������� ����� ��� ������ ������
    routeNumber = 0; // ������������� ����� �������� ��� 0
}

// ������ ��������� �������� ��� ��������� � �������� ����� ��������, ����������� ������ � �������� ����������
void MARSH::setStartPoint(const std::string& start) {
    startPoint = start; // ������������� ��������� ����� ��������
}

void MARSH::setEndPoint(const std::string& end) {
    endPoint = end; // ������������� �������� ����� ��������
}

// ����� ��������� ������ ��������, ����������� ����� ����� � �������� ���������
void MARSH::setRouteNumber(int number) {
    routeNumber = number; // ������������� ����� ��������
}

// ������ ��������� �������� ��������� � �������� ����� ��������
std::string MARSH::getStartPoint() const {
    return startPoint; // ���������� ��������� ����� ��������
}

std::string MARSH::getEndPoint() const {
    setlocale(LC_ALL, "Russian");
    return endPoint; // ���������� �������� ����� ��������
}

// ����� ��������� ������ ��������
int MARSH::getRouteNumber() const {
    setlocale(LC_ALL, "Russian");
    return routeNumber; // ���������� ����� ��������
}
