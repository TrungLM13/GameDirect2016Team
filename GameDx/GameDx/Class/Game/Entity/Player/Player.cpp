#include "Player.h"
#include "Class\Game\Utill\InformationResource.h"

CPlayer::CPlayer()
{
	this->initEntity();
}

CPlayer::~CPlayer()
{
}

CPlayer::CPlayer(LPDIRECT3DDEVICE9)
{
	this->initEntity();
	
}

bool CPlayer::initEntity()
{
	m_Position		= vector3d(200, 337, 0.5);
	m_State			= PLAYSTATE::START;

	m_Acceleration	= vector2d(0.5f, 0);
	this->m_isJump	= true;
	m_Velocity		= vector2d(9.8, 9.8);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);


	return true;
}

bool CPlayer::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart,				1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand,				1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStandShoot,		1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRun,				1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRunShoot,			1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJump,				1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJumpShoot,			1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimb,				1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimbShoot,		1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimbEnd,			1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanHit,				1, 3, 3, 0));
	return true;
}

void CPlayer::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case PLAYERSTATES::STATE_START:
		break;
	case PLAYERSTATES::STATE_STAND:
			logicStandPlayer(deltaTime);
		break;
	case PLAYERSTATES::STATE_MOVE:
			logicMovePlayer(deltaTime);
		break;
	case PLAYERSTATES::STATE_JUMP:
		logicJumpPlayer(deltaTime);
		break;
	default:
		break;
	}

}

void CPlayer::updateEntity(CKeyBoard* device)
{
	m_State				= PLAYERSTATES::STATE_STAND;

	if (device->KeyDown(DIK_LEFT))
	{
		m_State			= PLAYERSTATES::STATE_MOVE;
		m_Velocity.x	= std::abs(m_Velocity.x)*DIRECTION::DIRECTION_LEFT;
	}
	if (device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_MOVE;
		m_Velocity.x	= std::abs(m_Velocity.x)*DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyPress(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_STAND_SHOOT;
	}
	if (device->KeyDown(DIK_D))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		m_Velocity.y	= std::abs(m_Velocity.y) * DIRECTION::DIRECTION_UP;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_LEFT))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_JUMP;
		m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
	}
	if (device->KeyDown(DIK_RIGHT) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyDown(DIK_LEFT) && device->KeyDown(DIK_F))
	{
		m_State			= PLAYERSTATES::STATE_MOVE_SHOOT;
		m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_LEFT;
	}
	if (device->KeyDown(DIK_D) && device->KeyDown(DIK_F) && device->KeyDown(DIK_RIGHT))
	{
		m_State			= PLAYERSTATES::STATE_JUMP_SHOOT;
		m_Velocity.x	= std::abs(m_Velocity.x) * DIRECTION::DIRECTION_RIGHT;
	}
	if (device->KeyDown(DIK_LEFT) && device->KeyDown(DIK_RIGHT))
	{
		m_State = PLAYERSTATES::STATE_STAND;
	}
}

void CPlayer::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x)*2, SIGN(m_Velocity.y)*2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	//m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(this->getBounding().getX(), this->getBounding().getY(), 0.5f)), vector2d(SIGN(m_Velocity.x) * 2, SIGN(m_Velocity.y) * 2), 0, DRAWCENTER_LEFT_TOP, true, 10);
}

void CPlayer::logicMovePlayer(float deltaTime)
{
	m_Position.x += m_Velocity.x*(deltaTime / 100);

}
void CPlayer::logicJumpPlayer(float deltaTime)
{	
	m_Velocity.y = -10;
}

void CPlayer::logicStandPlayer(float deltaTime)
{
	if ((m_Velocity.x > 0 && m_Velocity.x <= 1) || (m_Velocity.x >= -1 && m_Velocity.x < 0))
	{
		m_Acceleration.x = 0;
		m_Velocity.x = 0;
	}
}

vector3d CPlayer::getPosition()
{
	return m_Position;
}
