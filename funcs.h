#pragma once
#include <string>
using namespace std;

int checkInt(string str) {
    if (str.find(".") != str.npos) {
        cout << "������ ����� ������" << endl;
        logfile << "�������� �� double �� �������" << endl;
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
        logfile << "� ������ " << str << "������������ �������" << endl;
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
    cout << "������� ������� � ��\n";
    getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        kmMark = temp;
    }
    else {
        logfile << "�� ����� �������� ��� �����" << endl;
        cout << "������ ����� :(" << endl;
        return;

    }
    cout << "������� ����� � ������ \n";
    getline(cin, temp);
    try {
        len = checkDouble(temp);
    }
    catch (invalid_argument) {
        logfile << "�� ����� ����� �����" << endl;
        cout << "������ ����� :(" << endl;
        return;
    }
    cout << "��e���� ������� � ��\n";
    getline(cin, temp);
    try {
        diam = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "�� ����� �������" << endl;
        cout << "������ ����� :(11" << endl;
        return;
    }
    cout << "������� ��������� ������, ��� 1 - ��������, 0 - ��� \n";
    getline(cin, temp);
    if (checkBool(temp) == 2) {
        logfile << "�� ����� ��������� ������" << endl;
        cout << "������ ����� :(" << endl;
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
    cout << "������� ��� ��\n";
    getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        name = temp;
    }
    else {
        logfile << "�� ����� ��� ��" << endl;
        return;
    }
    cout << "������� ���������� �����\n";
    getline(cin, temp);
    try {
        amountWorkshops = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "�������� ���� ������ ���������� �����  " << endl;
        return;
    }
    cout << "������� ���������� ����� � ������\n";
    getline(cin, temp);
    try {
        amountWorkshopsNow = checkInt(temp);
    }
    catch (invalid_argument) {
       
        logfile << "�������� ���� ����������� ���������� �����  " << endl;
        return;
    }
    if (amountWorkshopsNow > amountWorkshops) {
        logfile << "����� ���������� ������ ����������  " << endl;
        return;
    }
        if ((amountWorkshops >= amountWorkshopsNow) && name != " " && name != "0" && amountWorkshops > 0) {
            ksMap.emplace(Ks::id, new Ks(name, amountWorkshops, amountWorkshopsNow));


    }
}
void findTubes(map<int,Pipe*> map) {
    int count = 0;
    cout << "1)��� ����� " << endl;
    cout << "2)����� �� �������� " << endl;
    cout << "3)����� �� ������ " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "������ ����� temp � findTubes" << endl;
        cout << "������ ����� :(" << endl;
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
            cout << "����� �������� �����: " << endl;
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
            cout << "����� ������ ������ �����: " << endl;
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
            logfile << "����� ��������������� �������� ������" << endl;
            cout << "������ ����� :(" << endl;
            break;
        }
    }
    else {
        cout << "��� ����" << endl;
        logfile << " ������� ������ ���� ��� ����" << endl;
    }
}
void findKs(map<int, Ks*> map) {
    int count = 0;
    cout << "1)��� �� " << endl;
    cout << "2)����� �� �������� " << endl;
    cout << "3)����� �� ������������� " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "������ ����� temp � findKs" << endl;
        cout << "������ ����� :(" << endl;
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
            cout << "����� �������� Kc: " << endl;
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
            cout << " 1)������ 50%" << endl;
            cout << " 2)������ 50%" << endl;
            cout << " 3)50%" << endl;
            getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                logfile << "�������� ������ ��� ������ �������������" << endl;
                cout << "������ ����� :(" << endl;
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
            logfile << "����� ��������������� �������� ������" << endl;
            cout << "������ ����� :(" << endl;
            break;
        }
    }
    else {
        cout << "��� ��" << endl;
        logfile << "����� �� ��� ��" << endl;
    }
}
void PipeEdit(map<int, Pipe*> map) {
    int count = 0;
    cout << "1)�������������� ���� ���� " << endl;
    cout << "2)�������������� ��������� ����: " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        cout << "������ ����� :(" << endl;
        logfile << "�������� ������ ��� �������������� ����" << endl;
    }
    if (count == 0) {
        switch (answer) {
        case 1:
            std::cout << "�������� ��������� ������" << endl;
            std::cout << "1)��� ";
            std::cout << "2)����" << endl;
            getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                cout << "������ ����� :(" << endl;
                logfile << "�������� ������ ��� �������������� ����" << endl;
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
                    cout << "������ ����� :(" << endl;
                    logfile << "����� ��������������� �������� ������ ��� �������������� ����" << endl;
                    break;
                }
            }
            else {
                cout << "��� ����" << endl;
                logfile << "����� ���� ��� ����" << endl;
            }
            break;
        case 2:
            std::cout << "�������� ��������� ������" << endl;
            std::cout << "1)��� ";
            std::cout << "2)����" << endl;
            getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                cout << "������ ����� :(" << endl;
                logfile << "�������� ������ ��� �������������� ����" << endl;
            }
            if (count == 0 && !map.empty()) {
                switch (answer) {
                case 1:
                    cout << "id ���� : ";
                        for (auto& item : map) {
                            cout << item.first << " ";
                        }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            cout << "����� �����" << endl;
                            logfile << "�������� ������ ��� ����� id ����� ��� ��������������" << endl;
                            continue;
                        }
                        if (map.find(answer) == map.end()) {
                            cout << "��� ������ id" << endl;
                            logfile << "���� ��������������� id" << endl;
                            continue;
                        }
                        else {
                            map[answer]->isWorking = 1;
                        }
                    }
                    break;
                case 2:
                    cout << "id ���� : ";
                    for (auto& item : map) {
                        cout << item.first << " ";
                    }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            logfile << "�������� ������ ��� ����� id ����� ��� ��������������" << endl;
                            cout << "����� �����" << endl;
                            continue;
                        }
                        if (!map.count(answer)) {
                            cout << "��� ������ id" << endl;
                            logfile << "���� ��������������� id" << endl;
                            continue;
                        }
                        else {
                            map[answer]->isWorking = 0;
                        }
                    }
                    break;
                default:
                    count++;
                    cout << "������ ����� :(" << endl;
                    logfile << "����� ��������������� �������� ��� �������������� ����" << endl;

                    break;
                    }
                }
            else {
                cout << "��� ����" << endl;
                logfile << "����� ���� ��� ����" << endl;
            }
            break;
        default:
            count++;
            cout << "������ ����� :(" << endl;
            logfile << "����� ��������������� �������� ��� �������������� ����" << endl;
            break;
            }
        }
    }
void KsEdit(map<int, Ks*> map) {
    int count = 0;
    cout << "id �� " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        cout << "������ ����� :(" << endl;
        logfile << "�������� ������ ��� �������������� ��" << endl;
    }
    if (map.find(answer) == map.end()) {
        cout << "��� ������ id" << endl;
        logfile << "�������������� id ��� �������������� ��" << endl;
        count++;
    }
    if (count == 0) {
        cout << "�������� ���������� ���������� �������: " << endl;
        getline(cin, temp);
        try {
            answer1 = checkInt(temp);
        }
        catch (invalid_argument) {
            count++;
            cout << "������ ����� :(" << endl;
            logfile << "�������� ������ ��� �������������� ��" << endl;
        }
        if (count == 0){
            if (answer1 > map[answer]->amountWorkshops) {
                count++;
                logfile << "���������� ���������� ������� ����� ������ ������������" << endl;
                cout << "������ ����� :(" << endl;
            }
            else {
                map[answer]->amountWorkshopsNow = answer1;
                map[answer]->uptadeEff();
            }
    }
    }
}
void save() {
    cout << "����� ��� �����" << endl;
    getline(cin, fileName);
    try {
        file.open(fileName);
        if (file.is_open()) {
            if (pipes.empty()) {
                file << "��� ����" << endl;
            }
            else {
                for (auto& item : pipes) {
                    file << "����� : " << item.first << endl;
                    item.second->cout(file);
                }
            }
            if (ksMap.empty()) {
                file << "��� Ks" << endl;
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
        logfile << "���������� ��� ������ � ������ " << &ex << endl;
    }
}
void load() {
    cout << "����� ��� �����" << endl;
    getline(cin, fileName);
    try {
        file1.open(fileName);
        if (file1.is_open()) {
            getline(file1, temp);
            if (temp != "��� ����") {
                while (temp != "��� Ks" && temp != "Ks : 1") {
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
                if (temp == "��� Ks") {
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
                if (temp == "��� Ks") {
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
        logfile << "���������� ��� ������ � ������ " << &ex << endl;
    }
}
