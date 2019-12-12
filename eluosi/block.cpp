#include<conio.h>  
#include<Windows.h>
#include<iostream>
#include"tools.h"
#include"block.h"

Block::Block()  
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			grid[i][j] = false;//判断当前格子是否为方块，true是，false不是         
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		grid[i][20] = true;
	}
}

void Block::InitBlock()
{
	for (auto& point : arrays)
	{
		point.Print();
	}
}

void Block::Create() 
{
	int key;
	int rotate_srand;
	srand((unsigned)time(NULL));
	key = rand() % 7;
	rotate_srand = rand() %2;
	switch (key)
	{
	case 0://直线型
		arrays.clear();
		arrays.emplace_back(Point(6, 3));
		arrays.emplace_back(Point(5, 3));
		arrays.emplace_back(Point(7, 3));
		arrays.emplace_back(Point(8, 3));
		for (int i = 0; i < rotate_srand; ++i)
		{
			MoveUp();
		}
		break;
	case 1://田字型
		arrays.clear();
		arrays.emplace_back(Point(6, 2));
		arrays.emplace_back(Point(7, 2));
		arrays.emplace_back(Point(6, 3));
		arrays.emplace_back(Point(7, 3));
		break;
	case 2://正7字型
		arrays.clear();
		arrays.emplace_back(Point(6, 2));
		arrays.emplace_back(Point(7, 2));
		arrays.emplace_back(Point(7, 3));
		arrays.emplace_back(Point(7, 4));
		for (int i = 0; i < rotate_srand; ++i)
		{
			MoveUp();
		}
		break;
	case 3://反7字型
		arrays.clear();
		arrays.emplace_back(Point(6, 2));
		arrays.emplace_back(Point(6, 3));
		arrays.emplace_back(Point(7, 3));
		arrays.emplace_back(Point(8, 3));
		for (int i = 0; i < rotate_srand; ++i)
		{
			MoveUp();
		}
		break;
	case 4://正梯型
		arrays.clear();
		arrays.emplace_back(Point(7, 3));
		arrays.emplace_back(Point(6, 3));
		arrays.emplace_back(Point(7, 4));
		arrays.emplace_back(Point(8, 4));
		for (int i = 0; i < rotate_srand; ++i)
		{
			MoveUp();
		}
		break;
	case 5://反梯型
		arrays.clear();
		arrays.emplace_back(Point(7, 3));
		arrays.emplace_back(Point(8, 3));
		arrays.emplace_back(Point(6, 4));
		arrays.emplace_back(Point(7, 4));
		for (int i = 0; i < rotate_srand; ++i)
		{
			MoveUp();
		}
		break;
	case 6://T型
		arrays.clear();
		arrays.emplace_back(Point(6, 3));
		arrays.emplace_back(Point(5, 3));
		arrays.emplace_back(Point(6, 2));
		arrays.emplace_back(Point(7, 3));
		for (int i = 0; i < rotate_srand; ++i)
		{
			MoveUp();
		}
		break;
	}
}

void Block::MoveUp()//旋转函数 这里应该还要考虑一字型等方块在边界附近是否可以旋转的问题，但我懒
{
	for (auto& point : arrays)
	{
		point.Clear();
	}
	for (int i = 1; i < 4; ++i)
	{
		int gap1 = arrays[i].GetX() - arrays[0].GetX();
		int gap2 = arrays[i].GetY() - arrays[0].GetY();
		arrays[i].ChangePosition(arrays[0].GetX() - gap2, arrays[0].GetY() + gap1);
	}
	SetColor(6);
	InitBlock();
}

void Block::MoveRight()//右移
{	
	bool flag = true;
	for (int i = 0; i < 4; ++i)
	{
		if ( (arrays[i].GetX() >= 11) || (grid[arrays[i].GetX()-1][arrays[i].GetY()-2]==true))
		{
			flag = false;
			break;
		}
	}
	if(flag == true)
	{
		for (auto& point : arrays)
		{
			point.Clear();
		}
		for (int i = 0; i < 4; ++i)
	    {
		    arrays[i].ChangePosition(arrays[i].GetX() + 1, arrays[i].GetY());
			SetColor(6);
	    }
		SetColor(6);
		InitBlock();
	}	
}

void Block::MoveLeft()//左移
{
	bool flag = true;
	for (int i = 0; i < 4; ++i)
	{
		if (arrays[i].GetX() <= 2 || (grid[arrays[i].GetX() - 3][arrays[i].GetY()-2] == true))
		{
			flag = false;
			break;
		}
	}
	if(flag == true)
	{
		for (auto& point : arrays)
		{
			point.Clear();
		}
		for (int i = 0; i < 4; ++i)
		{			
			arrays[i].ChangePosition(arrays[i].GetX() - 1, arrays[i].GetY());
			
		}
		SetColor(6);
		InitBlock();
	}
}

void Block::MoveDown()//下降
{
	bool flag = IsBlock();
	if (flag == false)
	{
		for (auto& point : arrays)
		{
			point.Clear();
		}
		for (int i = 0; i < 4; ++i)
		{
		arrays[i].ChangePosition(arrays[i].GetX(), arrays[i].GetY()+1);
		}
		SetColor(6);
		InitBlock();
	}
	
}

void Block::BlockStop()//方块停止并检测消行
{
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].GetX() - 2][arrays[i].GetY() - 2] = true;
	}
	for (int j = 19; j > 1; j--)
	{
		bool flag = false;
		for (int i = 0; i < 10; ++i)
		{
			if (grid[i][j] == false)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		for (int m = j; m > 1; m--)
		{
			for (int n = 0; n < 10; n++)
			{
				grid[n][m] = grid[n][m-1];
			}
		}
		**j++;** //这是后来修改的，可以同时消除多行
	}
	SetColor(13);
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 2; j < 20; ++j)
		{
			if (grid[i][j] == true)
			{
				SetCursorPosition(i + 2, j + 2);				
				std::cout << "■";
			}
			else
			{
				SetCursorPosition(i + 2, j + 2);
				std::cout << "  ";
			}
		}
	}
}

bool Block::IsBlock()//判断下方是否方块
{
	for (int i = 0; i < 4; ++i)
	{
		if (grid[arrays[i].GetX() -2][arrays[i].GetY()-1] == true)
		{
			return true;
		}
	}
	return false;
}

bool Block::Direction()
{
	char ch;
	if (_kbhit()) //判断是否有键被按下
	{
		ch = _getch();
		switch (ch)
		{
		case -32:
			ch = _getch();
			switch (ch)
			{
			case 72:
				MoveUp();
				break;
			case 80:
				MoveDown();
				break;
			case 75:
				MoveLeft();
				break;
			case 77:
				MoveRight();
				break;
			default:
				break;
			}
			return true;
			return true;
		case 27:   //ESC
			return false;
		default:
			return false;
		}
	}
	return true;
}

bool Block::IsTop() //判断是否有方块到顶
{
	for (int i = 0; i < 10; ++i)
	{
		if (grid[i][2] == true)
			return true;
	}
	return false;
}

