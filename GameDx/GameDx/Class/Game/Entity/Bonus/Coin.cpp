#include "Coin.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Utill\ResourceManager\BonusResource.h"

CCoin::CCoin()
{
	this->initEntity();
}

CCoin::CCoin(LPDIRECT3DDEVICE9)
{
	this->initEntity();
}

CCoin:: ~CCoin()
{
	SAFE_RELEASE(this->m_ResouceImage);
	if (!m_listSprite.empty()) {
		for (int i = 0; i < m_listSprite.size(); ++i) {
			SAFE_RELEASE(m_listSprite.at(i));
			m_listSprite.at(i) = nullptr;
		}
	}
}

bool CCoin::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(this->m_ResouceImage->getImage(TAGNODE::COIN), 1, 4, 4, 0));
	return true;
}

bool CCoin::initEntity()
{
	m_Position = vector3d(100, 200, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	return true;
}

void CCoin::updateEntity(CKeyBoard* device)
{

}

void CCoin::updateEntity(float deltaTime)
{
}

void CCoin::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CCoin::updateEntity(RECT* camera)
{

}

int  CCoin::getTagNodeId()
{
	return TAGNODE::COIN;
}