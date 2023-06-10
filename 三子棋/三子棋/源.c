#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };

	//数组初始化
	Initboard(board, ROW, COL);

	//棋盘设定
	displayboard(board, ROW, COL);
	while (1)
	{
		//玩家走
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')

			break;
		//电脑走
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
	if (ret == '*')
	{
		printf("你赢了\n");
	}
	if (ret == '#')
	{
		printf("电脑赢了\n");
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
		printf("请输入>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
}