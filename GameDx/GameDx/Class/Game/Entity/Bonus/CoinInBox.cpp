#include "CoinInBox.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Mathematics\Collision.h"

CCoinInBox::CCoinInBox()
{
	this->initEntity();
}

CCoinInBox:: ~CCoinInBox()
{

}

bool CCoinInBox::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::coinInBox, 1, 4, 4, 0));
	return true;
}

bool CCoinInBox::initEntity()
{
	this->m_TagNode = "CoinInBox";
	isDraw = true;
	m_Position = vector3d(50, 50, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(0,0);
	return true;
}

void CCoinInBox::updateEntity(CKeyBoard* device)
{

}

void CCoinInBox::updateEntity(float deltaTime)
{
	
	if (this->m_Position.y >= 200)
	{
		isDraw = true;
		m_Velocity.y *= -1;
	}
    if (this->m_Position.y <= 150 && this->m_Velocity.y <0)
	{
		isDraw = false;
		m_Velocity.y = 0;
	}
	this->m_Position.y = this->m_Position.y + this->m_Velocity.y *deltaTime / 100;
}

void CCoinInBox::drawEntity()
{
	if (isDraw)
	{
		for (int i = 0; i < m_listSprite.size(); i++)
			this->m_listSprite.at(i)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
}

void CCoinInBox::updateEntity(RECT* camera)
{

}
