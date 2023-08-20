#include "stack.h"

void STInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void STDestroy(Stack* ps)
{
	assert(ps);
	
	ps->capacity = ps->top = 0;
	free(ps->a);
	ps->a = NULL;
}

void STPush(Stack* ps, STDataType x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top++] = x;
}

void STPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType STTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}