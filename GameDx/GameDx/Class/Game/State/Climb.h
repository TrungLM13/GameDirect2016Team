#ifndef __CCLIMB_H__
#define __CCLIMB_H__

#include "State.h"


class CClimb :
	public CState
{
public:
	CClimb();
	~CClimb();
};

class CPlayerClimb :
	public CClimb
{
public:
	CPlayerClimb();
	~CPlayerClimb();
};

#endif