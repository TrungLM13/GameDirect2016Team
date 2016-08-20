#include "CarnivorousPlants.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Utill\ResourceManager\EnermyResource.h"

CCarnivorousPlants::CCarnivorousPlants()
{
	this->initEntity();
}

CCarnivorousPlants:: ~CCarnivorousPlants()
{
	SAFE_RELEASE(m_ResouceImage);

	if (!m_listSprite.empty()) {
		for (int i = 0; i < m_listSprite.size(); ++i) {
			SAFE_RELEASE(m_listSprite.at(i));
			m_listSprite.at(i) = nullptr;
		}
	}
}

bool CCarnivorousPlants::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(this->m_ResouceImage->getImage(TAGNODE::CARNIVOROUS_PLANT, CARNIVOROUS_PLANT_TYPE::GREEN_CARNIVOROUS_PLANT), 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(this->m_ResouceImage->getImage(TAGNODE::CARNIVOROUS_PLANT, CARNIVOROUS_PLANT_TYPE::BLUE_CARNIVOROUS_PLANT), 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(this->m_ResouceImage->getImage(TAGNODE::CARNIVOROUS_PLANT, CARNIVOROUS_PLANT_TYPE::RED_CARNIVOROUS_PLANT), 1, 2, 2, 0));
	return true;
}

bool CCarnivorousPlants::initEntity()
{
	m_Position = vector3d(150, 150, 0);
	m_Velocity = vector2d(0, -2.5);

	this->m_ResouceImage = new CEnermyResource();
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

int CCarnivorousPlants::getObjectType() {
	return OBJECT_TYPE::TYPE_ENERMY;
}

