#pragma once
#include "Matrix.h"
#include <string>
#include <iostream>

class Gauss
{
public:
	Gauss(std::string& fileName);
	~Gauss();

	Matrix* equations = nullptr;

	void basicElimination();
	void swapRowsElimination();
	void swapColumnsElimination();
	void completeElimination();

private:
	static double E;

	bool isZero(const double) const;
	void backSubstitution();
	void substractRows(const int);
	void swapRows(const int, const int);
	void swapColumns(const int, const int);
	void printSolutions(const std::vector<double>&) const;
};