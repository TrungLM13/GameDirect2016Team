#include "Flag.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Utill\ResourceManager\TileResource.h"

CFlag::CFlag()
{
	this->initEntity();
}

CFlag::CFlag(vector2d pos)
{
	this->m_Position.x = pos.x;
	this->m_Position.y = pos.y;
	this->initEntity();
}

CFlag:: ~CFlag()
{
	SAFE_RELEASE(this->m_ResouceImage);
}

bool CFlag::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(this->m_ResouceImage->getImage(TYPEOFTILE::TOF_FLAG), 1, 1, 1, 0));
	return true;
}

bool CFlag::initEntity()
{
	m_Velocity = vector2d(0, -9.8);
	this->m_ResouceImage = new CTileResource();
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "Flag";
	return true;
}

void CFlag::updateEntity(CKeyBoard* device)
{

}

void CFlag::handleCollision(CBaseEntity* entity, float deltaTime) {
	if (entity->getTagNodeId() == TAGNODE::FLAG_POLE_TAIL){
		if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_TOP) {
			m_IsEnable = true;
			m_Position.y = entity->getPosition().y + entity->getBounding().getHeight() / 2 + this->getBounding().getHeight() / 2;
		}
	}
}

void CFlag::updateEntity(float deltaTime)
{
	if ( CPlayer::getInstance()->m_IsEnable == true) {
		if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_BOTTOM) {
			m_Velocity.y = CPlayer::getInstance()->getVelocity().y;
		}
		else if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_NONE && m_IsEnable == false) {
			m_Position.y += m_Velocity.y * deltaTime / 60;
		}
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
