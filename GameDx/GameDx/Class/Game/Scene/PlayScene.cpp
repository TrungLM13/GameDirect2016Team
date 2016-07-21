//#include "PlayScene.h"
//
//
//CPlayScene::CPlayScene()
//{
//	this->initScene();
//}
//
//
//CPlayScene::~CPlayScene()
//{
//}
//
//bool	CPlayScene::initScene()
//{
//<<<<<<< Updated upstream
//	//m_Player->initEntity();
//
//	m_Player = new CPlayer();
//	m_EnemyTankRed = new CEnemyTankRed();
//
//	//m_EnemyBall = new CEnemyBall();
//
//=======
//	map->initEntity();	
//>>>>>>> Stashed changes
//	return true;
//}
//
//void	CPlayScene::updateScene(double deltaTime)
//{
//
//	CCamera::getInstance()->Update(m_Player->getPosition());
//
//	m_Player->updateEntity(deltaTime);
//	m_EnemyTankRed->updateEntity(deltaTime);
//
//	CCollision::CheckCollision(m_Player, m_EnemyTankRed);
//	CBox2D::Intersect(m_Player->getBounding(), m_EnemyTankRed->getBounding());
//
//	OutputDebugString(L"COLLISION DIRECTION: ");
//	OutputDebugString(_itow(CCollision::CheckCollision(m_Player, m_EnemyTankRed), new WCHAR[1], 10));
//	OutputDebugString(L"\n");
//
//	OutputDebugString(L"IS INTERSECT: ");
//	OutputDebugString(_itow(CBox2D::Intersect(m_Player->getBounding(), m_EnemyTankRed->getBounding()), new WCHAR[1], 10));
//	OutputDebugString(L"\n");
//}
//
//void	CPlayScene::updateScene(CKeyBoard* keyboard)
//{
//	if (keyboard->KeyPress(DIK_P))
//		return;
//
//	m_Player->updateEntity(keyboard);
//}
//
//void	CPlayScene::renderScene()
//{
//<<<<<<< Updated upstream
//	m_Player->drawEntity();
//	m_EnemyTankRed->drawEntity();
//=======
//	map->drawEntity();
//>>>>>>> Stashed changes
//}