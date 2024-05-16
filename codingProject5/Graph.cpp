//
// Created by yuto&scott&Andy on 5/7/2024.
//



#include <iostream>
#include <vector>

#include <map>
#include "graph.h"
//add Vertices
Graph::Graph(int vertices,int egde) : V(vertices),E(egde) {

    vertixList.resize(V, nullptr);
    adjList.resize(E);
}

Graph::~Graph() {
    std::cout<<"destructed called";
    for (int i = 0; i < V; ++i) {
        Vertix* current = adjList[i];
        while (current != nullptr) {
            Vertix* temp = current;
            current = current->next;
            delete temp;
        }
        adjList[i] = nullptr; // Set the pointer to nullptr after deleting the vertices

    }
    adjList.clear(); // Clear the adjacency list
    std::cout<<"size:"<<adjList.size();
}

Graph::Graph(const Graph& other) : V(other.V), adjList(other.adjList.size()) {
    // Deep copy of adjacency lists
    for (size_t i = 0; i < other.adjList.size(); ++i) {
        Vertix* current = other.adjList[i];
        Vertix* prev = nullptr;
        Vertix* newAdjListHead = nullptr; // Head of the copied adjacency list for vertex i

        // Traverse the adjacency list of the current vertex in 'other'
        while (current != nullptr) {
            // Create a new vertex and copy the 'dest' value
            Vertix* newVertix = new Vertix;
            newVertix->dest = current->dest;

            if (prev == nullptr) {
                // If this is the first vertex in the adjacency list, update the head pointer
                newAdjListHead = newVertix;
            } else {
                // Link the new vertex to the previous one
                prev->next = newVertix;
            }

            // Update the previous vertex pointer
            prev = newVertix;

            // Move to the next vertex in the adjacency list of 'other'
            current = current->next;
        }

        // Set the copied adjacency list for vertex i in the new graph
        adjList[i] = newAdjListHead;
    }
}


Graph& Graph::operator=(const Graph& other) {
    if (this != &other) { // Check for self-assignment
        // Deep copy of adjacency lists
        std::vector<Vertix*> newAdjList(other.adjList.size(), nullptr);
        for (size_t i = 0; i < other.adjList.size(); ++i) {
            Vertix* current = other.adjList[i];
            Vertix* prev = nullptr;
            while (current != nullptr) {
                Vertix* newVertix = new Vertix;
                if (prev == nullptr)
                    newAdjList[i] = newVertix;
                else
                    prev->next = newVertix;
                prev = newVertix;
                current = current->next;
            }
        }
        // Swap the contents
        V = other.V;
        adjList.swap(newAdjList);
//        parent = other.parent;
    }
    return *this;
}

void Graph::addEdge(int from, int dest) {
    // Check if 'from' vertex exists in the adjacency list
    if(vertixList[from]== nullptr&&vertixList[dest]== nullptr){//if both null

        Vertix* newVertexDest = new Vertix;
        newVertexDest->dest = dest;
        newVertexDest->next = nullptr;
        newVertexDest->predecessor = nullptr;
        vertixList[dest]=newVertexDest;

        Vertix* newVertexFrom = new Vertix;
        newVertexFrom ->dest = dest;
        newVertexFrom ->next = nullptr;
        newVertexFrom ->predecessor = nullptr;
        vertixList[from]=newVertexFrom ;
    }

    if (from >= adjList.size() || adjList[from] == nullptr) {
        // If 'from' vertex doesn't exist, create it
        adjList.resize(std::max(from + 1, (int)adjList.size()), nullptr);
    }

    // Check if 'dest' vertex exists in the adjacency list
    if (dest >= adjList.size() || adjList[dest] == nullptr) {
        // If 'dest' vertex doesn't exist, create it
        adjList.resize(std::max(dest + 1, (int)adjList.size()), nullptr);
    }

    // Create a new vertex for the destination
    Vertix* newVertexDest = new Vertix;
    newVertexDest->dest = dest;
    newVertexDest->next = nullptr;
    newVertexDest->predecessor = nullptr;

    // If 'from' vertex already has vertices in its adjacency list
    if (adjList[from] != nullptr) {
        Vertix* current = adjList[from];

        // Traverse to the end of the adjacency list of 'from'
        while (current->next != nullptr) {
            current = current->next;
        }

        // Append the new vertex to the end of the list
        current->next = newVertexDest;
        newVertexDest->predecessor = current;
        vertixList[dest]=newVertexDest;
    } else {
        // If 'from' vertex doesn't have any adjacent vertices yet
        adjList[from] = newVertexDest;
        vertixList[from]=newVertexDest;
    }

    // Output message indicating the edge addition
    std::cout << "Added edge from " << from << " to " << dest << std::endl;
}


void Graph::BFS(Vertix* source) {
    // Initialize vertices
    for (Vertix* vertix : vertixList) {
        vertix->VertixColor = white;
        vertix->predecessor = nullptr;
    }

    // Initialize source vertex
    source->VertixColor = grey;
    source->predecessor = nullptr;
    Q.push(source);

    while (!Q.empty()) {
        Vertix* u = Q.front();
        Q.pop();

        // Traverse the adjacency list of the current vertex 'u'
        Vertix* adjVertex = adjList[u->dest];
        while (adjVertex != nullptr) {
            if (adjVertex->VertixColor == white) {
                adjVertex->VertixColor = grey;
                adjVertex->predecessor = u;
                Q.push(adjVertex);
            }
            adjVertex = adjVertex->next;
        }

        // Set the color of the current vertex to black
        u->VertixColor = black;
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


