﻿#include <iostream>
#include <string>
#include <Vector>
#include <fstream>
#include "Ks.h"
#include "Pipe.h"
#include "funcs.h"
using namespace std;
extern std::map<int, Ks*> ksMap;
int main()
{
    setlocale(LC_ALL, "ru");
    while (true) {
        std::cout << "1)Добавить трубу\n";
        std::cout << "2)Добавить КС\n";
        std::cout << "3)Просмотр труб\n";
        std::cout << "4)Просмотр Кс\n";
        std:: cout << "5)Редактирование Труб\n";
        std::cout << "6)Редактирование КС\n";
        std::cout << "7)Сохранить\n";
        std::cout << "8)Загрузить\n";
        std::cout << "9)Удаление труб\n";
        std::cout << "10)Удаление Кс\n";
        std::cout << "11)Создание Сети\n";
        std::cout << "12)Топологическая сортировка\n";
        std::cout << "0)Выход\n";
        std::getline(cin, temp);
        try {
            answer = checkInt(temp);
        }
        catch (invalid_argument) {
            std::cout << ":(";
            continue;
        }
        switch (answer) {
        case 1:
            Pipe::pipeInput();
            break;
        case 2:
            Ks::ksInput();
            break;
        case 3:
            Pipe:: findTubes();
            break;
        case 4:
            Ks::findKs();
            break;
        case 5:
            Pipe::PipeEdit();
            break;
        case 6:
            Ks::KsEdit();
            break;
        case 7:
            save();
            break;
        case 8:
            load();
            break;
        case 9:
            Pipe::deletePipe();
            break;
        case 10:
            Ks::deleteKs();
            break;
        case 11:
            addPipeToGraph();
            break;
        case 12:
            topologicalSort();
            break;
        case 0:
            break;
        default: std::cout << "Неверный ввод:(\n";
            break;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
