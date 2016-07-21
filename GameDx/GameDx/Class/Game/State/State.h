/************************************************/
/* CREATE BY MICHAEL LE AND SHN TRUONG*/
/* 14/07/2015*/
/**********************************************/

#ifndef __CSTATE_H__
#define __CSTATE_H__

#include "Game\Utill\stdafx.h"
#include "Game\Utill\Config.h"

class CBaseEntity;

class CState
{
public:
	CState();
	CState(directDevice);
	~CState();
	virtual	const	char*	getTag()								= 0;
	virtual			void	setTag(char*)							= 0;
	virtual			void	switchState(CBaseEntity*)				= 0;
	virtual			void	update(vector2d &Position)				= 0;
	/***********************UPDATE IF YOU NEED SOME ANOTHER FUCTION****************/
	virtual			void	render()								= 0;

protected:
	char*				m_Tag;
};

#include "Game\Entity\BaseEntity.h"

#endif