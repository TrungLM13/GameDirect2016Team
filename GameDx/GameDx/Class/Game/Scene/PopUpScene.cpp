//#include "PopUpScene.h"
//#include "Game\Scene\GameOverScene.h"
//
//CPopUpScene::CPopUpScene()
//{
//	this->initScene();
//}
//
//
//CPopUpScene::~CPopUpScene()
//{
//}
//
//bool CPopUpScene::initScene()
//{
//	m_PpopUp	= new CSprite(CInfomationResource::popUp);
//	m_LifeItem	= new CSprite(CInfomationResource::itemLife);
//	return true;
//}
//
//void CPopUpScene::updateScene(CKeyBoard* keyboard)
//{
//	if (keyboard->KeyPress(DIK_RETURN))
//	{
//		CSceneManager::getInstance()->getScene().pop();
//		CSceneManager::getInstance()->getScene().push(new CGameOverScene());
//	}
//
//}
//void CPopUpScene::updateScene(double deltaTime)
//{
//
//}
//void CPopUpScene::renderScene()
//{
//	m_PpopUp			->Render(		vector3d(		BACKBUFFER_WIDTH / 2,		BACKBUFFER_HEIGHT / 5, 0.5f),			vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP);
//	m_LifeItem			->Render(		vector3d(13 *	BACKBUFFER_WIDTH / 20,	9 * BACKBUFFER_HEIGHT / 12, 0.5f),			vector2d(2.0f, 2.0f), 0.0f, DRAWCENTER_LEFT_TOP);
//	CText::getInstace()	->Draw	(L"=",	vector3d(14.5*	BACKBUFFER_WIDTH / 20, 9.2* BACKBUFFER_HEIGHT / 12, 0.5f), DEFAULT_FONT_COLOR, 16, DT_BOTTOM, DEFAULT_FONTNAME);
//}