#pragma once


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_Employee_No 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX_POSITION 20

#define MAX 1000

#define DEFAULT_SZ 3
#define INC_SZ 2


//类型的定义
typedef struct PeoInfo
{
	char Employee_No[MAX_Employee_No];
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	double wages;
	char position[MAX_POSITION];
}PeoInfo;

//员工信息管理系统-静态版本
//typedef struct Contact
//{
//	PeoInfo data[MAX];//存放添加进来的人的信息
//	int sz;//记录的是当前员工信息管理系统中有效信息的个数
//}Contact;

//动态版本
typedef struct Contact
{
	PeoInfo *data;//指向动态申请的空间，用来存放员工的信息
	int sz;//记录的是当前员工信息管理系统中有效信息的个数
	int capacity;//记录当前员工信息管理系统的最大容量
}Contact;


//初始化员工信息管理系统
void InitContact(Contact* pc);

//增加员工
void AddContact(Contact* pc);

//打印员工信息
void PrintContact(const Contact* pc);

//删除员工的信息
void DelContact(Contact* pc);

//查找指定员工
void SearchContact(Contact* pc);

void SearchContact_ByName(Contact* pc);
void SearchContact_ByTele(Contact* pc);
void SearchContact_ByEmployee_No(Contact* pc);
void SearchContact_ByPostition(Contact* pc);

//修改指定员工
void ModifyContact(Contact* pc);

//销毁员工信息管理系统
void DestoryContact(Contact* pc);

//保存员工信息管理系统信息到文件
void SaveContact(Contact* pc);

//加载文件内容到员工信息管理系统
void LoadContact(Contact* pc);

//检测增容的问题
void CheckCapacity(Contact* pc);

//排序员工信息管理系统
void SortContact(Contact* pc);

//统计
void StatisContact(Contact* pc);