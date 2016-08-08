#ifndef __TBASESTATE_H__
#define __TBASESTATE_H__

#include "Class\Game\Entity\Enemy\Turtle.h"


class TBaseState
{
public:
	virtual ~TBaseState(){};
	virtual void enter(Turtle& turtle) {};
	virtual void enter(Turtle& turtle, TURTLE_STATE state) { turtle.setState(state); }
	virtual TBaseState* handleInput(Turtle& turtle, CKeyBoard* device){ return nullptr; };
	virtual void update(Turtle& turtle, double deltaTime){};
	void exitCurrentState(Turtle& turtle, TBaseState* newState);
private:

};
#endif