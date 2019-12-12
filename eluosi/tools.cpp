#include "tools.h"
#include <windows.h>
#include <stdio.h>   //ʹ��sprintf()
#include<cstddef>

void SetWindowSize(int cols, int lines)//���ô��ڴ�С
{
	system("title ����˹����");//���ô��ڱ���
	char cmd[30];
	int col = cols * 2;
	size_t sizeOfBuffer = 30;
	sprintf_s(cmd, sizeOfBuffer, "mode con cols=%d lines=%d", col, lines);//һ��ͼ�Ρ�ռ�����ַ����ʿ�ȳ���2
	system(cmd);            //system(mode con cols=88 lines=88)���ô��ڿ�Ⱥ͸߶�
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);//����̨��ɫ����
}

void SetCursorPosition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);//����̨���λ��
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}