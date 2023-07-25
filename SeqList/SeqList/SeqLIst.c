#include "SeqList.h"


void SeqListInit(SeqList* SL)
{
	SL->a = (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (SL->a == NULL)
	{
		perror("malloc error");
		exit(-1);
	}
	SL->size = 0;
	SL->capacity = 4;
}

void SeqListDestroy(SeqList* SL)
{
	free(SL->a);
	SL->a = NULL;
	SL->capacity = SL->size = 0;

}

void SeqListPrint(SeqList* SL)
{
	int i = 0;
	while (i < SL->size)
	{
		printf("%d ", SL->a[i]);
		i++;
	}
	printf("\n");
}

void SeqListPushBack(SeqList* SL, SLDateType x)
{
	if (SL->capacity == SL->size)
	{
		SLDateType* tmp = realloc(SL->a, sizeof(SLDateType) * 2 * SL->capacity);
		if (tmp == NULL)
		{
			perror("realloc error");
			exit(-1);
		}
		SL->a = tmp;
		SL->capacity *= 2;
	}
	SL->a[SL->size] = x;
	SL->size++;
}

void SeqListPopBack(SeqList* SL)
{
	if (SL->size == 0)
		return;

	SL->size--;
}

void SeqListPushFront(SeqList* SL, SLDateType x)
{
	if (SL->capacity == SL->size)
	{
		SLDateType* tmp = realloc(SL->a, sizeof(SLDateType) * 2 * SL->capacity);
		if (tmp == NULL)
		{
			perror("realloc error");
			exit(-1);
		}
		SL->a = tmp;
		SL->capacity *= 2;
	}

	for (int i = SL->size; i > 0; i--)
	{
		SL->a[i] = SL->a[i - 1];
	}
	SL->a[0] = x;

	SL->size++;
}

void SeqListPopFront(SeqList* SL)
{
	if (SL->size == 0)
		return;

	for (int i = 0; i < SL->size - 1; i++)
	{
		SL->a[i] = SL->a[i + 1];
	}

	SL->size--;

}

int SeqListFind(SeqList* SL, SLDateType x)
{
	for (int i = 0; i < SL->size; i++)
	{
		if (SL->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SeqListInsert(SeqList* SL, int pos, SLDateType x)
{
	assert(pos <= SL->size && pos >= 0);
	if (SL->capacity == SL->size)
	{
		SLDateType* tmp = realloc(SL->a, sizeof(SLDateType) * 2 * SL->capacity);
		if (tmp == NULL)
		{
			perror("realloc error");
			exit(-1);
		}
		SL->a = tmp;
		SL->capacity *= 2;
	}

	for (int i = SL->size; i > pos; i--)
	{
		SL->a[i] = SL->a[i - 1];
	}
	SL->a[pos] = x;


	SL->size++;
}

void SeqListErase(SeqList* SL, int pos)
{
	assert(pos <= SL->size && pos >= 0);
	if (SL->size == 0)
		return;

	for (int i = pos; i < SL->size - 1; i++)
	{
		SL->a[i] = SL->a[i + 1];
	}

	SL->size--;
}