#include "TurtleIndentState.h"
#include "TurtleRunState.h"

TIndentState::TIndentState() {
	countTime = 0.0f;
	
}

TIndentState::~TIndentState() {

}

void TIndentState::enter(Turtle& turtle) {

	turtle.setState(TURTLE_STATE::TURTLE_INDENT);
	
}

TBaseState* TIndentState::handleInput(Turtle& turtle, CKeyBoard* input){
	return nullptr;
}

void TIndentState::update(Turtle& turtle, double deltaTime) {
	

	turtle.setPosition(vector3d(turtle.getPosition().x, turtle.getPosition().y, 0));
	if (countTime < 1000)
	{
		countTime += deltaTime;
	}
	else
	{
		countTime = 0;
		exitCurrentState(turtle, new TRunState());
	}
}