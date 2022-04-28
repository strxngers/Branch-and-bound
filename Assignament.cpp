#include "Assignament.h"

Assignament::Assignament(){}

Assignament::Assignament(int size){
    this->lenght = lenght;
    this->array = new int[lenght]; 
    this->matrix = Cost(lenght);
}

 
Cost Assignament::getCost(){
    return this->matrix;
}

int Assignament::greedy(){
    int *array = new int[this->lenght]; 
    int time = 0;
    for(int i = 0; i < this->lenght; i++){
        int menor = 999;
        int current = -1;
        for(int j = 0; j < this->lenght; j++){
            if(this->matrix.getValue(i,j) < menor && array[j] == 0){
                menor = this->matrix.getValue(i,j);
                current = j;
            }
        }
        array[current] = 1;
        time += menor;
    }
    return time;
}

bool Assignament::isBusy(int position){
    if(this->array[position] == 1){
        return true;
    }else if(this->array[position] == 0){
        return false;
    }else{
        return false;
    }
}

void Assignament::Solve(){
    
}

