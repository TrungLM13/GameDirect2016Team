#ifndef __CSHOOT_H__
#define __CSHOOT_H__


#include "State.h"

class CShoot : public CState
{
public:
	CShoot();
	CShoot(directDevice);
	~CShoot();

};


class CPlayerShoot :
	public CShoot
{
public:
	CPlayerShoot();
	CPlayerShoot(directDevice);
	~CPlayerShoot();
};

#endif