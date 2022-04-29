#include <iostream>
#include <stdlib.h>
#include "Cost.h"
using namespace std;

class Assignament
{
private:
    int lenght;
    int *array;
    

public:
    Assignament();
    Assignament(int lenght);
    int greedy(Cost cost);
    bool isBusy(int position);
    void Solve();
    int* generateArray(int size);

};