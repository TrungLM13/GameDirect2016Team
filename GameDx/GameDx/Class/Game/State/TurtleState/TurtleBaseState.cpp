#include "TurtleBaseState.h"

void TBaseState::exitCurrentState(Turtle& turtle, TBaseState* newState) {
	if (turtle.getState() != nullptr) {
		delete turtle.getState();
		turtle.setState(newState);
	}
}