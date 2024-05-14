//
// Created by yuto&scott&Andy on 5/7/2024.
//



#include <iostream>
#include <vector>

#include <map>
#include "graph.h"
//add Vertices
Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V, nullptr);
}

Graph::~Graph() {
    for (int i = 0; i < V; ++i) {
        Vertix* current = adjList[i];
        while (current != nullptr) {
            Vertix* temp = current;
            current = current->next;
            delete temp;
        }
    }

}
//Graph::Graph(const Graph& other) : V(other.V), adjList(other.adjList.size()), parent(other.parent) {
//    // Deep copy of adjacency lists
//    for (size_t i = 0; i < other.adjList.size(); ++i) {
//        Vertix* current = other.adjList[i];
//        Vertix* prev = nullptr;
//        while (current != nullptr) {
//            Vertix* newVertix = new Vertix;
//            if (prev == nullptr)
//                adjList[i] = newVertix;
//            else
//                prev->next = newVertix;
//            prev = newVertix;
//            current = current->next;
//        }
//    }
//}

//Graph& Graph::operator=(const Graph& other) {
//    if (this != &other) { // Check for self-assignment
//        // Deep copy of adjacency lists
//        std::vector<Vertix*> newAdjList(other.adjList.size(), nullptr);
//        for (size_t i = 0; i < other.adjList.size(); ++i) {
//            Vertix* current = other.adjList[i];
//            Vertix* prev = nullptr;
//            while (current != nullptr) {
//                Vertix* newVertix = new Vertix;
//                if (prev == nullptr)
//                    newAdjList[i] = newVertix;
//                else
//                    prev->next = newVertix;
//                prev = newVertix;
//                current = current->next;
//            }
//        }
//        // Swap the contents
//        V = other.V;
//        adjList.swap(newAdjList);
//        parent = other.parent;
//    }
//    return *this;
//}

void Graph::addEdge(int from, int dest) {
    // Create a new vertex for the destination
    Vertix* newVertex = new Vertix;
    newVertex->dest = dest; // Set destination
    newVertex->next = nullptr; // Initialize next pointer
    newVertex->predecessor = nullptr; // Initialize predecessor pointer

    // Check if there are any vertices in the adjacency list for the 'from' vertex
    if (adjList[from] == nullptr) {
        // If there are no vertices in the list for 'from', directly add the new vertex
        adjList[from] = newVertex;
    } else {
        // If there are vertices in the list for 'from', find the last vertex and append the new one
        Vertix* current = adjList[from];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newVertex; // Append the new vertex at the end of the list
        newVertex->predecessor = current; // Set the predecessor of the new vertex
    }

    std::cout << "Added edge from " << from << " to " << dest << std::endl;
}


void Graph::BFS(int source) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[source] = true;
    q.push(source);
    std::cout<<"shortest path:";
    std::cout<<source;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        //shortest path
        for (Vertix* neighbor = adjList[current]; neighbor != nullptr; neighbor = neighbor->next) {
            if (!visited[neighbor->dest]) {
                std::cout<<"->"<<neighbor->dest;
                visited[neighbor->dest] = true;
                q.push(neighbor->dest);
            }
        }
    }


}
void Graph::printShortestPath(int source) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[source] = true;
    q.push(source);
    std::cout<<"shortest path:";
    std::cout<<source;
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        //shortest path
        for (Vertix* neighbor = adjList[current]; neighbor != nullptr; neighbor = neighbor->next) {
            if (!visited[neighbor->dest]) {
                std::cout<<"->"<<neighbor->dest;
                visited[neighbor->dest] = true;
                q.push(neighbor->dest);
            }
        }
    }


}
void Graph::printBFSTree(int source) {
    std::queue<int> q;
    std::vector<bool> visited(V, false);
    std::vector<int> parent(V, -1);

    q.push(source);
    visited[source] = true;

    std::cout << "BFS Tree:" << std::endl;
    for(int j=V;j!=0;j--){
        std::cout << " ";
    }
    std::cout <<" "<<source;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Print the edge from parent[u] to u
        if (parent[u] != -1) {
            if(parent[u]==parent[u-1]){
                std::cout <<"  "<< u ;
            }else{
                std::cout << "\n";
                for(int j=V-u;j!=0;j--){
                    std::cout << " ";
                }
                if(parent[u]!=parent[u+1]){
                    std::cout << " / \n";
                }else {
                    std::cout << " /\\ \n ";
                }

                for(int j=V-u;j!=0;j--){
                    std::cout << " ";
                }
                std::cout<< u;

            }
        }

        for (int v=source; v<=adjList[u]->dest;++v) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }

}


