#include "List.h"

ListNode* ListBuyNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc error");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

ListNode* ListInit()
{
	ListNode* phead = ListBuyNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

void ListDestory(ListNode* pHead)
{
	assert(pHead);

	while (pHead != pHead->next)
	{
		ListPopFront(pHead);
	}
	free(pHead);
}

void ListPrint(ListNode* pHead)
{
	assert(pHead);
	printf("pHead<=>");
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("pHead\n");
}

void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* tail = pHead->prev;
	ListNode* newhead = ListBuyNode(x);

	newhead->next = pHead;
	pHead->prev = newhead;
	tail->next = newhead;
	newhead->prev = tail;
}

void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* tail = pHead->prev->prev;
	free(tail->next);
	tail->next = pHead;
	pHead->prev = tail;
}

void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* first = pHead->next;
	ListNode* newhead = ListBuyNode(x);

	newhead->next = first;
	first->prev = newhead;
	newhead->prev = pHead;
	pHead->next = newhead;
}

void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* second = pHead->next->next;
	free(pHead->next);
	pHead->next = second;
	second->prev = pHead;
}

ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* Prev = pos->prev;
	ListNode* newhead = ListBuyNode(x);
	
	newhead->prev = Prev;
	Prev->next = newhead;
	newhead->next = pos;
	pos->prev = newhead;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	assert(pos != pos->next);

	ListNode* Prev = pos->prev;
	ListNode* Next = pos->next;

	free(pos);
	Prev->next = Next;
	Next->prev = Prev;
}