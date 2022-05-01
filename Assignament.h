#include <iostream>
#include <stdlib.h>
#include "Cost.h"
#include "State.h"
using namespace std;

class Assignament
{
private:
    int lenght;
    int *array;
    

public:
    Assignament();
    Assignament(int lenght);
    int greedy(Cost* cost);
    bool isBusy(int position);
    void Solve();
    int* generateArray(int size);
    State* addState(State* head, State* nextHead);
    State* removeHead(State* head);
    State* generateSons(int greedyTime, Cost* matrix,State* open, State* father);
    bool isSolution(State* state);
};