#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };

	//�����ʼ��
	Initboard(board, ROW, COL);

	//�����趨
	displayboard(board, ROW, COL);
	while (1)
	{
		//�����
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')

			break;
		//������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
	if (ret == '*')
	{
		printf("��Ӯ��\n");
	}
	if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		printf("**********************\n");
		printf("****    1.play    ****\n");
		printf("****    0.exit    ****\n");
		printf("**********************\n");
		printf("������>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ����\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
}