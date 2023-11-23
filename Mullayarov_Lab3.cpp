#include <iostream>
#include <string>
#include <Vector>
#include <fstream>
#include "Ks.h"
#include "Pipe.h"
#include "variables.h"
#include "funcs.h"
using namespace std;
Pipe pipeManager;
Ks ksManager;
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
            pipeManager.pipeInput();
            break;
        case 2:
            ksManager.ksInput();
            break;
        case 3:
            pipeManager.findTubes();
            break;
        case 4:
            findKs(ksMap);
            break;
        case 5:
            pipeManager.PipeEdit();
            break;
        case 6:
            ksManager.KsEdit();
            break;
        case 7:
            save();
            break;
        case 8:
            load();
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
