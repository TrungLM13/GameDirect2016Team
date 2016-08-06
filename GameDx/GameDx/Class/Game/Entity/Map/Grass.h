#ifndef __GRASS_H__
#define __GRASS_H__
#include "Class\Game\Entity\StaticEntity.h"
class CGrass :
	public CStaticEntity
{
public:
	CGrass();
	CGrass(vector2d position, int type);
	virtual ~CGrass();

	virtual bool initEntity()						override;
	virtual void updateEntity(float deltaTime)		;
	virtual void updateEntity(CKeyBoard* device)	;
	virtual void updateEntity(RECT* rectCamera)		;
	virtual void drawEntity()						override;
	virtual bool loadSprite()						override;

private:
	int		m_TypeGrass;
};

#endif