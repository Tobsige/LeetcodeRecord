#include <iostream>
#include "binarySearch.h"

int main(int argc, char const *argv[])
{
	Solution a;
	std::vector<int> v = {0, 1, 4, 8};
	int b = a.search(v, 1);
	std::cout << b << std::endl;
	return 0;
}