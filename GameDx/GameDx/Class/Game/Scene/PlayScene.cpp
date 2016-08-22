#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Scene\PopupInfo.h"
#include "Class\Game\Entity\Map\MapManager.h"
#include "Class\Game\Algorithsm\QuadTree.h"
#include "Class\Game\Entity\Player\Player.h"

CPlayScene::CPlayScene()
{
	this->initScene();
}

CPlayScene::~CPlayScene()
{

}

bool CPlayScene::initScene()
{
	CMapManager::getInstance();
	m_treeGame = new CQuadTree();
	m_Sound = CAudio::getInstance()->LoadSound(L"Resource//Sound//Pokemon_Pokemon_-_No.wav");
	m_treeGame->CreateTree();
	CPlayer::getInstance();
	return true;
}

void CPlayScene::updateScene(double deltaTime)
{
	CAudio::getInstance()->PlaySoundW(m_Sound);
	CPlayer::getInstance()->updateEntity(deltaTime);
	/*for (int i = 0; i < CMapManager::getInstance()->getListBonus().size(); i++)
	{
	CMapManager::getInstance()->getListBonus().at(i)->updateEntity(deltaTime);
	}*/

	CCamera::getInstance()->Update(CPlayer::getInstance()->getPosition());

	m_listObjectInViewport = m_treeGame->Retrieve(CCamera::getInstance()->getBoundingScreen());

	for (int i = 0; i < m_listObjectInViewport.size(); ++i) {
		if (m_listObjectInViewport.at(i)->getObjectType() == OBJECT_TYPE::TYPE_BONUS) {
			CPlayer::getInstance()->handleCollisionWithBonus(m_listObjectInViewport.at(i), deltaTime);
		}
		else if (m_listObjectInViewport.at(i)->getObjectType() == OBJECT_TYPE::TYPE_ENERMY) {
			CPlayer::getInstance()->handleCollisionWithEnermy(m_listObjectInViewport.at(i), deltaTime);
		}
		else if (m_listObjectInViewport.at(i)->getObjectType() == OBJECT_TYPE::TYPE_TILE) {
			CPlayer::getInstance()->handleCollisionWithTile(deltaTime);
		}
		m_listObjectInViewport.at(i)->updateEntity(deltaTime);
	}
	if (CMapManager::getInstance()->getListBonusItem().size() != 0)
	{
		for (int i = 0; i < CMapManager::getInstance()->getListBonusItem().size(); i++)
		{
			CMapManager::getInstance()->getListBonusItem().at(i)->updateEntity(deltaTime);
		}
	}
}

void CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;
	CPlayer::getInstance()->updateEntity(keyboard);
}

void CPlayScene::renderScene()
{
	CPlayer::getInstance()->drawEntity();
	if (CMapManager::getInstance()->getListBonusItem().size() != 0)
	{
		for (int i = 0; i < CMapManager::getInstance()->getListBonusItem().size(); i++)
		{
			CMapManager::getInstance()->getListBonusItem().at(i)->drawEntity();
		}
	}
	if (m_listObjectInViewport.size())
	for (int i = 0; i < m_listObjectInViewport.size(); ++i)
		m_listObjectInViewport.at(i)->drawEntity();
}