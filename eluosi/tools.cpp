#include "tools.h"
#include <windows.h>
#include <stdio.h>   //使用sprintf()
#include<cstddef>

void SetWindowSize(int cols, int lines)//设置窗口大小
{
	system("title 俄罗斯方块");//设置窗口标题
	char cmd[30];
	int col = cols * 2;
	size_t sizeOfBuffer = 30;
	sprintf_s(cmd, sizeOfBuffer, "mode con cols=%d lines=%d", col, lines);//一个图形■占两个字符，故宽度乘以2
	system(cmd);            //system(mode con cols=88 lines=88)设置窗口宽度和高度
}

void SetColor(int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);//控制台颜色属性
}

void SetCursorPosition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);//控制台光标位置
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}