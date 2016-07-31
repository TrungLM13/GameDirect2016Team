#ifndef __CBRICK_H__
#define __CBRICK_H__
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\MovableEntity.h"

class CBrick : public CMovable
{
public:
	CBrick();
	~CBrick();
	virtual	bool			loadSprite()											override;
	virtual	bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(RECT* camera)                              override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;

public:
	void setPosition(vector3d position);
	void setVelocity(vector2d velocity);
private:
};
#endif