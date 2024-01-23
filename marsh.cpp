#include "MARSH.h"
#include <iostream>

// Реализация перегруженного оператора вывода объекта класса MARSH в поток
std::ostream& operator<<(std::ostream& out, const MARSH& marsh) {
    out << "Route Number: " << marsh.getRouteNumber() << "\n";
    out << "Start Point: " << marsh.getStartPoint() << "\n";
    out << "End Point: " << marsh.getEndPoint() << "\n";
    return out;
}

// Реализация перегруженного оператора ввода объекта класса MARSH из потока
std::istream& operator>>(std::istream& in, MARSH& marsh) {
    int routeNum;
    std::string startPoint, endPoint;

    std::cout << "Enter Route Number: ";
    in >> routeNum;
    marsh.setRouteNumber(routeNum);

    std::cout << "Enter Start Point: ";
    in.ignore(); // Игнорировать символ новой строки во входном буфере
    std::getline(in, startPoint);
    marsh.setStartPoint(startPoint);

    std::cout << "Enter End Point: ";
    std::getline(in, endPoint);
    marsh.setEndPoint(endPoint);

    return in;
}
// Конструктор класса MARSH, инициализирующий поля объекта значениями по умолчанию
MARSH::MARSH() {
    startPoint = ""; // Устанавливаем начальную точку как пустую строку
    endPoint = ""; // Устанавливаем конечную точку как пустую строку
    routeNumber = 0; // Устанавливаем номер маршрута как 0
}

// Методы установки значений для начальной и конечной точек маршрута, принимающие строки в качестве аргументов
void MARSH::setStartPoint(const std::string& start) {
    startPoint = start; // Устанавливаем начальную точку маршрута
}

void MARSH::setEndPoint(const std::string& end) {
    endPoint = end; // Устанавливаем конечную точку маршрута
}

// Метод установки номера маршрута, принимающий целое число в качестве аргумента
void MARSH::setRouteNumber(int number) {
    routeNumber = number; // Устанавливаем номер маршрута
}

// Методы получения значений начальной и конечной точек маршрута
std::string MARSH::getStartPoint() const {
    return startPoint; // Возвращаем начальную точку маршрута
}

std::string MARSH::getEndPoint() const {
    setlocale(LC_ALL, "Russian");
    return endPoint; // Возвращаем конечную точку маршрута
}

// Метод получения номера маршрута
int MARSH::getRouteNumber() const {
    setlocale(LC_ALL, "Russian");
    return routeNumber; // Возвращаем номер маршрута
}
