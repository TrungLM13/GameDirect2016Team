#ifndef __CBRICK_H__
#define __CBRICK_H__
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Entity\Bonus\CoinInBox.h"
#include "Class\Game\Entity\Bonus\Star.h"

class CBrick : public CMovable
{
public:
	CBrick();
	CBrick(vector2d position, BRICK_TYPE type);
	~CBrick();
	virtual	bool			loadSprite()											override;
	virtual	bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(RECT* camera)                              override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;
	virtual void			updateCollision(CBaseEntity*, float deltaTime)			override;
	virtual int				getTagNodeId()											override;

public:

	void setPosition(vector3d position);
	void setVelocity(vector2d velocity);
	void setGiftBox(bool check);
public:
	BRICK_TYPE m_BrickType;
	BRICK_EVENT m_BrickEvent;
	BRICK_STATE m_BrickState;
	CStar* m_Star;
};
#endif