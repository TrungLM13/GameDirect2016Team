#include "PlayScene.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Scene\PopupInfo.h"
#include "Class\Mathematics\T_Collision.h"


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
	listRedMushroom.push_back(new CRedMushroom());
	listGiftBox.push_back(new CGiftBox());
	return true;
}

void	CPlayScene::updateScene(double deltaTime)
{
	static int temp = 0;
	CPlayer::getInstance()->updateEntity(deltaTime);

	for (int i = 0; i < listBrick.size(); ++i) {
		listBrick.at(i)->updateEntity(deltaTime);
	}

	for (int i = 0; i < listCoin.size(); i++)
	{
		if (Collision::getInstance()->isCollision(CPlayer::getInstance(), listCoin.at(i)))
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

		if (Collision::getInstance()->isCollision(CPlayer::getInstance(), listStar.at(i)))
		{
			CPlayer::getInstance()->setPlayerTag(PLAYERTAGS::UNDYING);
			CPlayer::getInstance()->loadSprite();
			temp++;
			this->listStar.erase(this->listStar.begin() + i);
		}
	}

	for (int i = 0; i < listBrick.size(); i++)
	{
		static bool isCollision = false;

		if (Collision::getInstance()->isCollision(CPlayer::getInstance(), listBrick.at(i))) {
			// Update Player
			if (CPlayer::getInstance()->getVelocity().y > 0) {
				CPlayer::getInstance()->setVelocity(vector2d(CPlayer::getInstance()->getVelocity().x, CPlayer::getInstance()->getVelocity().y * (-1)));
			}
			// Update Brick
			if (listBrick.at(i)->getVelocity().y < 0) {
				listBrick.at(i)->setVelocity(vector2d(listBrick.at(i)->getVelocity().x, listBrick.at(i)->getVelocity().y * (-1)));
			}
			isCollision = true;
		}
		if (isCollision) {
			if (listBrick.at(i)->getPosition().y > 200) {
				listBrick.at(i)->setVelocity(vector2d(listBrick.at(i)->getVelocity().x, listBrick.at(i)->getVelocity().y * (-1)));
			}
			listBrick.at(i)->setPosition(vector3d(this->listBrick.at(i)->getPosition().x, this->listBrick.at(i)->getPosition().y + this->listBrick.at(i)->getVelocity().y *deltaTime / 50, 0));
		}
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

	CShowBouding::getInstance()->drawBouding(CPlayer::getInstance());

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
		CShowBouding::getInstance()->drawBouding(this->listBrick.at(i));
	}
	
	for (int i = 0; i < listRedMushroom.size(); i++)
	{
		this->listRedMushroom.at(i)->drawEntity();
	}
	for (int i = 0; i < listGiftBox.size(); i++)
	{
		this->listGiftBox.at(i)->drawEntity();
	}
}