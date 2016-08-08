#ifndef __TILE_H__
#define __TILE_H__

#include "Class\Game\Entity\BaseEntity.h"
#include "Class\Game\Entity\StaticEntity.h"
#include "Class\Framework\Camera.h"

class CTile : public CStaticEntity
{
public:
	CTile();
	CTile(vector3d, int);
	~CTile();

public:
	virtual bool initEntity()						override;
	virtual void updateEntity(float deltaTime)		override;
	virtual void updateCollision(CBaseEntity*,float deltaTime)		override;
	virtual void updateEntity(CKeyBoard* device)	override;
	virtual void updateEntity(RECT* rectCamera)		override;
	virtual void drawEntity()						override;
	virtual bool loadSprite()						override;

	int				m_Index;
	vector3d		m_Pos;
	bool			isDraw;
};

#endif