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
	this->m_listSprite.push_back(new CSprite(CInfomationResource::giftbox, 1, 4, 1, 0));
	return true;
}

bool CGiftBox::initEntity()
{
	m_Position = vector3d(150, 150, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(5.8, 5.8);
	return true;
}

void CGiftBox::updateEntity(CKeyBoard* device)
{

}

void CGiftBox::updateEntity(float deltaTime)
{
}

void CGiftBox::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x) * 2, SIGN(m_Position.y) * 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CGiftBox::updateEntity(RECT* camera)
{

}

