#include "TurtleFlyState.h"

TFlyState::TFlyState() {
}

TFlyState::~TFlyState() {

}

void TFlyState::enter(Turtle& turtle) {

	turtle.setState(TURTLE_STATE::TURTLE_FLY);
}

TBaseState* TFlyState::handleInput(Turtle& turtle, CKeyBoard* input){
	return nullptr;
}

void TFlyState::update(Turtle& turtle, double deltaTime) {
	if (turtle.getPosition().x <= BACKBUFFER_WIDTH || turtle.getPosition().x >= 0)
	{
			turtle.setVelocity(vector2d(turtle.getVelocity().x, -turtle.getVelocity().y));
			turtle.setPosition(vector3d(turtle.getPosition().x + (turtle.getVelocity().x - 1)* deltaTime / 400, turtle.getPosition().y - 0.1 + turtle.getVelocity().y* deltaTime / 100, 0));

	}
}