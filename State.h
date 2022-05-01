#include <iostream>
#include <stdlib.h>

using namespace std;

class State{
private: 

public: 
    int* busyCpu;
    int size;
    int time; 
    int current;
    bool* visited;
    State();
    State(int size, int current);
    State(int size, int current, int* array, bool* visited);
    int* generateArrayState(int size);
    int* copyArray(int* array, int size);
    bool* generateVisitedArray(int size);
    State* next;
    

};
