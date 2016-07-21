#ifndef __CSTAND_H__
#define __CSTAND_H__


#include "State.h"
#include "Framework\Sprite.h"
#include "Game\Utill\stdafx.h"

class CStand :
	public CState
{
public:
	CStand();
	~CStand();
};


class CPlayerStand :
	public CStand
{
public:
	CPlayerStand();
	~CPlayerStand();

	virtual	const	char*	getTag()								override;
	virtual			void	setTag(char*)							override;
	virtual			void	switchState(CBaseEntity*)				override;
	virtual			void	update(vector2d &Position)				override;
/***********************UPDATE IF YOU NEED SOME ANOTHER FUCTION******************/
	virtual			void	render()								override;

	static			CPlayerStand*			getInstance();

private:
	static			CPlayerStand*			m_Instance;
					vector<CSprite*>		m_listSprite;
					int						m_stateStand;
};

#endif


