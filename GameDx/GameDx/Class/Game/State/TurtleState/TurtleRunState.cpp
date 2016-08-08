#include "TurtleRunState.h"

TRunState::TRunState() {
}

TRunState::~TRunState() {

}

void TRunState::enter(Turtle& turtle) {

		turtle.setState(TURTLE_STATE::TURTLE_RUN);
}

TBaseState* TRunState::handleInput(Turtle& turtle, CKeyBoard* input){

	if (input->KeyDown(DIK_RIGHT)) {
		if (turtle.getVelocity().x < 0)
			turtle.setVelocity(vector2d(turtle.getVelocity().x * (-1), turtle.getVelocity().y));
			return new TRunState();
		}
		if (input->KeyDown(DIK_LEFT)) {
			if (turtle.getVelocity().x > 0)
				turtle.setVelocity(vector2d(turtle.getVelocity().x * (-1), turtle.getVelocity().y));
		}

	return new TRunState();
}

void TRunState::update(Turtle& turtle, double deltaTime) {

	if (turtle.getPosition().x < 0 || turtle.getPosition().x > 300)
	{
		turtle.setVelocity(vector2d(-turtle.getVelocity().x, turtle.getVelocity().y));
		turtle.setPosition(vector3d(turtle.getPosition().x + turtle.getVelocity().x * deltaTime / 100, turtle.getPosition().y, 0));
	}
	else
	{
		turtle.setPosition(vector3d(turtle.getPosition().x + turtle.getVelocity().x * deltaTime / 100, turtle.getPosition().y, 0));
	}

		
}