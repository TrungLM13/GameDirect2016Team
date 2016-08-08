#include "Elevator.h"
#include "Class\Game\Utill\InformationResource.h"

Elevator::Elevator()
{
	this->initEntity();
}

Elevator::~Elevator()
{
}

Elevator::Elevator(directDevice device)
{
	this->initEntity();

}

bool Elevator::initEntity()
{
	//m_Position = vector3d(200, 50, 0.5);
	m_Position = vector3d(150, 50, 0.5);
	m_State = ELEVATOR_STATE::UP;
	m_TagNode = "Elevator";

	m_Acceleration = vector2d(0.5f, 0);
	m_Velocity = vector2d(5, 5);

	this->loadSprite();
	this->m_Bounding = new CBox2D(0, 0, 0, 0);

	return true;
}

bool Elevator::loadSprite()
{
	if (m_listSprite.size() > 0) {
		m_listSprite.clear();
	}

	this->m_listSprite.push_back(new CSprite(CInfomationResource::elevator, 1, 1, 1, 0));

	return true;
}

void Elevator::updateEntity(float deltaTime)
{


	switch (m_State)
	{
	case ELEVATOR_STATE::DOWN:
		this->setPosition(vector3d(this->getPosition().x, this->getPosition().y - abs(this->getVelocity().y * deltaTime / 100), 0));
		break;
	case ELEVATOR_STATE::UP:
		this->setPosition(vector3d(this->getPosition().x, this->getPosition().y + abs(this->getVelocity().y * deltaTime / 100), 0));
		break;
	case ELEVATOR_STATE::RIGHT:
		this->setPosition(vector3d(this->getPosition().x + abs(this->getVelocity().x * deltaTime / 100), this->getPosition().y, 0));
		break;
	case ELEVATOR_STATE::LEFT:
		this->setPosition(vector3d(this->getPosition().x - abs(this->getVelocity().x * deltaTime / 100), this->getPosition().y, 0));
		break;
	default:
		break;
	}
}

void Elevator::updateEntity(RECT* camera) {

}

void Elevator::updateEntity(CKeyBoard* input)
{

	/*if (input->KeyDown(DIK_A))
	{
		m_State = DIRECTION::DIRECTION_LEFT;
		this->loadSprite();
		this->setPosition(vector3d(this->getPosition().x - this->getVelocity().x, this->getPosition().y, 0));
	}*/
}

void Elevator::drawEntity()
{{
		m_listSprite.at(0)->Render(CCamera::setPositionEntity(m_Position), vector2d(SIGN(m_Velocity.x) * (-1), abs(m_Velocity.y / m_Velocity.y) * 1), 0, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		//m_listSprite.at(m_State)->Render(CCamera::setPositionEntity(vector3d(this->getBounding().getX(), this->getBounding().getY(), 0.5f)), vector2d(SIGN(m_Velocity.x) * 2, SIGN(m_Velocity.y) * 2), 0, DRAWCENTER_LEFT_TOP, true, 10);
	}
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
