#ifndef __CCOLLOSION_H__
#define __CCOLLOSION_H__

#include "Class\Game\Utill\Config.h"
#include "Class\Mathematics\Box2D.h"
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Mathematics\SweptAABB.h"

class CCollision
{
public:
	CCollision();
	~CCollision();
	
	static COLDIRECTION CheckCollision(CMovable* MovableObject, CBaseEntity* Object);
};

#endif
