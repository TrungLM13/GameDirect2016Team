#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Scene\PopupInfo.h"
#include "Class\Game\Entity\Map\MapManager.h"

CPlayScene::CPlayScene()
{
	this->initScene();
}


CPlayScene::~CPlayScene()
{

}

bool	CPlayScene::initScene()
{
	CPlayer::getInstance();
	CMapManager::getInstance();
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	static int temp = 0;
	CPlayer::getInstance()->updateEntity(deltaTime);
	for (int i = 0; i < CMapManager::getInstance()->getListEnemy().size(); ++i)
	{
		CMapManager::getInstance()->getListEnemy().at(i)->updateEntity(deltaTime);
	}
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	CPlayer::getInstance()->updateEntity(keyboard);
}

void	CPlayScene::renderScene()
{
	for (int i = 0; i < CMapManager::getInstance()->getListBackground().size(); ++i)
	{
		CMapManager::getInstance()->getListBackground().at(i)->drawEntity();
	}
	CPlayer::getInstance()->drawEntity();

	CShowBouding::getInstance()->drawBouding(CPlayer::getInstance());

	for (int i = 0; i < CMapManager::getInstance()->getListEnemy().size(); ++i)
	{
		CMapManager::getInstance()->getListEnemy().at(i)->drawEntity();
	}
}