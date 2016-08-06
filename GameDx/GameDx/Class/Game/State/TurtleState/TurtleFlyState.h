#ifndef __TFLY_STATE_H__
#define __TFLY_STATE_H__

#include "TurtleBaseState.h"


class TFlyState : public TBaseState {
public:
	TFlyState();
	~TFlyState();
	void enter(Turtle& turtle);
	TBaseState* handleInput(Turtle& turtle, CKeyBoard* device);
	void update(Turtle& turtle, double deltaTime);
private:
};

#endif