//#include "GameOverScene.h"
//
//
//CGameOverScene::CGameOverScene()
//{
//	this->initScene();
//}
//
//
//CGameOverScene::~CGameOverScene()
//{
//}
//
//bool CGameOverScene::initScene()
//{
//	m_Background = new CSprite(CInfomationResource::backgroundIntroStage);
//
//	return true;
//
//}
//
//void CGameOverScene::updateScene(double deltaTime)
//{
//
//}
//
//void CGameOverScene::updateScene(CKeyBoard*)
//{
//
//}
//
//void CGameOverScene::renderScene()
//{
//	m_Background->Render(vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);
//	CText::getInstace()->Draw(_T(GAME_OVER_STRING), vector3d(BACKBUFFER_WIDTH / 2, BACKBUFFER_HEIGHT / 3, 0.5), DEFAULT_FONT_COLOR, 20, DT_CENTER, DEFAULT_FONTNAME);
//
//	//CText::getInstace()->Draw(_T(GAME_OVER_STRING), vector3d(BACKBUFFER_WIDTH / 2, BACKBUFFER_HEIGHT / 3, 0.5), DEFAULT_FONT_COLOR, 15, DT_CENTER, DEFAULT_FONTNAME);
//	//CText::getInstace()->Draw(_T(CONTINUE_STRING), vector3d(BACKBUFFER_WIDTH / 2, 3 * BACKBUFFER_HEIGHT / 5, 0.5f), DEFAULT_FONT_COLOR, 15, DT_CENTER, DEFAULT_FONTNAME);
//	//CText::getInstace()->Draw(_T(SELECT_STAGE_STRING_GV),	vector3d(BACKBUFFER_WIDTH / 2, 4 *	BACKBUFFER_HEIGHT / 5, 0.5f), DEFAULT_FONT_COLOR, 15, DT_CENTER, DEFAULT_FONTNAME);
//}
