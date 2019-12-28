#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
	Matrix(std::string& fileName);

	//std::vector<std::vector<float>>& getMatrix() { return matrix; }
	//std::vector<float>& getComplementMatrix() { return complementMatrix; }

	std::vector<std::vector<float>> matrix;
	

	void print();

private:
	std::vector<float> complementaryMatrix;

	void readMatrix(std::string& fileName);
};
