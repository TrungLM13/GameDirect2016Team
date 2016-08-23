#include "MapManager.h"
#include <fstream>
#include "Class\Framework\Camera.h"
#include "Class\Game\Scene\PopupInfo.h"
#include "Class\Game\Entity\Enemy\CarnivorousPlants.h"
#include "Class\Game\Entity\Bonus\Brick.h"
#include "Class\Game\Entity\Bonus\GiftBox.h"
#include "Class\Game\Entity\Tile\Castle.h"


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
	m_listBonusItem.clear();
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

vector<CBaseEntity*> CMapManager::getListBonusItem()
{
	return m_listBonusItem;
}

void CMapManager::setListBonusItem(vector<CBaseEntity*> list)
{
	this->m_listBonusItem = list;
}

vector<MapInfo*> CMapManager::getListMapInGame()
{
	return m_listAllMapInGame;
}



bool CMapManager::initMapInfo()
{
	m_listAllMapInGame.push_back(new MapInfo("1-1", "Resource//Data//1-1.txt", 3584, 240));
	m_listAllMapInGame.push_back(new MapInfo("1-2", "Resource//Data//1-2.txt", 3584, 240));
	m_listAllMapInGame.push_back(new MapInfo("1-3", "Resource//Data//1-3.txt", 3584, 240));
	return true;
}

int CMapManager::getCurrentMapINT()
{
	string temp = CPopUpInfo::getInstance()->getMapName();

	if (temp == "1-1")
		return 1;
	if (temp == "1-2")
		return 2;
	if (temp == "1-3")
		return 3;
	return -1;
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
	int type;

	while (data >> type >> positionEntity.x >> positionEntity.y >> size.x >> size.y)
	{
		if (type == TODI::TODI_STARS)
			m_listBonus.push_back(new CBrick(this->getCurrentMapINT(),positionEntity,	BRICK_TYPE::BRICK_STAR));
		if (type == TODI::TODI_COIN)
			m_listBonus.push_back(new CBrick(this->getCurrentMapINT(), positionEntity,	BRICK_TYPE::BRICK_COIN));
		if (type == TODI::TODI_BRICK)
			m_listBonus.push_back(new CBrick(this->getCurrentMapINT(), positionEntity,	BRICK_TYPE::BRICK_NONE));
		if (type == TODI::TODI_GREEN_MUSHROOM_BOX)
			m_listBonus.push_back(new CBrick(this->getCurrentMapINT(), positionEntity,	BRICK_TYPE::BRICK_GREENMUSHROOM));

		if (type == TODI::TODI_RED_MUSHROOM_BOX)
			m_listBonus.push_back(new CGiftBox(positionEntity,							GIFTBOX_TYPE::GIFTBOX_ITEMINBOX_TYPE));
		if (type == TODI::TODI_GIFT_BOX)
			m_listBonus.push_back(new CGiftBox(positionEntity,							GIFTBOX_TYPE::GIFTBOX_NONE));
		
		if (type == TODI::TODI_CASTLE)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_CASTTLE));
		if ((type == TODI::TODI_CEMENT))
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_CEMENT_BARRIER_RED));

		if ((type == TODI::TODI_LANDSCAPE))
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_CEMENT_LANE_RED));

		if (type == TODI::TODI_CLOUND_ONE)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_CLOUND_ONE_MEMBER));
		if (type == TODI::TODI_CLOUND_DOUBLE)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_CLOUND_TOW_MEMBER));
		if (type == TODI::TODI_CLOUND_TRIPPLE)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_CLOUND_THREE_MEMBER));
		
		if (type == TODI::TODI_GRASS_ONE_BRUSH)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_GRASS_ONE_BUSH));
		if (type == TODI::TODI_GRASS_DOUBLE_BRUSH)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_GRASS_TOW_BUSH));
		if (type == TODI::TODI_GRASS_TRIPPLE_BRUSH)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_GRASS_THREE_BUSH));
		
		if (type == TODI::TODI_HEAD_MOUNTAIN)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_MOUNTAIN_SMALL));
		if (type == TODI::TODI_TAIL_MOUNTAIN)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_MOUNTAIN_BIG));

		if (type == TODI::TODI_PIPE_HEAD)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_PIPE_HEAD_DOWN));
		if (type == TODI::TODI_PIPE_HEAD_BODY)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_PIPE_HEAD_BODY_DOWN));
		if (type == TODI::TODI_PIPE_BODY)
			m_listBackground.push_back(new CTiless(positionEntity,						TileStyle::TOF_PIPE_BODY_DOWN));

		if (type == TODI::TODI_RECTANGLE)
			m_listRectangeForCollision.push_back(new CBox2D(positionEntity.x, positionEntity.y - 16, size.x, size.y));
	}

	return true;
}

void CMapManager::pushBonusObject(CBaseEntity* entity)
{
	m_listBonusItem.push_back(entity);
}

void CMapManager::popBonusObject()
{
	m_listBonusItem.pop_back();
}

void CMapManager::pushInFirst(CBaseEntity* entity)
{
	m_listBonusItem.insert(m_listBonus.begin(), entity);
}

void CMapManager::removeInFirst() {
	m_listBonusItem.erase(m_listBonus.begin());
}

void CMapManager::removeEntity(vector<CBaseEntity*>& list, int tagnode)
{
	for (int i = 0; i < list.size(); ++i)
	{
		if (list.at(i)->getTagNodeId() == tagnode)
			list.erase(list.begin() + i);
	}

}