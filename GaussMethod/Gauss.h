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
	void simpleSolution();
	void printSimpleSolution() const;

	static double E;

private:
	bool isZero(const float) const;
	void zeroDiagonal();
	void backSubstitution();
};