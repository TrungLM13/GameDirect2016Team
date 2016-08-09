#ifndef __CITEMINBOX_H__
#define __CITEMINBOX_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Entity\Player\Player.h"

class CIteminbox : public CMovable
{
public:
	CIteminbox();
	~CIteminbox();
	virtual bool			loadSprite()									override;
	virtual	bool			initEntity()									override;
	virtual void			updateEntity(float deltaTime)					override;
	virtual void			updateEntity(RECT* camera)                      override;
	virtual void			updateEntity(CKeyBoard *device)					override;
	virtual void			drawEntity()									override;

public:
	void chkShowItem(CPlayer*);
	void setVelocity(vector2d velocity);
	void setPosition(vector3d position);
	ITEMINBOX_TYPE getitemtype();

private:
	ITEMINBOX_TYPE        m_itemtype;
};
#endif