#include "gasNetwork.h"


Ks* gasNetwork::addOrGetNode(int id) {
    if (id == -1) {
        return nullptr;
    }
    if (graph.find(id) != graph.end()) {
        return graph[id];
    }
    Ks* ks = ksMap[id];
    graph[id] = ks;
    return ks;
}
gasNetwork::gasNetwork() {
    std::map<int, Ks*> graph;
}
void gasNetwork::cout() {
    for (auto& temp : graph) {
        for (auto& temp1 : temp.second->parents) {
            std::cout << "[" << temp1.first->idInit << "]" << "->" << temp1.second->diam << "[" << temp.first << "]" << std::endl;
        }
    }
}

void gasNetwork::generateGraph(int idValueFrom, int idValueTo, Pipe* pipe) {
    Ks* from = addOrGetNode(idValueFrom);
    Ks* to = addOrGetNode(idValueTo);
    pipe->adjacentNode = to;
    from->tubes.insert(pipe);
    to->parents.emplace(from, pipe);
}

void gasNetwork::DFS(Ks* ks, std::list<Ks*>& order, std::set<Ks*>& passed) {
    passed.insert(ks);
    for (auto tube : ks->tubes) {
        if (passed.find(tube->adjacentNode) == passed.end()) {
            DFS(tube->adjacentNode, order, passed);
        }
    }
    order.push_back(ks);
}

void gasNetwork::DFSWrap(std::map<int, Ks*>& graph) {
    std::list<Ks*> order;
    std::set<Ks*> passed;
    for (auto& entry : graph) {
        if (passed.find(entry.second) == passed.end()) {
            DFS(entry.second, order, passed);
        }
    }
    order.reverse();
    for (Ks* ks : order) {
        std::cout << ks->idInit << " ";
    }
    std::cout << std::endl;
    //for (Node* node : passed) {
    //    std::cout << node->value << " ";
    //}
}