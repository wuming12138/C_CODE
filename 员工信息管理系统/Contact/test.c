#define _CRT_SECURE_NO_WARNINGS 1

//Ա����Ϣ����ϵͳ-��̬�汾
//1.Ա����Ϣ����ϵͳ���ܹ����1000���˵���Ϣ
//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//2. �����˵���Ϣ
//3. ɾ��ָ���˵���Ϣ
//4. �޸�ָ���˵���Ϣ
//5. ����ָ���˵���Ϣ
//6. ����Ա����Ϣ����ϵͳ����Ϣ
//
//�汾2��
//��̬�����İ汾
//1>Ա����Ϣ����ϵͳ��ʼ�����ܴ��3���˵���Ϣ
//2>�����ǿռ�Ĵ������ʱ����������2����Ϣ
//3+2+2+2+...
//

//
//�汾3
//��Ա����Ϣ����ϵͳ�˳���ʱ�򣬰���Ϣд���ļ�
//��Ա����Ϣ����ϵͳ��ʼ����ʱ�򣬼����ļ�����Ϣ��Ա����Ϣ����ϵͳ��
//


#include "contact.h"

void menu()
{

	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t***  ��ҵԱ����Ϣ����ϵͳ�������ʵ��  ***\n");
	printf("\t\t\t\t******************************************\n");
	printf("\t\t\t\t*      1.¼��Ա����Ϣ---ADD              *\n");
	printf("\t\t\t\t*      2.ɾ��Ա����Ϣ---DEL              *\n");
	printf("\t\t\t\t*      3.��ѯԱ����Ϣ---SEARCH	         *\n");
	printf("\t\t\t\t*      4.�޸�Ա����Ϣ---MODIFY           *\n");
	printf("\t\t\t\t*      5.����Ա����Ϣ---SORT             *\n");
	printf("\t\t\t\t*      6.��ʾԱ����Ϣ---PRINT            *\n");
	printf("\t\t\t\t*      7.Ա����Ϣͳ��---STATIS           *\n");
	printf("\t\t\t\t*      0.�˳�����ϵͳ---EXIT             *\n");
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
	//����Ա����Ϣ����ϵͳ
	Contact con;//Ա����Ϣ����ϵͳ
	//��ʼ��Ա����Ϣ����ϵͳ
	//��data����һ�������Ŀռ��ٶ�����
	//sz=0
	//capacity ��ʼ��Ϊ��ǰ����������
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			//�����˵���Ϣ
			AddContact(&con);
			break;
		case DEL:
			//ɾ��
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
			//������Ϣ���ļ�
			SaveContact(&con);
			//����Ա����Ϣ����ϵͳ
			DestoryContact(&con);
			printf("�˳�Ա����Ϣ����ϵͳ\n");
			break;
		default:
			printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (input);

	return 0;
}


