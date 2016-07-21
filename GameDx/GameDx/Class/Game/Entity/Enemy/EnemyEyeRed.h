#ifndef __ENEMY_EYE_RED_H__
#define __ENEMY_EYE_RED_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"

class CEnemyEyeRed : public CMovable
{
public:
	CEnemyEyeRed();
	CEnemyEyeRed(vector3d m_position_p, bool m_Horizontal,bool m_isleft, bool m_istop);
	~CEnemyEyeRed();
	bool initEntity();
	void updateEntity(CKeyBoard* keyboard);
	void updateEntity( float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();

	bool loadSprite();
private:
	bool m_horizontal;
	bool m_isTop;
	bool m_isLeft;
	int m_checkState;
	int	 m_delay_Time;

};

#endif