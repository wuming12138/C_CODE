#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}Stack;

void STInit(Stack *ps);
void STDestroy(Stack *ps);
void STPush(Stack *ps, STDataType x);
void STPop(Stack *ps);
STDataType STTop(Stack* ps);



