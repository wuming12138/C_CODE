#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int cnt = 0;
//	scanf("%d", &cnt);
//	int i, j;
//	for (i = 0; i < cnt; i++)
//	{
//		for (j = i; j < cnt; j++)
//		{
//			printf("%-2d*%-2d=%-2d ", i + 1, j + 1, (i + 1) * (j + 1));
//		}
//		printf("\n");
//	}
//
//	return 0;
//}



//#include <stdio.h>
//
//void fuc(int* x, int* y)
//{
//	int Temp = *x;
//	*x = *y;
//	*y = Temp;
//}
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d %d", &a, &b);
//	fuc(&a, &b);
//	printf("%d %d", a, b);
//
//
//	return 0;
//}


//#include <stdio.h>
//
//int fuc(int x)
//{
//	int i = 0;
//	for (i = 2; i < x; i++)
//	{
//		if (x % i == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int i;
//	for (i = 100; i <= 200; i++)
//	{
//		if (fuc(i))
//			printf("%d\n", i);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//int fuc(int x)
//{
//	if (x == 0)
//		return 0;
//	if (x == 1)
//		return 1;
//	return fuc(x - 1) + fuc(x - 2);
//}
//int main()
//{
//	int input;
//	scanf("%d", &input);
//	printf("%d", fuc(input));
//
//	return 0;
//}

//#include <stdio.h>
//
//int fuc(int n, int k)
//{
//	if (k > 1)
//		return n * fuc(n, k - 1);
//	else
//		return n;
//}
//int main()
//{
//	int n, k;
//	scanf("%d %d", &n, &k);
//	printf("%d", fuc(n, k));
//
//	return 0;
//}


/*
дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��

���磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19

���룺1729�������19
*/


//#include <stdio.h>
//
//int DigitSum(int n)
//{
//	if (n > 10)
//		return n % 10 + DigitSum(n / 10);
//	else
//		return n;
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d", DigitSum(n));
//
//	return 0;
//}


/*
��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�

ʵ�֣��������ַ����е��ַ��������У����������ӡ��

Ҫ�󣺲���ʹ��C�������е��ַ�������������

����:

char arr[] = "abcdef";

����֮����������ݱ�ɣ�fedcba
*/



//#include <stdio.h>
//
//int my_strlen(char* string)
//{
//	int cnt = 0;
//	while (*string++)
//	{
//		cnt++;
//	}
//	return cnt;
//}
//void reverse_string(char* string)
//{
//	char Temp = 0;
//	int len = my_strlen(string);
//	if (len > 1)
//	{
//		Temp = *string;
//		*string = *(string + len - 1);
//		*(string + len - 1) = '\0';
//		reverse_string(string + 1);
//		*(string + len - 1) = Temp;
//	}
//}
//int main()
//{
//
//	int arr[10] = { 0 };
//	scanf("%s", arr);
//	reverse_string(arr);
//	printf("%s", arr);
//
//	return 0;
//}


/*
strlen��ģ�⣨�ݹ�ʵ�֣�
*/
//
//#include <stdio.h>
//
//int my_strlen(char* string)
//{
//	if (*string)
//	{
//		return 1 + my_strlen(string + 1);
//	}
//	else
//		return 0;
//}
//
//int main()
//{
//
//	printf("%d", my_strlen("abcde"));
//
//	return 0;
//}

/*
��ӡһ������ÿһλ

��ҵ����
�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
*/

//#include <stdio.h>
//
//void DigitSum(int n)
//{
//	if (n > 10)
//	{
//		DigitSum(n / 10);
//		printf("%d ", n % 10);
//	}
//	else
//	{
//		printf("%d ", n % 10);
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	DigitSum(n);
//
//	return 0;
//}



/*
��׳�

��ҵ����
�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳ˣ���������������⣩
*/

#include <stdio.h>

int digui_fuc(int n)
{
	if (n > 0)
		return n * digui_fuc(n - 1);
	else
		return 1;
}
int no_digui_fuc(int n)
{
	int sum = 1;
	while (n > 0)
	{
		sum *= n;
		n--;
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", digui_fuc(n));
	printf("%d\n", no_digui_fuc(n));
	return 0;
}