#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "BaseScene.h"
#include "Class\Game\Algorithsm\QuadTree.h"


class CPlayScene :
	public CBaseScene
{
public:
	CPlayScene();
	~CPlayScene();

	virtual bool initScene()						override;
	virtual void updateScene(double deltaTime)		override;
	virtual void updateScene(CKeyBoard* keyboard)	override;
	virtual void renderScene()						override;

private:
	CQuadTree*				m_treeGame;
	vector<CObjectss*>		m_listObjectInViewport;
};

#endif
