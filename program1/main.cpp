#include <iostream>
#include <fstream>
#include <cstdlib> // rand, srand
#include <ctime>   // time

int main() {
    // 1) ������ ��� ������
    const char* filenames[3] = { "file1.txt", "file2.txt", "file3.txt" };

    // 2) ������������� ���������� ��������� ����� (������ ��� ���� ���)
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 3) ��� ������� ����� �� �������:
    for (int f = 0; f < 3; ++f) {
        std::ofstream out(filenames[f]);        // 3.1 ������� ����
        if (!out) {                             // 3.2 ���������, �������� �� ����
            std::cerr << "�� ������� ������� ����: " << filenames[f] << '\n';
            continue;                           // ������� � ���������� �����
        }

        // 3.3 �������� 10 ��������� ����� 1..10 � ���� ������
        for (int i = 0; i < 10; ++i) {
            int num = (std::rand() % 10) + 1;   // rand()%10 ��� 0..9, +1 -> 1..10
            out << num;
            if (i < 9) out << ' ';             // ������ ����� �������, ����� ���������� �� ������
        }
        out << '\n';                            // ������� ������ � ����� ������
        out.close();                            // 3.4 ������� ���� (����� �������� � ��������� �������������)
    }

    return 0; // 4) ������
}
