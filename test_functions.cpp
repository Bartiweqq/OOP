#include "functions.h"
#include <cassert>
#include <fstream> // Добавляем заголовочный файл для работы с файлами

void testFileOpening() {
    // Попытка открыть файл
    std::ifstream file("input.txt");

    // Проверяем, открыт ли файл успешно
    assert(file.is_open());

    // Закрываем файл
    file.close();
}
