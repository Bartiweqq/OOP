#include "functions.h" // Подключение заголовочного файла с объявлениями функций
#include <iostream>
#include <fstream>
#include <cctype>

// Функция, которая проверяет, является ли символ гласной буквой
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Функция, которая проверяет, начинается ли и заканчивается ли слово гласной буквой
bool startsAndEndsWithVowel(const std::string& word) {
    if (word.length() < 2) {
        return false; // Слово должно состоять как минимум из двух символов
    }

    char first = word.front(); // Получение первого символа слова
    char last = word.back(); // Получение последнего символа слова

    return isVowel(first) && isVowel(last); // Проверка, являются ли оба символа гласными
}

// Функция для обработки слов из потока строк
void processWords(std::istringstream& iss) {
    std::string word;
    while (iss >> word) { // Пока есть слова в строке
        if (startsAndEndsWithVowel(word)) { // Проверяем, начинается ли и заканчивается ли слово гласной буквой
            std::cout << word << std::endl; // Выводим слово, если оно соответствует условию
        }
    }
}

// Функция для обработки содержимого файла
void processFile(const std::string& filename) {
    std::ifstream file(filename); // Попытка открыть файл для чтения
    if (!file.is_open()) { // Если файл не открывается
        std::cerr << "Unable to open file." << std::endl; // Выводим сообщение об ошибке
        return; // Выходим из функции
    }

    std::string line;
    while (std::getline(file, line)) { // Пока есть строки в файле
        std::istringstream iss(line); // Создаем поток строк из текущей строки файла
        processWords(iss); // Обрабатываем слова из текущей строки
    }

    file.close(); // Закрываем файл после обработки
}
