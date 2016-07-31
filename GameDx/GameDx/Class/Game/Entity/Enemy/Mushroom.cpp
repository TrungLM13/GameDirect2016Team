#include "Mushroom.h"


CMushroom::CMushroom()
{
	this->initEntity();
}


CMushroom::~CMushroom()
{
}

bool	CMushroom::loadSprite(){
	this->m_listSprite.push_back(new CSprite(CInfomationResource::mushroomenemy_run, 1, 2));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::mushroomenemy_die, 1, 1));

	return true;
}

bool	CMushroom::initEntity()
{
	this->loadSprite();

	this->m_Position			= vector3d(100, 150, 0);
	this->m_Bounding			= new CBox2D(0, 0, 0, 0);
	this->m_Velocity			= vector2d(0.1, -0.98);
	this->m_State				= MUSHROOM_STATE::MUSH_RUN;
	return true;
}

void	CMushroom::updateEntity(float deltaTime)
{
	if (m_State == MUSHROOM_STATE::MUSH_RUN)
	{
	m_Position.x += m_Velocity.x*deltaTime;
	m_Position.y += m_Velocity.y*deltaTime;

	if (m_Position.y <= 20)
		m_Position.y = 20;

	if (m_Position.x <= 0 || m_Position.x >= 200)
		m_Velocity.x *= -1;
	}
}


void	CMushroom::updateEntity(CKeyBoard* device)
{
	if (device->KeyPress(DIK_DELETE))
		if (m_State == MUSHROOM_STATE::MUSH_RUN)
			m_State = MUSHROOM_STATE::MUSH_DIE;
		else
			m_State = MUSHROOM_STATE::MUSH_RUN;
}

void	CMushroom::updateEntity(RECT* rectCamera)
{

}

void	CMushroom::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
}
