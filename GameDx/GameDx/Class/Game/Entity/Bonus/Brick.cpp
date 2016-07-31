#include "Brick.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"


CBrick::CBrick()
{
	this->initEntity();
}


CBrick:: ~CBrick()
{

}

bool CBrick::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::brick, 1, 1, 1, 0));
	return true;
}

bool CBrick::initEntity()
{
	m_Position = vector3d(150, 150, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(5.8, 5.8);
	return true;
}

void CBrick::updateEntity(CKeyBoard* device)
{

}
void CBrick::updateEntity(float deltaTime)
{

	if (CCollision::CheckCollision(CPlayer::getInstance(), this) == COLDIRECTION::COLDIRECTION_BOTTOM)
	{

		if (this->m_Velocity.y <0)
			this->m_Velocity = vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1));
	}
	else{

		if (this->m_Velocity.y >0)
			this->m_Velocity = vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1));	
	}
	this->m_Position = vector3d(this->m_Position.x, this->m_Position.y + this->m_Velocity.y *deltaTime / 50, 0);
	if (this->m_Position.y < 150)
	{
		this->m_Position = vector3d(150, 150, 0);
	}






}
void CBrick::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
		this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x) * 2, SIGN(m_Position.y) * 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}
void CBrick::updateEntity(RECT* camera)
{

}

