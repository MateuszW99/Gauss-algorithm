#include "Matrix.h"
#include <istream>
#include <fstream>

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


	for (unsigned i = 0; i < matrixSize + 1; ++i)
	{
		inp >> semicolon;
	}

	float valueForCompelementMatrix;

	for (auto row = matrix.begin(); row < matrix.end(); ++row)
	{
		row->resize(matrixSize);
		for (auto column = row->begin(); column < row->end(); ++column)
		{
			inp >> *column;
			inp >> semicolon;
		}
		inp >> semicolon;
		inp >> valueForCompelementMatrix;
		complementMatrix.push_back(valueForCompelementMatrix);
	}
}

void Matrix::print()
{
	for (auto row = matrix.begin(); row < matrix.end(); ++row)
	{
		for (auto column = row->begin(); column < row->end(); ++column)
		{
			std::cout << *column << " ";
		}
		std::cout << '\n';
	}

	for (auto x : complementMatrix)
	{
		std::cout << x << " ";
	}
}