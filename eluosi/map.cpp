#include "map.h"
#include <windows.h>

void Map::PrintInitMap()
{
	for (auto& point : initmap)
	{
		point.Print();
		Sleep(10);
	}
}