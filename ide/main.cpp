#include <iostream>
#include "binarySearch.h"
int main() {

    Solution a;
    std::vector<int> v{1,2,3,4,5,6,7};

    a.rotate(v, 8);
    std::cout << v[0] << std::endl;

    return 0;
}
