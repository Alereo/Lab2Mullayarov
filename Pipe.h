#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "variables.h"
using namespace std;
class Ks;
extern std::map<int, Ks*> ksMap;
class Pipe
{
public:
    int idInit;
    Ks* adjacentNode;
    void pipeInput();
    void deletePipe();
    void findTubes();
    void PipeEdit();
    Pipe();
    Pipe(string name, double len, int diam, bool isWorking);
    string kmMark;
    int len;
    double diam;
    bool isWorking;
    static int id ;
    void cout();
    void cout(ofstream& file);
};

