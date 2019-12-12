#include "point.h"
#include "tools.h"
#include <iostream>

void Point::Print()
{
	SetCursorPosition(x, y);
	std::cout << "��";    //window+R�����н��棬����charmapѰ�������ַ�
}

void Point::Clear()
{
	SetCursorPosition(x, y);
	std::cout << "  ";   //�����ǰλ�õ��ַ�
}

void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;
}
