//
// Created by yuto&scott&Andy on 5/7/2024.
//



#include <iostream>
#include <vector>

#include <map>
#include "graph.h"
//add Vertices
Graph::Graph(int vertices) : V(vertices) {

    vertixList.resize(V+1, nullptr);
    adjList.resize(V*V, nullptr);
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
Graph::Graph(const Graph& other) : V(other.V), adjList(other.adjList.size()) {
    // Deep copy of adjacency lists
    for (size_t i = 0; i < other.adjList.size(); ++i) {
        Vertix* current = other.adjList[i];
        Vertix* prev = nullptr;
        while (current != nullptr) {
            Vertix* newVertix = new Vertix;
            if (prev == nullptr)
                adjList[i] = newVertix;
            else
                prev->next = newVertix;
            prev = newVertix;
            current = current->next;
        }
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
    // Create a new vertex for the destination


    // Check if there are any vertices in the adjacency list for the 'from' vertex
    if (adjList[from] == nullptr&&adjList[dest] != nullptr) {//if from V is null but not dest
        // If there are no vertices in the list for 'from', directly add the new vertex
        Vertix* newVertex = new Vertix;//from V
        newVertex->dest = dest; // Set destination
        newVertex->next = nullptr; // Initialize next pointer
        newVertex->predecessor =nullptr; // Initialize predecessor pointer
        adjList[from] = newVertex;
        vertixList.at(from)=newVertex;//add to vertixList just add from

        Vertix* current = adjList[from];
        while (current->next != nullptr) {//go over till the edge
            current = current->next;
        }
        current->dest=dest;
        newVertex->next=adjList[from];

    }else if(adjList[from] != nullptr&&adjList[dest] != nullptr) {//if both not null

        // If there are vertices in the list for 'from', find the last vertex and append the new one
        Vertix* current = adjList[from];
        Vertix* destination = adjList[dest];
        while (current->next != nullptr) {//go over till the edge
            current = current->next;
        }

        current->dest=dest;
        current->next = destination; // Append the new vertex at the end of the list
        destination->predecessor = current; // Set the predecessor of the new vertex
    }else if(adjList[from]!= nullptr&&adjList[dest]== nullptr){//if dest is null
         Vertix* newVertex = new Vertix;//dest
         newVertex->dest =-1; // Set destination
         newVertex->next = nullptr; // Initialize next pointer

        Vertix* current = adjList[from];

        while (current->next != nullptr) {//go over till the edge
            current = current->next;
        }
        current->dest=dest;
        newVertex->predecessor = current; // Initialize predecessor pointer
        current->next = newVertex; // Append the new vertex at the end of the list

         adjList[dest] = newVertex;
         vertixList[dest]=newVertex; //just add dest
    }else {//if both null
        //set from
        Vertix* newVertexFrom = new Vertix;
        newVertexFrom->dest = dest; // Set destination
        newVertexFrom->predecessor = nullptr; // Initialize predecessor pointer

        Vertix* newVertexDest = new Vertix;

        newVertexDest->dest =-1; // Set destination
        newVertexDest->next = nullptr; // Initialize next pointer


        newVertexDest->predecessor = newVertexFrom; // add predecessor pointer
        newVertexFrom->next = newVertexDest; // add next pointer
        adjList[dest] = newVertexDest;
        adjList[from] = newVertexFrom;
         vertixList.at(from)=newVertexFrom;
         vertixList.at(dest)=newVertexDest;

    }



      std::cout << "Added edge from " << from << " to " << dest << std::endl;
}


void Graph::BFS(Vertix* source) {

            //vertixlist:  1, 2, 3, 4, 5
        for (Vertix* vertix: vertixList) {//set all vertix
            vertix->VertixColor=white;
           //vertix->distance=-1
            vertix->predecessor= nullptr;
        }
    //V: 1,2,4,6,5,3
    //verixList[0,1,2,3,4,5]
    //source=1
    //vertixList[source]=2

    source->VertixColor=grey;
    //vertix->distance=-1
    source->predecessor= nullptr;
    Q.push(source);
        while (!Q.empty()) {
            Vertix* u=Q.front();
            Q.pop();
            for(Vertix* vertix:adjList) {
                if(vertix->VertixColor==white) {
                    vertix->VertixColor=grey;
                    vertix->predecessor=u;
                    Q.push(vertix);
                }
                u->VertixColor=black;
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


