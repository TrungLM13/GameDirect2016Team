#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include "Game\Entity\Map\Tile.h"
#include "Game\Entity\StaticEntity.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();
	
	vector<CTile *> listTile;

	vector<CSprite *> m_listSprite;

	bool initEntity();
	void drawEntity();
	//void Update(float);
public:
	
};


#endif