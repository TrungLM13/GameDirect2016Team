#include "IntroMap.h"
#include <ctime>
#include <stack>
#include "Class\Game\Scene\SelectStageScene.h"
#include "Class\Game\Scene\PopupInfo.h"



CIntroMap::CIntroMap()
{
	this->initScene();
}


CIntroMap::~CIntroMap()
{

}

bool CIntroMap::initScene()
{
	m_timeWaiting	= 0;

	m_backgroud		= new CSprite(CInfomationResource::backgroundIntroStage);
	m_marioIcon		= new CSprite(CInfomationResource::marioIcon, 1, 3, 1, 0);


	return true;
}

void CIntroMap::updateScene(double deltaTime)
{
	if (m_timeWaiting > 2000)
	{
		m_timeWaiting += deltaTime;
		return;
	}
	m_timeWaiting = 0;

	CSceneManager::getInstance()->getScene().pop();
	CSceneManager::getInstance()->getScene().push(new CIntroMap());
}

void CIntroMap::updateScene(CKeyBoard* keybard)
{
	
}

void CIntroMap::setMapLevel()
{
	if (true);
}

void CIntroMap::renderScene()
{
	m_backgroud->Render(vector3d(0.0, 0.0f, 0.5f), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP);
	m_marioIcon->Render(vector3d(85, 100, 0), vector2d(1.0f, 1.0f), 0, DRAWCENTER_LEFT_TOP, true);

	wchar_t temp [100];
	_itow(CPopUpInfo::getInstance()->getPoint(), temp, 10);
	CText::getInstace()->Draw(temp, vector3d(50, 24, 0), DEFAULT_FONT_COLOR, 8, DT_CENTER, DEFAULT_FONTNAME);

	ZeroMemory(temp, 100);
	_itow(CPopUpInfo::getInstance()->getCoin(), temp, 10);
	CText::getInstace()->Draw(temp, vector3d(110, 24, 0), DEFAULT_FONT_COLOR, 8, DT_CENTER, DEFAULT_FONTNAME);

	int wchars_num = MultiByteToWideChar(CP_UTF8, 0, CPopUpInfo::getInstance()->getMapName().c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[wchars_num];
	MultiByteToWideChar(CP_UTF8, 0, CPopUpInfo::getInstance()->getMapName().c_str(), -1, wstr, wchars_num);
	
	CText::getInstace()->Draw(wstr, vector3d(160, 24, 0), DEFAULT_FONT_COLOR, 8, DT_CENTER, DEFAULT_FONTNAME);

	ZeroMemory(temp, 100);
	_itow(CPopUpInfo::getInstance()->getTimer(), temp, 10);
	CText::getInstace()->Draw(temp, vector3d(220, 24, 0), DEFAULT_FONT_COLOR, 8, DT_CENTER, DEFAULT_FONTNAME);

	delete[] wstr;
}