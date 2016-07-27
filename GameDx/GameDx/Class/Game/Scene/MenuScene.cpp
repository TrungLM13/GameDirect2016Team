#include "MenuScene.h"
#include "Class\Framework\Camera.h"
#include "Class\Game\Utill\InformationResource.h"
#include "Class\Game\Scene\IntroMap.h"
#include "Class\Game\Scene\SceneManager.h"
#include "Class\Game\Utill\Config.h"

class CSceneManager;

CMenuScene::CMenuScene()
{

	this->initScene();
}

CMenuScene::~CMenuScene()
{
	SAFE_RELEASE(m_Background);
}

bool CMenuScene::initScene()
{
	m_Background		= new CSprite(CInfomationResource::backgroundMenu);
	m_selectArrow		= new CSprite(CInfomationResource::selectArrow, 1, 2);
	m_enterTheGame		= false;

	return true;
}

void CMenuScene::updateScene(double deltaTime)
{
	if (m_enterTheGame)
	{
		CSceneManager::getInstance()->getScene().pop();
		CSceneManager::getInstance()->getScene().push(new CIntroMap());
	}
}

void CMenuScene::updateScene(CKeyBoard* Keyboard)
{
	if (Keyboard->KeyPress(DIK_RETURN))
		m_enterTheGame = true;
}


void CMenuScene::renderScene()
{
		m_Background		->Render(						vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);
		m_selectArrow->Render(vector3d(70, 137, 0), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP, true, 5);

		//CText::getInstace()	->Draw(_T(START_GAME_STRING),	vector3d(BACKBUFFER_WIDTH / 2, 12 * BACKBUFFER_HEIGHT / 15, 0.5),			DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
		//CText::getInstace()	->Draw(_T(PRODUCTOR),			vector3d(BACKBUFFER_WIDTH / 2, 7 *	BACKBUFFER_HEIGHT / 8, 0.5),			DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
		//CText::getInstace()	->Draw(_T(TM),					vector3d(13 * BACKBUFFER_WIDTH / 16, 11 * BACKBUFFER_HEIGHT / 28, 0.5),		DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
}

#include "Class\Game\Scene\SceneManager.h"