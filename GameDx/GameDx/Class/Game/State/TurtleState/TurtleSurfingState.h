#ifndef __SURFING_STATE_H__
#define __SURFING_STATE_H__

#include "TurtleBaseState.h"


class TSurfingState : public TBaseState {
public:
	TSurfingState();
	~TSurfingState();
	void enter(Turtle& turtle);
	TBaseState* handleInput(Turtle& turtle, CKeyBoard* device);
	void update(Turtle& turtle, double deltaTime);
private:
};

#endif