#include "TurtleEnsconseState.h"
#include "TurtleIndentState.h"

TEnsconseState::TEnsconseState() {
	countTime = 0.0f;
}

TEnsconseState::~TEnsconseState() {

}

void TEnsconseState::enter(Turtle& turtle) {

	turtle.setState(TURTLE_STATE::TURTLE_ENSCONSE);
}

TBaseState* TEnsconseState::handleInput(Turtle& turtle, CKeyBoard* input){
	return nullptr;
}

void TEnsconseState::update(Turtle& turtle, double deltaTime) {

	turtle.setPosition(vector3d(turtle.getPosition().x, turtle.getPosition().y, 0));
	if (countTime < 1000)
	{

		countTime += deltaTime;
	}
	else
	{
		countTime = 0;
		exitCurrentState(turtle, new TIndentState());
	}
}
