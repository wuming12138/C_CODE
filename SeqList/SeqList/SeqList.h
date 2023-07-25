#pragma once
#ifndef __SEQLIST__
#define __SEQLIST__

#include <stdio.h>
#include <stdlib.h>  
#include <assert.h>

typedef int SLDateType;

typedef struct
{
	SLDateType* a;
	int size;
	int capacity;
}SeqList;

void SeqListInit(SeqList* SL);
void SeqListDestroy(SeqList* SL);
void SeqListPrint(SeqList* SL);
void SeqListPushBack(SeqList* SL, SLDateType x);
void SeqListPushFront(SeqList* SL, SLDateType x);
void SeqListPopBack(SeqList* SL);
void SeqListPopFront(SeqList* SL);
int SeqListFind(SeqList* ps, SLDateType x);
void SeqListInsert(SeqList* ps, int pos, SLDateType x);
void SeqListErase(SeqList* ps, int pos);



#endif // !__SEQLIST__
