#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"


CPlayScene::CPlayScene()
{
	this->initScene();
}


CPlayScene::~CPlayScene()
{
	for (int i = 0; i < listCoin.size(); i++)
	{
		SAFE_RELEASE(this->listCoin.at(i));
	}
}

bool	CPlayScene::initScene()
{
	CPlayer::getInstance()->initEntity();
	listCoin.push_back(new CCoin());
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	static int temp = 0;
	CPlayer::getInstance()->updateEntity(deltaTime);
	for (int i = 0; i < listCoin.size(); i++)
	{
		if (CCollision::CheckCollision(CPlayer::getInstance(), this->listCoin.at(i)) != COLDIRECTION ::COLDIRECTION_NONE)
		{
			temp++;
			this->listCoin.erase(this->listCoin.begin() + i);
		}		
	}
	OutputDebugString(L"SCORE: ");
	OutputDebugString(_itow(temp, new WCHAR[1], 10));
	OutputDebugString(L"\n");
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
	for (int i = 0; i < listCoin.size(); i++)
	{
		this->listCoin.at(i)->drawEntity();
	}
}