#pragma once
#include <string>
#include <iostream>

#include <fstream>
using namespace std;
class Pipe
{
public:
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

