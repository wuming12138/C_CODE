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


//���͵Ķ���
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

//Ա����Ϣ����ϵͳ-��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];//�����ӽ������˵���Ϣ
//	int sz;//��¼���ǵ�ǰԱ����Ϣ����ϵͳ����Ч��Ϣ�ĸ���
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo *data;//ָ��̬����Ŀռ䣬�������Ա������Ϣ
	int sz;//��¼���ǵ�ǰԱ����Ϣ����ϵͳ����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰԱ����Ϣ����ϵͳ���������
}Contact;


//��ʼ��Ա����Ϣ����ϵͳ
void InitContact(Contact* pc);

//����Ա��
void AddContact(Contact* pc);

//��ӡԱ����Ϣ
void PrintContact(const Contact* pc);

//ɾ��Ա������Ϣ
void DelContact(Contact* pc);

//����ָ��Ա��
void SearchContact(Contact* pc);

void SearchContact_ByName(Contact* pc);
void SearchContact_ByTele(Contact* pc);
void SearchContact_ByEmployee_No(Contact* pc);
void SearchContact_ByPostition(Contact* pc);

//�޸�ָ��Ա��
void ModifyContact(Contact* pc);

//����Ա����Ϣ����ϵͳ
void DestoryContact(Contact* pc);

//����Ա����Ϣ����ϵͳ��Ϣ���ļ�
void SaveContact(Contact* pc);

//�����ļ����ݵ�Ա����Ϣ����ϵͳ
void LoadContact(Contact* pc);

//������ݵ�����
void CheckCapacity(Contact* pc);

//����Ա����Ϣ����ϵͳ
void SortContact(Contact* pc);

//ͳ��
void StatisContact(Contact* pc);