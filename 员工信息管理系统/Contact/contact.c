#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//静态版本的
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	//memset();  - 内存设置
//	memset(pc->data, 0, sizeof(pc->data));
//}


//动态版本-初始化
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;//初始化后默认是0
	pc->capacity = DEFAULT_SZ;

	//加载文件
	LoadContact(pc);
}

void DestoryContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc->capacity = 0;
}


void SaveContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)
	{
		perror("SaveContact");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.dat", "r");
	if (pf == NULL)
	{
		perror("LoadContact");
		return;
	}
	//读文件
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//是否需要增容
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//
// 静态版本的-增加员工
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("员工信息管理系统已满，无法添加\n");
//		return;
//	}
//	//增加一个人的信息
//	printf("请输入名字:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("请输入年龄:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("请输入性别:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("请输入电话:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("请输入地址:>");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("增加成功\n");
//}

void CheckCapacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr != NULL)
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("增容成功\n");
		}
		else
		{
			perror("AddContact");
			printf("增加员工失败\n");
			return;
		}
	}
}

//动态版本- 增加员工
void AddContact(Contact* pc)
{
	//考虑增容
	CheckCapacity(pc);
	//增加一个人的信息
	printf("请输入员工工号:>");
	scanf("%s", &(pc->data[pc->sz].Employee_No));
	printf("请输入名字:>");
	scanf("%s", &(pc->data[pc->sz].name));
	printf("请输入年龄:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("请输入性别:>");
	scanf("%s", &(pc->data[pc->sz].sex));
	printf("请输入电话:>");
	scanf("%s", &(pc->data[pc->sz].tele));
	printf("请输入地址:>");
	scanf("%s", &(pc->data[pc->sz].addr));
	printf("请输入工资:>");
	scanf("%lf", &(pc->data[pc->sz].wages));
	printf("请输入部门职位:>");
	scanf("%s", &(pc->data[pc->sz].position));

	pc->sz++;
	printf("增加成功\n");
}



void PrintContact(const Contact* pc)
{
	int i = 0;
	//打印标题
	printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "工号", "名字", "年龄", "性别", "电话", "地址", "工资", "部门");
	//打印数据
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n", 
			pc->data[i].Employee_No,
			pc->data[i].name, 
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr,
			pc->data[i].wages,
			pc->data[i].position
			);
	}
}

static int FindByPostition(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].position, name) == 0)
		{
			return i;
		}
	}

	return -1;//找不到
}

static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}

	return -1;//找不到
}

static int FindByEmployee(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].Employee_No, name) == 0)
		{
			return i;
		}
	}

	return -1;
}

static int FindByTele(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].tele, name) == 0)
		{
			return i;
		}
	}

	return -1;
}

void DelContact(Contact* pc)
{
	int DelFlag;
	char name[MAX_NAME] = {0};

	if (pc->sz == 0)
	{
		printf("员工信息管理系统为空，无需删除\n");
		return;
	}	
	printf("请输入要删除人的名字:>");
	scanf("%s", name);

	//1. 查找要删除的人
	//有/没有
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	//2. 删除
	printf("请确认要删除人的信息：\n");
	printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "工号", "名字", "年龄", "性别", "电话", "地址", "工资", "部门");
	//打印数据

	printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n",
		pc->data[pos].Employee_No,
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr,
		pc->data[pos].wages,
		pc->data[pos].position);

	printf("确认请输入1不确认请输入0：>");
	scanf("%d", &DelFlag);
	if (DelFlag)
	{
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}

		pc->sz--;
		printf("删除成功\n");
	}

}

void SearchContact(Contact* pc)
{
	int Search_num;
	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t*      1.按照员工工号查询                *\n");
	printf("\t\t\t\t*      2.按照员工姓名查询                *\n");
	printf("\t\t\t\t*      3.按照员工电话查询                *\n");
	printf("\t\t\t\t*      4.按照员工部门查询                *\n");
	printf("\t\t\t\t******************************************\n");


	printf("请选择:>");
	scanf("%d", &Search_num);
	switch (Search_num)
	{
	case 1:
		SearchContact_ByEmployee_No(pc);
		break;
	case 2:
		SearchContact_ByName(pc);
		break;
	case 3:
		SearchContact_ByTele(pc);
		break;
	case 4:
		SearchContact_ByPostition(pc);
		break;
	default:
		printf("输入指令错误\n");
		break;
	}

}

void SearchContact_ByPostition(Contact* pc)
{
	char Postition[MAX_POSITION] = { 0 };
	printf("请输入要查找人的部门:>");
	scanf("%s", Postition);
	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].position, Postition) == 0)
		{
			if(FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "工号", "名字", "年龄", "性别", "电话", "地址", "工资", "部门");
			//打印数据

			printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n",
				pc->data[i].Employee_No,
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr,
				pc->data[i].wages,
				pc->data[i].position);

			FindFlag = 1;
		}
	}
	if (FindFlag == 0)
	{
		printf("要查找的部门不存在\n");
		return;
	}

}

void SearchContact_ByEmployee_No(Contact* pc)
{
	char Employee_No[MAX_Employee_No] = { 0 };
	printf("请输入要查找人的工号:>");
	scanf("%s", Employee_No);

	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].Employee_No, Employee_No) == 0)
		{
			if (FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "工号", "名字", "年龄", "性别", "电话", "地址", "工资", "部门");
			//打印数据

			printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n",
				pc->data[i].Employee_No,
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr,
				pc->data[i].wages,
				pc->data[i].position);

			FindFlag = 1;
		}
	}
	if (FindFlag == 0)
	{
		printf("要查找的工号不存在\n");
		return;
	}
}

void SearchContact_ByTele(Contact* pc)
{
	char Tele[MAX_TELE] = { 0 };
	printf("请输入要查找人的电话:>");
	scanf("%s", Tele);

	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].tele, Tele) == 0)
		{
			if (FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "工号", "名字", "年龄", "性别", "电话", "地址", "工资", "部门");
			//打印数据

			printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n",
				pc->data[i].Employee_No,
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr,
				pc->data[i].wages,
				pc->data[i].position);

			FindFlag = 1;
		}
	}
	if (FindFlag == 0)
	{
		printf("要查找的电话不存在\n");
		return;
	}
}

void SearchContact_ByName(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);

	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			if (FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "工号", "名字", "年龄", "性别", "电话", "地址", "工资", "部门");
			//打印数据

			printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n",
				pc->data[i].Employee_No,
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr,
				pc->data[i].wages,
				pc->data[i].position);

			FindFlag = 1;
		}
	}
	if (FindFlag == 0)
	{
		printf("要查找的名字不存在\n");
		return;
	}
}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	else
	{
		printf("请输入员工工号:>");
		scanf("%s", &(pc->data[pos].Employee_No));
		printf("请输入名字:>");
		scanf("%s", &(pc->data[pos].name));
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别:>");
		scanf("%s", &(pc->data[pos].sex));
		printf("请输入电话:>");
		scanf("%s", &(pc->data[pos].tele));
		printf("请输入地址:>");
		scanf("%s", &(pc->data[pos].addr));
		printf("请输入工资:>");
		scanf("%lf", &(pc->data[pos].wages));
		printf("请输入部门职位:>");
		scanf("%s", &(pc->data[pc->sz].position));


		printf("修改成功\n");
	}
}

int Sort_Byname(void* e1, void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

int Sort_ByEmployee(void* e1, void* e2)
{
	return strcmp(((PeoInfo*)e1)->Employee_No, ((PeoInfo*)e2)->Employee_No);
}

int Sort_ByAge(void* e1, void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}

void SortContact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("通讯录为空，无法排序\n");
	}
	else
	{
		int Sort_num;
		printf("\t\t\t\t******************************************\n");
		printf("\t\t\t\t*      1.按照员工工号排序                *\n");
		printf("\t\t\t\t*      2.按照员工姓名排序                *\n");
		printf("\t\t\t\t*      3.按照员工年龄排序                *\n");
		printf("\t\t\t\t******************************************\n");


		printf("请选择:>");
		scanf("%d", &Sort_num);
		switch (Sort_num)
		{
		case 1:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), Sort_ByEmployee);
			printf("按照工号排序成功\n");
			break;
		case 2:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), Sort_Byname);
			printf("按照姓名排序成功\n");
			break;
		case 3:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), Sort_ByAge);
			printf("按照年龄排序成功\n");
			break;
		default:
			printf("输入指令错误\n");
			break;
		}
	}
}

void StatisContact(Contact* pc)
{
	int Age_Max = 0, Age_Min = 150;
	int age18_30 = 0;
	int age30_40 = 0;
	int age40_50 = 0;
	int age50_70 = 0;
	if (pc->sz == 0)
	{
		printf("管理系统暂时无数据\n");
		return;
	}

	for (int i = 0; i < pc->sz; i++)
	{
		if (pc->data[i].age > Age_Max)
		{
			Age_Max = pc->data[i].age;
		}
		if (pc->data[i].age < Age_Min)
		{
			Age_Min = pc->data[i].age;
		}


		if (pc->data[i].age >= 18 && pc->data[i].age < 30)
			age18_30++;
		else if (pc->data[i].age >= 30 && pc->data[i].age < 40)
			age30_40++;
		else if (pc->data[i].age >= 40 && pc->data[i].age < 50)
			age40_50++;
		else if (pc->data[i].age >= 50 && pc->data[i].age <= 70)
			age50_70++;

	}
	printf("员工最大年龄为%d，最小年龄为%d\n", Age_Max, Age_Min);
	printf("员工年龄在18岁至29岁之间的有%d人\n", age18_30);
	printf("员工年龄在30岁至39岁之间的有%d人\n", age30_40);
	printf("员工年龄在40岁至49岁之间的有%d人\n", age40_50);
	printf("员工年龄在50岁至70岁之间的有%d人\n", age50_70);
}









