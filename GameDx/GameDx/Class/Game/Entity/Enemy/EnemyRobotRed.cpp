#include "EnemyRobotRed.h"


EnemyRobotRed::EnemyRobotRed()
{
	this->initEntity();
}


EnemyRobotRed::~EnemyRobotRed()
{
}

bool EnemyRobotRed::initEntity()
{
	check_State = true;
	m_Position = D3DXVECTOR3(300.0f, 300.0f, 0.0f);
	m_delay_Time = 0;
	// LOAD SPRITE
	this->loadSprite();
	return true;
}


bool EnemyRobotRed::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_robot_red.png", 1, 2, 2, 0));
	return true;
}
void EnemyRobotRed::updateEntity(CKeyBoard *device)
{

}
void EnemyRobotRed::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;
	m_delay_Time++;
	if (m_Position.x >= 400)
	{
		m_isLEFT = true;
	}
	if (m_Position.x <= 10)
	{
		m_isLEFT = false;
	}

	if (m_delay_Time >= 70)
		m_delay_Time = 0;
	if (m_delay_Time > 0 && m_delay_Time < 50)
	{
		
		if (m_Position.y >= 300)
		{
			check_State = true;
			m_Velocity.y = 0;
		}
		m_Velocity.x = 0;
		
	}
	if (m_delay_Time >= 50)
	{
		check_State = false;
		if (m_isLEFT)
		{
			m_Velocity.x = -2;
		}
		else
		{
			m_Velocity.x = 2;
		}

		m_Velocity.y = -9;
	}
	if (m_Position.y < 300)
	{
		m_Velocity.y ++;
	}

}

void EnemyRobotRed::updateEntity(RECT rectCamera)
{

}

void  EnemyRobotRed::drawEntity()
{
	if (m_isLEFT)
	{
		if (check_State)
			this->m_listSprite[m_State]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		else
			this->m_listSprite[m_State]->Render(1, 1, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	else
	{
		if (check_State)
			this->m_listSprite[m_State]->Render(0, 0, m_Position, vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
		else
			this->m_listSprite[m_State]->Render(1, 1, m_Position, vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	}
	
}