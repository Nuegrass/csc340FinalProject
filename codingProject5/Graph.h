//
// Created by yutto on 5/7/2024.
//


#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

struct Vertix {
    enum color {black,grey,white};//white-not visited, grey&black visited
    Vertix* predecessor;//to point previous node
    Vertix* next;//to point next
    int dest;
};

class Graph {
private:
    int V;//number of vertices

    std::vector<Vertix*> adjList;//connection
    std::queue<int> tree;
    std::queue<int> shortestPath;
public:
    Graph(int vertices);//add V
    Graph(const Graph& other); // Copy constructor
    //Graph& operator=(const Graph& other); // Copy assignment operator
    ~Graph();
    void addEdge(int from, int dest);
    void BFS(int source);
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


    // Getter function for tree
    const std::queue<int>& getTree() const {
        return tree;
    }


};

#endif // GRAPH_H