#include "Elevator.h"
#include "Class\Game\Utill\InformationResource.h"

Elevator::Elevator()
{
	this->initEntity();
}

Elevator::~Elevator()
{
}

Elevator::Elevator(vector2d pos, ELEVATOR_STATE ElevatorState)
{
	this->m_Position.x = pos.x;
	this->m_Position.y = pos.y;

	this->m_State = ElevatorState;

	this->initEntity();

}

bool Elevator::initEntity()
{

	m_TagNode = "Elevator";

	m_Velocity = vector2d(ELEVATOR_VELOCITY_X, ELEVATOR_VELOCITY_Y);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	return true;
}

bool Elevator::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(CInfomationResource::elevator, 1, 1, 1, 0));

	return true;
}

void Elevator::updateEntity(float deltaTime)
{
	switch (m_State)
	{
	case ELEVATOR_STATE::DOWN:
		if (SIGN(this->m_Velocity.y) == DIRECTION::DIRECTION_UP)
			this->m_Velocity.y = CHANGE_DIRECTION(this->m_Velocity.y);

		this->m_Position.y += this->m_Velocity.y *deltaTime / 100;
		//this->setPosition(vector3d(this->getPosition().x, this->getPosition().y - abs(this->getVelocity().y * deltaTime / 100), 0));
		break;
	case ELEVATOR_STATE::UP:
		if (SIGN(this->m_Velocity.y) == DIRECTION::DIRECTION_DOWN)
			this->m_Velocity.y = CHANGE_DIRECTION(this->m_Velocity.y);

		this->m_Position.y += this->m_Velocity.y *deltaTime / 100;
		//this->setPosition(vector3d(this->getPosition().x, this->getPosition().y + abs(this->getVelocity().y * deltaTime / 100), 0));
		break;
	case ELEVATOR_STATE::UP_DOWN:
		if (this->m_Position.y <= ELEVATOR_POSITION_Y_MIN)
		{
			if (SIGN(this->m_Velocity.y) == DIRECTION::DIRECTION_DOWN)
				this->m_Velocity.y = CHANGE_DIRECTION(this->m_Velocity.y);
		}
		else if (this->m_Position.y >= ELEVATOR_POSITION_Y_MAX){
			if (SIGN(this->m_Velocity.y) == DIRECTION::DIRECTION_UP)
				this->m_Velocity.y = CHANGE_DIRECTION(this->m_Velocity.y);
		}
		this->m_Position.y += this->m_Velocity.y * deltaTime / 100;
		break;
	case ELEVATOR_STATE::RIGHT_LEFT:
		if (this->m_Position.x <= ELEVATOR_POSITION_X_MIN)
		{
			if (SIGN(this->m_Velocity.x) == DIRECTION::DIRECTION_LEFT)
				this->m_Velocity.x = CHANGE_DIRECTION(this->m_Velocity.x);
		}
		else if (this->m_Position.x >= ELEVATOR_POSITION_X_MAX){
			if (SIGN(this->m_Velocity.y) == DIRECTION::DIRECTION_RIGHT)
				this->m_Velocity.x = CHANGE_DIRECTION(this->m_Velocity.x);
		}
		this->m_Position.x += this->m_Velocity.x * deltaTime / 100;
		break;
	default:
		break;
	}
}

void Elevator::updateEntity(RECT* camera) {

}

void Elevator::updateEntity(CKeyBoard* input)
{
}

void Elevator::drawEntity()
{
	m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * (-1), abs(m_Velocity.y / m_Velocity.y) * 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}

void Elevator::setState(ELEVATOR_STATE state) {
	m_State = state;
}

vector3d Elevator::getPosition()
{
	return m_Position;
}

void Elevator::setPosition(vector3d position) {
	m_Position = position;
}

void Elevator::setVelocity(vector2d velocity) {
	m_Velocity = velocity;
}

int	Elevator::getTagNodeId()
{
	return TAGNODE::ELEVATOR;
}