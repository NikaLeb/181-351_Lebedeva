// LR3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>




//Шифр Цезаря.
/*void print_array(char arr[6])
{
	for (int iter = 0; iter < 6; iter++)
	{
		std::cout << arr[iter];
	}
	std::cout << std::endl;
}
int* input_array()
{
	int arr[10] = { 0 };
	for (int iter = 0; iter < 6; iter++)
	{
		std::cin >> arr[iter];
	}
	return arr;
}
*/
//Шейкерная сортировка
/*void func(int *arr, int i)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = temp;
}

void Shake(int *arr, int size)
{
	int left = 1;
	int right = size - 1;
	while (left <= right)
	{
		for (int i = right; i >= left; i--)
			if (arr[i - 1] > arr[i]) func(arr, i);
		left++;

		for (int i = left; i <= right; i++)
			if (arr[i - 1] > arr[i]) func(arr, i);
		right--;
	}
}



int main()
{ //Цезарь.
	/*char str[10] = { 0 };

	for (int iter = 0; iter < 6; iter++)
	{
		std::cin >> str[iter];
	}

	print_array(str);




	int k = 3;
	int c = 0;
	for (int iter = 0; iter < 6; iter++)
	{
		c = str[iter] + k;
		if (c > 122)
		{
			c = c - 26;
		}
		str[iter] = char(c);
	}

	print_array(str);
	*/

	// Сортировка пузырьком.
	/*const int n = 7;
	int arr[n] = { 4, 3, 7, 2, 9, 0, 1 };
	int t;

	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	for (int k = 0; k < n - 1; k++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
			}
		}
	}
		for (int i = 0; i < n; i++)
		{
			std::cout << arr[i] << " ";
		}
		*/
	//Шейкер.
	/*int size = 0;
	std::cout << "Size:";
	std::cin >> size;
	int *A = new int[size];

	std::cout << "Sort-1: ";
	for (int j = 0; j < size; j++)
	{
		A[j] = size - j;
		std::cout << A[j] << " ";
	}
	Shake(A, size);
	std::cout << "\nSort-2: ";
	for (int j = 0; j < size; j++)
	{
		std::cout << A[j] << " ";
	}

	std::cout << std::endl;

		return 0;
}
*/