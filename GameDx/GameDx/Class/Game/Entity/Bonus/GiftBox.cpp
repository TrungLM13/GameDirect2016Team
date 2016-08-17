#include "GiftBox.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\Map\MapManager.h"

CGiftBox::CGiftBox()
{
	this->initEntity();
}

CGiftBox::CGiftBox(vector2d pos, GIFTBOX_TYPE type)
{
	this->m_Position.x = pos.x;
	this->m_Position.y = pos.y;

	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	this->m_Velocity = vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y);

	this->m_GiftBoxType = type;

	this->initEntity();

}

CGiftBox:: ~CGiftBox()
{
	SAFE_RELEASE(m_Coin);
	SAFE_RELEASE(m_itemInBox);
}

bool CGiftBox::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::box, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::giftbox, 1, 1, 1, 0));
	return true;
}

bool CGiftBox::initEntity()
{
	m_itemInBox = nullptr;
	m_Coin = nullptr;

	this->m_GiftBoxEvent = GIFTBOX_BRICK_EVENT::EVENT_NONE;
	this->m_GiftBoxState = GIFTBOX_STATE::GIFTBOX_NORMAL;

	this->loadSprite();

	return true;
}

void CGiftBox::updateEntity(CKeyBoard* device)
{

}

void CGiftBox::updateEntity(float deltaTime)
{
	switch (CCollision::CheckCollision(CPlayer::getInstance(), this))
	{
	case COLDIRECTION::COLDIRECTION_BOTTOM:
		if (this->m_GiftBoxState == GIFTBOX_STATE::GIFTBOX_NORMAL)
		{
			m_Velocity.y = VEL_DEFAULT_Y + GIFTBOX_VELOCITY_MAX_Y;

			this->m_GiftBoxEvent = GIFTBOX_BRICK_EVENT::EVENT_PROCCESSING;
			this->m_GiftBoxState = GIFTBOX_STATE::GIFTBOX;
		}
		else if (this->m_GiftBoxState == GIFTBOX_STATE::GIFTBOX)
		{

		}
		break;
	case COLDIRECTION::COLDIRECTION_TOP:
		break;
	default:
		break;
	}

	if (m_Position.y >= GIFTBOX_PRE_POSITION_Y_MAX)
	{
		if (m_Velocity.y > 0)
		{
			m_Velocity.y = CHANGE_DIRECTION(m_Velocity.y);
		}
	}

	if (SIGN(m_Velocity.y) == DIRECTION::DIRECTION_DOWN)
	{
		if (m_Position.y <= GIFTBOX_PRE_POSITION_Y)
		{
			m_Velocity.y = VEL_DEFAULT_Y;
		}
	}

	m_Position = vector3d(m_Position.x, m_Position.y + (m_Velocity.y + SIGN(m_Velocity.y) * GRAVITATION)* deltaTime / 100, 0);

	if (this->m_Position.y <= GIFTBOX_PRE_POSITION_Y &&
		this->m_GiftBoxEvent == GIFTBOX_BRICK_EVENT::EVENT_PROCCESSING &&
		this->m_GiftBoxState == GIFTBOX_STATE::GIFTBOX)
	{
		if (this->m_GiftBoxType == GIFTBOX_TYPE::GIFTBOX_ITEMINBOX_TYPE ||
			this->m_GiftBoxType == GIFTBOX_TYPE::GIFTBOX_COIN)
		{
			this->m_Position.y = GIFTBOX_PRE_POSITION_Y;
			this->m_GiftBoxEvent = GIFTBOX_BRICK_EVENT::EVENT_DONE;
		}
	}

	if (this->m_GiftBoxEvent == GIFTBOX_BRICK_EVENT::EVENT_DONE)
	{
		if (this->m_GiftBoxType == GIFTBOX_TYPE::GIFTBOX_ITEMINBOX_TYPE)
		{
			this->m_itemInBox = new CIteminbox();
			this->m_itemInBox->setPosition(vector3d(this->m_Position.x, GIFTBOX_PRE_POSITION_Y, 0));
			this->m_itemInBox->setVelocity(vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y + 0.5));
			CMapManager::getInstance()->pushInFirst(m_itemInBox);
		}
		else if (this->m_GiftBoxType == GIFTBOX_TYPE::GIFTBOX_COIN)
		{
			m_Coin = new CCoinInBox(vector3d(this->m_Position.x, GIFTBOX_PRE_POSITION_Y, 0));
			m_Coin->setVelocity(vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y + 2));
			CMapManager::getInstance()->pushInFirst(m_Coin);
		}

		this->m_GiftBoxEvent = GIFTBOX_BRICK_EVENT::EVENT_NONE;
		this->m_GiftBoxType = GIFTBOX_TYPE::GIFTBOX_NONE;

	}
}

void CGiftBox::drawEntity()
{
	this->m_listSprite.at(this->m_GiftBoxState)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CGiftBox::updateEntity(RECT* camera)
{
}

void CGiftBox::setPosition(vector3d vector)
{
	this->m_Position = vector;
}

int	CGiftBox::getTagNodeId()
{
	return TAGNODE::GIFT_BOX;
}
