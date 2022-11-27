﻿#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//void obhod(int num, int* visited, int** M, int dlin) //обход графа в глубину
//{
//	visited[num] = 1;
//	printf("%d ", num);
//	for (int i = 0; i < dlin; i++) {
//		if (M[num][i] == 1 && visited[i] == 0) {
//			obhod(i, visited, M, dlin);
//		}
//	}
//}

void DFS(int num, int* visited, int** M, int dlin)
{
	using namespace std;
	stack <int> s;
	s.push(num);
	visited[num] = 1;
	while (!s.empty())
	{
		int num = s.top();
		s.pop();
		printf("%d ", num);
		for (int i = 0; i < dlin; ++i)
		{
			if (M[num][i] == 1 && visited[i] == 0)
			{
				s.push(i);
				visited[i] = 1;
			}
		}
	}
}


int main(void)
{
	setlocale(LC_ALL, "Rus");
	int** a;
	int N;
	printf("Введите количество вершин: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		int* b = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			b[j] = 0;
		}
		a[i] = b;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j) {
				int num = rand() % 2;
				a[i][j] = num;
				a[j][i] = num;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	int dlin = N;
	int* visited = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		visited[i] = 0;
	}
	printf("Введите вершину, с которой хотите начать обход: ");
	scanf("%d", &N);
	DFS(N, visited, a, dlin);
	getchar();
}

