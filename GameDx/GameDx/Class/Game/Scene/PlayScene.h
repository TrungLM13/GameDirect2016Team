#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "BaseScene.h"
#include "Class\Game\Test\Test.h"

class CPlayScene :
	public CBaseScene
{
public:
	CPlayScene();
	~CPlayScene();

	virtual bool initScene()						override;
	virtual void updateScene(CKeyBoard*)			override;
	virtual void updateScene(double deltaTime)		override;
	virtual void renderScene()						override;

private:
};

#endif
