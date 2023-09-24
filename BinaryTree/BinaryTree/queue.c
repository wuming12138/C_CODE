#include "queue.h"


// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}


// ��β����� 
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

// ��ͷ������ 
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

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q) 
{
	assert(q);
	assert(q->front);
	return q->front->a;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->front);
	return q->rear->a;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->front == NULL;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	while (q->front)
	{
		QueuePop(q);
	}
	q->size = 0;
}





