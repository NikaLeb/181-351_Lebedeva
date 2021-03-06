// LR11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n"; 
}

/* ЯВНОЕ ДИНАМИЧЕСКОЕ СВЯЗЫВАНИЕ С БИБЛИОТЕКОЙ
{
	//1.Загрузка файла dll в OII

	HINSTANCE hDLL; // ссылка (указатель) на загруженную DLL, которая будет загружаться 

	hDLL = LoadLibrary(L "Lab10 Dll.dll"); //L означает использование 16-битных символов - только для х64
	std::cout << hDLL << std::endl; //проверка, загрузилась ли бмблиотека (0 если нет)

	//2. Поиск в загруженной DLL функции по строковому имени

	FUNC2 fnc2explicit = (FUNC2)GetProcAddress(hDLL, "fnc2"); поиск и возвращение укаателя на функцию

	std::сout << fnc2explicit << std::endl; //проверка, нашлась ли фцнкция (0 если нет)

	std::cout << "FROM explicit DLL:\tfnc2(10, 5) = " << snc2explicit(10, 5) << std::endl;

	   getchar();
	   return 0;
}



#include "pch.h"

#include <Windows.h> //для использование типа CALLBACK, HINSTANCE
//явное связывание - отдается специальная команда на подгрузку dll внутри приложения

typedef int(CALLBACK* FUNC2) double, char); //прототип или объявление функции -  инструкция для компилятора
//в каком порядке и какого размера передавать в стек параметры
//и какой ожидаьб выходной параметр


// _stdcall - компилятор передает параметры в стек по порядку: р1, р2, р3
// _cdecl - компилятор передает параметры в обратном порядке: p1, p2, p3
//CALLBACK - псевдоним для _ stdcall





#pragma once

extern "C" _declspec(dllexpont) int(double p1, char p2);

//extern "C" - директива компилятору не добавлять к имени функции
служебных символов

//_declspec(dllexport) - директива, указывающая, в каком порядке передавать параметры (в круглых скобках)


*/

extern int func1(double p1, char p2);

int main()
{
	std::cout << "From lib " << func1(18, 5) << std::endl;
	return 0;
}

// Включение SDKDDKVer.h обеспечивает определение самой последней доступной платформы Windows.

// Если требуется выполнить сборку приложения для предыдущей версии Windows, включите WinSDKVer.h и
// задайте для макроса _WIN32_WINNT значение поддерживаемой платформы перед включением SDKDDKVer.h.

//#include <SDKDDKVer.h>






























*/