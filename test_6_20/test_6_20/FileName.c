

/*
��������

������A�е����ݺ�����B�е����ݽ��н�����������һ����
*/

//#include <stdio.h>
//int main()
//{
//	char arr1[5] = "abcd";
//	char arr2[5] = "efgo";
//	for (int i = 0; i < sizeof(arr1); i++)
//	{
//		int Temp = arr1[i];
//		arr1[i] = arr2[i];
//		arr2[i] = Temp;
//	}
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//
//
//	return 0;
//}


/*
����һ���������飬��ɶ�����Ĳ���

ʵ�ֺ���init() ��ʼ������Ϊȫ0
ʵ��print()  ��ӡ�����ÿ��Ԫ��
ʵ��reverse()  �����������Ԫ�ص����á�
Ҫ���Լ�������Ϻ����Ĳ���������ֵ��


*/

//#include <stdio.h>
//void init(int* arr, int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		arr[i] = 0;
//	}
//}
//
//void reverse(int* arr, int num)
//{
//	int Temp = 0;
//	for (int i = 0; i < num / 2; i++)
//	{
//		Temp = arr[i];
//		arr[i] = arr[num - 1 - i];
//		arr[num - 1 - i] = Temp;
//	}
//}
//
//void print(int* arr, int num)
//{
//	for (int i = 0; i < num; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//int main()
//{
//	int arr[10];
//	init(arr, sizeof(arr) / 4);
//	for (int i = 0; i < sizeof(arr) / 4; i++)
//	{
//		arr[i] = i;
//	}
//	reverse(arr, sizeof(arr) / 4);
//	print(arr, sizeof(arr) / 4);
//
//	return 0;
//}



/*
* ʵ��һ�������������ð������
*/

#include <stdio.h>
void print(int* arr, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int arr[10] = { 5,9,36,20,15,14,12,36,20,45 };
	int i = 0, j = 0;
	int Temp = 0;
	for (i = 0; i < 10 - 1; i++)
	{
		for (j = 0; j < 10 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = Temp;
			}
		}
	}
	print(arr, 10);
	return 0;
}