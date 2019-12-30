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
	void swapRows();
	void swapColumns();
	void completeElimination();

private:
	static double E;

	bool isZero(const float) const;
	void zeroDiagonal();
	void backSubstitution();
};