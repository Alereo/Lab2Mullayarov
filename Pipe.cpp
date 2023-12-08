#include "Pipe.h"
#include <string>
#include "funcs.h"
using namespace std;
int Pipe::id = 0;
Pipe::Pipe()
{
	len = diam = isWorking = 0;
	kmMark = " ";
}
Pipe::Pipe(string name, double len, int diam , bool isWorking) {
	Pipe::kmMark = name;
	Pipe::len = len;
	Pipe::diam = diam;
	Pipe::isWorking = isWorking;
	id++;
}
void Pipe::cout() {
    std::cout << "Километровая отметка: " << this->kmMark << endl << "Длина трубы: " << len << endl << "Диаметр: " << this->diam << endl
        << "Состояние работы трубы: " << isWorking << endl;
}
void Pipe::cout(ofstream& file) {
    file << "Километровая отметка: " << this->kmMark << endl << "Длина трубы: " << len << endl
        << "Диаметр: " << this->diam << endl << "Состояние работы трубы: " << isWorking << endl;
}
void Pipe::pipeInput() {
    string kmMark;
    int len;
    double diam;
    bool isWorking;
    int count = 0;
    std::cout << "Введите отметку в км\n";
    std::getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        kmMark = temp;
    }
    else {
        logfile << "Не верно название для трубы" << endl;
        std::cout << "Ошибка ввода :(" << endl;
        return;

    }
    std::cout << "Введите длину в метрах \n";
    std::getline(cin, temp);
    try {
        len = checkDouble(temp);
    }
    catch (invalid_argument) {
        logfile << "Не верна длина трубы" << endl;
        std::cout << "Ошибка ввода :(" << endl;
        return;
    }
    std::cout << "Ввeдите диаметр в мм\n";
    std::getline(cin, temp);
    try {
        diam = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "Не верен диаметр" << endl;
        std::cout << "Ошибка ввода :(11" << endl;
        return;
    }
    std::cout << "Вводите состояние работы, где 1 - работает, 0 - нет \n";
    std::getline(cin, temp);
    if (checkBool(temp) == 2) {
        logfile << "Не верно состояние работы" << endl;
        std::cout << "Ошибка ввода :(" << endl;
        return;
    }
    else {
        isWorking = checkBool(temp);
    }
    if (kmMark != " " && kmMark != "0" && len > 0 && diam > 0) {
        pipes.emplace(Pipe::id,new Pipe(kmMark, len, diam, isWorking));
        pipes[id]->idInit = id;
    }
}
void Pipe::findTubes() {
    int count = 0;
    std::cout << "1)Все трубы " << endl;
    std::cout << "2)Поиск по названию " << endl;
    std::cout << "3)Поиск по работе " << endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "Ошибка ввода temp в findTubes" << endl;
        std::cout << "Ошибка ввода :(" << endl;
    }
    if (count == 0 && !pipes.empty()) {
        switch (answer) {
        case 1:
            for (auto& item : pipes) {
                std::cout << "id: " << item.first << endl;
                item.second->cout();
            }
            break;
        case 2:
            std::cout << "Введи название трубы: " << endl;
            std::getline(cin, temp);
            if (checkStr(temp) != "Error") {
                for (auto& item : pipes) {
                    if (checkStr(temp) == item.second->kmMark) {
                        std::cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
            }
            break;
        case 3:
            std::cout << "Введи статус работы трубы: " << endl;
            std::getline(cin, temp);
            if (checkBool(temp) != 2) {
                for (auto& item : pipes) {
                    if (checkBool(temp) == item.second->isWorking) {
                        std::cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
            }
            break;
        default:
            count++;
            logfile << "Выбор несуществующего варианта ответа" << endl;
            std::cout << "Ошибка ввода :(" << endl;
            break;
        }
    }
    else {
        std::cout << "Нет Труб" << endl;
        logfile << " Попытка вывода труб без труб" << endl;
    }
}
void Pipe::PipeEdit() {
    int count = 0;
    std::cout << "1)Редактирование всех труб " << endl;
    std::cout << "2)Редактирование отдельных труб: " << endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        std::cout << "Ошибка ввода :(" << endl;
        logfile << "Неверный формат при редактировании труб" << endl;
    }
    if (count == 0) {
        switch (answer) {
        case 1:
            std::cout << "Изменить состояние работы" << endl;
            std::cout << "1)Вкл ";
            std::cout << "2)Выкл" << endl;
            std::getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                std::cout << "Ошибка ввода :(" << endl;
                logfile << "Неверный формат при редактировании труб" << endl;
            }
            if (count == 0 && !pipes.empty()) {
                switch (answer) {
                case 1:
                    for (auto& item : pipes) {
                        item.second->isWorking = 1;
                    }
                    break;
                case 2:
                    for (auto& item : pipes) {
                        item.second->isWorking = 0;
                    }
                    break;
                default:
                    count++;
                    std::cout << "Ошибка ввода :(" << endl;
                    logfile << "Выбор несуществующего варианта ответа при редактировании труб" << endl;
                    break;
                }
            }
            else {
                std::cout << "Нет труб" << endl;
                logfile << "Вывод труб без труб" << endl;
            }
            break;
        case 2:
            std::cout << "Изменить состояние работы" << endl;
            std::cout << "1)Вкл ";
            std::cout << "2)Выкл" << endl;
            std::getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                std::cout << "Ошибка ввода :(" << endl;
                logfile << "Неверный формат при редактировании труб" << endl;
            }
            if (count == 0 && !pipes.empty()) {
                switch (answer) {
                case 1:
                    std::cout << "id труб : ";
                    for (auto& item : pipes) {
                        std::cout << item.first << " ";
                    }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            std::cout << "Вводи число" << endl;
                            logfile << "Неверный формат при вводе id трубы для редактирования" << endl;
                            continue;
                        }
                        if (pipes.find(answer) == pipes.end()) {
                            std::cout << "Нет такого id" << endl;
                            logfile << "Ввод несуществующего id" << endl;
                            continue;
                        }
                        else {
                            pipes[answer]->isWorking = 1;
                        }
                    }
                    break;
                case 2:
                    std::cout << "id труб : ";
                    for (auto& item : pipes) {
                        std::cout << item.first << " ";
                    }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            logfile << "Неверный формат при вводе id трубы для редактирования" << endl;
                            std::cout << "Вводи число" << endl;
                            continue;
                        }
                        if (!pipes.count(answer)) {
                            std::cout << "Нет такого id" << endl;
                            logfile << "Ввод несуществующего id" << endl;
                            continue;
                        }
                        else {
                            pipes[answer]->isWorking = 0;
                        }
                    }
                    break;
                default:
                    count++;
                    std::cout << "Ошибка ввода :(" << endl;
                    logfile << "Выбор несуществующего варианта при редактировании труб" << endl;

                    break;
                }
            }
            else {
                std::cout << "Нет труб" << endl;
                logfile << "Вывод труб без труб" << endl;
            }
            break;
        default:
            count++;
            std::cout << "Ошибка ввода :(" << endl;
            logfile << "Выбор несуществующего варианта при редактировании труб" << endl;
            break;
        }
    }
}
void Pipe::deletePipe(){
    std::map<int, Pipe*>::iterator it;
    std::cout << "Выберите трубы для удаления (id) :" << std::endl;
    findTubes();
    while (std::getline(cin, temp) && !temp.empty()) {
        try {
            answer = checkInt(temp);
        }
        catch (invalid_argument) {
            std::cout << "Вводи число" << endl;
            logfile << "Неверный формат при вводе id трубы для редактирования" << endl;
            continue;
        }
        if (pipes.find(answer) == pipes.end()) {
            std::cout << "Нет такого id" << endl;
            logfile << "Ввод несуществующего id" << endl;
            continue;
        }
        else {
            it = pipes.find(answer);
            pipes.erase(it);
        }
    }
}
