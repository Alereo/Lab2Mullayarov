#pragma once

#include <map>
#include <set>
#include "Pipe.h"
#include "Ks.h"
#include <list>
extern std::map<int, Ks*> ksMap;
class gasNetwork {
public:
    std::map<int, Ks*> graph;
    gasNetwork();

    Ks* addOrGetNode(int id);

    void generateGraph(int idValueFrom, int idValueTo, Pipe* pipe);

    static void DFS(Ks* ks, std::list<Ks*>& order, std::set<Ks*>& passed);

    static void DFSWrap(std::map<int, Ks*>& graph);
    void cout();
};