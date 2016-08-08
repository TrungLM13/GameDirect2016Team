#ifndef __CCARNIVOROUS_PLANTS_H__
#define __CCARNIVOROUS_PLANTS_H__

#include "Class\Game\Entity\MovableEntity.h"

class CCarnivorousPlants : public CMovable
{
public:
	CCarnivorousPlants();
	~CCarnivorousPlants();

	virtual bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(RECT* camera)								override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;
	virtual bool			loadSprite()											override;

private:
	int m_Direction;
	int m_mapId;
};

#endif
