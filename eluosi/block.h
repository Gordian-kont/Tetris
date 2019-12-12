#ifndef BLOCK_H
#define BLOCK_H

#include<stdlib.h>
#include<time.h>
#include<vector>
#include"point.h"

class Block
{
public:
	Block();
	void InitBlock();//初始化方块
	void Create();//随机生成方块
	void MoveUp();//旋转
	void MoveRight();//右移
	void MoveLeft();//左移
	void MoveDown();//下降
	void BlockStop();//方块停止并消行
	bool IsBlock();//判断下方是否为方块
	bool Direction();//键盘操作
	bool IsTop();//判断是否游戏结束
private:
	bool grid[10][21];
	std::vector<Point> arrays;
};

#endif //BLOCK_H