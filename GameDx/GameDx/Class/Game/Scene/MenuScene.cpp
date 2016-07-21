//#include "MenuScene.h"
//#include "Framework\Camera.h"
//#include "Game\Utill\InformationResource.h"
//#include "Game\Scene\SelectStageScene.h"
//#include "Game\Scene\SceneManager.h"
//#include "Game\Utill\Config.h"
//
//class CSceneManager;
//
//CMenuScene::CMenuScene()
//{
//
//	this->initScene();
//}
//
//CMenuScene::~CMenuScene()
//{
//	SAFE_RELEASE(m_Background);
//}
//
//bool CMenuScene::initScene()
//{
//	m_Background		= new CSprite(CInfomationResource::backgroundMenu);
//	m_MegaMan			= new CSprite(CInfomationResource::megaManBackground,	1, 2, 2, 0);
//	m_RuleBackground	= new CSprite(CInfomationResource::rulerBackground,		1, 2, 2, 0);
//	m_enterTheGame		= false;
//
//
//	return true;
//}
//
//void CMenuScene::updateScene(double deltaTime)
//{
//	static double countTimeOfMenu = 0;
//	if (m_enterTheGame && deltaTime >= 0)
//		countTimeOfMenu += deltaTime;
//
//	if (countTimeOfMenu >= 1000 * 32 / 16)
//	{
//		countTimeOfMenu = 0;
//		CSceneManager::getInstance()->getScene().pop();
//		CSceneManager::getInstance()->getScene().push(new CSelectStageScene());
//	}
//
//}
//
//void CMenuScene::updateScene(CKeyBoard* Keyboard)
//{
//	if (Keyboard->KeyPress(DIK_RETURN))
//		m_enterTheGame = true;
//}
//
//
//void CMenuScene::renderScene()
//{
//		m_Background		->Render(						vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);
//		CText::getInstace()	->Draw(_T(START_GAME_STRING),	vector3d(BACKBUFFER_WIDTH / 2, 12 * BACKBUFFER_HEIGHT / 15, 0.5),			DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
//		CText::getInstace()	->Draw(_T(PRODUCTOR),			vector3d(BACKBUFFER_WIDTH / 2, 7 *	BACKBUFFER_HEIGHT / 8, 0.5),			DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
//		CText::getInstace()	->Draw(_T(TM),					vector3d(13 * BACKBUFFER_WIDTH / 16, 11 * BACKBUFFER_HEIGHT / 28, 0.5),		DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
//
//	if (m_enterTheGame == true)
//	{
//		m_MegaMan			->Render(0, 2, vector3d(BACKBUFFER_WIDTH / 2, 3 * BACKBUFFER_HEIGHT / 5, 0.5),		vector2d(2.0, 2.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true,  10);
//		m_RuleBackground	->Render(0, 2, vector3d(0, 4 * BACKBUFFER_HEIGHT / 7, 0.5),							vector2d(4.0, 1.0), 0.0f, DRAWCENTER_LEFT_TOP,		true,  10);
//		m_RuleBackground	->Render(0, 2, vector3d(BACKBUFFER_WIDTH, 4 * BACKBUFFER_HEIGHT / 7, 0.5),			vector2d(4.0, 1.0), 0.0f, DRAWCENTER_RIGHT_TOP,		true,  10);
//	}
//	else
//	{
//		m_MegaMan			->Render(0, 0, vector3d(BACKBUFFER_WIDTH / 2, 3 * BACKBUFFER_HEIGHT / 5, 0.5),		vector2d(2.0, 2.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, false,  3);
//		m_RuleBackground	->Render(0, 0, vector3d(0, 4 * BACKBUFFER_HEIGHT / 7, 0.5),							vector2d(4.0, 1.0), 0.0f, DRAWCENTER_LEFT_TOP,		false,  3);
//		m_RuleBackground	->Render(0, 0, vector3d(BACKBUFFER_WIDTH, 4 * BACKBUFFER_HEIGHT / 7, 0.5),			vector2d(4.0, 1.0), 0.0f, DRAWCENTER_RIGHT_TOP,		false,  3);
//	}
//
//}
//
//#include "Game\Scene\SceneManager.h"