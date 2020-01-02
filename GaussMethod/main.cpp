#include <iostream>
#include "Gauss.h"

int main()
{
	std::string name = "test.csv";

	bool run = true;
	while (run)
	{
		std::cout << "Menu:\n"
			<< "1. Podstawowa metoda eliminacji Gaussa\n"
			<< "2. Metoda eliminacji Gaussa z wyborem elementu podstawowego w wierszu\n"
			<< "3. Metoda eliminacji Gaussa z wyborem elementu podstawowego w kolumnie\n"
			<< "4. Metoda eliminacji Gaussa z pe³nym wyborem elementu podstawowego\n"
			<< "5. Wyjscie\n";
		int choice;
		std::cout << "Wprowadz opcje: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			Gauss gauss(name);
			gauss.basicElimination();
			std::cout << '\n';
			break;
		}
		case 2:
		{
			Gauss gauss(name);
			gauss.swapRowsElimination();
			std::cout << '\n';
			break;
		}
		case 3:
		{
			Gauss gauss(name);
			gauss.swapColumnsElimination();
			std::cout << '\n';
			break;
		}
		case 4:
		{
			Gauss gauss(name);
			gauss.completeElimination();
			std::cout << '\n';
			break;
		}
		case 5:
		{
			run = false;
			break;
		}
		default:
		{
			std::cout << "Nie istnieje taka opcja.\n";
			break;
		}
		}
	}
}