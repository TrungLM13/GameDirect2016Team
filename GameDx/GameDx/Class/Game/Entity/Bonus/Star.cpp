#include "Star.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CStar::CStar()
{
	this->initEntity();
}

CStar:: ~CStar()
{

}

bool CStar::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::star, 1, 4, 4, 0));
	return true;
}

bool CStar::initEntity()
{
	this->m_TagNode = "Star";
	m_Position = vector3d(120, 70, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(0, 0);
	return true;
}

void CStar::updateEntity(CKeyBoard* device)
{

}

void CStar::updateEntity(float deltaTime)
{
	static int temp = 1;
	m_Position.x += 1 * sin((2 * PI / 6));
	m_Position.y += 3 * cos(2 * PI / 6) * temp ;
	if (m_Position.y > 100 || m_Position.y < 30)
		temp *= -1;
}

void CStar::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CStar::updateEntity(RECT* camera)
{

}

int	CStar::getTagNodeId(){
	return TAGNODE::STAR;
}

