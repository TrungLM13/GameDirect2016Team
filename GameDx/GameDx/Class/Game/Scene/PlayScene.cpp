#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Scene\PopupInfo.h"
#include "Class\Game\Entity\Bonus\GreenMushroom.h"

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
		SAFE_RELEASE(this->listMovable.at(i));
	}

}

bool	CPlayScene::initScene()
{
	CPlayer::getInstance()->initEntity();
	listCoin.push_back(new CCoin());
	listStar.push_back(new CStar());
	listBrick.push_back(new CBrick(1));
	listIteminbox.push_back(new CIteminbox());
	listGiftBox.push_back(new CGiftBox());
	listMushroom.push_back(new CMushroom());
	listMovable.push_back(new CGreenMushroom());
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	static int temp = 0;
	CPlayer::getInstance()->updateEntity(deltaTime);

	for (int i = 0; i < listMushroom.size(); ++i) {
		listMushroom.at(i)->updateEntity(deltaTime);
	}

	for (int i = 0; i < listBrick.size(); ++i) {
		listBrick.at(i)->updateCollision(CPlayer::getInstance(), deltaTime);
	}

	OutputDebugString(L"SCORE: ");
	OutputDebugString(_itow(temp, new WCHAR[1], 10));
	OutputDebugString(L"\n");

	for (int i = 0; i < listBrick.size(); i++)
	{
//Update Brick after collision with player
		this->listBrick.at(i)->updateCollision(CPlayer::getInstance(), deltaTime);
	}
	for (int i = 0; i < listIteminbox.size(); i++)
	{
		this->listIteminbox.at(i)->updateEntity(deltaTime);
	}
	listGiftBox.at(0)->updateCollision(CPlayer::getInstance(), deltaTime);
}

void	CPlayScene::updateScene(CKeyBoard* keyboard)
{
	if (keyboard->KeyPress(DIK_P))
		return;

	CPlayer::getInstance()->updateEntity(keyboard);

	for (int i = 0; i < listMushroom.size(); i++)
	{
		this->listMushroom.at(i)->updateEntity(keyboard);
	}

}

void	CPlayScene::renderScene()
{
	CPlayer::getInstance()->drawEntity();

	CShowBouding::getInstance()->drawBouding(CPlayer::getInstance());

	for (int i = 0; i < listBrick.size(); i++)
	{
		this->listBrick.at(i)->drawEntity();
	}

	for (int i = 0; i < listIteminbox.size(); i++)
	{
		this->listIteminbox.at(i)->drawEntity();
	}
	for (int i = 0; i < listMushroom.size(); i++)
	{
		this->listMushroom.at(i)->drawEntity();
	}
	for (int i = 0; i < listMovable.size(); i++)
	{
		listMovable.at(i)->drawEntity();
	}
	listGiftBox.at(0)->drawEntity();
}