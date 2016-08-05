#include "FlagPoleTail.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CFlagPoleTail::CFlagPoleTail()
{
	this->initEntity();
}

CFlagPoleTail:: ~CFlagPoleTail()
{

}

bool CFlagPoleTail::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::flagPoleTail, 1, 1, 1, 0));
	return true;
}

bool CFlagPoleTail::initEntity()
{
	m_Position = vector3d(128, 48, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "FlagPoleTail";
	return true;
}

void CFlagPoleTail::updateEntity(CKeyBoard* device)
{

}
void CFlagPoleTail::updateEntity(float deltaTime)
{
}
void CFlagPoleTail::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CFlagPoleTail::updateEntity(RECT* camera)
{

}

