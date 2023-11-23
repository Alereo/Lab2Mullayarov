#include "Ks.h"
#include <string>
#include <map>
#include "variables.h"
#include "funcs.h"
using namespace std;
int Ks::id = 0;
Ks::Ks()
{
    amountWorkshops = amountWorkshopsNow = effectiveness = 0;
}
Ks::Ks(string name, int amountWorkshops, int amountWorhshopsNow) {
    Ks::name = name;
    Ks::amountWorkshops = amountWorkshops;
    Ks::amountWorkshopsNow = amountWorhshopsNow;
    id++;
    uptadeEff();
}
void Ks::uptadeEff()
{
    Ks::effectiveness = (int)(Ks::amountWorkshopsNow / (double)Ks::amountWorkshops * 100);
}
void Ks::cout() {
    std::cout << "Имя: " << name << endl << "Количество цехов: " << amountWorkshops << endl <<
        "Количество цехов в работе: " << amountWorkshopsNow << endl << "Эффективность: " << effectiveness << "%" << endl;
}
void Ks::cout(ofstream& file) {
    file << "Имя: " << name << endl << "Количество цехов: " << amountWorkshops << endl <<
        "Количество цехов в работе: " << amountWorkshopsNow << endl << "Эффективность: " << effectiveness << "%" << endl;
}
void Ks::ksInput() {
    std::cout << "Введите имя кс\n";
    std::getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        name = temp;
    }
    else {
        logfile << "Не верно имя Кс" << endl;
        return;
    }
    std::cout << "Введите Количество цехов\n";
    std::getline(cin, temp);
    try {
        amountWorkshops = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "Неверный ввод общего количества цехов  " << endl;
        return;
    }
    std::cout << "Введите Количество цехов в работе\n";
    std::getline(cin, temp);
    try {
        amountWorkshopsNow = checkInt(temp);
    }
    catch (invalid_argument) {

        logfile << "Неверный ввод работующего количества цехов  " << endl;
        return;
    }
    if (amountWorkshopsNow > amountWorkshops) {
        logfile << "Общее количество меньше работающих  " << endl;
        return;
    }
    if ((amountWorkshops >= amountWorkshopsNow) && name != " " && name != "0" && amountWorkshops > 0) {
        ksMap.emplace(Ks::id, new Ks(name, amountWorkshops, amountWorkshopsNow));


    }
}
void Ks::findKs() {
    int count = 0;
    std::cout << "1)Все Кс " << endl;
    std::cout << "2)Поиск по названию " << endl;
    std::cout << "3)Поиск по эффективности " << endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "Ошибка ввода temp в findKs" << endl;
        std::cout << "Ошибка ввода :(" << endl;
    }
    if (count == 0 && !ksMap.empty()) {
        switch (answer) {
        case 1:
            for (auto& item : ksMap) {
                std::cout << "id: " << item.first << endl;
                item.second->cout();
            }
            break;
        case 2:
            std::cout << "Введи название Kc: " << endl;
            std::getline(cin, temp);
            if (checkStr(temp) != "Error") {
                for (auto& item : ksMap) {
                    if (checkStr(temp) == item.second->name) {
                        std::cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
            }
            break;
        case 3:
            std::cout << " 1)Больше 50%" << endl;
            std::cout << " 2)Меньше 50%" << endl;
            std::cout << " 3)50%" << endl;
            std::getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                logfile << "Неверный формат при выводе эффективности" << endl;
                std::cout << "Ошибка ввода :(" << endl;
            }
            switch (answer) {
            case 1:
                for (auto& item : ksMap) {
                    if (item.second->effectiveness > 50) {
                        std::cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
                break;
            case 2:
                for (auto& item : ksMap) {
                    if (item.second->effectiveness < 50) {
                        std::cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
                break;
            case 3:
                for (auto& item : ksMap) {
                    if (item.second->effectiveness == 50) {
                        std::cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
                break;
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
        std::cout << "Нет Кс" << endl;
        logfile << "Вывод Кс без Кс" << endl;
    }
}
void Ks::KsEdit() {
    int count = 0;
    std::cout << "id КС " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        std::cout << "Ошибка ввода :(" << endl;
        logfile << "Неверный формат при редактировании Кс" << endl;
    }
    if (ksMap.find(answer) == ksMap.end()) {
        std::cout << "Нет такого id" << endl;
        logfile << "Несуществующее id при редактировании Кс" << endl;
        count++;
    }
    if (count == 0) {
        std::cout << "Изменить количество работающих станков: " << endl;
        getline(cin, temp);
        try {
            answer1 = checkInt(temp);
        }
        catch (invalid_argument) {
            count++;
            std::cout << "Ошибка ввода :(" << endl;
            logfile << "Неверный формат при редактировании Кс" << endl;
        }
        if (count == 0) {
            if (answer1 > ksMap[answer]->amountWorkshops) {
                count++;
                logfile << "Количество работающих станков стало больше существующих" << endl;
                std::cout << "Ошибка ввода :(" << endl;
            }
            else {
                ksMap[answer]->amountWorkshopsNow = answer1;
                ksMap[answer]->uptadeEff();
            }
        }
    }
}