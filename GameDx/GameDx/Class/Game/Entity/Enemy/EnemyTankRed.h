#ifndef __ENEMY_TANK_RED_H__
#define __ENEMY_TANK_RED_H__

#include "Class\Game\Entity\StaticEntity.h"
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"


class CEnemyTankRed : public CStaticEntity
{
public:
	CEnemyTankRed();
	CEnemyTankRed(vector3d position);
	~CEnemyTankRed();
	virtual bool initEntity()											override;
	void updateEntity(CKeyBoard* keyboard);
	void updateEntity(float deltaTime);
	void updateEntity(RECT rectCamera);
	void drawEntity();
	bool loadSprite();

private:
	bool m_checkState;
	int	 m_delay_Time;

};

#endif