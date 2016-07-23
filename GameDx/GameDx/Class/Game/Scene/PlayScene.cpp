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
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

}

void	CPlayScene::renderScene()
{
}