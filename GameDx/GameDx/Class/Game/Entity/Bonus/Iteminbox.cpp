#include "Iteminbox.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Mathematics\SweptAABB.h"


CIteminbox::CIteminbox()
{
	this->initEntity();
}

CIteminbox:: ~CIteminbox()
{

}

bool CIteminbox::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::redmushroom, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::flower, 1, 4, 4, 0));
	return true;
}

bool CIteminbox::initEntity()
{
	chkShowItem(CPlayer::getInstance());
	m_Position = vector3d(100, 200, 0);
	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(9.8, 9.8);
	return true;
}

void CIteminbox::updateEntity(CKeyBoard* device)
{

}

void CIteminbox::updateEntity(float deltaTime)
{
	if (this->m_itemtype == ITEMINBOX_TYPE::REDMUSHROOM)
	{
		if (this->m_Position.y > 100)
		{
			if (this->m_Velocity.y >0)
				this->m_Velocity = vector2d(this->m_Velocity.x, this->m_Velocity.y*(-1)); 
			this->m_Position.y = this->m_Position.y + this->m_Velocity.y *deltaTime / 100;
		}
		if (this->m_Position.y <= 10)
		{
			this->m_Position.y = 10;
		}
		if (this->m_Position.x >200)
		{
			if (this->m_Velocity.x > 0)
				this->m_Velocity = vector2d(this->m_Velocity.x*(-1), this->m_Velocity.y);
		}
		this->m_Position = vector3d(this->m_Position.x + this->m_Velocity.x*deltaTime / 250,this->m_Position.y, 0);
	}
}

void CIteminbox::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); i++)
	{
		if (this->m_itemtype == 0)
		{
			this->m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		}
		if (this->m_itemtype == 1)
		{
			this->m_listSprite.at(1)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Position.x), SIGN(m_Position.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		}
	}
}

void CIteminbox::updateEntity(RECT* camera)
{

}

void CIteminbox::setVelocity(vector2d velocity)
{
	this->m_Velocity.x = velocity.x;
	this->m_Velocity.y = velocity.y;
}


ITEMINBOX_TYPE CIteminbox::getitemtype()
{
	return this->m_itemtype;
}

void CIteminbox::chkShowItem(CPlayer* player)
{
	if (player->getPlayerTag() == PLAYERTAGS::SMALL)
	{
		this->m_itemtype = ITEMINBOX_TYPE::REDMUSHROOM;
		this->m_TagNode = "RedMushroom";
	}
	if (player->getPlayerTag() == PLAYERTAGS::BIG)
	{
		this->m_itemtype = ITEMINBOX_TYPE::ITEM_FLOWER;
		this->m_TagNode = "Flower";
	}
}