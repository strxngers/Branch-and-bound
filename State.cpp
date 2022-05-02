#include "State.h"

// Constructor 
State::State(){}

State::State(int size, int current){
    this->size = size;
    this->current = current;
    this->time = 0;
    this->busyCpu = generateArrayState(size);
    this->visited = generateVisitedArray(size);
    this->next = NULL;
}

State::State(int size, int current, int* array, bool* visited){
    this->size = size;
    this->current = current;
    this->time = 0;
    this->busyCpu = generateArrayState(size);
    this->next = NULL;
    this->visited = generateVisitedArray(size);
    for(int i = 0; i < size; i++){
        this->visited[i] = visited[i];
        this->busyCpu[i] = array[i];
    }
}

int* State::generateArrayState(int size){
    int *array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = -1;
    }
    return array;
}

bool* State::generateVisitedArray(int size){
    bool *array = new bool[size];
    for (int i = 0; i < size; i++){
        array[i] = false;
    }
    return array;
}

void State::copyArray(int* array, int size){
    int *aux = new int[size];
    for (int i = 0; i < size; i++){
        aux[i] = array[i];
    }
}



