#ifndef __TENSCONSE_STATE_H__
#define __TENSCONSE_STATE_H__

#include "TurtleBaseState.h"


class TEnsconseState : public TBaseState {
public:
	TEnsconseState();
	~TEnsconseState();
	void enter(Turtle& turtle);
	TBaseState* handleInput(Turtle& turtle, CKeyBoard* device);
	void update(Turtle& turtle, double deltaTime);

private:
	float countTime;
};

#endif