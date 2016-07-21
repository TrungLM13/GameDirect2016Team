#ifndef __CJUMP_H__
#define __CJUMP_H__

#include "State.h"
class CJump :
	public CState
{
public:
	CJump();
	~CJump();
};

class CPlayerJump :
	public CJump
{
public:
	CPlayerJump();
	~CPlayerJump();
};

#endif