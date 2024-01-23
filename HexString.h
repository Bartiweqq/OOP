#ifndef HEXSTRING_H // Защита от множественного включения заголовочного файла
#define HEXSTRING_H

#include <string>

class HexString {
private:
    std::string hexValue; // Шестнадцатеричное значение в виде строки

public:
    // Конструктор, принимающий шестнадцатеричную строку
    HexString(const std::string& hex) : hexValue(hex) {}

    // Получение шестнадцатеричного значения
    std::string GetHexValue() const {
        return hexValue;
    }

    void ShowHex() const; // Отображение шестнадцатеричного значения

    // Прототип оператора вычитания для объектов HexString
    HexString operator-(const HexString& other) const;
};

#endif // HEXSTRING_H
