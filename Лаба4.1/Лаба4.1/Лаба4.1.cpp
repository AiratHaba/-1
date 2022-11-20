#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data; //данные в узле 
	struct Node* left;//левая нода
	struct Node* right;//правая нода
};

struct Node* CreateTree(struct Node* root, struct Node* r, int data) // функция создания дерева
{
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node)); //динамическое выделение памяти под структуру
		if (r == NULL)
		{
			cout << "Ошибка выделения памяти";
			exit(0);
		}
		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) 
			return r;

		if (data > root->data)	root->right = r;
		else root->left = r;
		return r;
	}

	if (data > r->data)
		CreateTree(r, r->right, data);
	else
		CreateTree(r, r->left, data);

	return root;
}

void print_tree(struct Node* r, int l) //функция вывода дерева
{
	if (r == NULL)
		return;

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
		cout << ("   ");

	cout << r->data << endl;
	print_tree(r->left, l + 1);
}

void search (struct Node* r, int data)	//поиск по заданному элементу
{
	if (r == NULL)
		return;

	if (r->data < data) {
		search (r->right, data);
	}
	else if (r->data > data) {
		search (r->left, data);
	}

	if (r->data == data)
		cout << r->data << endl;
}

int quantity (Node* root, int N)	// подсчет количества элементв в дереве
{
	if (root == 0) return 0;
	return (root->data == N) + quantity(root->left, N) + quantity(root->right, N);
}

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int A, num;
	struct Node* root = NULL;

	cout << "Введите размер дерева: ";
	cin >> A;
	while (A) {
		root = CreateTree(root, root, rand() % 100);
		A--;
	}
	cout << "Дерево построено" << endl << endl;

	print_tree(root, 0);
	cout << endl << "Введите элемент, чтобы определить наличие и количество вхождений в созданное дерево: ";
	cin >> A;
	search (root, A);
	num = quantity (root, A);
	if (num)
		cout << "Кол-во найденных элементов: " << num;
	else
		cout << "Ничего не найдено";
	return 0;
	getchar();
}