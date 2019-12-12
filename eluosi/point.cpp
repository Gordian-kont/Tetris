#include "point.h"
#include "tools.h"
#include <iostream>

void Point::Print()
{
	SetCursorPosition(x, y);
	std::cout << "■";    //window+R打开运行界面，输入charmap寻找特殊字符
}

void Point::Clear()
{
	SetCursorPosition(x, y);
	std::cout << "  ";   //清除当前位置的字符
}

void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
