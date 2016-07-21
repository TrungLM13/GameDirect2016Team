#ifndef __ENEMY_BALL_H__
#define __ENEMY_BALL_H__

#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"
#include "Class\Mathematics\Collision.h"
#include "Class\EnemyBubbleBlue.h"

class CEnemyBall : public CMovable
{
public:
	CEnemyBall();
	CEnemyBall(LPDIRECT3DDEVICE9);
	~CEnemyBall();

	bool initEntity()											;
	void updateEntity(float deltaTime)							;
	void updateEntity(CKeyBoard *device)						;
	void updateEntity(RECT rectCamera)							;
	void drawEntity()											;

	bool loadSprite()											;

private:
	int m_delay_Time;
	bool check_State;
};

#endif