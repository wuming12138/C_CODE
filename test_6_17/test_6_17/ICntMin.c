#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ISmin.h"
int main()
{
	int count = 0, sum = 0;
	FILE* pd = fopen("datafile01.dat", "r");
	if (pd == NULL)
	{
		return 1;
	}
	FILE* pr = fopen("resultdata.dat", "w");
	if (pr == NULL)
	{
		return 1;
	}
	int* arr = (int*)malloc(sizeof(int));
	while (fscanf(pd, "%d", arr + count) != EOF)
	{
		count++;
		arr = realloc(arr, sizeof(int) * (count + 1));
	}
	sum = ICntMin(arr, count);
	for (int i = 0; i < 20; i++)
	{
		fprintf(pr, "%d\n", arr[i]);
		printf("%d\n", arr[i]);
	}
	fprintf(pr, "%d\n", sum);
	printf("%d\n", sum);

	fclose(pd);
	pd = NULL;
	fclose(pr);
	pr = NULL;
	free(arr);
	arr = NULL;
	return 0;
}