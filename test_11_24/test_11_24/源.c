#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int jia(int x,int y)
{
	return x + y;
}
int jian(int x, int y)
{
	return x - y;
}
int cheng(int x, int y)
{
	return x * y;
}
int chu(int x, int y)
{
	return x / y;
}
int calc(int (*pf)(int, int))
{
	int x = 0, y = 0;
	printf("请输入两个数");
	scanf("%d %d", &x, &y);
	return pf(x, y);
}
//void meun()
//{
//	printf("************************\n");
//	printf("***1.jia     2.jian  ***\n");
//	printf("***3.cheng   4.chu   ***\n");
//	printf("***0.exit            ***\n");
//	printf("************************\n");
//}
//int main()
//{
//	int input = 0;
//	do {
//		meun();
//		scanf("%d", &input);
//		int ret = 0;
//		switch (input)
//		{
//		case 1:
//			ret = calc(jia);
//			printf("%d", ret);
//			break;
//		case 2:
//			ret = calc(jian);
//			printf("%d", ret);
//			break;
//		case 3:
//			ret = calc(cheng);
//			printf("%d", ret);
//			break;
//		case 4:
//			ret = calc(chu);
//			printf("%d", ret);
//			break;
//		}
//	} while (input);
//	return 0;
//}
void meun()
{
	printf("************************\n");
	printf("***1.jia     2.jian  ***\n");
	printf("***3.cheng   4.chu   ***\n");
	printf("***0.exit            ***\n");
	printf("************************\n");
}
//int main()
//{
//	int input = 0;
//	do {
//		meun();
//		scanf("%d", &input);
//		int ret = 0;
//		int m=0, n=0;
//		int(*ps[5])(int, int) = { NULL,jia,jian,cheng,chu };
//		printf("请输入两个数");
//		scanf("%d %d", &m, &n);
//		ret = ps[input](m, n);
//		printf("%d", ret);
//	} while (input);
//	return 0;
//}
swap(char* e1, char* e2,int width)
{
	int i = 0;
	for (i = 0;i < width;i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void mao_sort(void* base,int sz,int width,int (* cmp)(const void* e1,const void* e2))
{
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int j = 0;
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmp((char*)base + width * j, (char*)base + width * (j + 1)) > 0)
			{
				swap((char*)base + width * j, (char*)base + width * (j + 1),width);
			}
		}
	}
}
int int_sort(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
struct stu
{
	char name[30];
	int age;
};
int name_sort(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
int main()
{
	struct stu peo[3] = { {"zhangsan",30},{"lisi",40},{"wangwu",20} };
	int sz = sizeof(peo) / sizeof(peo[0]);
	mao_sort(peo, sz, sizeof(peo[0]), name_sort);
	return 0;
}