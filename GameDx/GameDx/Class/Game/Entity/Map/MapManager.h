#ifndef _MAP_H_
#define _MAP_H_

#include <vector>
#include "Class\Game\Entity\Map\Tile.h"
#include "Class\Game\Entity\StaticEntity.h"
#include "Class\Game\Entity\Map\Tiless.h"

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
	vector<CBaseEntity*>	getListBonus();
	vector<CTiless*>		getListBackground();
	vector<CBox2D*>			getListRect();
	static CMapManager*		getInstance();
	void pushBonusObject(CBaseEntity* entity);

private:
	static CMapManager*		m_instance;

	vector<MapInfo*>		m_listAllMapInGame;
	std::string				m_currentMapName;

	vector<CTiless*>		m_listBackground;
	vector<CBaseEntity*>	m_listEnemy;
	vector<CBaseEntity*>	m_listBonus;
	vector<CBox2D*>			m_listRectangeForCollision;
};


#endif