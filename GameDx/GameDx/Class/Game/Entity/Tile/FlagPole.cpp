#include "FlagPole.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Utill\ShowBouding.h"

CFlagPole::CFlagPole()
{
	this->initEntity();
}

CFlagPole:: ~CFlagPole()
{

}

bool CFlagPole::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::flagPole, 1, 1, 1, 0));
	return true;
}

bool CFlagPole::initEntity()
{
	m_Position = vector3d(250, 120, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "FlagPole";
	return true;
}

void CFlagPole::updateEntity(CKeyBoard* device)
{

}
void CFlagPole::updateEntity(float deltaTime)
{
}
void CFlagPole::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
	{
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
}

void CFlagPole::updateEntity(RECT* camera)
{

}

int	CFlagPole::getTagNodeId() {
	return TAGNODE::FLAG_POLE;
}