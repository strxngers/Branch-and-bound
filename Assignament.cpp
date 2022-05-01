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

int Assignament::greedy(Cost* matrix){
    int *array = generateArray(this->lenght);
    
    int time = 0;
    
    for(int i = 0; i < this->lenght; i++){
        int menor = 999;
        int current = -1;
       
        for(int j = 0; j < this->lenght; j++){
            
            if(matrix->getCost(i,j) < menor && array[j] == 0){
                

                menor = matrix->getCost(i,j);
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

State* Assignament::addState(State* head, State* nextHead){
    if(head == NULL){
        return nextHead;
    }else{
        State* aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = nextHead;
        return head;
    }
}

State* Assignament::removeHead(State* head){
    if(head == NULL){
        return NULL;
    }
    else{
        return head->next;
    }
}

bool Assignament::isSolution(State* state){
    for (int i = 0; i < state->size; i++){
        if(state->visited[i] == false){
            return false;
        }
    }
    return true;
}

State* Assignament::generateSons(int greedyTime, Cost* matrix,State* open, State* father){
    int current = father->current;
    
    for(int i = 0; i < father->size; i++){
        
        //si no esa ocupado ni se ha asignado la tarea y el tiempo actual + el tiempo del hijo es menor al tiempo del greedy
        if(father->busyCpu[current] == -1 && father->visited[i] == false && matrix->getValue(current,i) + father->time < greedyTime){
            State* aux = new State(father->size,current + 1,father->busyCpu,father->visited);
            aux->visited[i] = true;
            // se guarda en el array en el procesador current el numero de tarea i
            
            aux->busyCpu[current] = i;
            // se pasa al siguiente procesador
            aux->current = current + 1;
            //se añade el tiempo
            aux->time = father->time + matrix->getCost(current,i);
            open = addState(open,aux);
        }
        else{
            continue;
        }
    }
    return open;
}

void Assignament::Solve(){
    Cost* matrix = new Cost(this->lenght);
    State* open = new State(this->lenght,0);
    State* solution;
    //tiempo base para empezar a podar
    int greedyTime = greedy(matrix);
    cout << "greedy time: " << greedyTime << "\n";
    while (open != NULL){
        //se saca el primero de la lista
        State* aux = open;
        open = aux->next;
        //si es solucion
        if(isSolution(aux) && aux->time <= greedyTime){
            //Crear una condicion si se encuentra una solucion compararlas y elegir
            //la mejor y actualizar el tiempo del greedy
            solution = aux;
            greedyTime = aux->time;
            for(int i = 0 ; i < aux->size; i++){
                cout << aux->busyCpu[i]<< " ";
            }
            cout<<"\n" <<"\n";
            matrix->print();
        }
        //generar los hijos
        else{
            //parte de la cpu actual del estado
            open = generateSons(greedyTime,matrix,open,aux);

        }
    }
    
    //matrix.print();
    cout << greedy(matrix) << "\n";
    cout << greedyTime;
}

