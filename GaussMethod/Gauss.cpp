#include "Gauss.h"
#include <iomanip> 

Gauss::Gauss(std::string& fileName)
{
	equations = new Matrix(fileName);
}

Gauss::~Gauss()
{
	delete equations;
}

void Gauss::simpleSolution()
{
	for (int i = 1; i < equations->matrix.size(); ++i)
	{
		float calculatedConstant = 0.0;
		for (int j =  i + 1; j < equations->matrix.size(); ++j)
		{
			calculatedConstant = equations->matrix[j][i] / equations->matrix[i][i];
			//std::cout << equations->matrix[j][i] << '\n';
			equations->matrix[i][j] /= (calculatedConstant * equations->matrix[i][j]);
			for (int k = 0; k < equations->matrix.size(); ++k)
			{
				equations->matrix[j][k] -= (calculatedConstant * equations->matrix[i][k]);
				//std::cout << equations->matrix[j][k] << '\n';
				if (k == equations->matrix.size() - 1)
				{
					//std::cout << equations->matrix[j][k] << '\n';
				}
			}
		}
	}
}

void Gauss::printSimpleSolution() const
{
	for (auto row = equations->matrix.begin(); row < equations->matrix.end(); ++row)
	{
		std::cout << "X = " <<*(row->end() - 1) << '\n';
	}
}
