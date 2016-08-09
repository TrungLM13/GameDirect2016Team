#ifndef __CCOININBOX_H__
#define __CCOININBOX_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Entity\Player\Player.h"

class CCoinInBox : public CMovable
{
public:
	CCoinInBox();
	~CCoinInBox();
	virtual	bool			loadSprite()											override;
	virtual	bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(RECT* camera)                              override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;
private:
	bool isDraw;
};
#endif