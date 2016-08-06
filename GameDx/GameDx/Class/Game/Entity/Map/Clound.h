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

	virtual bool initEntity()						override;
	virtual void updateEntity(float deltaTime);
	virtual void updateEntity(CKeyBoard* device);
	virtual void updateEntity(RECT* rectCamera);
	virtual void drawEntity()						override;
	virtual bool loadSprite()						override;

private:
	int			m_TypeClound;

};

#endif