#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

//��̬�汾��
//void InitContact(Contact* pc)
//{
//	pc->sz = 0;
//	//memset();  - �ڴ�����
//	memset(pc->data, 0, sizeof(pc->data));
//}


//��̬�汾-��ʼ��
void InitContact(Contact* pc)
{
	pc->data = (PeoInfo*)malloc(DEFAULT_SZ*sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		perror("InitContact");
		return;
	}
	pc->sz = 0;//��ʼ����Ĭ����0
	pc->capacity = DEFAULT_SZ;

	//�����ļ�
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
	//д�ļ�
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data+i, sizeof(PeoInfo), 1, pf);
	}

	//�ر��ļ�
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
	//���ļ�
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pf))
	{
		//�Ƿ���Ҫ����
		CheckCapacity(pc);
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//
// ��̬�汾��-����Ա��
//void AddContact(Contact* pc)
//{
//	if (pc->sz == MAX)
//	{
//		printf("Ա����Ϣ����ϵͳ�������޷����\n");
//		return;
//	}
//	//����һ���˵���Ϣ
//	printf("����������:>");
//	scanf("%s", pc->data[pc->sz].name);
//	printf("����������:>");
//	scanf("%d", &(pc->data[pc->sz].age));
//	printf("�������Ա�:>");
//	scanf("%s", pc->data[pc->sz].sex);
//	printf("������绰:>");
//	scanf("%s", pc->data[pc->sz].tele);
//	printf("�������ַ:>");
//	scanf("%s", pc->data[pc->sz].addr);
//
//	pc->sz++;
//	printf("���ӳɹ�\n");
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
			printf("���ݳɹ�\n");
		}
		else
		{
			perror("AddContact");
			printf("����Ա��ʧ��\n");
			return;
		}
	}
}

//��̬�汾- ����Ա��
void AddContact(Contact* pc)
{
	//��������
	CheckCapacity(pc);
	//����һ���˵���Ϣ
	printf("������Ա������:>");
	scanf("%s", &(pc->data[pc->sz].Employee_No));
	printf("����������:>");
	scanf("%s", &(pc->data[pc->sz].name));
	printf("����������:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("�������Ա�:>");
	scanf("%s", &(pc->data[pc->sz].sex));
	printf("������绰:>");
	scanf("%s", &(pc->data[pc->sz].tele));
	printf("�������ַ:>");
	scanf("%s", &(pc->data[pc->sz].addr));
	printf("�����빤��:>");
	scanf("%lf", &(pc->data[pc->sz].wages));
	printf("�����벿��ְλ:>");
	scanf("%s", &(pc->data[pc->sz].position));

	pc->sz++;
	printf("���ӳɹ�\n");
}



void PrintContact(const Contact* pc)
{
	int i = 0;
	//��ӡ����
	printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "����", "����", "����", "�Ա�", "�绰", "��ַ", "����", "����");
	//��ӡ����
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

	return -1;//�Ҳ���
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

	return -1;//�Ҳ���
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
		printf("Ա����Ϣ����ϵͳΪ�գ�����ɾ��\n");
		return;
	}	
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);

	//1. ����Ҫɾ������
	//��/û��
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	//2. ɾ��
	printf("��ȷ��Ҫɾ���˵���Ϣ��\n");
	printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "����", "����", "����", "�Ա�", "�绰", "��ַ", "����", "����");
	//��ӡ����

	printf("%-15s\t%-5s\t%-5d\t%-5s\t%-12s\t%-20s\t%-5.1lf\t%-15s\n",
		pc->data[pos].Employee_No,
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr,
		pc->data[pos].wages,
		pc->data[pos].position);

	printf("ȷ��������1��ȷ��������0��>");
	scanf("%d", &DelFlag);
	if (DelFlag)
	{
		int i = 0;
		for (i = pos; i < pc->sz - 1; i++)
		{
			pc->data[i] = pc->data[i + 1];
		}

		pc->sz--;
		printf("ɾ���ɹ�\n");
	}

}

void SearchContact(Contact* pc)
{
	int Search_num;
	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t*      1.����Ա�����Ų�ѯ                *\n");
	printf("\t\t\t\t*      2.����Ա��������ѯ                *\n");
	printf("\t\t\t\t*      3.����Ա���绰��ѯ                *\n");
	printf("\t\t\t\t*      4.����Ա�����Ų�ѯ                *\n");
	printf("\t\t\t\t******************************************\n");


	printf("��ѡ��:>");
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
		printf("����ָ�����\n");
		break;
	}

}

void SearchContact_ByPostition(Contact* pc)
{
	char Postition[MAX_POSITION] = { 0 };
	printf("������Ҫ�����˵Ĳ���:>");
	scanf("%s", Postition);
	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].position, Postition) == 0)
		{
			if(FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "����", "����", "����", "�Ա�", "�绰", "��ַ", "����", "����");
			//��ӡ����

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
		printf("Ҫ���ҵĲ��Ų�����\n");
		return;
	}

}

void SearchContact_ByEmployee_No(Contact* pc)
{
	char Employee_No[MAX_Employee_No] = { 0 };
	printf("������Ҫ�����˵Ĺ���:>");
	scanf("%s", Employee_No);

	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].Employee_No, Employee_No) == 0)
		{
			if (FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "����", "����", "����", "�Ա�", "�绰", "��ַ", "����", "����");
			//��ӡ����

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
		printf("Ҫ���ҵĹ��Ų�����\n");
		return;
	}
}

void SearchContact_ByTele(Contact* pc)
{
	char Tele[MAX_TELE] = { 0 };
	printf("������Ҫ�����˵ĵ绰:>");
	scanf("%s", Tele);

	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].tele, Tele) == 0)
		{
			if (FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "����", "����", "����", "�Ա�", "�绰", "��ַ", "����", "����");
			//��ӡ����

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
		printf("Ҫ���ҵĵ绰������\n");
		return;
	}
}

void SearchContact_ByName(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);

	int FindFlag = 0;
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			if (FindFlag == 0)
				printf("%-15s\t%-5s\t%-5s\t%-5s\t%-12s\t%-20s\t%-5s\t%-15s\n", "����", "����", "����", "�Ա�", "�绰", "��ַ", "����", "����");
			//��ӡ����

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
		printf("Ҫ���ҵ����ֲ�����\n");
		return;
	}
}


void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	else
	{
		printf("������Ա������:>");
		scanf("%s", &(pc->data[pos].Employee_No));
		printf("����������:>");
		scanf("%s", &(pc->data[pos].name));
		printf("����������:>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�:>");
		scanf("%s", &(pc->data[pos].sex));
		printf("������绰:>");
		scanf("%s", &(pc->data[pos].tele));
		printf("�������ַ:>");
		scanf("%s", &(pc->data[pos].addr));
		printf("�����빤��:>");
		scanf("%lf", &(pc->data[pos].wages));
		printf("�����벿��ְλ:>");
		scanf("%s", &(pc->data[pc->sz].position));


		printf("�޸ĳɹ�\n");
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
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
	}
	else
	{
		int Sort_num;
		printf("\t\t\t\t******************************************\n");
		printf("\t\t\t\t*      1.����Ա����������                *\n");
		printf("\t\t\t\t*      2.����Ա����������                *\n");
		printf("\t\t\t\t*      3.����Ա����������                *\n");
		printf("\t\t\t\t******************************************\n");


		printf("��ѡ��:>");
		scanf("%d", &Sort_num);
		switch (Sort_num)
		{
		case 1:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), Sort_ByEmployee);
			printf("���չ�������ɹ�\n");
			break;
		case 2:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), Sort_Byname);
			printf("������������ɹ�\n");
			break;
		case 3:
			qsort(pc->data, pc->sz, sizeof(PeoInfo), Sort_ByAge);
			printf("������������ɹ�\n");
			break;
		default:
			printf("����ָ�����\n");
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
		printf("����ϵͳ��ʱ������\n");
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
	printf("Ա���������Ϊ%d����С����Ϊ%d\n", Age_Max, Age_Min);
	printf("Ա��������18����29��֮�����%d��\n", age18_30);
	printf("Ա��������30����39��֮�����%d��\n", age30_40);
	printf("Ա��������40����49��֮�����%d��\n", age40_50);
	printf("Ա��������50����70��֮�����%d��\n", age50_70);
}









