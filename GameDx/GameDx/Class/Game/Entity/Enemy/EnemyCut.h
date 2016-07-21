#ifndef __ENEMY_CUT_H__
#define __ENEMY_CUT_H__

#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"

class CEnemyCut : public CMovable
{
public:
	CEnemyCut();
	CEnemyCut(vector3d m_position_player);
	~CEnemyCut();

	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();

private: 
	vector3d m_position_p;
	bool m_isLEFT;
	bool m_isJUMP;
};

#endif
