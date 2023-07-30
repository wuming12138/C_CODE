#include "SList.h"

SListNode* reverseList(SListNode* head) {
	if (head == NULL)
	{
		return NULL;
	}
	else if (head->next = NULL)
	{
		return head;
	}
	else
	{
		SListNode* n1 = NULL;
		SListNode* n2 = head;
		SListNode* n3 = head->next;
		while (n3)
		{
			n2->next = n1;

			n1 = n2;
			n2 = n3;
			n3 = n3->next;
		}
		n2->next = n1;
		return n2;
	}

}

void test1()
{
	SListNode* phead = NULL;
	SListPushFront(&phead, 1);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPrint(phead);
	reverseList(phead);
	SListPrint(phead);
	//slistprint(phead);

	//slistpopfront(&phead);
	//slistprint(phead);

	//slistpopfront(&phead);
	//slistprint(phead);

	//slistpopfront(&phead);
	//slistprint(phead);

	//slistpopfront(&phead);
	//slistprint(phead);

	//slistpushback(&phead, 1);
	//slistpushback(&phead, 2);
	//slistpushback(&phead, 3);
	//slistpushback(&phead, 4);
	//slistprint(phead);



	//slistinsertafter(slistfind(phead, 3), 50);
	//slistprint(phead);

	//slistinsertafter(phead, 100);
	//slistprint(phead);

	//slisteraseafter(slistfind(phead, 3));
	//slistprint(phead);

	//slisteraseafter(phead);
	//slistprint(phead);

	//slisteraseafter(phead);
	//slistprint(phead);

	//slisteraseafter(phead);
	//slistprint(phead);

	//slisteraseafter(phead);
	//slistprint(phead);


}

int main()
{
	test1();
	return 0;
}