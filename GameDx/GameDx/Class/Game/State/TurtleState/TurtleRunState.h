#ifndef __TRUN_STATE_H__
#define __TRUN_STATE_H__

#include "TurtleBaseState.h"


class TRunState : public TBaseState {
public:
	TRunState();
	~TRunState();
	void enter(Turtle& turtle);
	TBaseState* handleInput(Turtle& turtle, CKeyBoard* device);
	void update(Turtle& turtle, double deltaTime);
private:
};

#endif