#include "Collision.h"


CCollision::CCollision()
{
}


CCollision::~CCollision()
{
}

COLDIRECTION CCollision::CheckCollision(CMovable* MovableObject, CBaseEntity* Object)
{
	float		moveX, moveY;
	vector2d	velocity;
	CMovable*	object;
	double		timeCollition;
	float		normalX, normalY;
	CBox2D		movableBox, baseBox;

	movableBox	= MovableObject->getBounding();
	baseBox		= Object->getBounding();

	/* Arcoding to Swept AABB Collision detected agolrismth. Collision detect by velocity * elapedtime.
	But the first thing, we need check intesert between 2 entity. Unless collision, next step.
	Unless detect collision with interset. We need calculate time so that is collition.
	*/
	if (AABB(movableBox, baseBox, moveX, moveY))
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
				if (movableBox.getY() == baseBox.getY() + baseBox.getHeight())
					return COLDIRECTION::COLDIRECTION_TOP;
				else if (movableBox.getY() + movableBox.getHeight() == baseBox.getY())
						return COLDIRECTION::COLDIRECTION_BOTTOM;
				else if (movableBox.getX() == baseBox.getX() + baseBox.getWidth())
							return COLDIRECTION::COLDIRECTION_LEFT;
				else if (movableBox.getX() + movableBox.getWidth() == baseBox.getX())
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

		if (AABB(GetBroadPhaseBox(movableBox, velocity), baseBox, moveX, moveY))
		{
			timeCollition = SweptAABB(GetBoundForMovable(movableBox, velocity), baseBox, normalX, normalY);
			
			// nesscessary. because if timeCollition > 1, thats mean, MovableObject' direction and Base's direction is opposition and more and more away from each other.
			if (timeCollition > 0.0f && timeCollition < 1.0f)
			{
				// we have 2 situaion that is collition.
				// 
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