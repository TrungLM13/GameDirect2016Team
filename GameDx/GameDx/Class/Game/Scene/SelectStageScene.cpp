#include "SelectStageScene.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Framework\Text.h"
#include "Class\Game\Scene\SceneManager.h"
#include "Class\Game\Scene\IntroStageScene.h"

bool m_Particle = false;
int CSelectStageScene::m_IndexSelect = STAGESELECTED::CUTMAN;

CSelectStageScene::CSelectStageScene()
{
	this->initScene();
}

CSelectStageScene::~CSelectStageScene()
{
	SAFE_RELEASE(m_Background);
	SAFE_RELEASE(m_ButtonMenuSelectStage);
}


bool CSelectStageScene::initScene()
{
	m_Background				= new CSprite(CInfomationResource::backgroundSeletStage,	1, 1, 1, 0);
	m_ButtonMenuSelectStage		= new CSprite(CInfomationResource::buttonMenuState,			1, 2, 2, 0);
	m_enterTheGame				= false;
	m_Particle					= false;

	return true;
}

void CSelectStageScene::updateScene(double deltaTime)
{
	switch (m_IndexSelect)
	{
	case STAGESELECTED::CUTMAN:
		m_PositionButton = vector3d(49 * BACKBUFFER_WIDTH / 170, 11 * BACKBUFFER_HEIGHT / 97, 0.5f);
		break;
	case STAGESELECTED::GUTSMAN:
		m_PositionButton = vector3d(91 * BACKBUFFER_WIDTH / 170, 11 * BACKBUFFER_HEIGHT / 97, 0.5f);
		break;
	case STAGESELECTED::ICEMAN:
		m_PositionButton = vector3d(113 * BACKBUFFER_WIDTH / 170, 38 * BACKBUFFER_HEIGHT / 97, 0.5f);
		break;
	case STAGESELECTED::BOMBMAN:
		m_PositionButton = vector3d(91 * BACKBUFFER_WIDTH / 170, 65 * BACKBUFFER_HEIGHT / 97, 0.5f);
		break;
	case STAGESELECTED::FIREMAN:
		m_PositionButton = vector3d(49 * BACKBUFFER_WIDTH / 170, 65 * BACKBUFFER_HEIGHT / 97, 0.5f);
		break;
	case STAGESELECTED::ELECMAN:
		m_PositionButton = vector3d(28 * BACKBUFFER_WIDTH / 170, 38 * BACKBUFFER_HEIGHT / 97, 0.5f);
		break;
	default:
		break;
	}

	if (m_enterTheGame)
	{
		CSceneManager::getInstance()->getScene().pop();
		//CSceneManager::getInstance()->getScene().push(new CIntroStageScene());
	}
}

void CSelectStageScene::updateScene(CKeyBoard* device)
{
	if (device->KeyPress(DIK_LEFT))
		m_IndexSelect--;
	if (device->KeyPress(DIK_RIGHT))
		m_IndexSelect++;
	if (device->KeyPress(DIK_RETURN))
		if((m_IndexSelect == STAGESELECTED::CUTMAN) || (m_IndexSelect == STAGESELECTED::BOMBMAN)|| (m_IndexSelect == STAGESELECTED::FIREMAN))
			m_enterTheGame = true;

	static double countTimeOfStageSceneSelected = 0;
	if (CTimer::getInstance()->getElapedTime() >= 0)
		countTimeOfStageSceneSelected += CTimer::getInstance()->getElapedTime();
	if (countTimeOfStageSceneSelected >= 100)
	{
		countTimeOfStageSceneSelected = 0;
		m_Particle = true;
	}
	else
		m_Particle = false;

	if (m_IndexSelect < 0)	m_IndexSelect	=	5;
	if (m_IndexSelect > 5)	m_IndexSelect	=	0;

}

void CSelectStageScene::renderScene()
{
	static clock_t tiner = 0;
	if (CTimer::getInstance()->getElapedTime() > 0)
		tiner += CTimer::getInstance()->getElapedTime();

	OutputDebugString(L"StageSelect: ");
	OutputDebugString(_itow(tiner, new WCHAR[1], 10));
	OutputDebugString(L"\n");
	tiner = 00;

	m_Background			->Render((vector3d(0.0, 0.0f, 0.5f)),	vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP,	true, FPS);
	m_ButtonMenuSelectStage	->Render (m_PositionButton,				vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP,	true, 10);

	CText::getInstace()->Draw(_T(SELECT_STAGE_STRING),		vector3d(		BACKBUFFER_WIDTH / 2, 3 * BACKBUFFER_HEIGHT / 7, 0.5),		DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(PRESS_START_GAME_STRING),	vector3d(		BACKBUFFER_WIDTH / 2, 7.2 * BACKBUFFER_HEIGHT / 14, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(SELECT_CUTMAN_STRING),		vector3d(64 *	BACKBUFFER_WIDTH / 170, 32 * BACKBUFFER_HEIGHT / 97, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(SELECT_GUTMAN_STRING),		vector3d(108 *	BACKBUFFER_WIDTH / 170, 32 * BACKBUFFER_HEIGHT / 97, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(SELECT_ICEMAN_STRING),		vector3d(130 *	BACKBUFFER_WIDTH / 170, 59 * BACKBUFFER_HEIGHT / 97, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(SELECT_BOMBMAN_STRING),	vector3d(108 *	BACKBUFFER_WIDTH / 170, 86 * BACKBUFFER_HEIGHT / 97, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(SELECT_FIREMAN_STRING),	vector3d(64 *	BACKBUFFER_WIDTH / 170, 86 * BACKBUFFER_HEIGHT / 97, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);
	CText::getInstace()->Draw(_T(SELECT_ELECMAN),			vector3d(42 *	BACKBUFFER_WIDTH / 170, 59 * BACKBUFFER_HEIGHT / 97, 0.5),	DAFAULT_TEXT_COLOR_STAGE, 16, DT_CENTER, DEFAULT_FONTNAME);


	if (m_Particle)
	{
		CText::getInstace()->Draw(_T(SELECT_STAGE_STRING),			vector3d(BACKBUFFER_WIDTH / 2, 3 * BACKBUFFER_HEIGHT / 7, 0.5),				DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
		CText::getInstace()->Draw(_T(PRESS_START_GAME_STRING),		vector3d(BACKBUFFER_WIDTH / 2, 7.2 * BACKBUFFER_HEIGHT / 14, 0.5),			DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
		switch (m_IndexSelect)
		{
		case STAGESELECTED::CUTMAN:
			CText::getInstace()->Draw(_T(SELECT_CUTMAN_STRING),		vector3d(64 *	BACKBUFFER_WIDTH / 170, 32 * BACKBUFFER_HEIGHT / 97, 0.5f),	DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
			break;
		case STAGESELECTED::GUTSMAN:
			CText::getInstace()->Draw(_T(SELECT_GUTMAN_STRING),		vector3d(108 *	BACKBUFFER_WIDTH / 170, 32 * BACKBUFFER_HEIGHT / 97, 0.5f),	DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
			break;
		case STAGESELECTED::ICEMAN:
			CText::getInstace()->Draw(_T(SELECT_ICEMAN_STRING),		vector3d(130 *	BACKBUFFER_WIDTH / 170, 59 * BACKBUFFER_HEIGHT / 97, 0.5f),	DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
			break;
		case STAGESELECTED::BOMBMAN:
			CText::getInstace()->Draw(_T(SELECT_BOMBMAN_STRING),	vector3d(108 *	BACKBUFFER_WIDTH / 170, 86 * BACKBUFFER_HEIGHT / 97, 0.5f),	DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
			break;
		case STAGESELECTED::FIREMAN:
			CText::getInstace()->Draw(_T(SELECT_FIREMAN_STRING),	vector3d(64 *	BACKBUFFER_WIDTH / 170, 86 * BACKBUFFER_HEIGHT / 97, 0.5f),	DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
			break;
		case STAGESELECTED::ELECMAN:
			CText::getInstace()->Draw(_T(SELECT_ELECMAN),			vector3d(42 *	BACKBUFFER_WIDTH / 170, 59 * BACKBUFFER_HEIGHT / 97, 0.5f),	DEFAULT_FONT_COLOR, 16, DT_CENTER, DEFAULT_FONTNAME);
			break;
		default:
			break;
		}
	}

}