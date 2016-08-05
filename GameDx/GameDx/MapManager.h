#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include "Class\Game\Entity\Map\Tile.h"
#include "Class\Game\Entity\StaticEntity.h"

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