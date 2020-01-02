#include <iostream>
#include "Gauss.h"

int main()
{
	std::string fileName = "test.csv";
	Gauss gauss(fileName);

	bool run = true;
	while (run)
	{
		std::cout << "Menu:\n"
			<< "1. Podstawowa metoda eliminacji Gaussa\n"
			<< "2. Metoda eliminacji Gaussa z zamiana wierszy\n"
			<< "3. Metoda eliminacji Gaussa z zamiana kolumn\n"
			<< "4. Metoda eliminacji Gaussa z pe³nym wyborem elementu podstawowego\n"
			<< "5. Wyjscie\n";
		int choice;
		std::cout << "\nWprowadz opcje: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			gauss.basicElimination();
			std::cout << '\n';
			break;
		}
		case 2:
		{
			gauss.swapRowsElimination();
			std::cout << '\n';
			break;
		}
		case 3:
		{
			gauss.swapColumnsElimination();
			std::cout << '\n';
			break;
		}
		case 4:
		{
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