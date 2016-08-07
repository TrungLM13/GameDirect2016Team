#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Scene\PopupInfo.h"

#include "Class\Game\Entity\Map\MapManager.h"

#include "Class\Game\State\StandState.h"
#include "Class\Mathematics\Collision.h"


CPlayScene::CPlayScene()
{
	this->initScene();
}

CPlayScene::~CPlayScene()
{
	m_ListEntity.clear();
}

bool	CPlayScene::initScene()
{
	CMapManager::getInstance();

	CPlayer::getInstance();

	m_ListEntity.push_back(new CStar());
	m_ListEntity.push_back(new CRedMushroom());
	m_ListEntity.push_back(new CFlag());
	m_ListEntity.push_back(new CFlagPole());
	m_ListEntity.push_back(new CFlagPoleTail());
	m_ListEntity.push_back(new CTile());
	m_ListEntity.push_back(new CBrick());
	m_ListEntity.push_back(new CMushroom());
//	m_ListEntity.push_back(Turtle::getInstance());

	//Turtle::getInstance()->initEntity();
	Elevator::getInstance()->initEntity();



	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	CPlayer::getInstance()->updateEntity(deltaTime);
	Turtle::getInstance()->updateEntity(deltaTime);
	Elevator::getInstance()->updateEntity(deltaTime);


	for (int i = 0; i < CMapManager::getInstance()->getListEnemy().size(); ++i)
	{
		CMapManager::getInstance()->getListEnemy().at(i)->updateEntity(deltaTime);
	}

	CCamera::getInstance()->Update(CPlayer::getInstance()->getPosition());

	for (int i = 0; i < m_ListEntity.size(); ++i) {
		m_ListEntity.at(i)->updateEntity(deltaTime);
		
		CPlayer::getInstance()->handleCollision(m_ListEntity.at(i), deltaTime);
		for (int j = 0; j < m_ListEntity.size(); ++j) {
			m_ListEntity.at(i)->handleCollision(m_ListEntity.at(j), deltaTime);
		}
	}

}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	CPlayer::getInstance()->updateEntity(keyboard);

	Turtle::getInstance()->updateEntity(keyboard);
	Elevator::getInstance()->updateEntity(keyboard);
}

void	CPlayScene::renderScene()
{
	for (int i = 0; i < CMapManager::getInstance()->getListBackground().size(); ++i)
	{
		CMapManager::getInstance()->getListBackground().at(i)->drawEntity();
	}
	CPlayer::getInstance()->drawEntity();


	CShowBouding::getInstance()->drawBouding(CPlayer::getInstance());

	//CPlayer::getInstance()->drawEntity();
	Turtle::getInstance()->drawEntity();
	Elevator::getInstance()->drawEntity();
	//CShowBouding::getInstance()->drawBouding(CPlayer::getInstance());
	//CShowBouding::getInstance()->drawBouding(Turtle::getInstance());



	for (int i = 0; i < CMapManager::getInstance()->getListEnemy().size(); ++i)
	{
		CMapManager::getInstance()->getListEnemy().at(i)->drawEntity();
	}

	for (int i = 0; i < m_ListEntity.size(); ++i)
	{
		m_ListEntity.at(i)->drawEntity();
		CShowBouding::getInstance()->drawBouding(m_ListEntity.at(i));
	}


}