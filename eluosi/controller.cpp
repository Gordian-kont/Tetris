#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"controller.h"
#include"tools.h"
#include"map.h"
#include"block.h"

void Controller::Game()//��Ϸ��һ��ѭ��
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

void Controller::Start()//��ʼ����
{
	SetColor(10);
	SetCursorPosition(12, 10);
	std::cout << "Press any key to start";
	SetCursorPosition(12, 15);
	system("pause");
}

void Controller::DrawGame()//��ʼ����ͼ
{
	system("cls");

	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitMap();
	delete init_map;
}

int Controller::PlayGame()//��Ϸ�Ķ���ѭ��
{
	/*��ʼ������*/
	Block *cblock = new Block();
	SetColor(6);
	cblock->Create();
	cblock->InitBlock();
	while (!cblock->IsTop())
	{
		if (!cblock->Direction())  //ESC��ʵ�ʲ����а�escû�з�Ӧ����̫�����ô���
		{
			int tmp = 1;//���Ʋ˵������õ�����ֵ
			switch (tmp)
			{
			case 1://������Ϸ
				break;

			case 2://���¿�ʼ
				delete cblock;
				return 1;//��1��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ���¿�ʼ

			case 3://�˳���Ϸ
				delete cblock;
				return 2;//��2��ΪPlayGame�����ķ���ֵ���ص�Game�����У���ʾ�˳���Ϸ

			default:
				break;
			}
		}
		if (cblock->IsBlock())//��ײ
		{
			cblock->BlockStop();
			SetColor(6);
			cblock->Create();
			cblock->InitBlock();
		}
		else//���������½�
		{
			cblock->MoveDown();
		}
		Sleep(speed);//�����Զ��½�ʱ����
	}

	/*GAMEOVER*/
	delete cblock;
	int tmp = GameOver();//������Ϸ�������棬��������ѡ��
	switch (tmp)
	{
	case 1:
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 2;
	}
}

int Controller::GameOver()//��Ϸ��������
{
	/*������Ϸ��������*/
	Sleep(500);  //ͣ���룬��������ִ��
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "��������������������������������������������";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ��               Game Over !!!              ��";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ��              ���ź��������              ��";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ��             ��ķ���Ϊ��                 ��";
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ��   �Ƿ�����һ�֣�                         ��";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ��    �ţ��õ�        ���ˣ�����ѧϰ����˼  ��";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ��                                          ��";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "��������������������������������������������";

	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "�ţ��õ�";
	SetCursorPosition(0, 31);

	/*ѡ�񲿷�*/
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
				std::cout << "�ţ��õ�";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "���ˣ�����ѧϰ����˼";
				--tmp_key;
			}
			break;

		case 77://RIGHT
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "���ˣ�����ѧϰ����˼";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "�ţ��õ�";
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
		return 1;//���¿�ʼ
	case 2:
		return 2;//�˳���Ϸ
	default:
		return 1;
	}
}