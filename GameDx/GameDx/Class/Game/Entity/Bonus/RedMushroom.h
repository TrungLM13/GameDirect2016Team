#ifndef __CMUSHROOM_H__
#define __CMUSHROOM_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Entity\Player\Player.h"

class CRedMushroom : public CMovable
{
public:
	CRedMushroom();
	~CRedMushroom();
	virtual bool			loadSprite()									override;
	virtual	bool			initEntity()									override;
	virtual void			updateEntity(float deltaTime)					override;
	virtual void			updateEntity(RECT* camera)                      override;
	virtual void			updateEntity(CKeyBoard *device)					override;
	virtual void			drawEntity()									override;
	virtual int				getTagNodeId()									override;
public:
	void setVelocity(vector2d velocity);

private:
};
#endif