#include "CarnivorousPlants.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CCarnivorousPlants::CCarnivorousPlants()
{
	this->initEntity();
}

CCarnivorousPlants:: ~CCarnivorousPlants()
{

}

bool CCarnivorousPlants::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::greenCarnivorousPlants, 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::blueCarnivorousPlants, 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::redCarnivorousPlants, 1, 2, 2, 0));
	return true;
}

bool CCarnivorousPlants::initEntity()
{
	m_Position = vector3d(150, 150, 0);
	m_Velocity = vector2d(0, -2.5);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	m_TagNode = "CarnivorousPlant";
	m_Direction = -1;
	m_mapId = 1;
	return true;
}

void CCarnivorousPlants::updateEntity(CKeyBoard* device)
{

}
void CCarnivorousPlants::updateEntity(float deltaTime)
{
	if (m_Position.y < 140 || m_Position.y > 150)
	{
		static float animationTime = 0;


		if (animationTime > 50) {
			m_Direction *= -1;
			m_Velocity.y = 2.5 * m_Direction;
			animationTime = 0;
		}

		else {
			m_Velocity.y = 0;
			animationTime ++;
		}
	}
		m_Position.y = m_Position.y + m_Velocity.y * deltaTime / 100;

}
void CCarnivorousPlants::drawEntity()
{
	this->m_listSprite.at(m_mapId - 1)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CCarnivorousPlants::updateEntity(RECT* camera)
{

}


