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
    std::cout << "���: " << name << endl << "���������� �����: " << amountWorkshops << endl <<
        "���������� ����� � ������: " << amountWorkshopsNow << endl << "�������������: " << effectiveness << "%" << endl;
}
void Ks::cout(ofstream& file) {
    file << "���: " << name << endl << "���������� �����: " << amountWorkshops << endl <<
        "���������� ����� � ������: " << amountWorkshopsNow << endl << "�������������: " << effectiveness << "%" << endl;
}
void Ks::ksInput() {
    std::cout << "������� ��� ��\n";
    std::getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        name = temp;
    }
    else {
        logfile << "�� ����� ��� ��" << endl;
        return;
    }
    std::cout << "������� ���������� �����\n";
    std::getline(cin, temp);
    try {
        amountWorkshops = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "�������� ���� ������ ���������� �����  " << endl;
        return;
    }
    std::cout << "������� ���������� ����� � ������\n";
    std::getline(cin, temp);
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
void Ks::findKs() {
    int count = 0;
    std::cout << "1)��� �� " << endl;
    std::cout << "2)����� �� �������� " << endl;
    std::cout << "3)����� �� ������������� " << endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "������ ����� temp � findKs" << endl;
        std::cout << "������ ����� :(" << endl;
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
            std::cout << "����� �������� Kc: " << endl;
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
            std::cout << " 1)������ 50%" << endl;
            std::cout << " 2)������ 50%" << endl;
            std::cout << " 3)50%" << endl;
            std::getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                logfile << "�������� ������ ��� ������ �������������" << endl;
                std::cout << "������ ����� :(" << endl;
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
            logfile << "����� ��������������� �������� ������" << endl;
            std::cout << "������ ����� :(" << endl;
            break;
        }
    }
    else {
        std::cout << "��� ��" << endl;
        logfile << "����� �� ��� ��" << endl;
    }
}
void Ks::KsEdit() {
    int count = 0;
    std::cout << "id �� " << endl;
    getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        std::cout << "������ ����� :(" << endl;
        logfile << "�������� ������ ��� �������������� ��" << endl;
    }
    if (ksMap.find(answer) == ksMap.end()) {
        std::cout << "��� ������ id" << endl;
        logfile << "�������������� id ��� �������������� ��" << endl;
        count++;
    }
    if (count == 0) {
        std::cout << "�������� ���������� ���������� �������: " << endl;
        getline(cin, temp);
        try {
            answer1 = checkInt(temp);
        }
        catch (invalid_argument) {
            count++;
            std::cout << "������ ����� :(" << endl;
            logfile << "�������� ������ ��� �������������� ��" << endl;
        }
        if (count == 0) {
            if (answer1 > ksMap[answer]->amountWorkshops) {
                count++;
                logfile << "���������� ���������� ������� ����� ������ ������������" << endl;
                std::cout << "������ ����� :(" << endl;
            }
            else {
                ksMap[answer]->amountWorkshopsNow = answer1;
                ksMap[answer]->uptadeEff();
            }
        }
    }
}