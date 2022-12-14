// Лабораторная 9 Поиск расстояний.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <queue> 
#include <locale.h>
#include <time.h>
using namespace std;
void BFSD(int** G, int* DIST, int num, int N) {
	queue <int> q;//создаем пустую очередь
	int i;
	q.push(num);// помещаем в очередь вершину
	DIST[num] = 0; // обновляем вектор расстояний
	while (!q.empty()) {
		num = q.front(); // устанавливаем текущую вершину
		q.pop(); // удаляем первый элемент из очереди
		printf("%d ", num); //выводим номер вершины на экран
		for (i = 0; i < N; i++) {
			if (DIST[i] == -1 && G[num][i] == 1) {   // Если вершина не посещенная и есть связь, то помещаем в очередь 
				q.push(i);
				DIST[i] = DIST[num] + 1; //обновляем вектор расстояний
			}

		}
	}
}
int main() {
	setlocale(LC_ALL, "Rus");
	int** a;
	int N;
	printf("Введите N: ");
	scanf("%d", &N);
	a = (int**)malloc(N * sizeof(int*));
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		a[i] = (int*)malloc(N * sizeof(int));
		for (int j = 0; j < N; j++) {
			a[i][j] = 0;
		}
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
	int len = N;
	int* visits = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
		visits[i] = -1;
	}
	printf("Введите вершину: ");
	scanf("%d", &N);
	BFSD(a, visits, N, len); 
	printf("\n");
	printf( "Расстояния от вершины ");
	printf("%d",N);
	printf(" до: ");
	printf("\n");
	
	for (int i = 0; i < len; i++) {
		printf("%d ", i);
		printf("-->");
		printf("%d ", visits[i]);
		printf("\n");
	}
	free(visits);
	free(a);
}

