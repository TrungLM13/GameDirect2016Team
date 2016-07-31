#include "AABB.h"
#include "Box2D.h"
#include "Class\Game\Utill\stdafx.h"
#include "Class\Framework\Sprite.h"
#include "Class\Game\Entity\MovableEntity.h"

class Collision
{
	
public:
	float veclocity_x;
	float veclocity_y;
	Collision();
	~Collision();
	COLDIRECTION isCollision(CMovable* MovableObject, CBaseEntity* Object);
	COLDIRECTION isCollision(CBox2D MovableObject, CBox2D Object);
	 

};

