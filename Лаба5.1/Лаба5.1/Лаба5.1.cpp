#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Rus");
    system("cls");
    srand(time(NULL));
    int N;
    int kolReber = 0;
    int x = 0;
    printf("Введите количество вершин: ");
    scanf("%d", &N);
    int kolvershin = N;
    int* d = new int[N];
    int** G = new int* [N];

    for (int i = 0; i < N; i++) {
        G[i] = new int[N];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < kolvershin; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else if (i != j) {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < kolvershin; j++) {
            if (G[i][j] != 0) {
                x = x + 1;
            }
            printf("%d ", G[i][j]);
        }
        d[i] = x;//заполняем нулями диагональ
        x = 0;
        printf("\n");
    }
    printf("\n");
    //Характеристика построенного графа
    for (int i = 0; i < N; i++) {
        if (d[i] == 0) {
            printf("Изолированная вершина: %d\n", i + 1);
        }
        if (d[i] == 1) {
            printf("Концевая вершина: %d\n", i + 1);
        }
        if (d[i] == N - 1) {
            printf("Доминирующая вершина: %d\n", i + 1);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i; j < kolvershin; j++) {
            if (G[i][j] != 0) {
                kolReber++;
            }
        }
    }
    printf("Колличество ребер графа (Размер графа): %d\n", kolReber);
    getchar();
}