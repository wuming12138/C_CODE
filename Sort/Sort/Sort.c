#include "Sort.h"

void Swap(int* n1, int* n2)
{
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap >= 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
				}
				else
				{
					break;
				}
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}


}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int exchange = 0;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}

}
void AdjustDown(int* a, int n, int parent)
{
	int child = 2 * parent + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (int i = 1; i < n; i++)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
	}
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
				maxi = i;
			if (a[i] < a[mini])
				mini = i;
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
		{
			maxi = mini;
		}
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}

//
//int PartSort1(int* a, int left, int right)
//{
//	int key = a[0];
//	while (left < right)
//	{
//		while (left < right && a[left] <= key)
//		{
//			left++;
//		}
//		while (left < right && a[right] >= key)
//		{
//			right--;
//		}
//		Swap(&a[left], &a[right]);
//	}
//	Swap(&a[0], &a[left]);
//	return left;
//}
//
//void QuickSort(int* a, int left, int right)
//{
//	if (left >= right)
//		return;
//
//	//int mid = PartSort1(a, left, right);
//	PartSort1(a, left, right);
//	//QuickSort(a, 0, mid - 1);
//	//QuickSort(a, mid + 1, right);
//}