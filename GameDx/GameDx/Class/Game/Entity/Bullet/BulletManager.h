#ifndef __BULLETMANAGER_H__
#define __BULLETMANAGER_H__

#include "Game\Algorithsm\Singleton.h"
#include "Game\Entity\MovableEntity.h"
#include "Game\Entity\StaticEntity.h"
#include "Game\Entity\Bullet\BulletNormal.h"

class CBulletManager : public CSingleton<CBulletManager>
{
public:
	CBulletManager();
	~CBulletManager();

	void			updateBullet(float			deltaTime);
	void			updateBullet(CStaticEntity*	staticEntity);
	void			updateBullet(CMovable*		player);

	void			getBullet	(int			styleBullet);
	void			createBullet(int			styleBullet);


private:
	vector<CBulletNormal*>						m_listBullet;

};

#endif