#include "MovableEntity.h"


CMovable::CMovable()
{
	this->initEntity();
}


CMovable::~CMovable()
{
}

bool CMovable::initEntity()
{
	m_TagNode = "Movable";
	return true;
}

vector3d CMovable::getPosition()
{
	return m_Position;
}

CBox2D  CMovable::getBounding()
{
	if (m_listSprite.size())
	{
		m_Bounding->setX(m_Position.x - m_listSprite.at(m_State)->getFrameInfo().Width / 2 * std::abs(m_listSprite.at(m_State)->getScale().x));
		m_Bounding->setY(m_Position.y + m_listSprite.at(m_State)->getFrameInfo().Height / 2 * std::abs(m_listSprite.at(m_State)->getScale().y));
		m_Bounding->setWidth(m_listSprite.at(m_State)->getFrameInfo().Width        * std::abs(m_listSprite.at(m_State)->getScale().x));
		m_Bounding->setHeight(m_listSprite.at(m_State)->getFrameInfo().Height      * std::abs(m_listSprite.at(m_State)->getScale().y));

	}

	return *m_Bounding;
}

const char* CMovable::getTagNode()
{
	return this->m_TagNode;
}

vector2d CMovable::getVelocity()
{
	return m_Velocity;
}

void CMovable::setVelocity(vector2d newVel)
{
	m_Velocity = newVel;
}