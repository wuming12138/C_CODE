#include "queue.h"


//void test1()
//{
//	Queue q;
//	QueueInit(&q);
//	QueuePush(&q, 1);
//	QueuePush(&q, 2);
//	QueuePush(&q, 3);
//	QueuePush(&q, 4);
//	printf("===%d\n", QueueSize(&q));
//	QueuePrint(&q);
//
//	QueuePop(&q);
//	QueuePrint(&q);
//	printf("===%d\n", QueueSize(&q));
//
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePop(&q);
//	QueuePrint(&q);
//
//	QueueDestroy(&q);
//	QueuePrint(&q);
//}

int main()
{
	//test1();
	MyStack* S = myStackCreate();
	myStackPush(S, 1);
	myStackPush(S, 2);
	printf("%d",myStackPop(S));
	return 0;
}