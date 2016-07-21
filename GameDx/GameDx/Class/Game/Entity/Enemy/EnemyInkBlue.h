#ifndef __ENEMY_INK_BLUE_H__
#define __ENEMY_INK_BLUE_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"

class CEnemyInkBlue : public CMovable
{
public:
	CEnemyInkBlue();
	CEnemyInkBlue(vector3d m_position_p, vector3d m_position = D3DXVECTOR3(300.0f, 100.0f, 0.0f));
	~CEnemyInkBlue();
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	vector3d m_position_Player;
	bool m_isLEFT;
	int m_delay_Time;
	bool check_State;
};

#endif