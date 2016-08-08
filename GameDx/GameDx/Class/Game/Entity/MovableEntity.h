/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CMOVABLE__H__
#define __CMOVABLE__H__

#include "BaseEntity.h"
#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Mathematics\Box2D.h"


class CMovable : public CBaseEntity
{
public:
	CMovable();
	~CMovable();
	virtual		bool					loadSprite()										=	0;
	virtual		vector3d				getPosition()												;
	virtual		CBox2D					getBounding()										override;
	virtual		bool					initEntity()										override;
	virtual		const char*				getTagNode()										override;
	virtual		vector2d				getVelocity()												;
	virtual		void					updateCollision(CBaseEntity*, float deltaTime)		override;
	virtual     void					setVelocity(vector2d);

protected:
				vector2d				m_Velocity;
};

#endif