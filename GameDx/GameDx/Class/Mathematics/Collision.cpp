#include "Collision.h"


CCollision::CCollision()
{
}


CCollision::~CCollision()
{
}

COLDIRECTION CCollision::CheckCollision(CMovable* MovableObject, CBaseEntity* Object)
{
	float moveX, moveY;
	vector2d velocity;
	CMovable* object;
	double timeCollition;
	float normalX, normalY;

	if (AABB((MovableObject->getBounding()), (Object->getBounding()), moveX, moveY))
	{
		if (moveY != 0)
			if (moveY >= 0)
				return COLDIRECTION::COLDIRECTION_TOP;
			else
				return COLDIRECTION::COLDIRECTION_BOTTOM;
		else 
			if (moveX != 0)
				if (moveX < 0)
					return COLDIRECTION::COLDIRECTION_LEFT;
				else
					return COLDIRECTION::COLDIRECTION_RIGHT;
			else
			{
				// already changing axis Oy into dacac
				if (MovableObject->getBounding().getY() == Object->getBounding().getY() + Object->getBounding().getHeight())
					return COLDIRECTION::COLDIRECTION_TOP;
				else if (MovableObject->getBounding().getY() + MovableObject->getBounding().getHeight() == Object->getBounding().getY())
						return COLDIRECTION::COLDIRECTION_BOTTOM;
				else if (MovableObject->getBounding().getX() == Object->getBounding().getX() + Object->getBounding().getWidth())
							return COLDIRECTION::COLDIRECTION_LEFT;
				else if (MovableObject->getBounding().getX() + MovableObject->getBounding().getWidth() == Object->getBounding().getX())
								return COLDIRECTION::COLDIRECTION_RIGHT;
			}
	}
	else
	{
		if (Object->getTagNode() == "Static")
			velocity = MovableObject->getVelocity();
		else
		{
			object = (CMovable*)Object;
			velocity = vector2d(MovableObject->getVelocity().x - object->getVelocity().x, MovableObject->getVelocity().y - object->getVelocity().y);
		}

		if (AABB(GetBroadPhaseBox(MovableObject->getBounding(), velocity), (Object->getBounding()), moveX, moveY))
		{
			timeCollition = SweptAABB(GetBoundForMovable(MovableObject->getBounding(), velocity), Object->getBounding(), normalX, normalY);
			
			if (timeCollition > 0.0f && timeCollition < 1.0f)
			{
				if (normalX != 0)
				{
					if (moveX != 0)
						if(normalX == -1.0f)
							return COLDIRECTION::COLDIRECTION_LEFT;
						else if (normalX == 1.0f)
							return COLDIRECTION::COLDIRECTION_RIGHT;
				}
				else
				{
					if (moveY != 0)
						if(normalY == -1.0f)
							return COLDIRECTION::COLDIRECTION_BOTTOM;
						else if (normalY == 1.0f)
							return COLDIRECTION::COLDIRECTION_TOP;
				}
				
			}

		}
	}
	return COLDIRECTION::COLDIRECTION_NONE;
}