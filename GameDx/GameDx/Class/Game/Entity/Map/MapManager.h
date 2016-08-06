#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include "Class\Game\Entity\Map\Tile.h"
#include "Class\Game\Entity\StaticEntity.h"
#include "Class\Game\Entity\Map\Grass.h"

using namespace std;

class CMapManager
{
public:
	CMapManager();
	~CMapManager();

	bool	initMapInfo();
	bool	loadEntityInMap();

public:
	vector<CBaseEntity*>	getListEnemy();
	vector<CBaseEntity*>	getListBackground();
	static CMapManager*		getInstance();

private:
	static CMapManager*		m_instance;

	vector<MapInfo*>		m_listAllMapInGame;
	std::string				m_currentMapName;

	vector<CBaseEntity*>			m_listBackground;
	vector<CBaseEntity*>	m_listEnemy;
	vector<CBaseEntity*>	m_listBonus;
};


#endif