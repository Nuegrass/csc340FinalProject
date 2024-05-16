//
// Created by yutto on 5/7/2024.
//


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>
enum color {black,grey,white};//white-not visited, grey&black visited
struct Vertix {
    enum color VertixColor;
    Vertix* predecessor;//to point previous node
    Vertix* next;//to point next
    int dest;
};

class Graph {
private:
    std::queue<Vertix*> Q;
    int V;//number of vertices
    std::vector<Vertix*> vertixList;//connection
    std::vector<Vertix*> adjList;//connection

public:
    Graph(int vertices);//add V
    Graph(const Graph& other); // Copy constructor
    Graph& operator=(const Graph& other); // Copy assignment operator
    ~Graph();
    void addEdge(int from, int dest);
    void BFS(Vertix* source);
    void printShortestPath(int source);
    void printBFSTree(int source);
    // Getter function for V
    int getV() const {
        return V;
    }
    // Getter function for adjList
    const std::vector<Vertix*>& getAdjList() const {
        return adjList;
    }
    const std::vector<Vertix*>& getVertixList() const {
        return vertixList;
    }



};

#endif // GRAPH_H