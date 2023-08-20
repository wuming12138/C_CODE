#include "stack.h"

int main()
{
	Stack ST;
	STInit(&ST);
	STPush(&ST, 1);
	STPush(&ST, 2);
	STPush(&ST, 3);
	STPush(&ST, 4);
	STPush(&ST, 5);
	STPop(&ST);
	printf("%d", STTop(&ST));


	return 0;
}