/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef __CSTATICENTITY_H__
#define __CSTATICENTITY_H__

#include "BaseEntity.h"
#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Mathematics\Box2D.h"
#include "Class\Framework\Sprite.h"

class CStaticEntity : public CBaseEntity
{
public:
	CStaticEntity();
	~CStaticEntity();

	virtual		bool					loadSprite()			= 0;
	virtual		CBox2D					getBounding()			override;
	virtual		bool					initEntity()			override;
	virtual		const char*				getTagNode()			override;
				vector2d				getPosition();
	virtual		vector2d				getVelocity();

protected:
				vector3d				m_Position;
				CBox2D*					m_Bounding;
				vector<CSprite*>		m_listSprite;
};

#endif
