#pragma once
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"

class CEnemyNinja : public CMovable
{
public:
	CEnemyNinja();
	CEnemyNinja(vector3d, vector3d);
	~CEnemyNinja();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
	void jump();
	void fire();

private:
	bool m_isLEFT;
	int	 m_checkState;
	int	 m_delayTime;
	vector3d m_PositionPlayer;

};

