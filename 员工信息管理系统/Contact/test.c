#define _CRT_SECURE_NO_WARNINGS 1

//员工信息管理系统-静态版本
//1.员工信息管理系统中能够存放1000个人的信息
//每个人的信息：
//名字+年龄+性别+电话+地址
//2. 增加人的信息
//3. 删除指定人的信息
//4. 修改指定人的信息
//5. 查找指定人的信息
//6. 排序员工信息管理系统的信息
//
//版本2：
//动态增长的版本
//1>员工信息管理系统初始化后，能存放3个人的信息
//2>当我们空间的存放满的时候，我们增加2个信息
//3+2+2+2+...
//

//
//版本3
//当员工信息管理系统退出的时候，把信息写到文件
//当员工信息管理系统初始化的时候，加载文件的信息到员工信息管理系统中
//


#include "contact.h"

void menu()
{

	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t***  企业员工信息管理系统的设计与实现  ***\n");
	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t*      1.录入员工信息---ADD              *\n");
	printf("\t\t\t\t*      2.删除员工信息---DEL              *\n");
	printf("\t\t\t\t*      3.查询员工信息---SEARCH	         *\n");
	printf("\t\t\t\t*      4.修改员工信息---MODIFY           *\n");
	printf("\t\t\t\t*      5.排序员工信息---SORT             *\n");
	printf("\t\t\t\t*      6.显示员工信息---PRINT            *\n");
	printf("\t\t\t\t*      7.员工信息统计---STATIS           *\n");
	printf("\t\t\t\t*      0.退出管理系统---EXIT             *\n");
	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t******************************************\n");

}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	PRINT,
	STATIS
};

int main()
{
	int input = 0;
	//创建员工信息管理系统
	Contact con;//员工信息管理系统
	//初始化员工信息管理系统
	//给data申请一块连续的空间再堆区上
	//sz=0
	//capacity 初始化为当前的最大的容量
	InitContact(&con);

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			//增加人的信息
			AddContact(&con);
			break;
		case DEL:
			//删除
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case PRINT:
			PrintContact(&con);
			break;
		case STATIS:
			StatisContact(&con);
			break;
		case EXIT:
			//保存信息到文件
			SaveContact(&con);
			//销毁员工信息管理系统
			DestoryContact(&con);
			printf("退出员工信息管理系统\n");
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);

	return 0;
}


