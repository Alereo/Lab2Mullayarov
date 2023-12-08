#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include "Pipe.h"
#include "gasNetwork.h"
#include "Ks.h"
int answer;
std::map<int, Pipe*> pipes;
std::map<int, Ks*> ksMap;
std::ofstream logfile;
std::string temp;
gasNetwork network;