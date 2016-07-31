#include "T_Collision.h"

Collision::Collision() :veclocity_x(0.0f), veclocity_y(0.0f)
{
}

Collision::~Collision()
{
}
COLDIRECTION Collision::isCollision(CBox2D MovableObject, CBox2D Object)
{
	CBox2D moveBox = MovableObject;
	CBox2D dynamicBox = Object;
	float normalx = 0.0f, normaly = 0.0f;
	veclocity_x = moveBox.getVelocityX();
	veclocity_y = moveBox.getVelocityY();

	//kiểm tra va chạm không cần biết vận tốc đối tượng
	COLDIRECTION coldiection = CheckAABB(moveBox, dynamicBox);
	if (coldiection == COLDIRECTION::COLDIRECTION_NONE)
	{
		//dừng box
		dynamicBox.setX(dynamicBox.getX() + dynamicBox.getVelocityX());
		dynamicBox.setY(dynamicBox.getY() + dynamicBox.getVelocityY());
		dynamicBox.setVelocityX(0.0f);
		dynamicBox.setVelocityY(0.0f);

		//vật nằm trong đối tượng
		if (CheckAABB(dynamicBox, GetSweptBroadPhaseBox(moveBox)) != COLDIRECTION::COLDIRECTION_NONE)
		{
			float timeCollision = SweptAABB(moveBox, dynamicBox, normalx, normaly);

			if (timeCollision > 0.0f && timeCollision <= 1.0f)
			{
				//update velocity
				if (abs(veclocity_x) >= abs(moveBox.getVelocityX() * timeCollision + normalx) && normalx != 0.0f)
					veclocity_x = moveBox.getVelocityX() * timeCollision + normalx;
				if (abs(veclocity_y) >= abs(moveBox.getVelocityY() *timeCollision + normaly) && normaly != 0.0f)
					veclocity_y = moveBox.getVelocityY() * timeCollision + normaly;

				if (normalx != 0.0f)
				{
					if (normalx == 1.0f)
					{
						return COLDIRECTION::COLDIRECTION_LEFT;

					}
					if (normalx == -1.0f)
					{
						return COLDIRECTION::COLDIRECTION_RIGHT;
					}
				}
				else
				{
					if (normaly == -1.0f)
					{
						return COLDIRECTION::COLDIRECTION_TOP;

					}
					if (normaly == 1.0f)
					{
						return COLDIRECTION::COLDIRECTION_BOTTOM;
					}
				}
			}
			else
			{
				return COLDIRECTION::COLDIRECTION_NONE;
			}
		}
		else
		{
			return COLDIRECTION::COLDIRECTION_NONE;
		}
	}
	else//xảy ra va chạm
	{
		veclocity_x = veclocity_y = 0;
		vector2d *position = new vector2d(MovableObject.getX(), MovableObject.getY());
		if (coldiection == COLDIRECTION_TOP)
		{
			position->x = dynamicBox.getY() + dynamicBox.getHeight() + 2;
		}
		else if (coldiection == COLDIRECTION_BOTTOM)
		{
			position->y = dynamicBox.getY() - moveBox.getHeight() - 2;
		}
		else if (coldiection == COLDIRECTION_RIGHT)
		{
			position->x = dynamicBox.getX() + dynamicBox.getWidth() + 2;
		}
		else if (coldiection == COLDIRECTION_LEFT)
		{
			position->x = dynamicBox.getX() - moveBox.getWidth() - 2;
		}
		MovableObject.setX(position->x);
		MovableObject.setY(position->x);

		return coldiection;

	}
}

COLDIRECTION Collision::isCollision(CMovable *MoveObject, CBaseEntity* Object)
{

		CBox2D moveBox = MoveObject->getBounding();
		CBox2D dynamicBox = Object->getBounding();
		float normalx = 0.0f, normaly = 0.0f;
		veclocity_x = moveBox.getVelocityX();
		veclocity_y = moveBox.getVelocityY();

		//kiểm tra va chạm không cần biết vận tốc đối tượng
		COLDIRECTION coldiection = CheckAABB(moveBox, dynamicBox);
		if (coldiection == COLDIRECTION::COLDIRECTION_NONE)
		{
			//dừng box
			dynamicBox.setX(dynamicBox.getX() + dynamicBox.getVelocityX());
			dynamicBox.setY(dynamicBox.getY() + dynamicBox.getVelocityY());
			dynamicBox.setVelocityX(0.0f);
			dynamicBox.setVelocityY(0.0f);

			//vật nằm trong đối tượng
			if (CheckAABB(dynamicBox, GetSweptBroadPhaseBox(moveBox)) != COLDIRECTION::COLDIRECTION_NONE)
			{
				float timeCollision = SweptAABB(moveBox, dynamicBox, normalx, normaly);

				if (timeCollision > 0.0f && timeCollision <= 1.0f)
				{
					//update velocity
					if (abs(veclocity_x) >= abs(moveBox.getVelocityX() * timeCollision + normalx) && normalx != 0.0f)
						veclocity_x = moveBox.getVelocityX() * timeCollision + normalx;
					if (abs(veclocity_y) >= abs(moveBox.getVelocityY() *timeCollision + normaly) && normaly != 0.0f)
						veclocity_y = moveBox.getVelocityY() * timeCollision + normaly;

					if (normalx != 0.0f)
					{
						if (normalx == 1.0f)
						{
							return COLDIRECTION::COLDIRECTION_LEFT;

						}
						if (normalx == -1.0f)
						{
							return COLDIRECTION::COLDIRECTION_RIGHT;
						}
					}
					else
					{
						if (normaly == -1.0f)
						{
							return COLDIRECTION::COLDIRECTION_TOP;

						}
						if (normaly == 1.0f)
						{
							return COLDIRECTION::COLDIRECTION_BOTTOM;
						}
					}
				}
				else
				{
					return COLDIRECTION::COLDIRECTION_NONE;
				}
			}
			else
			{
				return COLDIRECTION::COLDIRECTION_NONE;
			}
		}
		else//xảy ra va chạm
		{
			veclocity_x = veclocity_y = 0;
			vector2d *position = new vector2d(moveBox.getX(), moveBox.getY());
			if (coldiection == COLDIRECTION_TOP)
			{
				position->x = dynamicBox.getY() + dynamicBox.getHeight() + 2;
			}
			else if (coldiection == COLDIRECTION_BOTTOM)
			{
				position->y = dynamicBox.getY() - moveBox.getHeight() - 2;
			}
			else if (coldiection == COLDIRECTION_RIGHT)
			{
				position->x = dynamicBox.getX() + dynamicBox.getWidth() + 2;
			}
			else if (coldiection == COLDIRECTION_LEFT)
			{
				position->x = dynamicBox.getX() - moveBox.getWidth() - 2;
			}
			MoveObject->getBounding().setX(position->x);
			MoveObject->getBounding().setX(position->y);

			return coldiection;

		}
}




