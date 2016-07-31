#ifndef __CGIFTBOX_H__
#define __CGIFTBOX_H__
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\MovableEntity.h"

class CGiftBox : public CMovable
{
public:
	CGiftBox();
	~CGiftBox();
	virtual	bool					loadSprite()			override;
	virtual	bool					initEntity()			override;
	virtual void			updateEntity(float deltaTime)					override;
	virtual void			updateEntity(RECT* camera)                              override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;
private:
};
#endif