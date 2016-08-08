#ifndef __TINDENT_STATE_H__
#define __TINDENT_STATE_H__

#include "TurtleBaseState.h"


class TIndentState : public TBaseState {
public:
	TIndentState();
	~TIndentState();
	void enter(Turtle& turtle);
	TBaseState* handleInput(Turtle& turtle, CKeyBoard* device);
	void update(Turtle& turtle, double deltaTime);
private:
	float countTime;
};

#endif