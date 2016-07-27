#include "Class\Game\Game\Game.h"
#include "Class\Framework\Sprite.h"


CGame::CGame(HINSTANCE hInstance)
{
	m_Windows	= new CWindows(hInstance);
	m_Windows->initWindowGame();

	CSprite::initSpriteHandler(m_Windows->getSpriteHandler());
	CText::InitDevice(m_Windows->getDevice(), m_Windows->getSpriteHandler());
	
	m_Keyboard	= new CKeyBoard(hInstance, m_Windows->getWindowHandler());
	CAudio::getInstance()->Init_DirectSound(m_Windows->getWindowHandler());

	CSceneManager::initDevice(m_Windows->getDevice());

	this->initGame();
}

CGame::~CGame()
{
	SAFE_RELEASE(m_Windows);
	SAFE_RELEASE(m_Keyboard);
	SAFE_RELEASE(m_Test);
}


void CGame::initGame()
{
	m_Test			= new Test(m_Windows->getDevice());
}
void CGame::updateGame(double deltaTime)
{
	m_Keyboard->Update();
	m_Test->Update(m_Keyboard);
	CCamera::getInstance()->Update(m_Test->getPosision());

	if (m_Keyboard->KeyDown(DIK_ESCAPE))
		PostQuitMessage(0);

	CSceneManager::getInstance()->getScene().top()->updateScene(m_Keyboard);
	CSceneManager::getInstance()->getScene().top()->updateScene(deltaTime);

}
void CGame::renderGame()
{
	if (this->m_Windows->startDraw()) {
		CSceneManager::getInstance()->getScene().top()->renderScene();
		m_Test->Render();
	}
	this->m_Windows->stopDraw();
}