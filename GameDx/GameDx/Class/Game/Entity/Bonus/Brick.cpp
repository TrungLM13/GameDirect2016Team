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
	m_BrickEvent = BRICK_EVENT::EVENT_NONE; // When Brick doesnt move
	m_BrickState = BRICK_STATE::BRICK_NORMAL;

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
		m_Velocity.y = VEL_DEFAULT_Y + BRICK_VELOCITY_MAX_Y;

		if (m_BrickState == BRICK_STATE::BRICK_NORMAL) {
			m_BrickState = BRICK_STATE::BRICK_BOX;
			m_BrickEvent = BRICK_EVENT::EVENT_PROCCESSING;
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
	
	m_Position = vector3d(m_Position.x, m_Position.y + (m_Velocity.y  + SIGN(m_Velocity.y) * GRAVITATION)* deltaTime / 100, 0);

	if (m_Position.y <= BRICK_PRE_POSITION_Y && m_BrickState == BRICK_STATE::BRICK_BOX && m_BrickEvent == BRICK_EVENT::EVENT_PROCCESSING) {
		m_BrickEvent = BRICK_EVENT::EVENT_DONE;
	}

	if (m_BrickEvent == BRICK_EVENT::EVENT_DONE){
		m_Star = new CStar();
		CMapManager::getInstance()->pushBonusObject(m_Star);
		m_BrickEvent = BRICK_EVENT::EVENT_NONE;
		m_BrickType = BRICK_TYPE::BRICK_NONE;
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
