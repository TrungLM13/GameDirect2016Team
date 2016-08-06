#include "TurtleSurfingState.h"

TSurfingState::TSurfingState() {
}

TSurfingState::~TSurfingState() {

}

void TSurfingState::enter(Turtle& turtle) {

	turtle.setState(TURTLE_STATE::TURTLE_SURGING);
}

TBaseState* TSurfingState::handleInput(Turtle& turtle, CKeyBoard* input){
	return nullptr;
}

void TSurfingState::update(Turtle& turtle, double deltaTime) {
	turtle.setPosition(vector3d(turtle.getPosition().x + turtle.getVelocity().x*deltaTime/ 20, turtle.getPosition().y, 0));
}