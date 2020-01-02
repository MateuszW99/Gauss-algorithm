#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix(std::string& fileName);

	// Glowna macierz rozszerzona
	std::vector<std::vector<double>> matrix;
	
	void print() const;
	void restoreMatrix();

private:
	// Kopia, ktora przywraca po kazdym rozwiazanu rownan
	// matrix do stanu po inicjalizacji obiektu
	std::vector<std::vector<double>> matrixCopy;

	void readMatrix(std::string& fileName);
};
