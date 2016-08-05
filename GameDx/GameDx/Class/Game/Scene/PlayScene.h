#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "BaseScene.h"
#include "Class\Game\Test\Test.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\Bonus\Coin.h"
#include "Class\Game\Entity\Bonus\Star.h"
#include "Class\Game\Entity\Bonus\Brick.h"
#include "Class\Game\Entity\Bonus\RedMushroom.h"
#include "Class\Game\Entity\Bonus\GiftBox.h"
#include "Class\Game\Entity\Enemy\Mushroom.h"
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
	vector<CCoin*>			listCoin;
	vector<CStar*>			listStar;
	vector<CBrick*>			listBrick;
	vector<CRedMushroom*>	listRedMushroom;
	vector<CGiftBox*>		listGiftBox;
	vector<CMushroom*>		listMushroom;
};

#endif
