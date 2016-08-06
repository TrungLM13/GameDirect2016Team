#include "Flag.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CFlag::CFlag()
{
	this->initEntity();
}

CFlag:: ~CFlag()
{

}

bool CFlag::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::greenFlag, 1, 1, 1, 0));
	return true;
}

bool CFlag::initEntity()
{
	m_Position = vector3d(120, 184, 0);
	m_Velocity = vector2d(0, -9.8);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "Flag";
	return true;
}

void CFlag::updateEntity(CKeyBoard* device)
{

}
void CFlag::updateEntity(float deltaTime)
{
	if (m_Position.y < 10)
	{
		m_Velocity.y = 0;
	}
	m_Position = vector3d(m_Position.x, m_Position.y + m_Velocity.y * deltaTime / 100, 0);
}

void updateEntity(CMovable* movable, float deltaTime) {
	
}
void CFlag::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CFlag::updateEntity(RECT* camera)
{

}

int	CFlag::getTagNodeId() {
	return TAGNODE::FLAG;
}
