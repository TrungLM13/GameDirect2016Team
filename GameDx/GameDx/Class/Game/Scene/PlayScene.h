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


#include "Class\Game\Entity\Tile\Flag.h"

#include "Class\Game\Entity\Map\Tile.h"
#include "Class\Game\Entity\Tile\FlagPole.h"
#include "Class\Game\Entity\Tile\FlagPoleHead.h"
#include "Class\Game\Entity\Tile\FlagPoleTail.h"
#include "Class\Game\Entity\Tile\Castle.h"
#include "Class\Game\Entity\Tile\FlagCastle.h"

#include "Class\Game\Entity\Enemy\CarnivorousPlants.h"

#include "Class\Game\Entity\Enemy\Turtle.h"
#include "Class\Game\Entity\Tile\Elevator.h"

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
	vector<CBaseEntity*>	m_ListEntity;
};

#endif
