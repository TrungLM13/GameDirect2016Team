#ifndef __RUN_STATE_H__
#define __RUN_STATE_H__

#include "BaseState.h"


class CRunState : public CBaseState {
public:
	CRunState();
	~CRunState();
	void enter(CPlayer& player);
	CBaseState* handleInput(CPlayer& player, CKeyBoard* device);
	void update(CPlayer& player, double deltaTime);
	int  getMoveDirection();
	void setMoveDirection(DIRECTION direction);
private:
	bool m_IsShoot;
	int m_MoveDirection;
};

#endif