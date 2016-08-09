#include "GreenMushroom.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CGreenMushroom::CGreenMushroom()
{
	this->initEntity();
}

CGreenMushroom:: ~CGreenMushroom()
{

}

bool CGreenMushroom::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::greenmushroom, 1, 1, 1, 0));
	return true;
}

bool CGreenMushroom::initEntity()
{
	this->m_TagNode = "GreenMushroom";
	m_Position = vector3d(50, 200, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(9.8, 9.8);
	return true;
}

void CGreenMushroom::updateEntity(CKeyBoard* device)
{

}

void CGreenMushroom::updateEntity(float deltaTime)
{
}

void CGreenMushroom::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CGreenMushroom::updateEntity(RECT* camera)
{

}

void CGreenMushroom::setVelocity(vector2d velocity)
{
	this->m_Velocity.x = velocity.x;
	this->m_Velocity.y = velocity.y;
}

int CGreenMushroom::getTagNodeId() {
	return TAGNODE::GREEN_MUSHROOM;
}
