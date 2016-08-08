#include "Brick.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\Bonus\CoinInBox.h"

CBrick::CBrick()
{
	this->initEntity();
}
CBrick::CBrick(int isGift)
{
	this->isGiftBox = isGift;
	this->initEntity();
}

CBrick:: ~CBrick()
{
}

bool CBrick::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::box, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brick, 1, 1, 1, 0));
	return true;
}

bool CBrick::initEntity()
{
	this->counttime = 0;
	this->stateBrick = 1;
	isDraw = false;
	checkShowItem();
	m_Position = vector3d(150, 150, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(5.8, 5.8);
	return true;
}

void CBrick::updateEntity(CKeyBoard* device)
{

}

void CBrick::updateEntity(float deltaTime)
{
}

void CBrick::drawEntity()
{
	this->m_listSprite.at(this->stateBrick)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	if (isDraw)
	{
		counttime++;
		if (isGiftBox == 0)
		{
			ItemCoin->drawEntity();
		}
		if (isGiftBox == 1)
		{
			ItemStar->drawEntity();
		}
	}
}

void CBrick::updateEntity(RECT* camera)
{

}

void CBrick::setPosition(vector3d position) {
	m_Position = position;
}

void CBrick::setVelocity(vector2d velocity) {
	m_Velocity = velocity;
}

void CBrick::setGiftBox(bool check)
{
	isGiftBox = check;
}

void CBrick::updateCollision(CBaseEntity* player, float deltaTime)
{
	if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_BOTTOM)
	{

		if (this->getVelocity().y < 0)
			this->setVelocity(vector2d(this->getVelocity().x, this->getVelocity().y*(-1)));
		if (isGiftBox == 0)
		{
			ItemCoin = new CCoinInBox();
			isDraw = true;
			ItemCoin->drawEntity();
			ItemCoin->setVelocity(vector2d(0, 8));
		}
		if (isGiftBox == 1)
		{
			ItemStar = new CStar();
			isDraw = true;
			ItemStar->drawEntity();
			ItemStar->setVelocity(vector2d(0, 0.2));
			ItemStar->updateEntity(deltaTime);
		}
	}
	else{
		if (this->getVelocity().y > 0)
			this->setVelocity(vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1)));
	}
	this->setPosition(vector3d(this->m_Position.x, this->m_Position.y + this->m_Velocity.y* deltaTime / 50, 0));
	if (this->m_Position.y < 150)
	{
		this->setPosition(vector3d(150, 150, 0));
	}
	if (isGiftBox == 0 && isDraw)
	{
		ItemCoin->updateEntity(deltaTime);
		this->stateBrick = 0;
	}
	if (isGiftBox == 1 && isDraw)
	{
		if (ItemStar->getPosition().y >= 166)
		{
			ItemStar->setVelocity(vector2d(5, 5));
		}
		ItemStar->updateEntity(deltaTime);
		this->stateBrick = 0;
	}
}

void CBrick::checkShowItem()
{
	if (isGiftBox == 0)
	{
		this->m_TagNode = "BrickHaveCoin";
	}
	else
	{
		if (isGiftBox == 1)
		{
			this->m_TagNode = "BrickHaveStar";
		}
		else
		{
			this->m_TagNode = "Brick";
			this->stateBrick = 1;
		}
	}
}