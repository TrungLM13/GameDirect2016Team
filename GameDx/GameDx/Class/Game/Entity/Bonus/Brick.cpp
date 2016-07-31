#include "Brick.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\State\StandState.h"
#include "Class\Mathematics\T_Collision.h"


CBrick::CBrick()
{
	this->initEntity();
}


CBrick:: ~CBrick()
{

}

bool CBrick::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brick, 1, 1, 1, 0));
	return true;
}

bool CBrick::initEntity()
{
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
	if (this->m_Position.y <= 150)
	{
		m_Position = vector3d(150, 150, 0);
	}

}

void CBrick::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x) * 2, SIGN(m_Position.y) * 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
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
