#pragma once
#include <string>
#include <map>
#include "Pipe.h"
#include "gasNetwork.h"
#include "Ks.h"
class gasNetwork;
extern std::map<int, Pipe*> pipes;
extern std::map<int, Ks*> ksMap;
extern std::ofstream logfile;
extern std::string temp;
extern gasNetwork network;
extern int answer;