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

int Getmid(int* a, int left, int right)
{
	int mid = (left + right) / 2;
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else // left <= right
	{
		if (a[mid] > a[right])
		{
			return right;
		}
		else if (a[mid] < a[left])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
}

int PartSort1(int* a, int left, int right)
{
	int keyi = Getmid(a, left, right);
	Swap(&a[left], &a[keyi]);

	keyi = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

int PartSort2(int* a, int left, int right)
{
	int keyi = Getmid(a, left, right);
	Swap(&a[left], &a[keyi]);

	int cur = left + 1;
	int prev = left;
	while (cur <= right)
	{
		if (a[cur] < a[left] && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	Swap(&a[left], &a[prev]);
	return prev;
}

int PartSort3(int* a, int left, int right)
{
	int keyi = Getmid(a, left, right);
	Swap(&a[left], &a[keyi]);

	int key = a[left];
	int tmp = left;

	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[tmp] = a[right];
		tmp = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[tmp] = a[left];
		tmp = left;
	}
	a[tmp] = key;
	return tmp;

}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 > 16)
	{
		int mid = PartSort2(a, left, right);

		QuickSort(a, left, mid - 1);
		QuickSort(a, mid + 1, right);
	}
	else
	{
		InsertSort(a + left, (right - left + 1));
	}
}

void QuickSortNonR(int* a, int left, int right)
{
	Stack ST;
	STInit(&ST);

	STPush(&ST, left);
	STPush(&ST, right);

	while (!STEmpty(&ST))
	{
		int end = STTop(&ST);
		STPop(&ST);
		int begin = STTop(&ST);
		STPop(&ST);

		int mid = PartSort2(a, begin, end);
		//右区间
		if (end > mid + 1)
		{
			STPush(&ST, mid + 1);
			STPush(&ST, end);
		}

		//左区间
		if (begin < mid - 1)
		{
			STPush(&ST, begin);
			STPush(&ST, mid - 1);
		}

	}

	STDestroy(&ST);
}


// 归并排序递归实现
void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;

	//[left, mid], [mid + 1, right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int tmpi = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[tmpi++] = a[begin1++];
		}
		else
		{
			tmp[tmpi++] = a[begin2++];
		}
	}
	if (begin1 <= end1)
	{
		while (begin1 <= end1)
		{
			tmp[tmpi++] = a[begin1++];
		}
	}
	else if (begin2 <= end2)
	{
		while (begin2 <= end2)
		{
			tmp[tmpi++] = a[begin2++];
		}
	}

	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));

}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, tmp, 0, n - 1);


	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int begin1 = i, end1 = begin1 + gap - 1;
			int begin2 = begin1 + gap, end2 = begin1 + 2 * gap - 1;
			int tmpi = begin1;

			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}

			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[tmpi++] = a[begin1++];
				}
				else
				{
					tmp[tmpi++] = a[begin2++];
				}
			}
			if (begin1 <= end1)
			{
				while (begin1 <= end1)
				{
					tmp[tmpi++] = a[begin1++];
				}
			}
			else if (begin2 <= end2)
			{
				while (begin2 <= end2)
				{
					tmp[tmpi++] = a[begin2++];
				}
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}

	free(tmp);
}

// 计数排序
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	int i = 0;
	int j = 0;
	while (i < range)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
		i++;
	}


	free(count);
}