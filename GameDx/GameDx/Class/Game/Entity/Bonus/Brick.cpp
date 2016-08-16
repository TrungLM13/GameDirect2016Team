#include "Brick.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\Bonus\CoinInBox.h"
#include "Class\Game\Entity\Map\MapManager.h"

CBrick::CBrick()
{
	m_BrickType = BRICK_TYPE::BRICK_NONE;
	this->initEntity();
}

CBrick::CBrick(vector2d position, BRICK_TYPE type)
{
	m_Position.x = position.x;
	m_Position.y = position.y;

	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	this->m_Velocity = vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y);

	m_BrickType = type;

	this->initEntity();
}

CBrick:: ~CBrick()
{
}

bool CBrick::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brick, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::box, 1, 1, 1, 0));
	return true;
}

bool CBrick::initEntity()
{
	m_Star = nullptr;
	m_Coin = nullptr;
	m_GreenMushRoom = nullptr;
	m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_NONE; // When Brick doesnt move
	m_BrickState = BRICK_STATE::BRICK_NORMAL;
	m_CountCoin = COIN_NUM_MAX;
	this->loadSprite();
	return true;
}

void CBrick::updateEntity(CKeyBoard* device)
{

}

void CBrick::updateEntity(float deltaTime)
{
	switch (CCollision::CheckCollision(CPlayer::getInstance(), this))
	{
	case COLDIRECTION::COLDIRECTION_BOTTOM:
		if (m_BrickState == BRICK_STATE::BRICK_NORMAL) {
			m_Velocity.y = VEL_DEFAULT_Y + BRICK_VELOCITY_MAX_Y;
			if (m_BrickType == BRICK_TYPE::BRICK_STAR ||
				m_BrickType == BRICK_TYPE::BRICK_GREENMUSHROOM) {
				m_BrickState = BRICK_STATE::BRICK_BOX;
				m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_PROCCESSING;
			}
			else if (m_BrickType == BRICK_TYPE::BRICK_COIN) {
				m_CountCoin--;
				if (m_CountCoin >= 7) {
					m_BrickState = BRICK_STATE::BRICK_NORMAL;
				}
				else {
					m_BrickState = BRICK_STATE::BRICK_BOX;
				}

				m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_PROCCESSING;
			}
		}
		else if (m_BrickState == BRICK_STATE::BRICK_BOX) {
			/*if (m_CountCoin > 0 && m_BrickType == BRICK_TYPE::BRICK_COIN)
			{
				m_Velocity.y = VEL_DEFAULT_Y + BRICK_VELOCITY_MAX_Y;
			}
			else*/
				m_Velocity.y = VEL_DEFAULT_Y;
		}
		break;
	case COLDIRECTION::COLDIRECTION_TOP:
		break;
	default:
		break;
	}

	if (m_Position.y >= BRICK_PRE_POSITION_Y_MAX){
		if (m_Velocity.y > 0){
			m_Velocity.y = CHANGE_DIRECTION(m_Velocity.y);
		}
	}

	if (SIGN(m_Velocity.y) == DIRECTION::DIRECTION_DOWN) {
		if (m_Position.y <= BRICK_PRE_POSITION_Y) {
			m_Velocity.y = VEL_DEFAULT_Y;
		}
	}

	m_Position = vector3d(m_Position.x, m_Position.y + (m_Velocity.y + SIGN(m_Velocity.y) * GRAVITATION)* deltaTime / 100, 0);

	if (m_Position.y <= BRICK_PRE_POSITION_Y && m_BrickEvent == GIFTBOX_BRICK_EVENT::EVENT_PROCCESSING) {
		if ((m_BrickType == BRICK_TYPE::BRICK_STAR && m_BrickState == BRICK_STATE::BRICK_BOX) ||
			(m_BrickType == BRICK_TYPE::BRICK_COIN) ||
			(m_BrickType == BRICK_TYPE::BRICK_GREENMUSHROOM && m_BrickState == BRICK_STATE::BRICK_BOX))
		{
			m_Position.y = BRICK_PRE_POSITION_Y;
			m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_DONE;
		}
	}

	if (m_BrickEvent == GIFTBOX_BRICK_EVENT::EVENT_DONE){
		if (m_BrickType == BRICK_TYPE::BRICK_STAR)
		{
			m_Star = new CStar(vector3d(this->m_Position.x, BRICK_PRE_POSITION_Y, 0));
			m_Star->setVelocity(vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y + 0.5));
			CMapManager::getInstance()->pushInFirst(m_Star);
			m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_NONE;
			m_BrickType = BRICK_TYPE::BRICK_NONE;
		}
		else if (m_BrickType == BRICK_TYPE::BRICK_COIN) {
			m_Coin = new CCoinInBox(vector3d(this->m_Position.x, BRICK_PRE_POSITION_Y, 0));
			m_Coin->setVelocity(vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y + 2));
			CMapManager::getInstance()->pushInFirst(m_Coin);
			m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_NONE;
		}
		else if (this->m_BrickType == BRICK_TYPE::BRICK_GREENMUSHROOM)
		{
			m_GreenMushRoom = new CGreenMushroom(vector3d(this->m_Position.x, BRICK_PRE_POSITION_Y, 0));
			m_GreenMushRoom->setVelocity(vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y + 0.5));
			CMapManager::getInstance()->pushInFirst(m_GreenMushRoom);
			m_BrickEvent = GIFTBOX_BRICK_EVENT::EVENT_NONE;
			m_BrickType = BRICK_TYPE::BRICK_NONE;
		}
	}


}

void CBrick::drawEntity()
{
	this->m_listSprite.at(this->m_BrickState)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
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

void CBrick::updateCollision(CBaseEntity* player, float deltaTime)
{
}

int	CBrick::getTagNodeId()
{
	return TAGNODE::BRICK;
}
