#ifndef __CHIT_H__
#define __CHIT_H__

#include "State.h"
class CHit :
	public CState
{
public:
	CHit();
	~CHit();
};


class CPlayerHit :
	public CHit
{
public:
	CPlayerHit();
	~CPlayerHit();
};

#endif