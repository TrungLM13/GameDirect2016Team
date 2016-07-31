#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Scene\PopupInfo.h"


CPlayScene::CPlayScene()
{
	this->initScene();
}


CPlayScene::~CPlayScene()
{
	for (int i = 0; i < 100; i++)
	{
		SAFE_RELEASE(this->listCoin.at(i));
		SAFE_RELEASE(this->listStar.at(i));
		SAFE_RELEASE(this->listBrick.at(i));
	}
	
}

bool	CPlayScene::initScene()
{
	CPlayer::getInstance()->initEntity();
	listCoin.push_back(new CCoin());
	listStar.push_back(new CStar());
	listBrick.push_back(new CBrick());
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
	for (int i = 0; i < listStar.size(); i++)
	{
		this->listStar.at(i)->updateEntity(deltaTime);
	}
	for (int i = 0; i < listBrick.size(); i++)
	{
		this->listBrick.at(i)->updateEntity(deltaTime);
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
	CPlayer::getInstance()->drawEntity();
	for (int i = 0; i < listCoin.size(); i++)
	{
		this->listCoin.at(i)->drawEntity();
	}
	for (int i = 0; i < listStar.size(); i++)
	{
		this->listStar.at(i)->drawEntity();
	}

	for (int i = 0; i < listBrick.size(); i++)
	{
		this->listBrick.at(i)->drawEntity();
	}
	
}