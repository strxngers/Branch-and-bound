#include "Cost.h"

int main() {
    Cost c(20);
    cout << "Cost matrix:" << endl;
    c.print();
    c.generateCost();
    cout << "New cost matrix:" << endl;
    c.print();
    return 0;
}