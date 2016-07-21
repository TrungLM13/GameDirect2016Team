#include "EnemyNinja.h"


CEnemyNinja::CEnemyNinja()
{
}

CEnemyNinja::CEnemyNinja(vector3d position, vector3d position_player)
{
	this->m_Position = position;
	this->m_PositionPlayer = position_player;
	this->initEntity();
}


CEnemyNinja::~CEnemyNinja()
{
}

bool CEnemyNinja::initEntity()
{
	// LOAD SPRITE
	this->loadSprite();
	this->m_delayTime = 0;
	return true;
}


bool CEnemyNinja::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_ninja_green_stand.png", 1, 1, 1, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_ninja_green_fire.png", 1, 2, 2, 0));
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_ninja_green_jump.png", 1, 1, 1, 0));
	return true;
}
void CEnemyNinja::updateEntity(CKeyBoard *device)
{}

void CEnemyNinja::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;
	this->m_delayTime++;
	if (m_delayTime > 140)
	{
		m_delayTime = 0;
	}

	if (abs(m_Position.x - m_PositionPlayer.x) < 120)
	{
		if (m_delayTime > 0 && m_delayTime < 50)
		{
			this->m_checkState = 0;
			if (m_Position.y >= 420)
			{
				m_Velocity.y = 0;
			}
			m_Velocity.x = 0;
		}
		if (m_delayTime > 50 && m_delayTime < 110)
		{
			this->m_checkState = 1;
			if (m_Position.y >= 420)
			{
				m_Velocity.y = 0;	
			}
			m_Velocity.x = 0;
		}
		if (m_delayTime > 110)
		{
			this->m_checkState = 2;
			jump();
		}
		if (m_Position.y < 420)
		{
			m_Velocity.y++;
		}
	}
	
	
}

void CEnemyNinja::updateEntity(RECT rectCamera)
{

}

void CEnemyNinja::drawEntity()
{
	if (m_isLEFT)
		this->m_listSprite[m_checkState]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 8);
	else
		this->m_listSprite[m_checkState]->Render(0, 0, m_Position, vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 8);

}

void CEnemyNinja::jump()
{
	m_Velocity.y = -8;
	if (m_Position.x > m_PositionPlayer.x)
		m_Velocity.x = 3;
	else
		m_Velocity.x = -3;
	
	
}
void CEnemyNinja::fire()
{

}

