#include "MapManager.h"
#include <fstream>
#include "Class\Framework\Camera.h"
#include "Class\Game\Scene\PopupInfo.h"
#include "Class\Game\Entity\Enemy\CarnivorousPlants.h"


CMapManager* CMapManager::m_instance = NULL;

CMapManager::CMapManager()
{
	this->initMapInfo();
	this->loadEntityInMap();
}

CMapManager::~CMapManager()
{
	m_listAllMapInGame.clear();
	m_listBackground.clear();
	m_listBonus.clear();
	m_listEnemy.clear();
	m_listRectangeForCollision.clear();
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

vector<CBaseEntity*>	CMapManager::getListBonus()
{
	return m_listBonus;
}

void CMapManager::setListBonus(vector<CBaseEntity*> list) {
	m_listBonus = list;

}

vector<CTiless*> CMapManager::getListBackground()
{
	return m_listBackground;
}

vector<CBox2D*>	CMapManager::getListRect()
{
	return m_listRectangeForCollision;
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

	string filePath = "Resource\\Data\\" + CPopUpInfo::getInstance()->getMapName() + ".txt";

	// convert to unicode
	int wchars_num = MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[wchars_num];
	MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), -1, wstr, wchars_num);

	data.open(wstr);

	vector2d positionEntity;
	vector2d size;
	string type;

	while (data >> type >> positionEntity.x >> positionEntity.y >> size.x >> size.y)
	{
		/*if (type == "3E")
			m_listBonus.push_back(new CCarnivorousPlants());*/
		if (type == "1B")
			m_listBonus.push_back(new CBrick(positionEntity, BRICK_TYPE::BRICK_STAR));
		if (type == "2B")
			m_listBonus.push_back(new CBrick(positionEntity, BRICK_TYPE::BRICK_COIN));
		/*if (type == "3B")
			m_listBonus.push_back(new CBrick(positionEntity, BRICK_TYPE::BRICK_NONE));
		if (type == "4B")
			m_listBonus.push_back(new CGiftBox(positionEntity, GIFTBOX_TYPE::GIFTBOX_ITEMINBOX_TYPE));
		if (type == "5B")
			m_listBonus.push_back(new CGiftBox(positionEntity, GIFTBOX_TYPE::GIFTBOX_COIN));
		if (type == "6B")
			m_listBonus.push_back(new CGiftBox(positionEntity, GIFTBOX_TYPE::GIFTBOX_NONE));
		if (type == "7B")
			m_listBonus.push_back(new CBrick(positionEntity, BRICK_TYPE::BRICK_GREENMUSHROOM));
		/*if (type == "8B")
			m_listBonus.push_back(new Elevator(positionEntity, ELEVATOR_STATE::UP_DOWN));
		if (type == "9B")
			m_listBonus.push_back(new Elevator(positionEntity, ELEVATOR_STATE::RIGHT_LEFT));*/
		if (type == "R")
			m_listRectangeForCollision.push_back(new CBox2D(positionEntity.x, positionEntity.y, size.x, size.y));
		if (type == "1T")
			m_listBackground.push_back(new CTiless(positionEntity, TileStyle::TOF_CEMENT_LANE_RED));
	}

	return true;
}

void CMapManager::pushBonusObject(CBaseEntity* entity)
{
	m_listBonus.push_back(entity);
}

void CMapManager::popBonusObject()
{
	m_listBonus.pop_back();
}

void CMapManager::pushInFirst(CBaseEntity* entity)
{
	m_listBonus.insert(m_listBonus.begin(), entity);
}

void CMapManager::removeInFirst() {
	m_listBonus.erase(m_listBonus.begin());
}

void CMapManager::removeEntity(vector<CBaseEntity*>& list, int tagnode)
{
	for (int i = 0; i < list.size(); ++i)
	{
		if (list.at(i)->getTagNodeId() == tagnode)
			list.erase(list.begin() + i);
	}

}