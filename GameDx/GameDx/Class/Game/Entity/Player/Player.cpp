#include "Player.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Game\State\StandState.h"
#include "Class\Game\State\DieState.h"
#include "Class\Game\State\ClimbState.h"
#include "Class\Mathematics\Collision.h"

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
	m_IsCollision = false;
	m_Direction.push_back(DIRECTION::DIRECTION_NONE);
	m_Direction.push_back(DIRECTION::DIRECTION_NONE);

	m_UndyingTime = 0;
	m_Position = vector3d(50, 70, 0.5);

	m_State = PLAYERSTATES::STAND;
	m_PlayerState = new CJumpState();
	m_PlayerTag = PLAYERTAGS::SMALL;

	m_Acceleration = vector2d(0.5f, 0);
	m_Velocity = vector2d(0, 9.8);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	return true;
}

int	CPlayer::getTagNodeId() {
	return TAGNODE::PLAYER;
}

bool CPlayer::loadSprite()
{
	if (m_listSprite.size() > 0) {
		m_listSprite.clear();
	}

	switch (m_PlayerTag)
	{
	case PLAYERTAGS::SMALL:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_cdir, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_stand, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_run, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_jum, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_die, 1, 1, 1, 0));

		break;
	case PLAYERTAGS::BIG:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_stand, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_stand, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_run, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_jum, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_die, 1, 1, 1, 0));
		break;
	case PLAYERTAGS::SMALL_UNDYING:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_undying_stand, 1, 4, 4, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_undying_stand, 1, 4, 4, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_undying_run, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_undying_jum, 1, 4, 4, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_die, 1, 1, 1, 0));
		break;
	case PLAYERTAGS::UNDYING:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_undying_stand, 1, 4, 4, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_undying_stand, 1, 4, 4, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_undying_run, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigmario_undying_jum, 1, 4, 4, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_die, 1, 1, 1, 0));
		break;
	case PLAYERTAGS::FIRE:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_stand, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_stand, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_run, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_jum, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::smallmario_die, 1, 1, 1, 0));
		/*this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_runfire, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_runfire, 1, 3, 3, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_runfire, 1, 3, 3, 0));

		this->m_listSprite.push_back(new CSprite(CInfomationResource::bigfiremario_jumfire, 1, 1, 1, 0));*/
		break;
	default:
		break;
	}

	return true;
}

void CPlayer::updateEntity(float deltaTime)
{
	if (this->m_PlayerTag == PLAYERTAGS::UNDYING)
	{
		if (m_UndyingTime >= 0)
			m_UndyingTime -= deltaTime;
		else
		{
			this->m_PlayerTag = PLAYERTAGS::BIG;
			this->loadSprite();
		}
	}

	else if (this->m_PlayerTag == PLAYERTAGS::SMALL_UNDYING)
	{
		if (m_UndyingTime >= 0)
			m_UndyingTime -= deltaTime;
		else
		{
			this->m_PlayerTag = PLAYERTAGS::SMALL;
			this->loadSprite();
		}
	}

	if (m_PlayerState)
		m_PlayerState->update(*this, deltaTime);
}

void CPlayer::updateEntity(RECT* camera) {

}

void CPlayer::updateEntity(CKeyBoard* input)
{
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

void CPlayer::handleCollision(CBaseEntity* entity, float deltaTime) {
	switch (entity->getTagNodeId())
	{
	case TAGNODE::RED_MUSHROOM:
		if (CCollision::CheckCollision(this, entity)) {
			if (this->m_PlayerTag == PLAYERTAGS::SMALL) {
				m_PlayerTag = PLAYERTAGS::BIG;
				this->loadSprite();
			}
		}
		break;
	case TAGNODE::STAR:
		if (CCollision::CheckCollision(this, entity)) {
			if (this->m_PlayerTag == PLAYERTAGS::BIG || this->m_PlayerTag == PLAYERTAGS::FIRE) {
				m_PlayerTag = PLAYERTAGS::UNDYING;
				this->loadSprite();
				this->m_UndyingTime = PLAYER_UNDYING_TIME;
			}
		}
		break;
	case TAGNODE::FLOWER:
		if (CCollision::CheckCollision(this, entity)) {
			if (this->m_PlayerTag == PLAYERTAGS::BIG || this->m_PlayerTag == PLAYERTAGS::FIRE) {
				m_PlayerTag = PLAYERTAGS::FIRE;
			}
		}
		break;
	case TAGNODE::COIN:
		break;
	case TAGNODE::BRICK: case TAGNODE::GIFT_BOX:
		if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_BOTTOM)
		{
			if (this->m_Velocity.y > 0)
			{
				this->m_Velocity.y *= -1;
			}
		}
		break;
	case TAGNODE::TILE:
		if (this->m_State != PLAYERSTATES::DIE) {
			if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_TOP)
			{
				this->m_Position.y = entity->getPosition().y + entity->getBounding().getHeight() / 2 + this->getBounding().getHeight() / 2;
				this->m_PlayerState->exitCurrentState(*this, new CStandState());
				this->m_PlayerState->enter(*this);
			}

		}
		else {
			if (this->m_Velocity.y >= 0)
			{
				this->m_Velocity.y *= -1;
			}
		}
		break;
	case TAGNODE::FLAG:
		if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_BOTTOM)
		{

		}
		break;
	case TAGNODE::FLAG_POLE:

		break;
	case TAGNODE::FLAG_POLE_TAIL:
		if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_LEFT)
		{
			m_IsCollision = true;

			if (m_State == PLAYERSTATES::JUMP || m_State == PLAYERSTATES::JUMP_SHOOT) {
				this->m_PlayerState->exitCurrentState(*this, new CClimbState());
			}
			if (this->m_Direction.at(DIRECTIONINDEX::DIRECTION_X) == DIRECTION::DIRECTION_RIGHT)
			{
				m_Velocity.x = 0;
				//m_Position.x = entity->getPosition().x - entity->getBounding().getWidth() / 2 - this->getBounding().getWidth() / 2;
			}
			else if (this->m_Direction.at(DIRECTIONINDEX::DIRECTION_X) == DIRECTION::DIRECTION_LEFT) {
				m_IsCollision = false;
				this->m_Velocity.x = 9.8 * this->m_Direction.at(DIRECTIONINDEX::DIRECTION_X);
			}

		}
		else if (CCollision::CheckCollision(this, entity) == COLDIRECTION::COLDIRECTION_NONE)
			m_IsCollision = false;
		break;
	case TAGNODE::MUSHROOM:
		if (CCollision::CheckCollision(this, entity)) {
			if (this->m_PlayerTag == PLAYERTAGS::SMALL) {
				this->m_PlayerState->exitCurrentState(*this, new CDieState());
				this->m_PlayerState->enter(*this);
			}
			if (this->m_PlayerTag == PLAYERTAGS::BIG || this->m_PlayerTag == PLAYERTAGS::FIRE)
			{
				//undying but small and exists in 5s
				this->m_PlayerTag = PLAYERTAGS::SMALL_UNDYING;
				this->loadSprite();
				this->m_UndyingTime = SMALL_PLAYER_UNDYING_TIME;
			}
		}
		break;
	case TAGNODE::NONE:
		if (this->m_State == PLAYERSTATES::STAND || PLAYERSTATES::RUN)
		{
			//m_IsCollision = false;
		}
		break;
	default:
		break;
	}
}

void CPlayer::drawEntity()
{
	m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(m_Position)), vector2d(SIGN(m_Velocity.x), abs(m_Velocity.y / m_Velocity.y)), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
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

int	CPlayer::getStateInt() {
	return m_State;
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