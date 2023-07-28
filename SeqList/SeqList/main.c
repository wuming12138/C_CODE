#include <stdio.h>
#include "SeqList.h"

void test1(SeqList* SL)
{

	SeqListInit(&SL);

	
	SeqListPushBack(&SL, 1);
	SeqListPushBack(&SL, 2);
	SeqListPushBack(&SL, 3);
	SeqListPushBack(&SL, 4);
	SeqListPushBack(&SL, 4);
	SeqListPushBack(&SL, 4);
	SeqListPushBack(&SL, 4);
	SeqListPrint(&SL);
	printf("≤È’“%d\n", SeqListFind(&SL, 4));

	SeqListInsert(&SL, 3, 55);
	SeqListPrint(&SL);

	SeqListErase(&SL, 3);
	SeqListErase(&SL, 3);
	SeqListErase(&SL, 3); 
	SeqListErase(&SL, 3);
	SeqListErase(&SL, 0);
	SeqListErase(&SL, 0);
	SeqListErase(&SL, 0);
	SeqListErase(&SL, 0);
	SeqListPrint(&SL);

	SeqListInsert(&SL, 0, 55);
	SeqListPrint(&SL);


	//SeqListPopBack(&SL);
	//SeqListPopBack(&SL);
	//SeqListPopBack(&SL);
	//SeqListPopBack(&SL);
	//SeqListPopBack(&SL);
	//SeqListPopBack(&SL);
	//SeqListPrint(&SL);

	//SeqListPushBack(&SL, 55);
	//SeqListPrint(&SL);

	//SeqListPushFront(&SL, 1);
	//SeqListPushFront(&SL, 2);
	//SeqListPushFront(&SL, 3);
	//SeqListPrint(&SL);

	//SeqListPopFront(&SL);
	//SeqListPrint(&SL);
	//SeqListPopFront(&SL);
	//SeqListPrint(&SL);
	//SeqListPopFront(&SL);
	//SeqListPopFront(&SL);
	//SeqListPopFront(&SL);
	//SeqListPopFront(&SL);
	//SeqListPopFront(&SL);
	//SeqListPrint(&SL);
	//SeqListPushFront(&SL, 1);
	//SeqListPushFront(&SL, 2);
	//SeqListPrint(&SL);


	SeqListDestroy(&SL);
}

int main()
{

	SeqList SL;
	test1(&SL);


	return 0;
}