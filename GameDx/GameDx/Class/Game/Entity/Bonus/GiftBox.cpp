#include "GiftBox.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"

CGiftBox::CGiftBox()
{
	this->initEntity();
}

CGiftBox:: ~CGiftBox()
{

}

bool CGiftBox::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::box, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::giftbox, 1, 1, 1, 0));
	return true;
}

bool CGiftBox::initEntity()
{
	m_Position = vector3d(50, 150, 0);
	active = 1;
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(9.5, 9.5);
	return true;
}

void CGiftBox::updateEntity(CKeyBoard* device)
{

}

void CGiftBox::updateEntity(float deltaTime)
{
}

void CGiftBox::updateCollision(CBaseEntity *, float deltaTime)
{
	if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_BOTTOM)
	{
		active = 0;
		if (this->getVelocity().y < 0)
			this->setVelocity(vector2d(this->getVelocity().x, this->getVelocity().y*(-1)));
	}
	else{
		if (this->getVelocity().y > 0)
			this->setVelocity(vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1)));
	}
	this->setPosition(vector3d(this->m_Position.x, this->m_Position.y + this->m_Velocity.y* deltaTime / 50, 0));
	if (this->m_Position.y < 150)
	{
		this->setPosition(vector3d(50, 150, 0));
	}
}

void CGiftBox::drawEntity()
{
	this->m_listSprite.at(active)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CGiftBox::updateEntity(RECT* camera)
{
}

void CGiftBox::setPosition(vector3d vector)
{
	this->m_Position = vector;
}
