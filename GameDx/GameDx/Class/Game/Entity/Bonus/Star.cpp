#include "Star.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CStar::CStar()
{
	this->initEntity();
}


CStar:: ~CStar()
{

}

bool CStar::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::star, 1, 4, 4, 0));
	return true;
}

bool CStar::initEntity()
{
	m_Position = vector3d(50, 200, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(9.8, 9.8);
	return true;
}

void CStar::updateEntity(CKeyBoard* device)
{

}
void CStar::updateEntity(float deltaTime)
{
	if (this->m_Position.y < 10)
	{
		if (this->m_Velocity.y < 0)
			this->m_Velocity = vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1));
		
	}
	if (this->m_Position.y > 100)
	{
		if (this->m_Velocity.y >0)
			this->m_Velocity = vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1));
	}
	this->m_Position = vector3d(this->m_Position.x + this->m_Velocity.x*deltaTime / 250, this->m_Position.y + this->m_Velocity.y *deltaTime / 100, 0);
}
void CStar::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x) * 2, SIGN(m_Position.y) * 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CStar::updateEntity(RECT* camera)
{

}
