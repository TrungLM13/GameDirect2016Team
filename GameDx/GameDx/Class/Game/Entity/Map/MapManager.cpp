#include "MapManager.h"
#include <fstream>
#include "Class\Framework\Camera.h"
#include "Class\Game\Scene\PopupInfo.h"

CMapManager* CMapManager::m_instance = NULL;

CMapManager::CMapManager()
{
	this->initMapInfo();
	this->loadEntityInMap();
}

CMapManager::~CMapManager()
{

}

CMapManager* CMapManager::getInstance()
{
	if (!m_instance)
		m_instance = new CMapManager();

	return m_instance;
}

vector<CBaseEntity*> CMapManager::getListEnemy()
{
	return m_listEnemy;
}

bool CMapManager::initMapInfo()
{
	m_listAllMapInGame.push_back(new MapInfo("1-1", "Resource//Data//1-1.txt"));
	m_listAllMapInGame.push_back(new MapInfo("1-2", "Resource//Data//1-2.txt"));
	m_listAllMapInGame.push_back(new MapInfo("1-3", "Resource//Data//1-3.txt"));
	return true;
}

bool CMapManager::loadEntityInMap()
{

	ifstream data;

	string filePath			= "Resource\\Data\\" + CPopUpInfo::getInstance()->getMapName() + ".txt";

	// convert to unicode
	int wchars_num			= MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), -1, NULL, 0);
	wchar_t* wstr			= new wchar_t[wchars_num];
	MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), -1, wstr, wchars_num);
	
	data.open(wstr);

	vector2d positionEntity;
	string type;

	while (data >> type >> positionEntity.x >> positionEntity.y)
	{
		if (type == "1E")
			m_listEnemy.push_back(new CBrick(positionEntity));
		if (type == "1B")
			m_listBonus.push_back(new CBrick(positionEntity));
	}
	return true;
}
