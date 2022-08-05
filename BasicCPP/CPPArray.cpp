


#include<iostream>
#include<array>

int main()
{
	std::array<int, 4> arr = { 1, 3, 2, 4 };
	std::cout << "arr values:" << std::endl;
	for (auto it = arr.begin(); it != arr.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cin.get();
	return 0;
}
