#include "EnemyMachineOrange.h"


CEnemyMachineOrange::CEnemyMachineOrange()
{
}

CEnemyMachineOrange::CEnemyMachineOrange(vector3d position,vector3d position_player,int m_rangex)
{
	m_RangeX = m_rangex;
	this->m_Position = position;
	this->m_CurrentPosition = position;
	this->m_PositionPlayer = position_player;
	this->initEntity();
}



CEnemyMachineOrange::~CEnemyMachineOrange()
{
}

bool CEnemyMachineOrange::initEntity()
{
	// LOAD SPRITE
	m_Velocity.x = 5;
	this->loadSprite();
	return true;
}


bool CEnemyMachineOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_machine_orange.png", 1, 2, 2, 0));
	return true;
}
void CEnemyMachineOrange::updateEntity(CKeyBoard *device)
{}

void CEnemyMachineOrange::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;

	if (abs(m_CurrentPosition.x - m_PositionPlayer.x) < 100 && abs(m_CurrentPosition.y - m_PositionPlayer.y) < 10)
	{
		m_Sign = true;
	}
	else
	{
		m_Sign = false;
	}
	if (m_Sign)
	{
		if (m_Position.x - m_PositionPlayer.x > 3)
		{
			m_Velocity.x = -5;
		}
		else if (m_Position.x - m_PositionPlayer.x < -3)
		{
			m_Velocity.x = 5;
		}
		else if (abs(m_CurrentPosition.x - m_PositionPlayer.x) < 3)
		{
			m_Velocity.x *= 0.1;
		}
	}
	else
	{
		if (abs(m_CurrentPosition.x - m_Position.x) > m_RangeX)
		{
			m_Velocity.x *= -1;
		}
	}


}

void CEnemyMachineOrange::updateEntity(RECT rectCamera)
{

}

void CEnemyMachineOrange::drawEntity()
{
	this->m_listSprite[0]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}
