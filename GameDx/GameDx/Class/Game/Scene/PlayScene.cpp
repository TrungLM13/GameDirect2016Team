#include "PlayScene.h"


CPlayScene::CPlayScene()
{
	this->initScene();
}


CPlayScene::~CPlayScene()
{
}

bool	CPlayScene::initScene()
{
	CPlayer::getInstance()->initEntity();
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	CPlayer::getInstance()->updateEntity(deltaTime);
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	CPlayer::getInstance()->updateEntity(keyboard);

}

void	CPlayScene::renderScene()
{
	CPlayer::getInstance()->drawEntity();
}