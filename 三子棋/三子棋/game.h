#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//��������
#define ROW 3
#define COL 3
//�����ʼ��
void Initboard(char board[ROW][COL], int row, int col);
//���̴�ӡ
void displayboard(char board[ROW][COL], int row, int col);
//�����
void playermove(char board[ROW][COL],int row,int col);
//������
void computermove(char board[ROW][COL], int row, int col);
//1.���Ӯ *
//2.����Ӯ #
//3.ƽ�� Q
//4.���� C
char iswin(char board[ROW][COL], int row, int col);