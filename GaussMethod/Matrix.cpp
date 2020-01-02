#include "Matrix.h"
#include <istream>
#include <fstream>
#include <iomanip>

Matrix::Matrix(std::string& fileName)
{
	readMatrix(fileName);
}

void Matrix::readMatrix(std::string& fileName)
{
	std::ifstream inp (fileName, std::ifstream::in);
	
	char semicolon;

	if (!inp)
	{
		std::cout << "A problem occurred while opening the file.";
		return;
	}

	std::size_t matrixSize;
	inp >> matrixSize;
	matrix.resize(matrixSize);
	std::vector<double> complementaryMatrix;

	for (unsigned i = 0; i < matrixSize + 1; ++i)
	{
		inp >> semicolon;
	}

	float complementaryValue;

	for (auto row = matrix.begin(); row < matrix.end(); ++row)
	{
		row->resize(matrix.size());
		std::vector<double>::iterator column;
		for (column = row->begin(); column < row->end(); ++column)
		{
			inp >> *column;
			inp >> semicolon;
		}
		inp >> semicolon;
		inp >> complementaryValue;	
		complementaryMatrix.push_back(complementaryValue);
	}

	for (unsigned i = 0; i < complementaryMatrix.size(); ++i)
	{
		matrix[i].resize(matrix.size() + 1, complementaryMatrix[i]);
	}

	matrixCopy = matrix;
}

void Matrix::print() const
{
	std::cout << std::setprecision(4);
	for (auto row = matrix.begin(); row < matrix.end(); ++row)
	{
		for (auto column = row->begin(); column < row->end(); ++column)
		{
			std::cout << *column << " ";
		}
		std::cout << '\n';
	}
}

void Matrix::restoreMatrix()
{
	matrix = matrixCopy;
}