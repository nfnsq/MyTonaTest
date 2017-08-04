#include "Header.h"

int task1()
{
	std::string str = "abcdefghijklmnop";

	std::cout << "Initial string: " << str << std::endl;

	std::reverse(str.begin(), str.end());

	std::cout << "Reversed string: " << str << std::endl;

	system("pause");

	return 0;
}