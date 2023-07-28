#include "SList.h"

SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (newnode == NULL)
	{
		perror("malloc error");
		exit(-1);
	}

	newnode->date = x;
	newnode->next = NULL;

	return newnode;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->date);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	newnode->next = *pplist;
	*pplist = newnode;
}

void SListPopFront(SListNode** pplist)
{
	assert(*pplist);

	SListNode* n = (*pplist)->next;
	free(*pplist);
	*pplist = n;
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;

		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}
}

void SListPopBack(SListNode** pplist)
{
	assert(*pplist);
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else 
	{
		SListNode* tail = *pplist;

		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* FindNode = plist;
	while (FindNode)
	{
		if (FindNode->date == x)
		{
			return FindNode;
		}
		FindNode = FindNode->next;
	}
	return NULL;
}

void SListPrintOne(SListNode* plist)
{	
	if(plist != NULL)
		printf("%d\n", plist->date);
	else
		printf("NULL\n");
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	if (pos->next == NULL)
	{
		pos->next = newnode;
	}
	else
	{
		newnode->next = pos->next;
		pos->next = newnode;
	}
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* n = pos->next->next;
	free(pos->next);
	pos->next = n;
}