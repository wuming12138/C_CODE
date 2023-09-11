#include "heap.h"

void Swap(HPDataType* H1, HPDataType* H2)
{
	HPDataType* tmp = *H1;
	*H1 = *H2;
	*H2 = tmp;
}
//堆初始化
void HeapInit(Heap* hp)
{
	assert(hp);
	hp->_a = NULL;
	hp->_capacity = hp->_size = 0;
}
// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}
// 堆的插入
void AdjustUp(HPDataType* php, int child)
{
	int parent = (child - 1) / 2;
	while (child != 0)
	{
		if (php[child] > php[parent])
		{
			Swap(&php[child], &php[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = hp->_capacity == 0 ? 4 : hp->_capacity * 2;
		HPDataType* new = realloc(hp->_a, sizeof(HPDataType) * newcapacity);
		if (new == NULL)
		{
			perror("realloc fail");
			exit(-1);
		}
		hp->_a = new;
		hp->_capacity = newcapacity;
	}

	hp->_a[hp->_size] = x;
	++hp->_size;

	AdjustUp(hp->_a, hp->_size - 1);
}
// 堆的删除
void AdjustDown(HPDataType* a, int n, int parent)
{
	//左孩子
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child = child + 1;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(Heap* hp)
{
	assert(hp);
	assert(hp->_size > 0);
	hp->_a[0] = hp->_a[hp->_size - 1];
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// 堆打印
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0;
}
// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	assert(a);

	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_size = hp->_capacity = n;
	if (hp->_a == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	memcpy(hp->_a, a, sizeof(HPDataType) * n);
	for (int i = 1; i < n; i++)
	{
		AdjustUp(hp->_a, i);
	}
}

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	const char* file = "data.txt";
	FILE* fin = fopen(file, "r");
	if (fin == NULL)
	{
		ferror("fopen fail");
		exit(-1);
	}

	int* minheap = (int*)malloc(sizeof(int) * k);
	
	for (int i = 0; i < k; i++)
	{
		fscanf(fin, "%d", &minheap[i]);
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minheap, k, i);
	}

	int x = 0;
	while (fscanf(fin, "%d", &x) != EOF)
	{
		if (x > minheap[0])
		{
			minheap[0] = x;
		}
		AdjustDown(minheap, k, 0);
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}
	printf("\n");

	fclose(fin);
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (int i = 0; i < n; i++)
	{
		Swap(&a[0], &a[n - i - 1]);
		AdjustDown(a, n - i - 1, 0);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}