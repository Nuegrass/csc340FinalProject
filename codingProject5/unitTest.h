//
// Created by yuto&scott&Andy on 5/7/2024.
//

#ifndef PROJECT5_UNITTEST_H
#define PROJECT5_UNITTEST_H
#include "graph.h"
#include <cassert>
#include <algorithm>
#endif //PROJECT5_UNITTEST_H
namespace UNITTEST{

    bool testVertix(){
        try {
            Graph graph(6); // Attempt to create a Graph object with 6 vertices
            return (graph.getV()==6);
        } catch (const std::exception& e) {
            std::cerr << "An exception occurred: " << e.what() << std::endl;
            return false;
        }
    }

    bool testBFS(){
        try{
            Graph graph(5);
            graph.addEdge(0, 1);//0
            graph.addEdge(0, 2);//1
            graph.addEdge(1, 3);//2
            graph.addEdge(2, 4);//3
            graph.addEdge(3, 4);//4
            graph.addEdge(1, 2);//5
            int root=0;
            Vertix* source= nullptr;
            for (int i = 0; i < graph.getVertixList().size(); ++i) {
                if(graph.getVertixList().at(i)->dest==root){
                    source=graph.getVertixList().at(i+1);
                } else if(graph.getVertixList().at(i)->next== nullptr){
                    source=graph.getVertixList().at(i);
                }
            }
            if(source== nullptr){
                source=graph.getVertixList().at(0);
            }

            std::cout << "BFS traversal starting from node "<<root<<": ";
            graph.BFS(source);
            Vertix* vertix=source;
            while(vertix->next!= nullptr){
                if(vertix->VertixColor!=black){// all V should be visted
                    return false;
                }
                vertix=vertix->next;
            }

            return true;

        } catch (const std::exception& e) {
            std::cerr << "An exception occurred: " << e.what() << std::endl;
            return false;
        }

    }

    bool testAddEdge() {

        bool result= true;
        try {
            Graph graph(5);
            graph.addEdge(0, 1);//0->1
            graph.addEdge(0, 2);//0->1->2
            graph.addEdge(1, 3);//1->3?
            graph.addEdge(2, 4);
            graph.addEdge(3, 4);
            std::vector<Vertix*> adjList = graph.getAdjList();

            std::cout<<"\nfrom 0 to "<<adjList[0]->dest;
            if (adjList.at(0)->dest == 1) {
                std::cout<<"\nfrom 0 to "<<adjList[0]->next->dest;
                if(adjList.at(0)->next->dest == 2){

                }
            }else{
                return false;
            }

            std::cout<<"\nfrom 1 to "<<adjList[1]->dest;
            if (adjList.at(1)->dest == 3) {

            }else{
                return false;
            }
            std::cout<<"\nfrom 2 to "<<adjList[2]->dest;
            if (adjList.at(2)->dest == 4) {

            }else{
                return false;
            }
            std::cout<<"\nfrom 3 to "<<adjList[3]->dest;
            if (adjList.at(3)->dest == 4) {

            }else{
                return false;
            }
            return result;
        } catch (const std::exception &e) {
            std::cerr << "An exception occurred: " << e.what() << std::endl;
            return false;
        }
    }

//    bool testPrintTree(){
//        try{
//            Graph graph(5);
//            graph.addEdge(0, 1);
//            graph.addEdge(0, 2);
//            graph.addEdge(1, 3);
//            graph.addEdge(2, 4);
//            graph.addEdge(3, 4);
//            int root=0;
//            std::cout << "BFS traversal starting from node "<<root<<": ";
//            graph.BFS(root);
//            graph.printBFSTree(root);
//            std::cout << std::endl;
//            return true;
//        } catch (const std::exception& e) {
//            std::cerr << "An exception occurred: " << e.what() << std::endl;
//            return false;
//        }
//
//    }

//
     bool testCopyConstructor() {
         // Create graph1 with edges
         Graph graph1(5);
         graph1.addEdge(0, 1);
         graph1.addEdge(0, 2);

         // Create graph2 using copy constructor
         Graph graph2(graph1); // Copy constructor

         // Check if graph2 is a copy of graph1
         if (graph2.getV() != graph1.getV())
             return false;

         const std::vector<Vertix*>& adjList1 = graph1.getAdjList();
         const std::vector<Vertix*>& adjList2 = graph2.getAdjList();
         for (int i = 0; i < graph1.getV(); ++i) {
             Vertix* current1 = adjList1[i];
             Vertix* current2 = adjList2[i];
             while (current1 != nullptr) {
                 if (current2 == nullptr || current1->dest != current2->dest)
                     return false;
                 current1 = current1->next;
                 current2 = current2->next;
             }
         }

         // All checks passed
         return true;
     }




    bool testCopyAssignment() {
        Graph graph(5);
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(0, 3);
        graph.addEdge(2, 3);
        graph.addEdge(3, 1);

        Graph& ref = graph;
        ref = ref; // Self-assignment

        // Check if graph remains unchanged
        return (graph.getAdjList() == ref.getAdjList() && graph.getV() == ref.getV());
    }



     bool testDestructor() {
         // Create an empty graph
         Graph graph(0);

         // Delete the graph object
         // After deletion, the adjacency list should be empty
         delete &graph; // Delete the graph object

         return graph.getAdjList().empty();
     }

}


