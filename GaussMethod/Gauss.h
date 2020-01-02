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

	void simpleElimination();
	void printSimpleSolution() const;
	void chooseRowSolution();
	void chooseColumnSolution();
	void completeElimination();

private:
	static double E;

	bool isZero(const float) const;
	void zeroDiagonal();
	void backSubstitution();

	void swapRows(const int, const int);
	void swapColumns(const int, const int);
};