#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <map>
#include <string>

class Translator {
private:
    std::map<std::wstring, std::wstring> engToRus;
    std::map<std::wstring, std::wstring> rusToEng;

    void loadDictionary();
    void translateEngToRus() const;
    void translateRusToEng() const;

public:
    Translator();
    bool isEnglishWord(const std::wstring& word) const;
    bool isRussianWord(const std::wstring& word) const;
    void selectMode() const;
};

void runTranslator();

#endif // TRANSLATOR_H
