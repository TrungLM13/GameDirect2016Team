#ifndef __TURTLE_DIE_STATE_H__
#define __TURTLE_DIE_STATE_H__

#include "TurtleBaseState.h"
#include "TurtleRunState.h"

class TDieState : public TBaseState {
public:
	TDieState();
	~TDieState();
	void enter(Turtle& turtle);
	TBaseState* handleInput(Turtle& turtle, CKeyBoard* device);
	void update(Turtle& turtle, double deltaTime);
private:
};

#endif