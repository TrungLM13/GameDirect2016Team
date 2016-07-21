#ifndef __ENEMY_MACHINE_AUTO_ORANGE_H__
#define __ENEMY_MACHINE_AUTO_ORANGE_H__

#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"


class CEnemyMachineAutoOrange : public CMovable
{
public:
	CEnemyMachineAutoOrange();
	CEnemyMachineAutoOrange(vector3d position);
	~CEnemyMachineAutoOrange();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	int m_delay_Time;
	bool check_State;
};

#endif