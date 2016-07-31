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
	m_Position = vector3d(200, 50, 0.5);
	m_Position = vector3d(50, 50, 0.5);

	m_State = PLAYERSTATES::STAND;
	m_PlayerState = new CStandState();
	m_PlayerTag = PLAYERTAGS::SMALL;

	m_Acceleration = vector2d(0.5f, 0);
	m_Velocity = vector2d(9.8, 9.8);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	return true;
}

bool CPlayer::loadSprite()
{
	//this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand, 2, 2, 0, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_stand, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_stand, 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_run, 1, 3, 3, 0));
	this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_jum, 1, 1, 1, 0));
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
	if (m_listSprite.size() > 0) {
		m_listSprite.clear();
	}

	switch (m_PlayerTag)
	{
	case PLAYERTAGS::SMALL:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand, 1, 2, 2, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRun, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJump, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStandShoot, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRunShoot, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJumpShoot, 1, 1, 1, 0));
		break;
	case PLAYERTAGS::BIG:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStart1, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStand1, 1, 2, 2, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRun1, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJump1, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanStandShoot1, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanRunShoot1, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::rockmanJumpShoot1, 1, 1, 1, 0));
		break;
	default:
		break;
	}

	return true;
}

void CPlayer::updateEntity(float deltaTime)
{
	if (deltaTime > 10) {
		/*m_PlayerState->exitCurrentState(*this, new CRunState());
		m_PlayerState->enter(*this);*/
	}

	if (m_PlayerState)
		m_PlayerState->update(*this, deltaTime);
}

void CPlayer::updateEntity(RECT* camera) {

}

void CPlayer::updateEntity(CKeyBoard* input)
{
	if (input->KeyDown(DIK_Z))
	{
		m_PlayerTag = PLAYERTAGS::BIG;
		this->loadSprite();
	}
	else if (input->KeyDown(DIK_X)) 
	{
		m_PlayerTag = PLAYERTAGS::SMALL;
		this->loadSprite();
	}

	if (m_PlayerState){
		CBaseState* state = m_PlayerState->handleInput(*this, input);

		if (state != nullptr)
		{
			if (m_PlayerState != state)
				delete m_PlayerState;
			m_PlayerState = state;
		}
		m_PlayerState->enter(*this);
	}
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

CBaseState* CPlayer::getState(){
	return m_PlayerState;
}

void CPlayer::setState(CBaseState* state) {
	m_PlayerState = state;
}

void CPlayer::setPlayerTag(int playerTag){
	this->m_PlayerTag = playerTag;
}

int CPlayer::getPlayerTag() {
	return m_PlayerTag;
}