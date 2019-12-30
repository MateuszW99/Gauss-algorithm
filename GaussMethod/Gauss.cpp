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

void Gauss::chooseRowSolution()
{
	float max = 0;
	int columnIndex = 0;
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			columnIndex = i;
			max = std::fabs(equations->matrix.at(i).at(i));
			for (unsigned j = i; j < equations->matrix.at(i).size(); ++j)
			{
				if (std::fabs(equations->matrix.at(i).at(j) > max))
				{
					max = std::fabs(equations->matrix.at(i).at(j));
					columnIndex = j;
				}
			}
			if (columnIndex != i)
			{
				swapRows(columnIndex, i);
			}
			if (isZero(equations->matrix.at(i).at(i)))
			{
				std::cout << "Znaleziono 0 na przekatnej macierzy\n";
			    return;
			}
			for (unsigned j = i + 1; j < equations->matrix.size(); ++j)
			{
				float calculatedConst = equations->matrix.at(j).at(i) / equations->matrix.at(i).at(i);
				for (unsigned k = i; k < equations->matrix.at(i).size(); ++k)
				{
					equations->matrix.at(j).at(k) -= (calculatedConst * equations->matrix.at(i).at(k));
				}
			}
		}

		backSubstitution();
	}
	catch (std::exception e)
	{
		std::cout << "chooseRowSolution(): " << "1" << e.what();
	}
}


void Gauss::swapRows(const int index1, const int index2)
{
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			std::swap(equations->matrix.at(i).at(index1), equations->matrix.at(i).at(index2));
		}
		std::cout << "index1: " << index1 << ", index2: " << index2 << '\n';
		//std::swap(equations->matrix.at(index1).at(equations->matrix.size()), equations->matrix.at(index2).at(equations->matrix.size()));
	}
	catch (std::exception e)
	{
		std::cout << "chooseRowSolution(): " << "2" << e.what();
	}
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
	std::cout << std::setprecision(4);
	std::cout << "Rozwiazania:\n";
	for (unsigned i = 0; i < solution.size(); ++i)
	{
		std::cout << "X" << i + 1 << " = " << solution[i] << '\n';
	}
}