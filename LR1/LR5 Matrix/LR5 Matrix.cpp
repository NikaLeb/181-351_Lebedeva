// LR5 Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


class matrix
{
protected:
	double matr[10][10];
	int rows;
	int columns;
	int vec;
public:

	matrix(); 
	~matrix();

	bool input();
	bool print();
	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);
	bool transp();

	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row < rows && col<columns && row>-1 && col>-1)
		{
			return matr[row][col];
		}
		std::cout << "Index Error\n";
		return -1111111111;
	}
};

class vector : public matrix
{
//private:
	//int vec[10];
	//int n;
public:
	/*int getN() { return n; }
	int getElement(int n);
	bool input();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			std::cout << vec[i] << ' ';
		}
	};*/
	bool multVector(vector vec2);
	//bool summVector(vector vec2);
};




int main()
{
	/*
	//УМНОЖЕНИЕ МАТРИЦ
	///////////////////////////////////////////////////////////////////////////////
	int arr1[3][3];
	int arr2[3][3];
	int arr3[3][3] = { {0} };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> arr1[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cin >> arr2[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				arr3[i][j] += arr1[i][k] * arr2[k][j];
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << arr3[i][j] << "\t";
		
		}
		std::cout << std::endl;
	}
	///////////////////////////////////////////////////////////////////////////////////
	*/
	//matrix matA, matB;
	vector vecA, vecB;
	/*matA.input();
	matB.input();

	matA.print();
	//matB.print();
	//matA.transp();

	//matA.summMatrix(matB);
	matA.multMatrix(matB);
	*/
	//vecA.input();
	vecB.input();
	//vecA.summMatrix(vecB);
	//vecA.multVector(vecB);
	vecB.transp();

	return 0;
}

matrix::matrix() {}
matrix::~matrix() {}


bool matrix::input()
{
	std::cout << "rows:";
	std::cin >> rows;
	if (rows < 1 || rows > 10)
	{
		return false;
	}
	std::cout << "columns:";
	std::cin >> columns;
	if (columns < 1 || columns > 10)
	{
		return false;
	}
	
	

	for (int i = 0; i < rows; i++) {
		{
			for (int j = 0; j < columns; j++)
			{
				std::cin >> matr[i][j];
			}
		}
	}
	return true;
}


bool matrix::print()
{ 
	for (int n = 0; n < rows; n++)
	{
		for (int m = 0; m < columns; m++)
		{
			std::cout << matr[n][m]<<"\t";
		}
		std::cout << std::endl;
	}
	return true;
}


bool matrix::multMatrix(matrix matr2)
{
	int resultMultMatrix[10][10];

	if (columns == matr2.getRows())
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				int tab = 0;
				for (int k = 0; k < matr2.getColumns(); k++)
				{
					tab += matr[i][k] * matr2.getElem(k, j);
				}
				resultMultMatrix[i][j] = tab;
			}
		}
		print();
		return true;
	}
	else return false;
}

bool matrix::summMatrix(matrix matr2)
{
	int resultSummMatrix[10][10];

	if ((rows == matr2.getRows()) && (columns == matr2.getColumns()))
	{

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
			}
			print();
		}
		return true;
	}

	else
	{
		return false;
	}
}


bool matrix::transp()
{
	int a;
	if (rows != columns)
	{
		a = rows;
		rows = columns;
		columns = a;
	}
	int b = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = i; j < columns; j++) {
			b = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = b;
		}
	}
	return true;
}
/*int vector::getElement(int n)
{
	if (n < 10 && n>-1) { return vec[n]; }
	else
	{
		std::cout << "error";
		return -1;
	}
}*/

/*bool vector::input()
{
	std::cout << "columns=";
	std::cin >> n;
	if (n < 1 || n>10) 
	{
		return false;
	}
	for (int j = 0; j < n; j++)
	{
		std::cin >> vec[j];
	}
	return true;
}
*/
/*bool vector::multVector(vector vec2)
{
	int scal = 0;
	if (columns = vec2.getColumns()) {
		for (int i = 0; i < columns; i++)
		{
			scal += matr[0][i] * vec2.getElem(0, i);
		}
		std::cout << scal;
	}
	else { return false; }
}*/

bool vector::multVector(vector vec2)
{
	int scal = 0;
	if (columns = vec2.getColumns()) {
		for (int i = 0; i < columns; i++)
		{
			scal += matr[0][i] * vec2.getElem(0, i);
		}
		std::cout << scal;
	}
	else { return false; }
}