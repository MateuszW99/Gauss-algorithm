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

void Gauss::substractRows(const int i)
{
	for (unsigned j = i + 1; j < equations->matrix.size(); ++j)
	{
		if (isZero(equations->matrix.at(i).at(i)))
		{
			std::cout << "\nZnaleziono 0 na przekatnej macierzy\n";
			return;
		}

		double calculatedConst = equations->matrix.at(j).at(i) / equations->matrix.at(i).at(i);
		for (unsigned k = i; k < equations->matrix.at(i).size(); ++k)
		{
			equations->matrix.at(j).at(k) -= (calculatedConst * equations->matrix.at(i).at(k));
		}
	}
}

void Gauss::basicElimination()
{
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			if (equations->matrix.at(i).at(i) == 0)
			{
				std::cout << "\nZnaleziono 0 na przekatnej macierzy\n";
				return;
			}

			substractRows(i);
		}
		backSubstitution();
	}
	catch (std::exception e)
	{
		std::cout << "\nsimpleSolution(): " << e.what() << '\n';
	}
}

void Gauss::swapRowsElimination()
{
	double max = 0;
	int maxElementIndex = 0;
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			maxElementIndex = i;
			max = std::fabs(equations->matrix.at(i).at(i));
			for (unsigned j = i + 1; j < equations->matrix.size(); ++j)
			{
				if (std::fabs(equations->matrix.at(j).at(i) > max))
				{
					max = std::fabs(equations->matrix.at(j).at(i));
					maxElementIndex = j;
				}
			}

			if (max == 0)
			{
				std::cout << "Macierz osobliwa.\n";
				return;
			}

			if (maxElementIndex != i)
			{
				swapRows(maxElementIndex, i);
			}

			substractRows(i);
		}

		backSubstitution();
	}
	catch (std::exception e)
	{
		std::cout << "\nchooseRowSolution(): " <<  "1" << e.what() << '\n';
	}
}

void Gauss::swapColumnsElimination()
{
	double max = 0;
	int maxElementIndex = 0;
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			maxElementIndex = i;
			max = std::fabs(equations->matrix.at(i).at(i));
			for (unsigned j = i + 1; j < equations->matrix.size(); ++j)
			{
				if (std::fabs(equations->matrix.at(i).at(j) > max))
				{
					max = std::fabs(equations->matrix.at(i).at(j));
					maxElementIndex = j;
				}
			}

			if (max == 0)
			{
				std::cout << "Macierz osobliwa.\n";
				return;
			}

			if (maxElementIndex != i)
			{
				swapColumns(maxElementIndex, i);			
			}

			substractRows(i);
		}

		backSubstitution();
	}
	catch (std::exception e)
	{
		std::cout << "\nchooseRowSolution(): " << "1" << e.what() << '\n';
	}
}

void Gauss::completeElimination()
{
	double max = 0;
	int columnIndex = 0;
	int rowIndex = 0;
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			columnIndex = i;
			rowIndex = i;
			max = std::fabs(equations->matrix.at(i).at(i));
			for (unsigned j = i; j < equations->matrix.size(); ++j)
			{
				for (unsigned k = i; k < equations->matrix.size(); ++k)
				{
					if (std::fabs(equations->matrix.at(j).at(k)) > max)
					{
						max = std::fabs(equations->matrix.at(j).at(k));
						columnIndex = k;
						rowIndex = j;
					}
				}
			}

			if (max == 0)
			{
				std::cout << "Macierz osobliwa.\n";
				return;
			}

			if (columnIndex != i)
			{
				swapColumns(columnIndex, i);
			}
			if (rowIndex != i)
			{
				swapRows(rowIndex, i);
			}

			substractRows(i);
		
		}
		backSubstitution();
	}
	catch (std::exception e)
	{
		std::cout << "\ncompleteElimination(): " << e.what() << '\n';
	}
}

void Gauss::swapRows(const int maxElementIndex, const int rowIndex)
{
	try
	{
		for (unsigned i = 0; i < equations->matrix.size() + 1; ++i)
		{
			std::swap(equations->matrix.at(maxElementIndex).at(i), equations->matrix.at(rowIndex).at(i));
		}
	}
	catch (std::exception e)
	{
		std::cout << "\nspawRows(): " << e.what() << '\n';
	}
}

void Gauss::swapColumns(const int maxElementIndex, const int columnIndex)
{
	try
	{
		for (unsigned i = 0; i < equations->matrix.size(); ++i)
		{
			std::swap(equations->matrix.at(i).at(maxElementIndex), equations->matrix.at(i).at(columnIndex));
		}
	}
	catch (std::exception e)
	{
		std::cout << "\nswapColumns(): " << e.what() << '\n';
	}
}

void Gauss::backSubstitution()
{
	std::vector<double> solutions(equations->matrix.size(), 0);
	solutions.at(solutions.size() - 1) = equations->matrix.at(equations->matrix.size() - 1).at(equations->matrix.size()) / equations->matrix.at(equations->matrix.size() - 1).at(equations->matrix.size() - 1);
	try
	{
		for (int i = solutions.size() - 1; i >= 0; --i)
		{
			double sum = equations->matrix.at(i).at(equations->matrix.at(i).size() - 1);

			for (int j = equations->matrix.size() - 1; j >= i + 1; --j)
			{
				if (equations->matrix.at(i).at(i) == 0)
				{
					std::cout << "\nZnaleziono 0 na przekatnej macierzy\n";
					continue;
				}
				sum -= (solutions.at(j) * equations->matrix.at(i).at(j));
				solutions.at(i) = sum / equations->matrix.at(i).at(i);
			}
		}

		printSolutions(solutions);

		equations->restoreMatrix();
	}
	catch (std::exception e)
	{
		std::cout << "\nbackSubstitution(): " << e.what();
	}
}

void Gauss::printSolutions(const std::vector<double>& solutions) const
{
	std::cout << std::setprecision(4) << "\nRozwiazania:\n";
	for (unsigned i = 0; i < solutions.size(); ++i)
	{
		std::cout << "X" << i + 1 << " = " << solutions[i] << '\n';
	}
}

bool Gauss::isZero(const double element) const
{
	if (std::fabs(element) < Gauss::E)
	{
		return true;
	}
	return false;
}

