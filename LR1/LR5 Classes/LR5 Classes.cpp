// LR5 Classes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


//Определение класса и объекта
//Свойство (property) - переменная в составе класса
//Метод - функция в составе класса
//ИНКАПСУЛЯЦИЯ - фактически, объединение

/*class vehicle //игровое транспортное средство
{
private:
public: //доступно в мейне
	double speed; //скорость
	
	char regnumber[6] = { 0 }; //госномер
	unsigned char capacity; //число пассажиров

	bool check_regnumber()
	{
		const char * true_number = "K370AO";
		bool result = true;
	}
	//void add_passenger(int passengers);
	//void accelerate(double delta_velocity);
};
*/
class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];
public:

	user_data();
	~user_data();

	user_data(char * p_first_name[255], char * p_second_name[255], char * p_str_passport[10], char * p_str_birthdate[10]);
	user_data(char * p_first_name[255], char * p_second_name[255]);

	bool set_first_name(char * p_first_name)
	{
		int length = strlen(p_first_name);
		for (int i = 0; i < length; i++) {
			if ((p_first_name[i] < 'A') || (p_first_name[i] > 'Z' &&
				p_first_name[i] < 'a') || (p_first_name[i] > 'z')) {
				if (p_first_name[i] == '-') {
					continue;
				}
				return false;
			}
		}
		arr(p_first_name, first_name);
		return true;
	}
 //проверять на отсутствие цифр, точек и других знаков препинания кроме "-"
};

void arr(char * first_array, char * second_array) {
	int length = strlen(first_array);
	for (int i = 0; i < length; i++) {
		second_array[i] = first_array[i];
	}
}
void print_array_chr(char * arr) {
	int length = strlen(arr);
	for (int i = 0; i < length; i++) {
		std::cout << arr[i];
	}
}
	bool set_second_name(char * p_second_name)
	{
		int length = strlen(p_second_name);
		for (int i = 0; i < length; i++) {
			if (p_second_name[i] < 'A' || (p_second_name[i] > 'Z' &&
				p_second_name[i] < 'a') || p_second_name[i] > 'z') {
				if (p_second_name[i] == '-') 
				{
					continue;
				}
				return false;
			}
		}
		arr(p_second_name, second_name);
		return true;
	};

	bool set_birthdate(char p_birthdate)
	{
		for (int i = 0; i < 10; i++) 
	{
		if (i == 2 || i == 5) {
			if (p_birthdate[i] != '.') {
				return false;
			}
		}
		else if (p_birthdate[i] < '0' || p_birthdate[i] > '9') {
			return false;
		}
		 //должно соответствовать формату "00.00.0000"
		arr(p_birthdate, str_birthdate);
		return true;
		};
	};

	bool set_passport(char p_passport[10])
	{
		for (int i = 0; i < 10; i++) {
			if (p_passport[i] < '0' || p_passport[i] > '9') {
				return false;
			}
		}
		//строка должна содержать 10 цифр
		arr(p_passport, str_passport);
		return true;
	};
		
		 //должно соответствовать формату "0000000000"
	};



//user_data::user_data();
//user_data::~user_data()

//user_data::user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);
//{
	//set_first_name(p_first_name);
	//set_second_name(p_second_name);
	// str_passport = p_str_passport
	// str_birthdate = p_str_birthdate
//}
	

//user_data::user_data(char p_first_name[255], char p_second_name[255]);
	//first_name =  p_first_name
	// second_name = p_second_name


//2. Синтаксис объявления объекта и обращения к свойствам и методам
//Имя_Класса объект1; (В мейне)
//vehicle car;
//cat.speer = 123;
//объект1.свойство1 = 1ж
//объект1.метод3();

//3.СПЕЦИФИКАТОРЫ ДОСТУПА
//К полям (свойствам и методам), объявленным в разделе паблик:
//можно обращаться везде (И из методов класса, и снаружи, где виден объект)
//К полям приват и протектед можно обращаться только из методов
//самого класса. Различие между приват и протектед объясняется в следующей теме


//4. КОНСТРУКТОР И ДЕСТРУКТОР КЛАССА
//В случае, если при создании объекта нужно выполнять сложные действия по
//инициализации, установлению сетевого соединения, действия с файлами
// выделение ОП и т.п. эти действия прописываются в специальном методе - конструкторе
//Конструктор называется автоматически при создании объекта 
//В случае  если при исчезновении объекта


//5. СТРУКТУРА 
//Несмотря на то, что в литературе структура как правило хранит только данные, на самом деле это то же самое, что и класс.
//Единственное отличие - поля по умолчанию паблик 







int main()
{
	char first_name[10];
	bool set_first_name(char p_first_name[10]);
	for (int i = 0; i < 10; i++)
	{
		std::cin >> first_name[i];

		if (true)
		{
			std::cout << "OK";
		}

		else
		{
			
			std::cout << "Error";
		}
	}
	
	
}


