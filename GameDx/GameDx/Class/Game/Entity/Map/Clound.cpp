#include "Clound.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Game\Utill\Config.h"

CClound::CClound()
{
	m_Position		= vector3dZero;
	m_TypeClound	= CLOUNDSTRUCT::ONE_CLOUND;
	this->initEntity();
}


CClound::~CClound()
{
}

CClound::CClound(vector2d newPos, int type)
{
	m_Position.x = newPos.x; m_Position.y = newPos.y;
	m_TypeClound = type;

	this->initEntity();
}

bool	CClound::loadSprite()
{
	m_listSprite.push_back(new CSprite(CInfomationResource::clound_small,	1, 1));
	m_listSprite.push_back(new CSprite(CInfomationResource::clound_normal,	1, 1));
	m_listSprite.push_back(new CSprite(CInfomationResource::clound_big,		1, 1));

	return true;
}

bool	CClound::initEntity()
{
	this->loadSprite();
	return true;
}

void	CClound::updateEntity(float deltaTime)
{

}

void	CClound::updateEntity(CKeyBoard* device)
{

}

void	CClound::updateEntity(RECT* rectCamera)
{

}

void	CClound::drawEntity()
{
	m_listSprite.at(m_TypeClound)->Render(CCamera::getInstance()->setPositionEntity(m_Position));
}
