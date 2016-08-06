#include "Flag.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"

CFlag::CFlag()
{
	this->initEntity();
}

CFlag:: ~CFlag()
{

}

bool CFlag::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::greenFlag, 1, 1, 1, 0));
	return true;
}

bool CFlag::initEntity()
{
	m_Position = vector3d(120, 184, 0);
	m_Velocity = vector2d(0, -9.8);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "Flag";
	return true;
}

void CFlag::updateEntity(CKeyBoard* device)
{

}
void CFlag::updateEntity(float deltaTime)
{
	if (CPlayer::getInstance()->getStateInt() == PLAYERSTATES::CLIMB) {
		if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_BOTTOM) {
			m_Velocity.y = CPlayer::getInstance()->getVelocity().y;
		}
		else if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_NONE) {
			m_Velocity.y = CPlayer::getInstance()->getVelocity().y * 1.5;
		}
		m_Position.y += m_Velocity.y * deltaTime / 30;
	}

}

void CFlag::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CFlag::updateEntity(RECT* camera)
{

}

int	CFlag::getTagNodeId() {
	return TAGNODE::FLAG;
}
