#include "HexString.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// Метод класса для вывода шестнадцатеричного значения объекта
void HexString::ShowHex() const {
    std::cout << "Hex Value: " << hexValue << std::endl;
}

// Функция для преобразования шестнадцатеричной строки в беззнаковое целое число
unsigned int HexStringToUInt(const std::string& hexString) {
    unsigned int value;
    std::stringstream ss;
    ss << std::hex << hexString; // Устанавливаем шестнадцатеричный режим в потоке
    ss >> value; // Считываем значение
    return value;
}

// Функция для преобразования беззнакового целого числа в шестнадцатеричную строку
std::string UIntToHexString(unsigned int value) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << value; // Форматируем вывод в шестнадцатеричном виде
    return ss.str(); // Получаем шестнадцатеричную строку
}

// Перегрузка оператора "-" для вычитания объектов класса HexString
HexString HexString::operator-(const HexString& other) const {
    // Преобразование текущей шестнадцатеричной строки в беззнаковое целое число
    unsigned int num1 = std::stoul(hexValue, nullptr, 2);

    // Преобразование переданной шестнадцатеричной строки в беззнаковое целое число
    unsigned int num2 = std::stoul(other.hexValue, nullptr, 2);

    // Выполнение вычитания чисел в шестнадцатеричной системе
    unsigned int result = (num1 >= num2) ? (num1 - num2) : (num2 - num1);

    // Представление результата вычитания как шестнадцатеричную строку
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << result;

    return HexString(ss.str()); // Возвращаем результат как объект класса HexString
}
