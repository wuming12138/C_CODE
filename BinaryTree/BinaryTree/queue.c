#include "queue.h"


// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}


// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->a = data;
	newnode->next = NULL;

	if (q->rear == NULL)
	{
		q->front = q->rear = newnode;
	}
	else
	{
		q->rear->next = newnode;
		q->rear = newnode;
	}
	q->size++;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->front);
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		QNode* Del = q->front;
		q->front = Del->next;
		free(Del);
	}
	q->size--;
}

// 获取队列头部元素 
QDataType QueueFront(Queue* q) 
{
	assert(q);
	assert(q->front);
	return q->front->a;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->rear->a;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}

// 销毁队列 
void QueueDestroy(Queue* q)
{
	while (q->front)
	{
		QueuePop(q);
	}
	q->size = 0;
}





