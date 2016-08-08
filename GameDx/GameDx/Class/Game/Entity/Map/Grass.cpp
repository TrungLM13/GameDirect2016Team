#include "Grass.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Game\Utill\Config.h"

CGrass::CGrass()
{
	m_Position	=	vector3dZero;
	m_TypeGrass =	GRASSSTRUCT::GRASS_LEFT;
	this->initEntity();
}


CGrass::~CGrass()
{
}

CGrass::CGrass(vector2d newPos, int type)
{
	m_Position.x	= newPos.x; m_Position.y = newPos.y;
	m_TypeGrass		= type;

	this->initEntity();
}

bool	CGrass::loadSprite()
{
	m_listSprite.push_back(new CSprite(CInfomationResource::grass_small_map1,		1, 1));
	m_listSprite.push_back(new CSprite(CInfomationResource::grass_normal_map1,		1, 1));
	m_listSprite.push_back(new CSprite(CInfomationResource::grass_big_map1,			1, 1));

	m_listSprite.push_back(new CSprite(CInfomationResource::grass_left_map3,		1, 1));
	m_listSprite.push_back(new CSprite(CInfomationResource::grass_middle_map3,		1, 1));
	m_listSprite.push_back(new CSprite(CInfomationResource::grass_right_map3,		1, 1));
	
	return true;
}

bool	CGrass::initEntity()
{
	this->loadSprite();
	return true;
}

void	CGrass::updateEntity(float deltaTime)
{

}

void	CGrass::updateEntity(CKeyBoard* device)
{

}

void	CGrass::updateEntity(RECT* rectCamera)
{

}

void	CGrass::drawEntity()
{
	m_listSprite.at(m_TypeGrass)->Render(CCamera::getInstance()->setPositionEntity(m_Position));
}





