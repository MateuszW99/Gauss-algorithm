#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix(std::string& fileName);

	std::vector<std::vector<double>> matrix;
	

	void print() const;

private:
	std::vector<double> complementaryMatrix;

	void readMatrix(std::string& fileName);
};
