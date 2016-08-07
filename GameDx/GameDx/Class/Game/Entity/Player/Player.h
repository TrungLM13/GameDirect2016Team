#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"
#include "Class\Game\State\BaseState.h"
#include "Class\Game\Algorithsm\Singleton.h"
#include "Class\Game\Utill\ShowBouding.h"

class CBaseState;

#ifndef __CPLAYER_H__
#define __CPLAYER_H__

class CBaseState;

class CPlayer : public CMovable, public CSingleton<CPlayer>
{
public:
	CPlayer();
	CPlayer(directDevice);
	~CPlayer();

	virtual bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(RECT* camera)								override;
	virtual void			updateEntity(CKeyBoard *device)							override;
			void			handleCollision(CBaseEntity* entity,float deltaTime);
	virtual void			drawEntity()											override;
	virtual	vector3d		getPosition()											override;
	virtual bool			loadSprite()											override;
	virtual int				getTagNodeId()											override;

public:
	void					setPosition(vector3d position);
	void					setState(PLAYERSTATES state);
	void					setVelocity(vector2d velocity);
	void					setState(CBaseState* state);
	CBaseState*				getState();
	int						getStateInt();
	void					setPlayerTag(int playerTag);
	int						getPlayerTag();

	bool					m_IsCollision;
	bool					m_IsAutoMove; // Signal for Flag auto run
	vector<int>				m_Direction;

protected:
	vector2d				m_Acceleration;
	int						m_PlayerTag;
	CBaseState*				m_PlayerState;
	int						m_UndyingTime;
private:
};
#endif


