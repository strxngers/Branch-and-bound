#include "Assignament.h"

Assignament::Assignament(){

}

Assignament::Assignament(int size){
    this->lenght = size;
    this->array = new int [size];

    //this->matrix = Cost(size);
    //this->matrix = Cost(lenght);
}

 

int* Assignament::generateArray(int size){
    int *array = new int[size];
    for (int i = 0; i < size; i++){
        array[i] = 0;
    }
    return array;
    
}

int Assignament::greedy(Cost matrix){
    int *array = generateArray(this->lenght);
    
    int time = 0;
    
    for(int i = 0; i < this->lenght; i++){
        int menor = 999;
        int current = -1;
       
        for(int j = 0; j < this->lenght; j++){
            
            if(matrix.getValue(i,j) < menor && array[j] == 0){
                

                menor = matrix.getValue(i,j);
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
    Cost matrix(this->lenght);
    matrix.print();
    cout << greedy(matrix);
}

