#ifndef __CDIE_H__
#define __CDIE_H__

#include "State.h"

class CDie :
	public CState
{
public:
	CDie();
	~CDie();
};

class CPlayerDie :
	public CDie
{
public:
	CPlayerDie();
	~CPlayerDie();
};

#endif

