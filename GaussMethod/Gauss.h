#pragma once
#include "Matrix.h"
#include <string>
#include <iostream>

class Gauss
{
public:
	Gauss()
	{
		std::cout << "Podaj nazwe pliku: ";
		std::string nazwa;
		std::cin >> nazwa;
		matrix = new Matrix(nazwa);
		matrix->print();
	}

	~Gauss()
	{
		delete matrix;
	}


private:
	Matrix* matrix = nullptr;
};