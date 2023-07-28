#pragma once
#ifndef __SLIST__
#define __SLIST__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode* plist);
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);
// �������βɾ
void SListPopBack(SListNode** pplist);
// ������ͷɾ
void SListPopFront(SListNode** pplist);
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);
void SListPrintOne(SListNode* plist);
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x);
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos);


#endif // !__SLIST__
