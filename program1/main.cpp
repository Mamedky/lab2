#include <iostream>
#include <fstream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

int main() {
    // 1) Список имён файлов
    const char* filenames[3] = { "file1.txt", "file2.txt", "file3.txt" };

    // 2) Инициализация генератора случайных чисел (делаем это один раз)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 3) Для каждого файла по очереди:
    for (int f = 0; f < 3; ++f) {
        std::ofstream out(filenames[f]);        // 3.1 Открыть файл
        if (!out) {                             // 3.2 Проверить, открылся ли файл
            std::cerr << "Не удалось открыть файл: " << filenames[f] << '\n';
            continue;                           // перейти к следующему файлу
        }

        // 3.3 Записать 10 случайных чисел 1..10 в одну строку
        for (int i = 0; i < 10; ++i) {
            int num = (std::rand() % 10) + 1;   // rand()%10 даёт 0..9, +1 -> 1..10
            out << num;
            if (i < 9) out << ' ';             // пробел между числами, после последнего не ставим
        }
        out << '\n';                            // перевод строки в конце строки
        out.close();                            // 3.4 Закрыть файл (можно опустить — закроется автоматически)
    }

    return 0; // 4) Готово
}
