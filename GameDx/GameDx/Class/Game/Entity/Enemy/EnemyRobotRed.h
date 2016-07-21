#ifndef __ENEMY_ROBOT_RED_H__
#define __ENEMY_ROBOT_RED_H__

#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"

class EnemyRobotRed : public CMovable
{
public:
	EnemyRobotRed();
	~EnemyRobotRed();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	bool m_isLEFT;
	int m_delay_Time;
	bool check_State;
};

#endif

