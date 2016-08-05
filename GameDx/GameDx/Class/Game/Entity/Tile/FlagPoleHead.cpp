#include "FlagPoleHead.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CFlagPoleHead::CFlagPoleHead()
{
	this->initEntity();
}

CFlagPoleHead:: ~CFlagPoleHead()
{

}

bool CFlagPoleHead::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::flagPoleHead, 1, 1, 1, 0));
	return true;
}

bool CFlagPoleHead::initEntity()
{
	m_Position = vector3d(128, 200, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "FlagPoleHead";
	return true;
}

void CFlagPoleHead::updateEntity(CKeyBoard* device)
{

}
void CFlagPoleHead::updateEntity(float deltaTime)
{
}
void CFlagPoleHead::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CFlagPoleHead::updateEntity(RECT* camera)
{

}

