#include "Mushroom.h"
#include "Class\Game\Entity\Map\MapManager.h"
#include "Class\Mathematics\Collision.h"
#include "Class\Game\Entity\Player\Player.h"


CMushroom::CMushroom()
{
	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(0.1, -0.98);
	this->m_Direction = vector2d(DIRECTION::DIRECTION_LEFT, DIRECTION::DIRECTION_DOWN);
	this->initEntity();
}

CMushroom::CMushroom(vector2d vect, int type){
	m_Position.x	= vect.x;
	m_Position.y	= vect.y;

	m_Type			= type;

	this->m_Bounding = new CBox2D(0, 0, 0, 0);
	this->m_Velocity = vector2d(5, 9.8);

	this->initEntity();
}

CMushroom::~CMushroom()
{
}

bool	CMushroom::loadSprite(){
	switch (m_Type)
	{
	case EnemyStyle::TOF_RED_MUSHROOM:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::mushroomenemy_run, 1, 2));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::mushroomenemy_die, 1, 1));
		break;
		
	case EnemyStyle::TOF_BLUE_MUSHROOM:
		break;
	default:
		return false;
	}
	return true;
}

bool	CMushroom::initEntity()
{
	this->loadSprite();
	this->m_State				= MUSHROOM_STATE::MUSH_RUN;
	return true;
}

void	CMushroom::updateEntity(float deltaTime)
{
	if (m_State == MUSHROOM_STATE::MUSH_RUN)
	{
		m_Position.x += m_Velocity.x*deltaTime/1000;
		m_Position.y -= m_Velocity.y*deltaTime/100;
	}

	if (m_State == MUSHROOM_STATE::MUSH_IS_ACTTACKED)
	{

	}

	updateCollision(deltaTime);
}

void	CMushroom::updateEntity(CKeyBoard* device)
{
	if (device->KeyPress(DIK_DELETE))

	if (m_State == MUSHROOM_STATE::MUSH_RUN)
		m_State = MUSHROOM_STATE::MUSH_IS_ACTTACKED;	
		else
			m_State = MUSHROOM_STATE::MUSH_RUN;
}

void	CMushroom::updateEntity(RECT* rectCamera)
{

}

void	CMushroom::updateCollision(float deltaTime)
{
	this->getBounding().setVelocity(this->getVelocity());

	for (int i = 0; i < CMapManager::getInstance()->getListRect().size(); ++i) {
		if (this->m_State != MUSHROOM_STATE::MUSH_IS_ACTTACKED) {
			this->getBounding().setVelocity(this->getVelocity());
			switch (CCollision::CheckCollision(this->getBounding(), *(CMapManager::getInstance()->getListRect().at(i))))
			{
			case COLDIRECTION::COLDIRECTION_TOP:
				this->m_Position.y = CMapManager::getInstance()->getListRect().at(i)->getY() + this->getBounding().getHeight() / 2;
				break;
			case COLDIRECTION::COLDIRECTION_LEFT:
			case COLDIRECTION::COLDIRECTION_RIGHT:
				m_Velocity.x *= -1;
				break;
			default:
				break;
			}
		}
	}
	
	/* Collision with Player*/
	if (this->m_State != MUSHROOM_STATE::MUSH_IS_ACTTACKED) {
		this->getBounding().setVelocity(this->getVelocity());
		CPlayer::getInstance()->getBounding().setVelocity(CPlayer::getInstance()->getVelocity());
		switch (CCollision::CheckCollision(this->getBounding(), CPlayer::getInstance()->getBounding()))
		{
		case COLDIRECTION::COLDIRECTION_BOTTOM:
			m_State = MUSHROOM_STATE::MUSH_IS_ACTTACKED;
			break;
		default:
			break;
		}
	}
}

void	CMushroom::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(1, 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 5);
}

int CMushroom::getTagNodeId(){
	return TAGNODE::MUSHROOM;
}

class CMapManager;
