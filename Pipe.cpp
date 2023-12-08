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
    std::cout << "������������ �������: " << this->kmMark << endl << "����� �����: " << len << endl << "�������: " << this->diam << endl
        << "��������� ������ �����: " << isWorking << endl;
}
void Pipe::cout(ofstream& file) {
    file << "������������ �������: " << this->kmMark << endl << "����� �����: " << len << endl
        << "�������: " << this->diam << endl << "��������� ������ �����: " << isWorking << endl;
}
void Pipe::pipeInput() {
    string kmMark;
    int len;
    double diam;
    bool isWorking;
    int count = 0;
    std::cout << "������� ������� � ��\n";
    std::getline(cin, temp);
    if ((temp = checkStr(temp)) != "Error") {
        kmMark = temp;
    }
    else {
        logfile << "�� ����� �������� ��� �����" << endl;
        std::cout << "������ ����� :(" << endl;
        return;

    }
    std::cout << "������� ����� � ������ \n";
    std::getline(cin, temp);
    try {
        len = checkDouble(temp);
    }
    catch (invalid_argument) {
        logfile << "�� ����� ����� �����" << endl;
        std::cout << "������ ����� :(" << endl;
        return;
    }
    std::cout << "��e���� ������� � ��\n";
    std::getline(cin, temp);
    try {
        diam = checkInt(temp);
    }
    catch (invalid_argument) {
        logfile << "�� ����� �������" << endl;
        std::cout << "������ ����� :(11" << endl;
        return;
    }
    std::cout << "������� ��������� ������, ��� 1 - ��������, 0 - ��� \n";
    std::getline(cin, temp);
    if (checkBool(temp) == 2) {
        logfile << "�� ����� ��������� ������" << endl;
        std::cout << "������ ����� :(" << endl;
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
    std::cout << "1)��� ����� " << endl;
    std::cout << "2)����� �� �������� " << endl;
    std::cout << "3)����� �� ������ " << endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        logfile << "������ ����� temp � findTubes" << endl;
        std::cout << "������ ����� :(" << endl;
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
            std::cout << "����� �������� �����: " << endl;
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
            std::cout << "����� ������ ������ �����: " << endl;
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
            logfile << "����� ��������������� �������� ������" << endl;
            std::cout << "������ ����� :(" << endl;
            break;
        }
    }
    else {
        std::cout << "��� ����" << endl;
        logfile << " ������� ������ ���� ��� ����" << endl;
    }
}
void Pipe::PipeEdit() {
    int count = 0;
    std::cout << "1)�������������� ���� ���� " << endl;
    std::cout << "2)�������������� ��������� ����: " << endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        count++;
        std::cout << "������ ����� :(" << endl;
        logfile << "�������� ������ ��� �������������� ����" << endl;
    }
    if (count == 0) {
        switch (answer) {
        case 1:
            std::cout << "�������� ��������� ������" << endl;
            std::cout << "1)��� ";
            std::cout << "2)����" << endl;
            std::getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                std::cout << "������ ����� :(" << endl;
                logfile << "�������� ������ ��� �������������� ����" << endl;
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
                    std::cout << "������ ����� :(" << endl;
                    logfile << "����� ��������������� �������� ������ ��� �������������� ����" << endl;
                    break;
                }
            }
            else {
                std::cout << "��� ����" << endl;
                logfile << "����� ���� ��� ����" << endl;
            }
            break;
        case 2:
            std::cout << "�������� ��������� ������" << endl;
            std::cout << "1)��� ";
            std::cout << "2)����" << endl;
            std::getline(cin, temp);
            try {
                answer = checkInt(temp);
            }
            catch (invalid_argument) {
                count++;
                std::cout << "������ ����� :(" << endl;
                logfile << "�������� ������ ��� �������������� ����" << endl;
            }
            if (count == 0 && !pipes.empty()) {
                switch (answer) {
                case 1:
                    std::cout << "id ���� : ";
                    for (auto& item : pipes) {
                        std::cout << item.first << " ";
                    }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            std::cout << "����� �����" << endl;
                            logfile << "�������� ������ ��� ����� id ����� ��� ��������������" << endl;
                            continue;
                        }
                        if (pipes.find(answer) == pipes.end()) {
                            std::cout << "��� ������ id" << endl;
                            logfile << "���� ��������������� id" << endl;
                            continue;
                        }
                        else {
                            pipes[answer]->isWorking = 1;
                        }
                    }
                    break;
                case 2:
                    std::cout << "id ���� : ";
                    for (auto& item : pipes) {
                        std::cout << item.first << " ";
                    }
                    while (std::getline(cin, temp) && !temp.empty()) {
                        try {
                            answer = checkInt(temp);
                        }
                        catch (invalid_argument) {
                            logfile << "�������� ������ ��� ����� id ����� ��� ��������������" << endl;
                            std::cout << "����� �����" << endl;
                            continue;
                        }
                        if (!pipes.count(answer)) {
                            std::cout << "��� ������ id" << endl;
                            logfile << "���� ��������������� id" << endl;
                            continue;
                        }
                        else {
                            pipes[answer]->isWorking = 0;
                        }
                    }
                    break;
                default:
                    count++;
                    std::cout << "������ ����� :(" << endl;
                    logfile << "����� ��������������� �������� ��� �������������� ����" << endl;

                    break;
                }
            }
            else {
                std::cout << "��� ����" << endl;
                logfile << "����� ���� ��� ����" << endl;
            }
            break;
        default:
            count++;
            std::cout << "������ ����� :(" << endl;
            logfile << "����� ��������������� �������� ��� �������������� ����" << endl;
            break;
        }
    }
}
void Pipe::deletePipe(){
    std::map<int, Pipe*>::iterator it;
    std::cout << "�������� ����� ��� �������� (id) :" << std::endl;
    findTubes();
    while (std::getline(cin, temp) && !temp.empty()) {
        try {
            answer = checkInt(temp);
        }
        catch (invalid_argument) {
            std::cout << "����� �����" << endl;
            logfile << "�������� ������ ��� ����� id ����� ��� ��������������" << endl;
            continue;
        }
        if (pipes.find(answer) == pipes.end()) {
            std::cout << "��� ������ id" << endl;
            logfile << "���� ��������������� id" << endl;
            continue;
        }
        else {
            it = pipes.find(answer);
            pipes.erase(it);
        }
    }
}
