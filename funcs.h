#pragma once
#include <string>
using namespace std;

int checkInt(string str) {
    if (str.find(".") != str.npos) {
        cout << "Ошибка ввода строки" << endl;
        logfile << "Проверка на double не удалась" << endl;
        return 0;
    }
    else {
        return stoi(str);
    }
}
double checkDouble(string str) {
        return stod(str);

}
string checkStr(string str) {
    if (str.find("/") != str.npos || str.find(".") != str.npos) {
        logfile << "В строке " << str << "недопустимые сивмолы" << endl;
        return "Error";

    }
    else {
        return(str);
    }
}
int checkBool(string str) {
    if (str == "0") {
        return 0;
    }
    if (str == "1") {
        return 1;
    }
    else {
        return 2;
    }
}
void pipeInput() {
    int count = 0;
    cout << "Введите отметку в км\n";
    getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        kmMark = temp;
    }
    else {
        logfile << "Не верно название для трубы" << endl;
        cout << "Ошибка ввода :(" << endl;
        return;

    }
    cout << "Введите длину в метрах \n";
    getline(cin, temp);
    try {
        len = checkDouble(temp);
    }
    catch (invalid_argument) {
        logfile << "Не верна длина трубы" << endl;
        cout << "Ошибка ввода :(" << endl;
        return;
    }
    cout << "Ввeдите диаметр в мм\n";
    getline(cin, temp);
    try {
        diam = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "Не верен диаметр" << endl;
        cout << "Ошибка ввода :(11" << endl;
        return;
    }
    cout << "Вводите состояние работы, где 1 - работает, 0 - нет \n";
    getline(cin, temp);
    if (checkBool(temp) == 2) {
        logfile << "Не верно состояние работы" << endl;
        cout << "Ошибка ввода :(" << endl;
        return;
    }
    else {
        isWorking = checkBool(temp);
    }
        if (kmMark != " " && kmMark != "0" && len > 0 && diam > 0) {
            pipes.emplace(Pipe::id, new Pipe(kmMark, len, diam, isWorking));
        }
}
void ksInput() {
    cout << "Введите имя кс\n";
    getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        name = temp;
    }
    else {
        logfile << "Не верно имя Кс" << endl;
        return;
    }
    cout << "Введите Количество цехов\n";
    getline(cin, temp);
    try {
        amountWorkshops = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "Неверный ввод общего количества цехов  " << endl;
        return;
    }
    cout << "Введите Количество цехов в работе\n";
    getline(cin, temp);
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
void findTubes(map<int,Pipe*> map) {
    int count = 0;
    cout << "1)Все трубы " << endl;
    cout << "2)Поиск по названию " << endl;
    cout << "3)Поиск по работе " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "Ошибка ввода temp в findTubes" << endl;
        cout << "Ошибка ввода :(" << endl;
    }
    if (count == 0 && !map.empty()) {
        switch (answer) {
        case 1:
            for (auto& item : map) {
                cout << "id: " << item.first << endl;
                item.second->cout();
            }
            break;
        case 2:
            cout << "Введи название трубы: " << endl;
            getline(cin, temp);
            if (checkStr(temp) != "Error") {
                for (auto& item : map) {
                    if (checkStr(temp) == item.second->kmMark) {
                        cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
            }
            break;
        case 3:
            cout << "Введи статус работы трубы: " << endl;
            getline(cin, temp);
            if (checkBool(temp) != 2) {
                for (auto& item : map) {
                    if (checkBool(temp) == item.second->isWorking) {
                        cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
            }
            break;
        default:
            count++;
            logfile << "Выбор несуществующего варианта ответа" << endl;
            cout << "Ошибка ввода :(" << endl;
            break;
        }
    }
    else {
        cout << "Нет Труб" << endl;
        logfile << " Попытка вывода труб без труб" << endl;
    }
}
void findKs(map<int, Ks*> map) {
    int count = 0;
    cout << "1)Все Кс " << endl;
    cout << "2)Поиск по названию " << endl;
    cout << "3)Поиск по эффективности " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "Ошибка ввода temp в findKs" << endl;
        cout << "Ошибка ввода :(" << endl;
    }
    if (count == 0 && !map.empty()) {
        switch (answer) {
        case 1:
            for (auto& item : map) {
                cout << "id: " << item.first << endl;
                item.second->cout();
            }
            break;
        case 2:
            cout << "Введи название Kc: " << endl;
            getline(cin, temp);
            if (checkStr(temp) != "Error") {
                for (auto& item : map) {
                    if (checkStr(temp) == item.second->name) {
                        cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
            }
            break;
        case 3:
            cout << " 1)Больше 50%" << endl;
            cout << " 2)Меньше 50%" << endl;
            cout << " 3)50%" << endl;
            getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                logfile << "Неверный формат при выводе эффективности" << endl;
                cout << "Ошибка ввода :(" << endl;
            }
            switch (answer) {
            case 1:
                for (auto& item : map) {
                    if (item.second->effectiveness > 50) {
                        cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
                break;
            case 2:
                for (auto& item : map) {
                    if (item.second->effectiveness < 50) {
                        cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
                break;
            case 3:
                for (auto& item : map) {
                    if (item.second->effectiveness == 50) {
                        cout << "id: " << item.first << endl;
                        item.second->cout();
                    }
                }
                break;
            }
            break;
        default:
            count++;
            logfile << "Выбор несуществующего варианта ответа" << endl;
            cout << "Ошибка ввода :(" << endl;
            break;
        }
    }
    else {
        cout << "Нет Кс" << endl;
        logfile << "Вывод Кс без Кс" << endl;
    }
}
void PipeEdit(map<int, Pipe*> map) {
    int count = 0;
    cout << "1)Редактирование всех труб " << endl;
    cout << "2)Редактирование отдельных труб: " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        cout << "Ошибка ввода :(" << endl;
        logfile << "Неверный формат при редактировании труб" << endl;
    }
    if (count == 0) {
        switch (answer) {
        case 1:
            std::cout << "Изменить состояние работы" << endl;
            std::cout << "1)Вкл ";
            std::cout << "2)Выкл" << endl;
            getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                cout << "Ошибка ввода :(" << endl;
                logfile << "Неверный формат при редактировании труб" << endl;
            }
            if (count == 0 && !map.empty()) {
                switch (answer) {
                case 1:
                        for (auto& item : map) {
                            item.second->isWorking = 1;
                    }
                    break;
                case 2:
                        for (auto& item : map) {
                            item.second->isWorking = 0;
                        }
                    break;
                default:
                    count++;
                    cout << "Ошибка ввода :(" << endl;
                    logfile << "Выбор несуществующего варианта ответа при редактировании труб" << endl;
                    break;
                }
            }
            else {
                cout << "Нет труб" << endl;
                logfile << "Вывод труб без труб" << endl;
            }
            break;
        case 2:
            std::cout << "Изменить состояние работы" << endl;
            std::cout << "1)Вкл ";
            std::cout << "2)Выкл" << endl;
            getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                cout << "Ошибка ввода :(" << endl;
                logfile << "Неверный формат при редактировании труб" << endl;
            }
            if (count == 0 && !map.empty()) {
                switch (answer) {
                case 1:
                    cout << "id труб : ";
                        for (auto& item : map) {
                            cout << item.first << " ";
                        }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            cout << "Вводи число" << endl;
                            logfile << "Неверный формат при вводе id трубы для редактирования" << endl;
                            continue;
                        }
                        if (map.find(answer) == map.end()) {
                            cout << "Нет такого id" << endl;
                            logfile << "Ввод несуществующего id" << endl;
                            continue;
                        }
                        else {
                            map[answer]->isWorking = 1;
                        }
                    }
                    break;
                case 2:
                    cout << "id труб : ";
                    for (auto& item : map) {
                        cout << item.first << " ";
                    }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            logfile << "Неверный формат при вводе id трубы для редактирования" << endl;
                            cout << "Вводи число" << endl;
                            continue;
                        }
                        if (!map.count(answer)) {
                            cout << "Нет такого id" << endl;
                            logfile << "Ввод несуществующего id" << endl;
                            continue;
                        }
                        else {
                            map[answer]->isWorking = 0;
                        }
                    }
                    break;
                default:
                    count++;
                    cout << "Ошибка ввода :(" << endl;
                    logfile << "Выбор несуществующего варианта при редактировании труб" << endl;

                    break;
                    }
                }
            else {
                cout << "Нет труб" << endl;
                logfile << "Вывод труб без труб" << endl;
            }
            break;
        default:
            count++;
            cout << "Ошибка ввода :(" << endl;
            logfile << "Выбор несуществующего варианта при редактировании труб" << endl;
            break;
            }
        }
    }
void KsEdit(map<int, Ks*> map) {
    int count = 0;
    cout << "id КС " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        cout << "Ошибка ввода :(" << endl;
        logfile << "Неверный формат при редактировании Кс" << endl;
    }
    if (map.find(answer) == map.end()) {
        cout << "Нет такого id" << endl;
        logfile << "Несуществующее id при редактировании Кс" << endl;
        count++;
    }
    if (count == 0) {
        cout << "Изменить количество работающих станков: " << endl;
        getline(cin, temp);
        try {
            answer1 = checkInt(temp);
        }
        catch (invalid_argument) {
            count++;
            cout << "Ошибка ввода :(" << endl;
            logfile << "Неверный формат при редактировании Кс" << endl;
        }
        if (count == 0){
            if (answer1 > map[answer]->amountWorkshops) {
                count++;
                logfile << "Количество работающих станков стало больше существующих" << endl;
                cout << "Ошибка ввода :(" << endl;
            }
            else {
                map[answer]->amountWorkshopsNow = answer1;
                map[answer]->uptadeEff();
            }
    }
    }
}
void save() {
    cout << "Введи имя файла" << endl;
    getline(cin, fileName);
    try {
        file.open(fileName);
        if (file.is_open()) {
            if (pipes.empty()) {
                file << "Нет труб" << endl;
            }
            else {
                for (auto& item : pipes) {
                    file << "Труба : " << item.first << endl;
                    item.second->cout(file);
                }
            }
            if (ksMap.empty()) {
                file << "Нет Ks" << endl;
            }
            else {
                for (auto& item : ksMap) {
                    file << "Ks : " << item.first << endl;
                    item.second->cout(file);
                }
            }
        }
    }
    catch (exception& ex) {
        logfile << "Исключение при работе с файлом " << &ex << endl;
    }
}
void load() {
    cout << "Введи имя файла" << endl;
    getline(cin, fileName);
    try {
        file1.open(fileName);
        if (file1.is_open()) {
            getline(file1, temp);
            if (temp != "Нет труб") {
                while (temp != "Нет Ks" && temp != "Ks : 1") {
                    id = stoi(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    kmMark = temp.substr(temp.find_first_of(':') + 2);
                    getline(file1, temp);
                    len = stod(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    diam = stoi(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    isWorking = stoi(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    pipes.emplace(id,new Pipe(kmMark,len,diam,isWorking));
                }
                if (temp == "Нет Ks") {
                    return;
                }
                else {
                    while (file1.peek() != EOF) {
                        id = stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        name = temp.substr(temp.find_first_of(':') + 2);
                        getline(file1, temp);
                        amountWorkshops = stod(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        amountWorkshopsNow = stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        eff = stoi(temp.substr(temp.find_first_of(':') + 1, temp.find_first_of('%')));
                        getline(file1, temp);
                        ksMap.emplace(id, new Ks(name, amountWorkshops, amountWorkshopsNow));
                    }
                }
            }
            else {
                getline(file1, temp);
                if (temp == "Нет Ks") {
                    return;
                }
                else {
                    while (file1.peek() != EOF) {
                        id = stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        name = temp.substr(temp.find_first_of(':') + 2);
                        getline(file1, temp);
                        amountWorkshops = stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        amountWorkshopsNow = stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        eff = stoi(temp.substr(temp.find_first_of(':') + 1, temp.find_first_of('%')));
                        getline(file1, temp);
                        ksMap.emplace(id, new Ks(name, amountWorkshops, amountWorkshopsNow));
                    }
                }
            }
        }
    }
    catch(exception& ex){
        logfile << "Исключение при работе с файлом " << &ex << endl;
    }
}
