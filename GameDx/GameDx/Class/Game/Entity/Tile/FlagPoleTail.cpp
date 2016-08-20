#include "FlagPoleTail.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Utill\ResourceManager\TileResource.h"

CFlagPoleTail::CFlagPoleTail()
{
	this->initEntity();
}

CFlagPoleTail:: ~CFlagPoleTail()
{
	SAFE_RELEASE(this->m_ResouceImage);
}

bool CFlagPoleTail::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(this->m_ResouceImage->getImage(TYPEOFTILE::TOF_FLAG_POLE_TAIL), 1, 1, 1, 0));
	return true;
}

bool CFlagPoleTail::initEntity()
{
	m_Position = vector3d(250, 48, 0);
	this->m_ResouceImage = new CTileResource();
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "FlagPoleTail";
	return true;
}

void CFlagPoleTail::updateEntity(CKeyBoard* device)
{

}
void CFlagPoleTail::updateEntity(float deltaTime)
{
}
void CFlagPoleTail::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CFlagPoleTail::updateEntity(RECT* camera)
{

}

int	CFlagPoleTail::getTagNodeId() {
	return TAGNODE::FLAG_POLE_TAIL;
}