//
// Created by yuto&scott&Andy on 5/7/2024.
//
#include <iostream>
#include "unitTest.h"
#include "graph.h"
void printTestResult(bool result,std::string testName) {
    std::cout<<"\n\n testing:"<<testName<<"\n";
    if (result) {
        std::cout << testName << " is passed.\n\n";

    } else {
        std::cout << testName << " is failed\n\n";
    }
}
int main() {
    printTestResult(UNITTEST::testVertix(),"testVertix");
    printTestResult(UNITTEST::testAddEdge(),"testAddEdge");
//    printTestResult(UNITTEST::testCopyAssignment(),"testCopyAssignment");
  //  printTestResult(UNITTEST::testCopyConstructor(),"testCopyConstructor");
    //printTestResult(UNITTEST::testDestructor(),"testDestructor");

   // printTestResult(UNITTEST::testBFS(),"testBFS");
  //  printTestResult(  UNITTEST::testPrintTree(),"testPrintTree");
  //printShortest


    return 0;
}