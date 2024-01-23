#ifndef HEXSTRING_H // ������ �� �������������� ��������� ������������� �����
#define HEXSTRING_H

#include <string>

class HexString {
private:
    std::string hexValue; // ����������������� �������� � ���� ������

public:
    // �����������, ����������� ����������������� ������
    HexString(const std::string& hex) : hexValue(hex) {}

    // ��������� ������������������ ��������
    std::string GetHexValue() const {
        return hexValue;
    }

    void ShowHex() const; // ����������� ������������������ ��������

    // �������� ��������� ��������� ��� �������� HexString
    HexString operator-(const HexString& other) const;
};

#endif // HEXSTRING_H
