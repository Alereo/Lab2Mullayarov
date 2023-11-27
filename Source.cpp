//#include <iostream>
//
//#include <map>
//#include <set>
//#include <list>
//class Edge;
//class Node {
//public:
//    int value;
//    std::map<Node*, Edge*> parents;
//    std::set<Edge*> edges;
//
//    Node(int value) {
//        this->value = value;
//    }
//
//    std::string toString() {
//        return (this->value) + "";
//    }
//    std::set<Edge*>getEdges() {
//        return this->edges;
//    }
//};
//class Edge {
//public:
//    int weight;
//    Node* adjacentNode;
//
//    Edge(int weight) {
//        this->weight = weight;
//    }
//
//    std::string toString() {
//        return adjacentNode->toString();
//    }
//};
//
//
//class Graph {
//public:
//     std::map<int, Node*> graph;
//
//    Node* addOrGetNode(int value) {
//        if (value == -1) {
//            return nullptr;
//        }
//        if (graph.count(value)) {
//            return graph[value];
//        }
//        Node* node = new Node(value);
//        graph[value] = node;
//        return node;
//    }
//
//    void generateGraph(int valueFrom, int valueTo, int weight) {
//        Node* from = addOrGetNode(valueFrom);
//        Node* to = addOrGetNode(valueTo);
//        Edge* edge = new Edge(weight);
//        edge->adjacentNode = to;
//        from->edges.insert(edge);
//        to->parents[from] = edge;
//    }
//
//    static void DFS(Node* node, std::list<Node*>& order, std::set<Node*>& passed) {
//        passed.insert(node);
//        for (auto edge : node->edges) {
//            if (passed.find(edge->adjacentNode) == passed.end()) {
//                DFS(edge->adjacentNode, order, passed);
//            }
//        }
//        order.push_back(node);
//    }
//
//    static void DFSWrap(std::map<int, Node*>& graph) {
//        std::list<Node*> order;
//        std::set<Node*> passed;
//        for (auto& entry : graph) {
//            if (passed.find(entry.second) == passed.end()) {
//                DFS(entry.second, order, passed);
//            }
//        }
//        order.reverse();
//        for (Node* node : order) {
//            std::cout << node->value << " ";
//        }
//        std::cout << std::endl;
//        for (Node* node : passed) {
//            std::cout << node->value << " ";
//        }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    Graph graph;
//    graph.generateGraph(1, 2, 3);
//    graph.generateGraph(2, 3, 4);
//    graph.generateGraph(3, 4, 5);
//    graph.DFSWrap(graph.graph);
//    std::cout << "d";
//    return 0;
//}
//

