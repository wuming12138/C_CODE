#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

void PrintArray(int* a, int n);
void InsertSort(int* a, int n);
void ShellSort(int* a, int n);
void BubbleSort(int* a, int n);
void HeapSort(int* a, int n);
void SelectSort(int* a, int n);
void QuickSort(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);