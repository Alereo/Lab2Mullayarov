#pragma once
#include <string>

#include "gasNetwork.h"
#include "Ks.h"
#include "Pipe.h"
static int checkInt(std::string str) {
    if (str.find(".") != str.npos) {
        std::cout << "������ ����� ������" << std::endl;
        logfile << "�������� �� double �� �������" << std::endl;
        return 0;
    }
    else {
        return stoi(str);
    }
}
static double checkDouble(std::string str) {
        return stod(str);

}
static std::string checkStr(std::string str) {
    if (str.find("/") != str.npos || str.find(".") != str.npos) {
        logfile << "� ������ " << str << "������������ �������" << endl;
        return "Error";

    }
    else {
        return(str);
    }
}
static int checkBool(std::string str) {
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

static void save() {
    std::cout << "����� ��� �����" << std::endl;
    std::string fileName;
    std::ofstream file;
    getline(std::cin, fileName);
    try {
        file.open(fileName);
        if (file.is_open()) {
            if (pipes.empty()) {
                file << "��� ����" << std::endl;
            }
            else {
                for (auto& item : pipes) {
                    file << "����� : " << item.first << std::endl;
                    item.second->cout(file);
                }
            }
            if (ksMap.empty()) {
                file << "��� Ks" << std::endl;
            }
            else {
                for (auto& item : ksMap) {
                    file << "Ks : " << item.first << std::endl;
                    item.second->cout(file);
                }
            }
        }
    }
    catch (std::exception& ex) {
        logfile << "���������� ��� ������ � ������ " << &ex << std::endl;
    }
}
static void load() {
    std::string kmMark;
    std::ifstream file1;
    std::string fileName;
    int len;
    double diam;
    bool isWorking;
    int id;
    std::string name;
    int amountWorkshops;
    int amountWorkshopsNow;
    int eff;
    std::cout << "����� ��� �����" << std::endl;
    getline(std::cin, fileName);
    try {
        file1.open(fileName);
        if (file1.is_open()) {
            getline(file1, temp);
            if (temp != "��� ����") {
                while (temp != "��� Ks" && temp != "Ks : 1") {
                    id = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    kmMark = temp.substr(temp.find_first_of(':') + 2);
                    getline(file1, temp);
                    len = std::stod(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    diam = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    isWorking = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                    getline(file1, temp);
                    pipes.emplace(id,new Pipe(kmMark,len,diam,isWorking));
                    pipes[id]->idInit = id;
                }
                if (temp == "��� Ks") {
                    return;
                }
                else {
                    while (file1.peek() != EOF) {
                        id = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        name = temp.substr(temp.find_first_of(':') + 2);
                        getline(file1, temp);
                        amountWorkshops = std::stod(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        amountWorkshopsNow = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        eff = std::stoi(temp.substr(temp.find_first_of(':') + 1, temp.find_first_of('%')));
                        getline(file1, temp);
                        ksMap.emplace(id, new Ks(name, amountWorkshops, amountWorkshopsNow));
                        ksMap[id]->idInit = id;
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
                        id = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        name = temp.substr(temp.find_first_of(':') + 2);
                        getline(file1, temp);
                        amountWorkshops = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        amountWorkshopsNow = std::stoi(temp.substr(temp.find_first_of(':') + 2));
                        getline(file1, temp);
                        eff = std::stoi(temp.substr(temp.find_first_of(':') + 1, temp.find_first_of('%')));
                        getline(file1, temp);
                        ksMap.emplace(id, new Ks(name, amountWorkshops, amountWorkshopsNow));
                        ksMap[id]->idInit = id;
                    }
                }
            }
        }
    }
    catch(std::exception& ex){
        logfile << "���������� ��� ������ � ������ " << &ex << std::endl;
    }
}
static void addPipeToGraph() {
    Pipe *pipe{};
    int kses[2];
    std::map<int, Ks*>::iterator it;
    std::cout << "������� id ��" << std::endl;
    for (int i = 0; i < 2; i++) {
        std::getline(cin, temp);
        try {
            answer = checkInt(temp);
        }
        catch (invalid_argument) {
            std::cout << "����� �����" << endl;
            logfile << "�������� ������ ��� ����� id Ks ��� ��������������" << endl;
        }
        if (ksMap.find(answer) == ksMap.end()) {
            std::cout << "��� ������ id" << endl;
            logfile << "���� ��������������� id" << endl;
            return;
        }
        else {
            kses[i] = answer;

        }
    }
    std::cout << "������� id �����" << std::endl;
    std::getline(cin, temp);
    try {
        answer = checkInt(temp);
    }
    catch (invalid_argument) {
        std::cout << "����� �����" << endl;
        logfile << "�������� ������ ��� ����� id Ks ��� ��������������" << endl;
    }
    if (pipes.find(answer) == pipes.end()) {
        std::cout << "��� ������ id" << endl;
        logfile << "���� ��������������� id" << endl;
        std::cout << "�������� �����" << endl;
        Pipe::pipeInput();
        addPipeToGraph();
    }
    else {
         pipe = pipes[answer];
    }
    if (kses[0] != kses[1]) {
        network.generateGraph(kses[0], kses[1], pipe);
    }
}
static void topologicalSort() {
    network.cout();
    gasNetwork::DFSWrap(network.graph);
}
