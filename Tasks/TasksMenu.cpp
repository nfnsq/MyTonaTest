#include "TasksMenu.h"

int MenuItem()
{
	int correct = -1;
	int variant;
	while (correct < 0)
	{
		std::cout << "Select the task. Enter task number: from 1 to 5, 6 - for exit\n" << std::endl;
		std::cout << "1. Task 1\n"
			<< "2. Task 2\n"
			<< "3. Task 3\n"
			<< "4. Task 4\n"
			<< "5. Task 5\n"
			<< "6. Exit\n" << std::endl;
		std::cout << ">>> ";
		try
		{
			std::cin >> variant;
			if (!std::cin)
			{
				throw - 1;
			}
			else if (variant < 1)
			{
				throw - 2;
			}
			else if (variant > 6)
			{
				throw - 3;
			}
			correct = 1;
		}
		catch (int a)
		{
			system("cls");
			if (a == -1) {
				std::cout << "Value must be numeric.\n"
					<< "Try again...\n" << std::endl;
				std::cin.clear();
				std::cin.ignore();
			}
			if (a == -2) {
				std::cout << "The digit must be more than 0.\n"
					<< "Try again...\n" << std::endl;
			}
			if (a == -3) {
				std::cout << "The digit must be less than 7.\n" 
					<< "Try again...\n" << std::endl;
			}
		}
		catch (...)
		{
			system("cls");
			std::cout << "Unexpected exception.\n"
				<< "Try again...\n" << std::endl;
		}
	}
	return variant;
}