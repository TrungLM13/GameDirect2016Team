#include "EnemyInkBlue.h"


//D3DXVECTOR3(300.0f, 100.0f, 0.0f);
CEnemyInkBlue::CEnemyInkBlue()
{
	this->initEntity();
}

CEnemyInkBlue::CEnemyInkBlue(vector3d m_position_p, vector3d m_position)
{
	m_position_Player = m_position_p;
	m_Position = m_position;
	this->initEntity();
}

CEnemyInkBlue::~CEnemyInkBlue()
{
}

bool CEnemyInkBlue::initEntity()
{
	check_State = true;
	m_delay_Time = 0;
	m_Velocity.x = 1;
	// LOAD SPRITE
	this->loadSprite();
	return true;
}


bool CEnemyInkBlue::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_ink_blue.png", 1, 2, 2, 0));
	return true;
}
void CEnemyInkBlue::updateEntity(CKeyBoard *device)
{}

void CEnemyInkBlue::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;
	m_delay_Time++;

	if (m_Position.x >= 400|| m_position_Player.x < m_Position.x)
	{
		m_isLEFT = true;
	}
	if (m_Position.x <= 10 || m_position_Player.x > m_Position.x)
	{
		m_isLEFT = false;
	}
	if (m_delay_Time >= 70)
		m_delay_Time = 0;
	if (m_delay_Time > 0 && m_delay_Time < 40)
	{
		if (m_Position.y >= 300)
		{
			m_Velocity.y = 0;
			check_State = true;
		}
		m_Velocity.x = 0;
	}
	if (m_delay_Time >= 40)
	{
		check_State = false;
		if (m_isLEFT)
		{
			m_Velocity.x = -3;
		}
		else
		{
			m_Velocity.x = 3;
		}

		m_Velocity.y = -9;
	}
	if (m_Position.y < 300)
	{
		m_Velocity.y ++;
	}
	
}

void CEnemyInkBlue::updateEntity(RECT rectCamera)
{

}

void CEnemyInkBlue::drawEntity()
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