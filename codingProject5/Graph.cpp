//
// Created by amytx on 5/7/2024.
//
//
// Created by yutto on 5/7/2024.
//

#include "Graph.h"

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V, nullptr);
}

Graph::~Graph() {
    for (int i = 0; i < V; ++i) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

void Graph::addEdge(int from, int to) {
    Node* newNode = new Node;
    newNode->to = to;
    newNode->next = adjList[from];
    adjList[from] = newNode;
}

void Graph::BFS(int source) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int current = q.front();
        std::cout << current << " ";
        q.pop();

        for (Node* neighbor = adjList[current]; neighbor != nullptr; neighbor = neighbor->next) {
            if (!visited[neighbor->to]) {
                visited[neighbor->to] = true;
                q.push(neighbor->to);
            }
        }
    }


}
void Graph::printBFSTree() {
    std::cout << "BFS Tree:" << std::endl;
    for (int i = 0; i < V; ++i) {
        std::cout << "Parent of node " << i << " is ";
        if (parent[i] != -1) {
            std::cout << parent[i];
        } else {
            std::cout << "None"; // Indicate no parent for the root node
        }
        std::cout << std::endl;
    }
}