/****************************************************************************/
/* Create by Michael Le AND Shin Truong*/
/* 08/07/2015 */
/***************************************************************************/

#ifndef CSTATICENTITY_H
#define CSTATICENTITY_H

#include "BaseEntity.h"
#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Mathematics\Box2D.h"
#include "Class\Framework\Sprite.h"

class CStaticEntity : public CBaseEntity
{
public:
	CStaticEntity();
	virtual ~CStaticEntity();

	virtual  bool						loadSprite() = 0;
	virtual  CBox2D						getBounding()															 override;
	virtual  bool						initEntity();
	virtual  const char*				getTagNode()															 override;
	virtual  int						getTagNodeId()															 override { return 0; };
	virtual  vector3d					getPosition()															 override;
	virtual  vector2d					getVelocity();
	void								handleCollision(CBaseEntity*entity, float deltaTime) {};

protected:
	vector3d    m_Position;
	//CBox2D*     m_Bounding;
	vector<CSprite*>  m_listSprite;
};

#endif