#include "HexString.h"
#include <iostream>
#include <sstream>
#include <iomanip>

// ����� ������ ��� ������ ������������������ �������� �������
void HexString::ShowHex() const {
    std::cout << "Hex Value: " << hexValue << std::endl;
}

// ������� ��� �������������� ����������������� ������ � ����������� ����� �����
unsigned int HexStringToUInt(const std::string& hexString) {
    unsigned int value;
    std::stringstream ss;
    ss << std::hex << hexString; // ������������� ����������������� ����� � ������
    ss >> value; // ��������� ��������
    return value;
}

// ������� ��� �������������� ������������ ������ ����� � ����������������� ������
std::string UIntToHexString(unsigned int value) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << value; // ����������� ����� � ����������������� ����
    return ss.str(); // �������� ����������������� ������
}

// ���������� ��������� "-" ��� ��������� �������� ������ HexString
HexString HexString::operator-(const HexString& other) const {
    // �������������� ������� ����������������� ������ � ����������� ����� �����
    unsigned int num1 = std::stoul(hexValue, nullptr, 2);

    // �������������� ���������� ����������������� ������ � ����������� ����� �����
    unsigned int num2 = std::stoul(other.hexValue, nullptr, 2);

    // ���������� ��������� ����� � ����������������� �������
    unsigned int result = (num1 >= num2) ? (num1 - num2) : (num2 - num1);

    // ������������� ���������� ��������� ��� ����������������� ������
    std::stringstream ss;
    ss << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << result;

    return HexString(ss.str()); // ���������� ��������� ��� ������ ������ HexString
}
