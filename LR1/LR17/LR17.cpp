// LR17.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

struct node 
{
	int info;
	node *l, *r; 
};

node *tree = NULL;

void push(int a, node **t)
{
	if ((*t) == NULL) 
	{
		(*t) = new node; 
		(*t)->info = a; 
		(*t)->l = (*t)->r = NULL; 
		return;
	}
	if (a > (*t)->info) push(a, &(*t)->r); 
	else push(a, &(*t)->l);
}

void print(node *t, int u)
{
	if (t == NULL) return; 
	else 
	{
		print(t->l, ++u); 
		for (int i = 0; i < u; ++i) std::cout << "/";
		std::cout << t->info << std::endl; 
		u--;
	}
	print(t->r, ++u); 
}

int main()
{
	int n;
	int m;
	std::cout << "n =  ";
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		std::cout << "m=";
		std::cin >> m;

		push(m, &tree);
	}
	std::cout << "Result:\n";
	print(tree, 0);
	std::cin.ignore().get();
}

