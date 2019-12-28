#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix(std::string& fileName)
	{
		readMatrix(fileName);
	}

	std::vector<std::vector<float>>& getMatrix() { return matrix; }
	std::vector<float>& getComplementMatrix() { return complementMatrix; }

	void print();


private:
	std::vector<std::vector<float>> matrix;
	std::vector<float> complementMatrix;

	void readMatrix(std::string&);
};
