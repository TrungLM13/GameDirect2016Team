#include "Stand.h"
#include "Game\Utill\InformationResource.h"

CPlayerStand*			CPlayerStand::m_Instance		= NULL;

CStand::CStand()
{
}

CStand::~CStand()
{
}


CPlayerStand::CPlayerStand()
{
	this->m_Tag					= "CPlayerStand";

	m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand,			1, 2, 2));
	m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStandShoot,		1, 1, 1));

}

CPlayerStand::~CPlayerStand()
{
	SAFE_RELEASE(m_Instance);

	if (!m_listSprite.empty())
		m_listSprite.clear();
	m_listSprite.~vector();
}

CPlayerStand*	CPlayerStand::getInstance()
{
	if (!m_Instance)
		m_Instance				= new CPlayerStand();

	return m_Instance;
}

const char*	CPlayerStand::getTag()
{
	return this->m_Tag;
}

void		CPlayerStand::setTag(char*	tag)
{
	this->m_Tag					= tag;
}


void		CPlayerStand::switchState(CBaseEntity*	entity)
{


}

void		CPlayerStand::update(vector2d &position)
{

}

void		CPlayerStand::render()
{

}