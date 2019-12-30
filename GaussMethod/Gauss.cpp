#include "Gauss.h"
#include <iomanip> 

double Gauss::E = 1e-12;

Gauss::Gauss(std::string& fileName)
{
	equations = new Matrix(fileName);
}

Gauss::~Gauss()
{
	delete equations;
}

void Gauss::simpleElimination()
{
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			if (equations->matrix.at(i).at(i) == 0)
			{
				std::cout << "Znaleziono 0 na przekatnej macierzy\n";
				return;
			}
			for (unsigned j = i + 1; j < equations->matrix.size(); ++j)
			{
				float calculatedConst = equations->matrix.at(j).at(i) / equations->matrix.at(i).at(i);
				for (unsigned k = 0; k < equations->matrix.at(i).size(); ++k)
				{
					equations->matrix.at(j).at(k) -= (calculatedConst * equations->matrix.at(i).at(k));
				}
			}
		}
		backSubstitution();
	}
	catch (std::exception e)
	{
		std::cout << "simpleSolution(): " << e.what();
	}
}

void Gauss::printSimpleSolution() const
{
	for (auto row = equations->matrix.begin(); row < equations->matrix.end(); ++row)
	{
		std::cout << "X = " << *(row->end() - 1) << '\n';
	}
}

void Gauss::swapRows()
{

}

void Gauss::swapColumns()
{

}

void Gauss::completeElimination()
{

}





bool Gauss::isZero(const float element) const
{
	if (std::fabs(element) < Gauss::E)
	{
		return true;
	}
	return false;
}

void Gauss::zeroDiagonal()
{
	for (auto row = equations->matrix.begin() + 1; row < equations->matrix.end(); ++row)
	{
		for (auto column = row->begin(); column < row->end(); ++column)
		{
			if (isZero(*column))
			{
				*column = 0;
			}
		}
	}
}

void Gauss::backSubstitution()
{
	std::vector<float> solution(equations->matrix.size(), 0);
	solution.at(solution.size() - 1) = equations->matrix.at(equations->matrix.size() - 1).at(equations->matrix.size()) / equations->matrix.at(equations->matrix.size() - 1).at(equations->matrix.size() - 1);
	try
	{
		for (int i = solution.size() - 1; i >= 0; --i)
		{
			float sum = equations->matrix.at(i).at(equations->matrix.at(i).size() - 1);
			for (int j = equations->matrix.size() - 1; j >= i + 1; --j)
			{
				sum -= (solution.at(j) * equations->matrix.at(i).at(j));
				if (equations->matrix.at(i).at(i) == 0)
				{
					std::cout << "Znaleziono 0 na przekatnej macierzy\n";
					return;
				}
				solution.at(i) = sum / equations->matrix.at(i).at(i);
			}
		}
	}
	catch (std::exception e)
	{
		std::cout << "backSubstitution(): " << e.what();
	}
	std::cout << std::setprecision(2) << std::setw(5);
	std::cout << "Rozwiazania:\n";
	for (unsigned i = 0; i < solution.size(); ++i)
	{
		std::cout << "X" << i + 1 << " = " << solution[i] << '\n';
	}
}