#ifndef __CCOLLOSION_H__
#define __CCOLLOSION_H__

#include "Class\Game\Utill\Config.h"
#include "Class\Mathematics\Box2D.h"
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Mathematics\SweptAABB.h"
#include "Class\Game\Algorithsm\Singleton.h"

class CCollision: public CSingleton<CCollision>
{
public:
	CCollision();
	~CCollision();
	
	static COLDIRECTION CheckCollision(CMovable* MovableObject, CBaseEntity* Object);

	static COLDIRECTION CheckCollision(CBox2D movBox, CBox2D baseBox);
};

#endif
