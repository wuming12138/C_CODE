#include "SList.h"

void test1()
{
	SListNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);

	SListPrint(phead);

	SListPopFront(&phead);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPrint(phead);

	SListPopFront(&phead);
	SListPrint(phead);

	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);
	SListPrint(phead);



	SListInsertAfter(SListFind(phead, 3), 50);
	SListPrint(phead);

	SListInsertAfter(phead, 100);
	SListPrint(phead);

	SListEraseAfter(SListFind(phead, 3));
	SListPrint(phead);

	SListEraseAfter(phead);
	SListPrint(phead);

	SListEraseAfter(phead);
	SListPrint(phead);

	SListEraseAfter(phead);
	SListPrint(phead);

	SListEraseAfter(phead);
	SListPrint(phead);


}

int main()
{
	test1();
	return 0;
}