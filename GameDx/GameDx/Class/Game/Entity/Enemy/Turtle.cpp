#include "Turtle.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Game\State\TurtleState\TurtleRunState.h"
#include "Class\Game\State\TurtleState\TurtleDieState.h"
#include "Class\Game\State\TurtleState\TurtleEnsconseState.h"
#include "Class\Game\State\TurtleState\TurtleFlyState.h"
#include "Class\Game\State\TurtleState\TurtleSurfingState.h"

Turtle::Turtle()
{
	this->initEntity();
}

Turtle::~Turtle()
{
	SAFE_RELEASE(m_Turtle_State);
}

Turtle::Turtle(directDevice device)
{
	this->initEntity();

}

bool Turtle::initEntity()
{
	//m_Position = vector3d(200, 50, 0.5);
	m_Position = vector3d(50, 100, 0.5);

	m_State = TURTLE_STATE::TURTLE_RUN;
	m_Turtle_State = new TRunState();
	m_Turtle_Tag = TURTLE_TAG::RED;
	m_TagNode = "Turtle";

	m_Acceleration = vector2d(0.5f, 0);
	m_Velocity = vector2d(4, 2.5);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	return true;
}

bool Turtle::loadSprite()
{
	if (m_listSprite.size() > 0) {
		m_listSprite.clear();
	}

	switch (m_Turtle_Tag)
	{
	case TURTLE_TAG::GREEN:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::greenturtle_run, 1, 2, 2, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::greenturtle_ensconse, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::greenturtle_indent, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::greenturtle_fly, 1, 2, 2, 0));

		break;
	case TURTLE_TAG::RED:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::redturtle_run, 1, 2, 2, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::redturtle_ensconse, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::redturtle_indent, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::redturtle_fly, 1, 2, 2, 0));
		break;
	case TURTLE_TAG::NAVI:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::naviturtle_run, 1, 2, 2, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::naviturtle_ensconse, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::naviturtle_indent, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::naviturtle_fly, 1, 2, 2, 0));
		break;
	case TURTLE_TAG::THORN:
		this->m_listSprite.push_back(new CSprite(CInfomationResource::thornturtle_run, 1, 2, 2, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::thornturtle_ensconse, 1, 1, 1, 0));
		this->m_listSprite.push_back(new CSprite(CInfomationResource::thornturtle_indent, 1, 1, 1, 0));
		break;
	default:
		break;
	}

	return true;
}

void Turtle::updateEntity(float deltaTime)
{
	if (deltaTime > 10) {
		/*m_Turtle_State->exitCurrentState(*this, new CRunState());
		m_Turtle_State->enter(*this);*/
	}

	if (m_Turtle_State)
		m_Turtle_State->update(*this, deltaTime);
}

void Turtle::updateEntity(RECT* camera) {

}

void Turtle::updateEntity(CKeyBoard* input)
{
	if (input->KeyDown(DIK_Z))
	{
		m_Turtle_Tag = TURTLE_TAG::GREEN;
		this->loadSprite();
	}
	
	else if (input->KeyDown(DIK_X))
	{
		m_Turtle_Tag = TURTLE_TAG::NAVI;
		this->loadSprite();
	}

	if (input->KeyDown(DIK_D))
	{
		m_State = TURTLE_STATE::TURTLE_DIE;
		this->loadSprite();
		m_Turtle_State = new TDieState();
	}
	if (input->KeyDown(DIK_E))
	{
		m_State = TURTLE_STATE::TURTLE_ENSCONSE;
		this->loadSprite();
		m_Turtle_State = new TEnsconseState();
	}
	if (input->KeyDown(DIK_F))
	{
		m_State = TURTLE_STATE::TURTLE_FLY;
		this->loadSprite();
		m_Turtle_State = new TFlyState();
	}
	if (input->KeyDown(DIK_S))
	{
		m_State = TURTLE_STATE::TURTLE_SURGING;
		this->loadSprite();
		m_Turtle_State = new TSurfingState();
	}
	if (m_Turtle_State){
		TBaseState* state = m_Turtle_State->handleInput(*this, input);

		if (state != nullptr)
		{
			if (m_Turtle_State != state)
				delete m_Turtle_State;
			m_Turtle_State = state;
		}
		m_Turtle_State->enter(*this);
	}
}

void Turtle::drawEntity()
{
	if (m_State == TURTLE_STATE::TURTLE_DIE)
	{
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * (-1), abs(m_Velocity.y / m_Velocity.y) * -1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	else
	{
		m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * (-1), abs(m_Velocity.y / m_Velocity.y) * 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		//m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(this->getBounding().getX(), this->getBounding().getY(), 0.5f)), vector2d(SIGN(m_Velocity.x) * 2, SIGN(m_Velocity.y) * 2), 0, DRAWCENTER_LEFT_TOP, true, 10);
	}
}

void Turtle::setState(TURTLE_STATE state) {
	m_State = state;
}

vector3d Turtle::getPosition()
{
	return m_Position;
}

void Turtle::setPosition(vector3d position) {
	m_Position = position;
}

void Turtle::setVelocity(vector2d velocity) {
	m_Velocity = velocity;
}

TBaseState* Turtle::getState(){
	return m_Turtle_State;
}


void Turtle::setState(TBaseState* state) {
	m_Turtle_State = state;
}

void Turtle::setTurtleTag(int playerTag){
	this->m_Turtle_Tag = playerTag;
}

int Turtle::getTurtleTag() {
	return m_Turtle_Tag;
}