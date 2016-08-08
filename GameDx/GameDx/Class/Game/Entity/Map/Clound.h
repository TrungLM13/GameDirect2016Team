#ifndef __CLOUND_H__
#define __CLOUND_H__

#include "Class\Game\Entity\StaticEntity.h"
class CClound :
	public CStaticEntity
{
public:
	CClound();
	CClound(vector2d newPos, int type);
	virtual ~CClound();

	virtual bool initEntity()						= 0;
	virtual void updateEntity(float deltaTime);
	virtual void updateEntity(CKeyBoard* device);
	virtual void updateEntity(RECT* rectCamera);
	virtual void drawEntity()						= 0;
	virtual bool loadSprite()						= 0;

private:
	int			m_TypeClound;

};

#endif