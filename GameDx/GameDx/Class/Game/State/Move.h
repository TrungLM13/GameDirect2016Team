#ifndef __CMOVE_H__
#define __CMOVE_H__

#include "State.h"

class CMove :
	public CState
{
public:
	CMove();
	~CMove();
};


class CPlayerMove :
	public CMove
{
public:
	CPlayerMove();
	~CPlayerMove();
};

#endif