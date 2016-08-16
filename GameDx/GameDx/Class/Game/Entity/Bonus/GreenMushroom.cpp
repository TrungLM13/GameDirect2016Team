#include "GreenMushroom.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Map\MapManager.h"


inline bool IsCollision_GreenMushRoom(CMovable* entity, vector<CBaseEntity*> listEntity) {
	for (int i = 0; i < listEntity.size(); i++)
	{
		if (listEntity.at(i)->getTagNodeId() == TAGNODE::BRICK)
		{
			if (CCollision::CheckCollision(entity, listEntity.at(i)) == COLDIRECTION::COLDIRECTION_TOP)
			{
				return true;
			}
		}
	}

	return false;
}
CGreenMushroom::CGreenMushroom()
{
	this->initEntity();
}

CGreenMushroom::CGreenMushroom(vector3d pos)
{
	this->m_Position = pos;
	this->initEntity();
}

CGreenMushroom:: ~CGreenMushroom()
{

}

bool CGreenMushroom::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::greenmushroom, 1, 1, 1, 0));
	return true;
}

bool CGreenMushroom::initEntity()
{
	this->m_TagNode = "GreenMushroom";
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(9.8, 9.8);
	return true;
}

void CGreenMushroom::updateEntity(CKeyBoard* device)
{

}

void CGreenMushroom::updateEntity(float deltaTime)
{
	if (this->m_Position.y >= REDMUSHROOM_POSITION_Y_MAX)
	{
		this->m_Velocity.y = VEL_DEFAULT_Y;
		this->m_Position.y = REDMUSHROOM_POSITION_Y_MAX;

		if (IsCollision_GreenMushRoom(this, CMapManager::getInstance()->getListBonus()))
		{
			this->m_Velocity.x = REDMUSHROOM_VELOCITY_MAX;
		}
		else{
			this->m_Velocity.y = 0;
		}
	}
	for (int i = 0; i < CMapManager::getInstance()->getListRect().size(); i++)
	{
		this->getBounding().setVelocity(this->getVelocity());
		if (CCollision::CheckCollision(this->getBounding(), *CMapManager::getInstance()->getListRect().at(i)) == COLDIRECTION::COLDIRECTION_TOP)
		{
			this->m_Velocity.x = VEL_DEFAULT_X + REDMUSHROOM_VELOCITY_MAX;
			this->m_Velocity.y = VEL_DEFAULT_Y;
		}
		else if (CCollision::CheckCollision(this->getBounding(), *CMapManager::getInstance()->getListRect().at(i)) == COLDIRECTION::COLDIRECTION_LEFT) {
			// Change direction 
			this->m_Velocity.x = CHANGE_DIRECTION(this->m_Velocity.x);
		}
		else if (CCollision::CheckCollision(this->getBounding(), *CMapManager::getInstance()->getListRect().at(i)) == COLDIRECTION::COLDIRECTION_NONE)
		{
			if (this->getVelocity().x != VEL_DEFAULT_X &&
				IsCollision_GreenMushRoom(this, CMapManager::getInstance()->getListBonus()) == false)
				this->m_Velocity.y = 0;
		}
	}

	this->m_Position = vector3d(this->m_Position.x + this->m_Velocity.x*deltaTime / 250, this->m_Position.y + (this->m_Velocity.y + GRAVITATION) *deltaTime / 100, 0);

	if (CCollision::getInstance()->CheckCollision(this, CPlayer::getInstance()))
	{
			vector<CBaseEntity*> tempBonusList = CMapManager::getInstance()->getListBonus();
			CMapManager::getInstance()->removeEntity(tempBonusList, TAGNODE::GREEN_MUSHROOM);
			CMapManager::getInstance()->setListBonus(tempBonusList);
			tempBonusList.clear();
	}
}

void CGreenMushroom::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void CGreenMushroom::updateEntity(RECT* camera)
{

}

void CGreenMushroom::setVelocity(vector2d velocity)
{
	this->m_Velocity.x = velocity.x;
	this->m_Velocity.y = velocity.y;
}

int CGreenMushroom::getTagNodeId() {
	return TAGNODE::GREEN_MUSHROOM;
}
