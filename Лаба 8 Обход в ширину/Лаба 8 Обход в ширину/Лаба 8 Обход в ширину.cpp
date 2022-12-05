#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue> 
#include <locale.h>
#include <time.h>
using namespace std;
void BFS(int** G, int* visited, int num, int N) {
	queue <int> q; 
	int i;
	q.push(num); //помещаем вершину исходную в очередь
	visited[num] = 1; // отмечаем вершину как посещенную 
	while (!q.empty()) {  // пока очередь не пуста, выполняем
		num = q.front();  // устанавливаем текущую вершину 
		q.pop(); // удаляем первый элемент из очереди 
		printf("%d ", num); 
		for (i = 0; i < N; i++) {
			if (visited[i] == 0 && G[num][i] == 1) {
				q.push(i); // помещаем в очередь i
				visited[i] = 1; // отмечаем вершину как посещенную
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
	//mass = (int*)malloc(N * sizeof(int));
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
		int* visited = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++) {
			visited[i] = 0;
		}
		printf("Введите вершину: ");
		scanf("%d", &N);
		BFS(a, visited, N, len);
	}


