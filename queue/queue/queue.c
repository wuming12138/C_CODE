#include "queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

//��ӡ����
void QueuePrint(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		printf("%d   ", cur->a);
		cur = cur->next;
	}
	printf("\n");
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



MyStack* myStackCreate() {
	MyStack* newStack = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&newStack->q1);
	QueueInit(&newStack->q2);
	return newStack;
}

void myStackPush(MyStack* obj, int x) {
	assert(obj);
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else if (!QueueEmpty(&obj->q2))
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1;
	Queue* notempty = &obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = &obj->q2;
		notempty = &obj->q1;
	}

	while (QueueSize(notempty) > 1)
	{
		QueuePush(empty, QueueFront(notempty));
		QueuePop(notempty);
	}
	int top = QueueFront(notempty);
	QueuePop(notempty);

	return top;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else if (!QueueEmpty(&obj->q2))
	{
		return QueueBack(&obj->q2);
	}
	return 0;
}

int myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}
