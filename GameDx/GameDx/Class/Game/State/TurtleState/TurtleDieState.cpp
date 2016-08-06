#include "TurtleDieState.h"

TDieState::TDieState() {
}

TDieState::~TDieState() {

}

void TDieState::enter(Turtle& turtle) {
	turtle.setState(TURTLE_STATE::TURTLE_DIE);
}

TBaseState* TDieState::handleInput(Turtle& turtle, CKeyBoard* input){
	if (input->KeyDown(DIK_D))
	{
		return new TDieState();
	}


	//return nullptr;
}

void TDieState::update(Turtle& turtle, double deltaTime) {

	turtle.setPosition(vector3d(turtle.getPosition().x, turtle.getPosition().y + turtle.getVelocity().y * deltaTime / 10, 0.5));
	
	if (turtle.getPosition().y >= 150)
	{
		turtle.setVelocity(vector2d(turtle.getVelocity().x, turtle.getVelocity().y * (-1)));
	}
}