#include <iostream>
#include "Gauss.h"

int main()
{
	std::string name = "test3.csv";
	Gauss gauss(name);
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
			gauss.simpleSolution();
			break;
		}
		case 2:
		{
			//
			break;
		}
		case 3:
		{
			//
			break;
		}
		case 4:
		{
			//
			break;
		}
		case 5:
		{
			run = false;
			break;
		}
		}
	}

	//gauss.equations->print();
	
	//std::cout << "Wyniki\n";
	//gauss.equations->print();
}