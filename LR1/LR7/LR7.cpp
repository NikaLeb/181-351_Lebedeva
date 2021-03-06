// LR7.cpp ДИНАМИЧЕСКОЕ ВЫДЕЛЕНИЕ ПАМЯТИ
//

#include "pch.h"
#include <iostream>
using namespace std;
class matrix
{
protected:
	int * matr = new int[rows*columns];
	int rows, columns;
	int *res = new int[rows*columns];
public:
	matrix();
	~matrix();

	bool summMatrix(matrix matr2);
	bool multMatrix(matrix matr2);

	int getElem(int row, int col);
	int getRows() { return rows; }
	int getColumns() { return columns; }

	bool input();
	void transp();
	void kMult(int k);
	void printM()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << matr[i*columns + j] << "\t";
			}
			cout << endl;
		}
	};

};

class  vector :public matrix
{
private:
	//int *vec = new int[n];
	//int n;
public:
	vector();
	~vector();
	/*
	int getN() { return n; }
	int getEl(int i);
	bool enter();
	void kvec(int k)
	{
		for (int i = 0; i < n; i++)
		{
			vec[i] *= k;
			cout << vec[i] << ' ';
		}
	};

	*/
	bool multvec(matrix vec2);
};

vector::vector() {}
vector::~vector() {}



int main()
{
	matrix matrA, matrB;
	//vector vec1, vec2;
	matrA.input();
	matrB.input();
	matrA.printM();
	//matrA.transp();
	//matrA.summMatrix(matrB);
	//matrA.multMatrix(matrB);
	//vec1.input();
	//vec1.kMult(2);
	//vec2.input();
	//vec1.multvec(vec2);
	//vec2.input();
	//vec1.multvec(vec2);

	return 0;
}

matrix::matrix() {}
matrix::~matrix() { /*delete [] matr;*/ }

bool matrix::summMatrix(matrix matr2)
{
	if (rows == matr2.getRows() && columns == matr2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i*columns + j] += matr2.getElem(i, j);
			}
		}
		printM();
		return true;
	}
	else
	{
		cout << "columns and rows are not equal";
		return false;
	}
}

void matrix::transp()
{
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << matr[j * columns + i] << " ";
		}
		cout << endl;
	}

}

void matrix::kMult(int k)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			matr[i*columns + j] *= k;
		}
	}
	printM();
}

bool matrix::multMatrix(matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				int sum = 0;
				for (int k = 0; k < columns; k++) {
					sum += matr[i*columns + k] * matr2.getElem(k, j);
				}
				res[i*matr2.getColumns() + j] = sum;
			}
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr2.getColumns(); j++)
			{
				cout << res[i*matr2.getColumns() + j] << "\t";
			}
			cout << endl;
		}
		return true;
	}
	else
	{
		cout << "col1 != row2";
		return false;
	}
}

int matrix::getElem(int row, int col)
{
	if (row<rows && col<columns && row>-1 && col>-1)
	{
		return matr[row*columns + col];
	}
	else
	{
		cout << "error";
		return -1;
	}
}

bool matrix::input()
{
	cout << "rows=";
	cin >> rows;
	cout << "columns=";
	cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cin >> matr[i*columns + j];
		}
		cout << endl;
	}
	return true;
}

bool vector::multvec(matrix vec2)
{
	int scal = 0;
	if (columns == vec2.getColumns())
	{
		for (int i = 0; i < columns; i++)
		{
			scal += matr[i] * vec2.getElem(0, i);
		}
		cout << scal;
		//delete[]vec;
		return true;
	}
	else { return false; }
}
/*
//int arr[11][12] = {0}; - в таком объявлении ТОЛЬКО КОНСТАНТНЫЕ РАЗМЕРНОСТИ
// Стековая память ограничена, при неправильном использовании стек переполняется {steck overflow}
//размерности массивов, выделяемых в стековой памяти, фиксированы и задаются константами
// int b[1000][1000] = {0}; - ПЕРЕПОЛНЕНИЕ СТЕКА

//для использования свободной памяти ОС (heap - "куча")
//объявляются динамические переменные по синтаксису указатель_на_тип имя_переменной = new тип;
//или
// тип * имя_переменной = new тип;
//работа с динамической памятью происходит через указатели

//ПРЕИМУЩЕСТВА
//1) достаточно гораздо больше памяти, нежели в стеке
//2) размеры массивов и структур данных можно определять или менять во время работы приложения

// ОСОБЕННОСТЬ
// Если прилодение предназначено для длительной работы, во избежание переполнения памяти
//созданные переменные и блоки памяти после использования
//должны быть освобождены с помощью оператора delete:
// delete имя переменной;

int * ptr_int = new int; //в нераспределенной памяти создается блок
//размером с int и указатель на него возвращается в переменную ptr_int

//вызов утечки памяти

for (int i = 0; i < 10000; i++)
{
	long long * b = new long long
		//1) каждый заход в стеке создается новый указатель
		//2) выделяется блок new long long; в куче (нераспределенной памяти), приписанный к этой программе
		//3) стековая переменная b исчезает
		//4) блок по-прежнему остается там же
		//5) при следующем заходе выделяется новый блок 
		delete b; //удалить блок памяти, пока не потеряли указатель на нее
	//пара операторов new/delete -- это одно из нововведений С++ относительно С


	//в динамической памяти могут выделяться только одномерные массивы
	// тип * имя_указателя = new тип[длина];
	//удаляются одномерные массивы с помощью записи 
	// delete[] имя указателя;

	int * matr = new int[l1 * l2];
	for (int row = 0; row < l2; row++)
	{
		for (int col = 0; col < l1; col++)
		{
			matr[row*l1 + col] = row * l1 + col;
		}
	}


	for (int row = 0; row < l2; row++)
	{
		for (int col = 0; col < l1; col++)
		{
			cout << matr[row*l1 + col] << "\t";
		}
	}






	//для выделения двумерного массива сначала создается одномерный массив, содержащий указатели на другие массивы (строки)
	//Можем задавать размерность переменным
	int ** dynamic2Darray = new int *[l1];


}
*/
//dynamic_matrix::dynamic_matrix() {}
//dynamic_matrix::~dynamic_matrix() {}


/*bool dynamic_matrix::input()
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


	int  **matr = new int*[rows];
	for (int i = 0; i < rows; i++) {
		{
			matr[i] = new int[columns];
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
}
*/
/*bool dynamic_matrix::input()
{
	std::cout << "rows=";
	std::cin >> rows;
	std::cout << "columns=";
	std::cin >> columns;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i*columns + j];
		}
		std::cout << std::endl;
	}
	return true;
}

bool dynamic_matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matr[i*j] << "\t";
		}
		std::cout << std::endl;
	}
	return true;
}


bool dynamic_matrix::multMatrix(dynamic_matrix matr1)
{
	int *matr3 = new int[matr1.columns*rows];
	if (rows == matr1.columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < matr1.columns; j++)
			{
				int lm = 0;
				for (int k = 0; k < rows; k++)
				{
					lm += matr[i*k] * matr1.matr[k*j];
				}
				matr[i*j] = lm;
			}
		}
		std::cout << std::endl << "Done" << std::endl;
		return true;
	}
	else
	{
		std::cout << std::endl << "Error" << std::endl;
		return false;
	}
}
/*
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
*/