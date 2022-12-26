#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#define HEADER ("Курсовая работа\nТема: Алгоритм Форда - Беллмана.\nВыполнил: студент группы 21ВВ2 Хабибулин А.М.\n")
#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <queue>
#define inf 10000; //превосходит все возможные значения путей

using namespace std;

int** Matrix,  **Vis, n, puti[1000], e, x; //n-кол-во вершин, e-кол-во ребер

struct Edges {
	int v, u, w;
};
Edges edge[10000];

int SizeOfMatrix() {

	int n;
	cout << "Введите размер >> " << " ";
	cin >> n;
	return n;

}

int* FordBellman(int start) // функция алгоритм Форда-Беллмана
{
	for (int i = 0; i < n; i++)
	{
		puti[i]= inf;
	}
	puti[start]= 0;

	for (int i = 0; i < n; i++) 
	{
		x = 0;
		bool stop = false;
		for (int j = 0; j < e; j++)
			if (puti[edge[j].v] + edge[j].w < puti[edge[j].u]) {
				puti[edge[j].u] = puti[edge[j].v] + edge[j].w;
				x = edge[j].u;
				stop = true;
			}
		if (!stop) break;
	}

	if (x != 0) {
		cout << " Ошибка, найден отрицательный цикл" << endl;
	}
	else {
		//cout << "Кратчайшие расстояния от вершины : " << endl;
		printf("Кратчайшие расстояния от нее: ",&n);
		for (int i = 0; i < n; i++) {

			cout << puti[i] << " ";
		}

		cout << endl;
	}

	return puti;
}

int** createMatrix() // функция создания матрицы
{  
	int** M = (int**)(malloc(n * sizeof(int*))); // выделение памяти под матрицу 
	for (int i = 0; i < n; i++)
	{
		M[i] = (int*)(malloc(n * sizeof(int)));
		for (int j = 0; j < n; j++)
		{
			M[i][j] = 0; // заполнение матрицы 0
		}
	}
	return M;
}

void printMatrix(int** Matrica) //функция вывода матрицы на экран
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Matrica[i][j] == SHRT_MAX)
			{
				cout << NULL << " ";
			}
			else
			{
				cout << Matrica[i][j] << " ";
			}
		}
		cout << endl;
	}
}

void EditMatrix() // функция ручного заполнения матрицы
{
	cout << endl << endl << "Введите расстояния путей между вершинами:" << endl;
	for (int row = 0; row < n; row++) {

		for (int col = 0; col < n; col++) {
			cout << endl << "[" << row + 1 << "] -> [" << col + 1 << "] = ";
			cin >> Matrix[row][col];
		}
	}
	printMatrix(Matrix);
	e = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (Matrix[i][j] != 0) // передача значений в список ребер
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = Matrix[i][j];
				e++;
			}
		}
	}
}

void Edit() // функция рандомного заполнения матрицы
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				Matrix[i][j] = 0;
			}
			else if (rand() % 100 < 50)
			{
				Matrix[i][j] = SHRT_MAX;
			}
			else
			{
				Matrix[i][j] = (rand() % n) + 1;
			}
		}
	}
	e = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (Matrix[i][j] != 0)// передача значений в список ребер
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = Matrix[i][j];
				e++;
			}
		}
	}
}

void Save(int** Matrica, int* puti, int start) // сохранение в файл 
{
	FILE* G = fopen("Graph", "w");
	fprintf(G, "Размерность матрицы: %d\n", n);
	fprintf(G, "Матрица смежности графа:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Matrica[i][j] == SHRT_MAX)
			{
				fprintf(G, " %d ", NULL);
			}
			else
			{
				fprintf(G, " %d ", Matrica[i][j]);
			}
		}
		fprintf(G, "\n");
	}
	if (x != 0) {

		fprintf(G, "Найден отрицательный цикл");
		fclose(G);
		return;
	}
	else {
		for (int i = 0; i < n; i++) {

			if (puti[i] == 10000)
				fprintf(G, "%d -> %d = Пути не существует\n", start, i);
			else {
				fprintf(G, "%d -> %d = %d\n", start, i, puti[i]);

			}
		}
		fclose(G);
	}

	FILE* Gg = fopen("GraphMatrix", "w");
	fprintf(Gg, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (Matrica[i][j] == SHRT_MAX)
			{
				fprintf(Gg, "%d ", NULL);
			}
			else
			{
				fprintf(Gg, "%d ", Matrica[i][j]);
			}
		}
		fprintf(Gg, "\n");
	}
	fclose(Gg);
}

void Read() // чтение из файла
{
	FILE* Gg;
	if (!fopen("Graph", "r"))
	{
		printf("Невозможно открыть файл!\n");
		system("pause");
		return;
	}
	Gg = fopen("GraphMatrix", "r");
	fscanf(Gg, "%d", &n);
	Matrix = createMatrix();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(Gg, " %d ", &Matrix[i][j]);
		}
	}
	fclose(Gg);
	e = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (Matrix[i][j] != 0)// передача значений в список ребер
			{
				edge[e].v = i;
				edge[e].u = j;
				edge[e].w = Matrix[i][j];
				e++;
			}
		}
	}
}

void addVersh() // функция добавления вершины в граф
{
	Matrix = (int**)(realloc(Matrix, (n + 1) * sizeof(int**)));
	for (int i = 0; i < n; i++)
	{
		Matrix[i] = (int*)(realloc(Matrix[i], (n + 1) * sizeof(int)));
	}
	Matrix[n] = (int*)(malloc((n + 1) * sizeof(int)));
	n++;
	for (int i = 0; i < n; i++)
	{
		Matrix[n - 1][i] = 0;
		Matrix[i][n - 1] = 0;
	}
}

void delVersh(int v)
{
	for (int i = v; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Matrix[i][j] = Matrix[i + 1][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = v; j < n - 1; j++)
		{
			Matrix[i][j] = Matrix[i][j + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		Matrix[i] = (int*)(realloc(Matrix[i], (n - 1) * sizeof(int)));
	}
	free(Matrix[n - 1]);
	n--;
}

void menu1() {

	int k, nom;
	do
	{
		system("cls");
		cout << "Редактирование\n1)Заполнение графа\n2)Добавление вершины\n3)Удаление вершины\n4)Назад\n->";
		cin >> k;
		switch (k)
		{
		case(1):

			system("cls");
			cout << "Заполнение матрицы?\n1)Ручное\n2)Автоматическое\n3)Назад\n->";
			cin >> nom;
			if (nom == 1)
			{
				EditMatrix();
			}
			else if (nom == 2)
			{
				Edit();
				system("cls");
				cout << "Успех" << endl;
				system("pause");
			}
			else if (nom == 3)
			{
				return;
			}
			else
			{
				cout << "Ошибка" << endl;
				system("pause");
			}break;

		case(2):

			system("cls");
			addVersh();
			cout << "Успех" << endl;
			system("pause");
			break;

		case(3):

			system("cls");
			cout << "Номер удаляемой вершины >> " << endl;
			cin >> nom;
			if (nom < k)
			{
				delVersh(nom);
			}
			else
			{
				system("cls");
				cout << "Вершины нет" << endl;
				system("pause");
				return;
			}
			break;

		case(4):

			return;

		default:

			system("cls");
			cout << "Ошибка" << endl;
			system("pause");
			break;

		}

	} while (k != 4);

}

void menu()
{
	int k;
	do {
		system("cls");
		cout << "Меню\n1)Создать граф\n2)Редактировать граф\n3)Посмореть граф\n4)Алгоритм Форда - Беллмана\n5)Сохранить результат\n6)Загрузить граф\n7)Выход\n->";
		cin >> k;
		switch (k)
		{
		case(1):

			system("cls");
			n = SizeOfMatrix();
			Matrix = createMatrix();
			Vis  = createMatrix();
			break;

		case(2):

			menu1();
			break;

		case(3):

			system("cls");
			cout << "Матрица смежности:" << endl;
			printMatrix(Matrix);
			system("pause");
			break;

		case(4):
			/*int start;
			cout << "Стартовая вершина >> " << " ";
			cin >> start;*/

			for (int i = 0; i < n; i++) {
				printf("Номер вершины %d  " , i  );
				FordBellman(i);
		
			}
			system("pause");
			break;

		case(5):

			system("cls");
			cout << "Результат сохранён в файл Graph." << endl;
			//Save(Matrix, puti, start);
			system("pause");
			break;

		case (6):

			system("cls");
			Read();
			cout << "Матрица смежности успешно загружена!" << endl;
			system("pause");
			break;

		case(7):

			exit(NULL);

		default:
			system("cls");
			cout << "ошибка" << endl;
			system("pause");
			break;
		}
	} while (k != 7);
}

int main() {

	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << HEADER;
	system("pause");
	menu();
	system("pause");
	return 0;
}