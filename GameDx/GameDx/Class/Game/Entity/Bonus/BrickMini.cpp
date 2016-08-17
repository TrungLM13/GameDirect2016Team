#include "BrickMini.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\Bonus\CoinInBox.h"
#include "Class\Game\Entity\Map\MapManager.h"

CBrickMini::CBrickMini()
{
	this->initEntity();
}

CBrickMini::CBrickMini(vector3d position, BRICKMINI_TYPE type)
{
	m_Position.x = position.x;
	m_Position.y = position.y;

	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	this->m_Velocity = vector2d(VEL_DEFAULT_X, VEL_DEFAULT_Y);

	m_BrickMiniType = type;

	this->initEntity();
}

CBrickMini:: ~CBrickMini()
{
}

bool CBrickMini::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brickbreak_left, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brickbreak_right, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brickbreak_left, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brickbreak_right, 1, 1, 1, 0));
	return true;
}

bool CBrickMini::initEntity()
{
	this->loadSprite();
	return true;
}

void CBrickMini::updateEntity(CKeyBoard* device)
{

}

void CBrickMini::updateEntity(float deltaTime)
{
	if (this->m_BrickMiniType == BRICKMINI_TYPE::BRICKMINI_LEFT_UP)
	{
		this->m_Position.x += BRICKMINI_UP_VELOCITY * cos(PI / 3);
		this->m_Position.y += BRICKMINI_UP_VELOCITY * sin(PI / 3) + GRAVITATION * deltaTime / 70;
	}
	else if (this->m_BrickMiniType == BRICKMINI_TYPE::BRICKMINI_LEFT_DOWN)
	{
		this->m_Position.x += BRICKMINI_DOWN_VELOCITY * cos(7*PI / 18);
		this->m_Position.y += BRICKMINI_DOWN_VELOCITY * sin(7 * PI / 18) + GRAVITATION * deltaTime / 70;
	}
	else if (this->m_BrickMiniType == BRICKMINI_TYPE::BRICKMINI_RIGHT_UP)
	{
		this->m_Position.x += BRICKMINI_UP_VELOCITY * cos(2 * PI / 3);
		this->m_Position.y += BRICKMINI_UP_VELOCITY * sin(2 * PI / 3) + GRAVITATION * deltaTime / 70;
	}
	else if (this->m_BrickMiniType == BRICKMINI_TYPE::BRICKMINI_RIGHT_DOWN)
	{
		this->m_Position.x += BRICKMINI_DOWN_VELOCITY * cos(11 * PI / 18);
		this->m_Position.y += BRICKMINI_DOWN_VELOCITY * sin(11 * PI / 18) + GRAVITATION * deltaTime / 70;
	}
	if (this->m_Position.y <= VEL_DEFAULT_Y)
	{
		vector<CBaseEntity*> tempBonusList = CMapManager::getInstance()->getListBonus();
		CMapManager::getInstance()->removeEntity(tempBonusList, TAGNODE::BRICKMINI);
		CMapManager::getInstance()->setListBonus(tempBonusList);
		tempBonusList.clear();
	}
}

void CBrickMini::drawEntity()
{
	this->m_listSprite.at(this->m_BrickMiniType)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CBrickMini::updateEntity(RECT* camera)
{

}

void CBrickMini::setPosition(vector3d position) {
	m_Position = position;
}

void CBrickMini::setVelocity(vector2d velocity) {
	m_Velocity = velocity;
}

int	CBrickMini::getTagNodeId()
{
	return TAGNODE::BRICKMINI;
}
