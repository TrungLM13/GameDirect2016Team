#include "EnemyBall.h"
#include "Game\Utill\InformationResource.h"

CEnemyBall::CEnemyBall()
{
	this->initEntity();
}

CEnemyBall::CEnemyBall(LPDIRECT3DDEVICE9)
{
	this->initEntity();
}

CEnemyBall::~CEnemyBall()
{
}

bool CEnemyBall::initEntity()
{
	RECT rectangle = { 420, 300, 500, 200 };
	m_Bounding = new CBox2D(rectangle, vector2d(50, 50));
	m_Velocity = vector2d(50, 50);

	check_State = true;
	m_Position = vector3d(350.0f, 300.0f, 0.0f);
	m_delay_Time = 0;
	// LOAD SPRITE
	this->loadSprite();
	return true;

}


bool CEnemyBall::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_ball.png", 1, 2, 2, 0));
	return true;
}
void CEnemyBall::updateEntity(CKeyBoard *device)
{


}

void CEnemyBall::updateEntity(float deltaTime)
{
	CCollision::CheckCollision(new CEnemyBall(), new CEnemyBubbleBlue());
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;
	m_delay_Time++;
	if (m_delay_Time > 0 && m_delay_Time < 35)
	{
		check_State = false;
		m_Velocity.x = -2;
	}
	if (m_delay_Time >= 70)
		m_delay_Time = 0;

	if (m_delay_Time >= 35)
	{
		check_State = true;
		m_Velocity.x = 0;
	}
}

void CEnemyBall::updateEntity(RECT rectCamera)
{

}

void  CEnemyBall::drawEntity()
{
	if (check_State)
		this->m_listSprite[0]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	else
		this->m_listSprite[0]->Render(1, 1, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}