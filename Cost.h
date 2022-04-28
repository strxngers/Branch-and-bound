#ifndef COST_H
#define COST_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
Represent the cost to run a process j in in a given machine i.
Cost are generated randomly. We assume that generateCost() is 
not called a huge number of times, it has performance issues.
*/
class Cost  {
private:
    int N; // size of the square cost matrix
    int **cost;
    int isNotNewCost(int i, int j); // auxiliary function to check if the cost is new in row i
public:
    Cost();
    Cost(int N); // Receive the size of the problem
    ~Cost();
    void setCost(int i, int j, int value);
    int getCost(int i, int j);
    int getN(); // getter for the size of the matrix
    void generateCost(); // Generate random cost, reentrant function
    void print();
    int getValue(int i, int j);
};

#endif