#include <iostream>
#include "binarySearch.h"
#include "SolutionDS.h"
#include "offer.h"
int main() {

    MinStack a;
    a.push(0);
    a.push(1);
    a.push(0);
    a.min();
    a.pop();
    int b = a.min();

    return 0;
}
