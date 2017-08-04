#include "Header.h"

int task4()
{
	std::ifstream inputFile("input.txt");
	std::string bufer;
	if (!inputFile.is_open())
	{
		std::cout << "File could not opened." << std::endl;
	}
	else
	{
		while (!inputFile.eof())
		{
			inputFile >> bufer;
			bufer.replace(bufer.find(":"), 1, " ");
			std::cout << bufer << " ";
		}
		std::cout << std::endl;
	}
	inputFile.close();
	system("pause");
	return 0;
}