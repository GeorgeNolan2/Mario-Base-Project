#pragma once

#ifndef LEVELMAP_H
#define LEVELMAP_H

#include "Constants.h"

class LevelMap
{
public:
	LevelMap(int map[MAP_HEIGHT][MAP_WIDTH]);
	~LevelMap();
	int GetTileAt(unsigned int h, unsigned int w);

private:
	int** m_map;
};

#endif // !LEVELMAP_H

