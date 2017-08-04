#include "TasksMenu.h"
#include "Header.h"

int main()
{
	while (true)
	{
		system("cls");
		int variant = MenuItem();

		switch (variant) {
		case 1:
			std::cout << "Reverse string..." << std::endl;
			task1();
			break;
		case 2:
			std::cout << "Array..." << std::endl;
			task2();
			break;
		case 3:
			std::cout << "URL info..." << std::endl;
			task3();
			break;
		case 4:
			std::cout << "Working with a file..." << std::endl;
			task4();
			break;
		case 5:
			std::cout << "Matrix-vector multiplication..." << std::endl;
			task5();
			break;
		case 6:
			std::cout << "Exit..." << std::endl;
			exit(EXIT_SUCCESS);
			break;
		default:
			std::cerr << "Incorrect option selected." << std::endl;
			exit(EXIT_FAILURE);
			break;
		}
	}
	return 0;
}

