//
// Created by amytx on 5/7/2024.
//

#ifndef CSC340FINALGROUPPROJECT_GRAPH_H
#define CSC340FINALGROUPPROJECT_GRAPH_H

//
// Created by yutto on 5/7/2024.
//
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int to;
    Node* next;
};

class Graph {
private:
    int V;//number of vertices
    std::vector<Node*> adjList;
    std::vector<int> parent;
public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int from, int to);
    void BFS(int source);
    void printBFSTree();
};

#endif // GRAPH_H




#endif //CSC340FINALGROUPPROJECT_GRAPH_H
