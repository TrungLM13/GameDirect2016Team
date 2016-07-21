#ifndef __BOSS_CUT_MAN_H__
#define __BOSS_CUT_MAN_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"


class CBossCutMan : public CMovable
{
public:
	CBossCutMan();
	CBossCutMan(vector3d position);
	~CBossCutMan();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	int m_delayTime;
	int m_checkState;
	bool m_isLeft;
};


#endif