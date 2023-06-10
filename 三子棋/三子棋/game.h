#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//定义行列
#define ROW 3
#define COL 3
//数组初始化
void Initboard(char board[ROW][COL], int row, int col);
//棋盘打印
void displayboard(char board[ROW][COL], int row, int col);
//玩家走
void playermove(char board[ROW][COL],int row,int col);
//电脑走
void computermove(char board[ROW][COL], int row, int col);
//1.玩家赢 *
//2.电脑赢 #
//3.平局 Q
//4.继续 C
char iswin(char board[ROW][COL], int row, int col);