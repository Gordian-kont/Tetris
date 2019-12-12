#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"controller.h"
#include"tools.h"
#include"map.h"
#include"block.h"

void Controller::Game()//游戏的一级循环
{
	Start();
	while (true)
	{
		DrawGame();
		int tmp = PlayGame();
		if (tmp == 1)
		{
			system("cls");
			continue;
		}
		else
		{
			break;
		}
	}
}

void Controller::Start()//开始界面
{
	SetColor(10);
	SetCursorPosition(12, 10);
	std::cout << "Press any key to start";
	SetCursorPosition(12, 15);
	system("pause");
}

void Controller::DrawGame()//初始化地图
{
	system("cls");

	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitMap();
	delete init_map;
}

int Controller::PlayGame()//游戏的二级循环
{
	/*初始化方块*/
	Block *cblock = new Block();
	SetColor(6);
	cblock->Create();
	cblock->InitBlock();
	while (!cblock->IsTop())
	{
		if (!cblock->Direction())  //ESC，实际操作中按esc没有反应，不太清楚怎么解决
		{
			int tmp = 1;//绘制菜单，并得到返回值
			switch (tmp)
			{
			case 1://继续游戏
				break;

			case 2://重新开始
				delete cblock;
				return 1;//将1作为PlayGame函数的返回值返回到Game函数中，表示重新开始

			case 3://退出游戏
				delete cblock;
				return 2;//将2作为PlayGame函数的返回值返回到Game函数中，表示退出游戏

			default:
				break;
			}
		}
		if (cblock->IsBlock())//碰撞
		{
			cblock->BlockStop();
			SetColor(6);
			cblock->Create();
			cblock->InitBlock();
		}
		else//方块正常下降
		{
			cblock->MoveDown();
		}
		Sleep(speed);//方块自动下降时间间隔
	}

	/*GAMEOVER*/
	delete cblock;
	int tmp = GameOver();//绘制游戏结束界面，并返回所选项
	switch (tmp)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 2;
	}
}

int Controller::GameOver()//游戏结束界面
{
	/*绘制游戏结束界面*/
	Sleep(500);  //停半秒，继续向下执行
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ┃   是否再来一局？                         ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";

	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "嗯，好的";
	SetCursorPosition(0, 31);

	/*选择部分*/
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while ((ch = _getch()))
	{
		switch (ch)
		{
		case 75://LEFT
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 18);
				SetBackColor();
				std::cout << "嗯，好的";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "嗯，好的";
				++tmp_key;
			}
			break;

		case 13://Enter
			flag = true;
			break;

		default:
			break;
		}

		SetCursorPosition(0, 31);
		if (flag) {
			break;
		}
	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	default:
		return 1;
	}
}