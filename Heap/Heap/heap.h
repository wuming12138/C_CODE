#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

typedef int HPDataType;
typedef struct
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

// �ѵĹ���
void HeapCreate(Heap* hp, HPDataType* a, int n);
//�ѳ�ʼ��
void HeapInit(Heap* hp);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// �Ѵ�ӡ
void HeapPrint(Heap* hp);

void CreateNDate();
void PrintTopK(int k);
void HeapSort(int* a, int n);
