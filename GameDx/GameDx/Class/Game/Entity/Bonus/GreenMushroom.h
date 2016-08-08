#ifndef __CGREENMUSHROOM_H__
#define __CGREENMUSHROOM_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Entity\Player\Player.h"

class CGreenMushroom : public CMovable
{
public:
	CGreenMushroom();
	~CGreenMushroom();
	virtual bool			loadSprite()									override;
	virtual	bool			initEntity()									override;
	virtual void			updateEntity(float deltaTime)					override;
	virtual void			updateEntity(RECT* camera)                      override;
	virtual void			updateEntity(CKeyBoard *device)					override;
	virtual void			drawEntity()									override;
public:
	void setVelocity(vector2d velocity);


private:
};
#endif