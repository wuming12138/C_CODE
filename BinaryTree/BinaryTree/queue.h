#ifndef __QUEUE__
#define __QUEUE__

#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef BTNode* QDataType;

typedef struct QListNode
{
	QDataType a;
	struct QListNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

// 初始化队列 
void QueueInit(Queue* q);
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
// 队头出队列 
void QueuePop(Queue* q);
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列 
void QueueDestroy(Queue* q);


#endif
