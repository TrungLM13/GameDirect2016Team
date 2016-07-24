#include "Player.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Game\State\StandState.h"
CPlayer::CPlayer()
{
	this->initEntity();
}

CPlayer::~CPlayer()
{
	SAFE_RELEASE(m_PlayerState);
}

CPlayer::CPlayer(directDevice device)
{
	this->initEntity();

}

bool CPlayer::initEntity()
{
	m_Position = vector3d(200, 150, 0.5);

	m_State = PLAYERSTATES::STAND;
	m_PlayerState = new CStandState();

	m_Acceleration = vector2d(0.5f, 0);
	m_Velocity = vector2d(9.8, 9.8);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	return true;
}

bool CPlayer::loadSprite()
{
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand, 2, 2, 0, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart, 1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand, 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRun, 1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJump, 1, 1, 1, 0));

	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart,				1, 3, 3, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStandShoot,		1, 1, 1, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRun,				1, 3, 3, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRunShoot,			1, 3, 3, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJump,				1, 1, 1, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJumpShoot,			1, 1, 1, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimb,				1, 2, 2, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimbShoot,		1, 1, 1, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanClimbEnd,			1, 1, 1, 0));
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanHit,				1, 3, 3, 0));
	return true;
}

void CPlayer::updateEntity(float deltaTime)
{
	m_PlayerState->update(*this, deltaTime);

}

void CPlayer::updateEntity(RECT* camera) {

}

void CPlayer::updateEntity(CKeyBoard* input)
{
	CBaseState* state = m_PlayerState->handleInput(*this, input);

	if (state != nullptr)
	{
		//	delete m_PlayerState;
		m_PlayerState = state;
	}
	m_PlayerState->enter(*this);
}

void CPlayer::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * 2, abs(m_Velocity.y / m_Velocity.y) * 2), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	//m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(this->getBounding().getX(), this->getBounding().getY(), 0.5f)), vector2d(SIGN(m_Velocity.x) * 2, SIGN(m_Velocity.y) * 2), 0, DRAWCENTER_LEFT_TOP, true, 10);
}

void CPlayer::setState(PLAYERSTATES state) {
	m_State = state;
}

vector3d CPlayer::getPosition()
{
	return m_Position;
}

void CPlayer::setPosition(vector3d position) {
	m_Position = position;
}

void CPlayer::setVelocity(vector2d velocity) {
	m_Velocity = velocity;
}