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

	m_treeGame->CreateTree();

	CPlayer::getInstance();
	return true;
}

void CPlayScene::updateScene(double deltaTime)
{
	CPlayer::getInstance()->updateEntity(deltaTime);

	CCamera::getInstance()->Update(CPlayer::getInstance()->getPosition());

	m_listObjectInViewport = m_treeGame->Retrieve(CCamera::getInstance()->getBoundingScreen());

	for (int i = 0; i < m_listObjectInViewport.size(); ++i)
		m_listObjectInViewport.at(i)->updateEntity(deltaTime);
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

	if (m_listObjectInViewport.size())
	for (int i = 0; i < m_listObjectInViewport.size(); ++i)
		m_listObjectInViewport.at(i)->drawEntity();
}