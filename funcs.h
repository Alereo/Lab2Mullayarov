#pragma once
#include <string>
using namespace std;

int checkInt(string str) {
    if (str.find(".") != str.npos) {
        std::cout << "Ошибка ввода строки" << endl;
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
