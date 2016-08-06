#ifndef __MUSHROOM_H__
#define __MUSHROOM_H__
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Utill\InformationResource.h"

class CMushroom :
	public CMovable
{
public:
	CMushroom();
	virtual ~CMushroom();

public:
	bool initEntity();
	void updateEntity(float deltaTime);
	void updateEntity(CKeyBoard *device);
	void updateEntity(RECT* rectCamera);
	void drawEntity();
	int getTagNodeId();

	bool loadSprite();

private:
};
#endif

