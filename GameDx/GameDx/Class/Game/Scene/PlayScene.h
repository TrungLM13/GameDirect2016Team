#ifndef __PLAYSCENE_H__
#define __PLAYSCENE_H__

#include "BaseScene.h"
#include "Class\Game\Test\Test.h"
#include "Class\Game\Entity\Player\Player.h"
#include "Class\Game\Entity\Bonus\Coin.h"
#include "Class\Game\Entity\Bonus\Star.h"
#include "Class\Game\Entity\Bonus\Brick.h"
#include "Class\Game\Entity\Bonus\GiftBox.h"
#include "Class\Game\Entity\Enemy\Mushroom.h"
#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Game\Entity\Bonus\Iteminbox.h"
#include "Class\Game\Entity\Bonus\CoinInBox.h"
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
	vector<CCoin*>			listCoin;
	vector<CStar*>			listStar;
	vector<CBrick*>			listBrick;
	vector<CIteminbox*>		listIteminbox;
	vector<CGiftBox*>		listGiftBox;
	vector<CMushroom*>		listMushroom;
	vector<CMovable *>		listMovable;
	vector<CCoinInBox*>		listCoinInBox;
};

#endif
