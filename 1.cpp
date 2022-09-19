#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <Windows.h>

struct student
{
	char famil[20];
	char name[20];
	char facult[20];
	int Nomzach;
};

int main() {
	setlocale(LC_ALL, "Russian");
	struct student p[4];
	struct student search;
	int i,k;

	for (int i = 1; i < 4; i++) {
		printf("%d", i);
		printf("\n Введите фамилию студента: ");
		scanf("%s", &p[i].famil);
		printf(" Введите имя студента: ");
		scanf("%s", &p[i].name);
		printf(" Введите факультет студента: ");
		scanf("%s", &p[i].facult);
		printf(" Введите номер зачетки: ");
		scanf("%d", &p[i].Nomzach);
	}
	for (int i = 1; i < 4; i++)
	{
		printf(" Cтудент % s %s обучается на факультете % s, номер зачётной книжки % d \n ", p[i].famil, p[i].name, p[i].facult, p[i].Nomzach);

	}
	printf("выберите по какому параметру осуществить поиск\n");
	printf("1.По фамилии\n");
	printf("2.По имени\n");
	printf("3.По факультету\n");
	printf("4.По номеру\n");
	scanf("%d",&k);
	switch(k){
	case 1:
		printf("Поиск по фамилии\n");
		scanf("%s",&search.famil);
		for (i = 1; i < 4; i++)
		{
			if (strcmp (p[i].famil, search.famil) == 0)
			{
				printf("Фамилия: %s\n", p[i].famil);
				printf("Имя: %s\n", p[i].name);
				printf("Факультет: %s\n", p[i].facult);
				printf("Номер зач.книжки: %d\n", p[i].Nomzach);
			}
			else
			{
				printf("Информация не найдена\n");
			}
		}
		break;
    case 2:
		printf("Поиск по имени\n");
		scanf("%s",&search.name);
			for (i = 1; i < 4; i++)
		{
			if (strcmp (p[i].name, search.name) == 0)
			{
				printf("Фамилия: %s\n", p[i].famil);
				printf("Имя: %s\n", p[i].name);
				printf("Факультет: %s\n", p[i].facult);
				printf("Номер зач.книжки: %d\n", p[i].Nomzach);
			}
			else
			{
				printf("Информация не найдена\n");
			}
		break;
	case 3:
		printf("Поиск по факультету\n");
		scanf("%s",&search.facult);
		for (i = 1; i < 4; i++)
		{
			if (strcmp (p[i].facult, search.facult) == 0)
			{
				printf("Фамилия: %s\n", p[i].famil);
				printf("Имя: %s\n", p[i].name);
				printf("Факультет: %s\n", p[i].facult);
				printf("Номер зач.книжки: %d\n", p[i].Nomzach);
			}
			else
			{
				printf("Информация не найдена\n");
			}
		}
		break;
    case 4:
		printf("Поиск по номеру зачетки\n");
		scanf("%d",&search.Nomzach);
		for (i = 1; i < 4; i++)
		{
			if (p[i].Nomzach == search.Nomzach)
			{
				printf("Фамилия: %s\n", p[i].famil);
				printf("Имя: %s\n", p[i].name);
				printf("Факультет: %s\n", p[i].facult);
				printf("Номер зач.книжки: %d\n", p[i].Nomzach);
			}
			else
			{
				printf("Информация не найдена\n");
			}
		}
		break;
	default: printf("Ошибка");
			}}
	getchar();
	getchar();
}
