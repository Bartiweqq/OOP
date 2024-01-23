#include "Translator.h" 
#include <iostream> 
#include <fstream> 
#include <locale> 
#include <codecvt> 
#include <algorithm> 

Translator::Translator() { 
    loadDictionary();
}

void Translator::loadDictionary() { 
    std::wifstream file("dictionary.txt"); 
    file.imbue(std::locale("ru_RU.utf8")); 

    if (file.is_open()) { // Проверка успешного открытия файла.
        std::wstring engWord, rusWord; // Объявление переменных для хранения слов на английском и русском языках.
        while (file >> engWord >> rusWord) { // Чтение пар слов из файла.
            std::transform(engWord.begin(), engWord.end(), engWord.begin(), towlower); // Преобразование английских слов к нижнему регистру.
            std::transform(rusWord.begin(), rusWord.end(), rusWord.begin(), towlower); // Преобразование русских слов к нижнему регистру.

            std::wcout << L"Считаны слова из словаря: " << engWord << L" - " << rusWord << std::endl; // Вывод считанных слов на экран.
            engToRus[engWord] = rusWord; // Добавление английского слова и его перевода в словарь (английский -> русский).
            rusToEng[rusWord] = engWord; // Добавление русского слова и его перевода в словарь (русский -> английский).
        }
        file.close(); // Закрытие файла после чтения.
        std::wcout << L"Словарь успешно загружен." << std::endl; 
    }
    else {
        std::wcout << L"Не удалось открыть файл словаря." << std::endl; 
    }
}

bool Translator::isEnglishWord(const std::wstring& word) const { // Проверка, является ли слово на английском языке.
    if (word.find(L"eng_") == 0) { // Проверка наличия маркера английского слова.
        return true; // Возвращает true, если слово начинается с маркера английского слова.
    }
    for (wchar_t c : word) { // Проверка каждого символа слова.
        if ((c < L'A' || c > L'Z') && (c < L'a' || c > L'z')) { // Проверка на принадлежность символа к английскому алфавиту.
            return false; // Возвращает false, если слово содержит символы не из английского алфавита.
        }
    }
    return true; 
}

bool Translator::isRussianWord(const std::wstring& word) const { 
    for (wchar_t c : word) { // Проверка каждого символа слова.
        if ((c >= L'А' && c <= L'Я') || (c >= L'а' && c <= L'я')) { 
            return true; 
        }
    }
    return false; 
}

void Translator::translateEngToRus() const { 
    std::wstring word; 

    std::wcout << L"Введите английское слово для перевода на русский: ";
    std::wcin >> word; 

    std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n'); 

    std::transform(word.begin(), word.end(), word.begin(), towlower); // Преобразование введенного слова к нижнему регистру.

    if (word == L"3") { // Проверка на условие выхода из режима перевода.
        std::wcout << L"До свидания!" << std::endl; 
        return; 
    }

    if (!isEnglishWord(word)) { // Проверка, является ли введенное слово английским.
        std::wcout << L"Введено не английское слово. Возвращаемся к выбору режима." << std::endl; 
        return; 
    }

    auto it = engToRus.find(word); // Поиск перевода введенного слова в словаре (английский -> русский).
    if (it != engToRus.end()) { // Проверка, найден ли перевод в словаре.
        std::wcout << L"Перевод на русский: " << it->second << std::endl;
    }
    else {
        std::wcout << L"Слово не найдено в словаре." << std::endl; 
    }
}

void Translator::translateRusToEng() const { 
    std::wstring word; 

    do { // Цикл для запроса ввода слова и обработки его перевода.
        std::wcout << L"Введите русское слово для перевода на английский: "; 
        std::getline(std::wcin, word); // Чтение строки из потока ввода.

        std::transform(word.begin(), word.end(), word.begin(), towlower); // Преобразование введенного слова к нижнему регистру.

        if (word == L"3") { // Проверка на условие выхода из режима перевода.
            std::wcout << L"До свидания!" << std::endl; 
            return; // Возврат из функции.
        }

        if (!isRussianWord(word)) { // Проверка, является ли введенное слово русским.
            std::wcout << L"Введено не английское слово. Возвращаемся к выбору режима." << std::endl; 
            return; 
        }

        auto it = rusToEng.find(word); // Поиск перевода введенного слова в словаре (русский -> английский).
        if (it != rusToEng.end()) { 
            std::wcout << L"Перевод на английский: " << it->second << std::endl; 
        }
        else {
            std::wcout << L"Слово не найдено в словаре." << std::endl; 
        }
        break; 
    } while (true); 
}

void Translator::selectMode() const { 
    int choice; 

    do { 
        std::wcout << L"\nВыберите режим работы:\n"
            << L"1. Англо-русский\n"
            << L"2. Русско-английский\n"
            << L"3. Выйти\n";
        std::wcin >> choice; 
        std::wcin.ignore(std::numeric_limits<std::streamsize>::max(), L'\n'); 

        switch (choice) { 
        case 1:
            translateEngToRus(); // Запуск функции перевода с английского на русский.
            break;
        case 2:
            translateRusToEng(); // Запуск функции перевода с русского на английский.
            break;
        case 3:
            std::wcout << L"До свидания!" << std::endl; 
            return; // Возврат из функции (завершение работы программы).
        default:
            std::wcout << L"Неверный ввод. Попробуйте еще раз." << std::endl; // Вывод сообщения об ошибке.
            break;
        }
    } while (true); // Бесконечный цикл для повторного выбора режима работы.
}

void runTranslator() { // Функция запуска переводчика.
    Translator translator; // Создание объекта класса Translator.
    translator.selectMode(); // Запуск выбора режима работы с переводчиком.
}
