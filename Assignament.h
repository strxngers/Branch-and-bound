#include <iostream>
#include <stdlib.h>
#include "Cost.h"
using namespace std;

class Assignament
{
private:
    int lenght;
    int *array;
    Cost matrix;
    int cpu;
    int process;
    

public:
    Assignament();
    Assignament(int lenght);
    int greedy();
    bool isBusy(int position);
    void Solve();
    Cost getCost();
};