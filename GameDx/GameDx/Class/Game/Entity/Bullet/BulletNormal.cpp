#include "BulletNormal.h"
#include "Game\Utill\InformationResource.h"

CBulletNormal::CBulletNormal()
{
}


CBulletNormal::~CBulletNormal()
{
}

bool	CBulletNormal::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart, 1, 1, 1, 0));
	return	true;
}

bool	CBulletNormal::initEntity()
{
	m_Position		= vector3d(100, 300, 0.5);
	m_State			= BULLETSTATE::BULLET_STATE_SHOW;
	m_Velocity		= vector2d(9.8, 9.8);

	this->loadSprite();

	return true;
}

void	CBulletNormal::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case BULLETSTATE::BULLET_STATE_INVIS:
		m_Position					= vector3dMinimum;
		break;
	case BULLETSTATE::BULLET_STATE_SHOW:
		m_Position.x += m_Velocity.x*deltaTime / 30 * SIGN(m_Velocity.x);
		break;
	case BULLETSTATE::BULLET_STATE_HIT:
		m_State						= BULLETSTATE::BULLET_STATE_INVIS;
		break;
	case BULLETSTATE::BULLET_STATE_DIE:
			break;
	default:
		break;
	}
}

void	CBulletNormal::updateEntity(CKeyBoard* device)
{

}

void	CBulletNormal::drawEntity()
{
	m_listSprite.at(m_State)->Render(m_Position, vector2d(SIGN(m_Velocity.x)*2.0, SIGN(m_Velocity.y)*2.0), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

vector3d CBulletNormal::getPosition()
{

	return m_Position;
}

void	CBulletNormal::setState(int newState)
{
	m_State		= newState;
}
int		CBulletNormal::getState()
{
	return m_State;
}