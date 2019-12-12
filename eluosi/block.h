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
	void InitBlock();//��ʼ������
	void Create();//������ɷ���
	void MoveUp();//��ת
	void MoveRight();//����
	void MoveLeft();//����
	void MoveDown();//�½�
	void BlockStop();//����ֹͣ������
	bool IsBlock();//�ж��·��Ƿ�Ϊ����
	bool Direction();//���̲���
	bool IsTop();//�ж��Ƿ���Ϸ����
private:
	bool grid[10][21];
	std::vector<Point> arrays;
};

#endif //BLOCK_H