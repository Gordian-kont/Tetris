#ifndef MAP_H
#define MAP_H

#include<vector>
#include"point.h"

class Map                
{
public:
	Map()
	{
		for (int i = 1; i < 13; ++i)
		{
			initmap.emplace_back(Point(i, 1));
		}
		initmap.emplace_back(Point(1, 2));
		initmap.emplace_back(Point(12, 2));
		initmap.emplace_back(Point(1, 3));
		initmap.emplace_back(Point(12, 3));
		initmap.emplace_back(Point(1, 4));
		initmap.emplace_back(Point(12, 4));
		initmap.emplace_back(Point(1, 5));
		initmap.emplace_back(Point(12, 5));
		initmap.emplace_back(Point(1, 6));
		initmap.emplace_back(Point(12, 6));
		initmap.emplace_back(Point(1, 7));
		initmap.emplace_back(Point(12, 7));
		initmap.emplace_back(Point(1, 8));
		initmap.emplace_back(Point(12, 8));
		initmap.emplace_back(Point(1, 9));
		initmap.emplace_back(Point(12, 9));
		initmap.emplace_back(Point(1, 10));
		initmap.emplace_back(Point(12, 10));
		initmap.emplace_back(Point(1, 11));
		initmap.emplace_back(Point(12, 11));
		initmap.emplace_back(Point(1, 12));
		initmap.emplace_back(Point(12, 12));
		initmap.emplace_back(Point(1, 13));
		initmap.emplace_back(Point(12, 13));
		initmap.emplace_back(Point(1, 14));
		initmap.emplace_back(Point(12, 14));
		initmap.emplace_back(Point(1, 15));
		initmap.emplace_back(Point(12, 15));
		initmap.emplace_back(Point(1, 16));
		initmap.emplace_back(Point(12, 16));
		initmap.emplace_back(Point(1, 17));
		initmap.emplace_back(Point(12, 17));
		initmap.emplace_back(Point(1, 18));
		initmap.emplace_back(Point(12, 18));
		initmap.emplace_back(Point(1, 19));
		initmap.emplace_back(Point(12, 19));
		initmap.emplace_back(Point(1, 20));
		initmap.emplace_back(Point(12, 20));
		initmap.emplace_back(Point(1, 21));
		initmap.emplace_back(Point(12, 21));
		for (int i = 1; i < 13; ++i)
		{
			initmap.emplace_back(Point(i, 22));
		}
	}
	void PrintInitMap();
private:
	std::vector<Point> initmap;
};

#endif //MAP_H