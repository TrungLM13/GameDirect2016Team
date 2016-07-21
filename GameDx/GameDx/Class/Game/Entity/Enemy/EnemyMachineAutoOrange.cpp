#include "EnemyMachineAutoOrange.h"


CEnemyMachineAutoOrange::CEnemyMachineAutoOrange()
{
}

CEnemyMachineAutoOrange::CEnemyMachineAutoOrange(vector3d position)
{
	this->m_Position = position;
	this->initEntity();
}


CEnemyMachineAutoOrange::~CEnemyMachineAutoOrange()
{
}

bool CEnemyMachineAutoOrange::initEntity()
{
	check_State = true;
	m_delay_Time = 0;
	// LOAD SPRITE
	this->loadSprite();
	return true;

}


bool CEnemyMachineAutoOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_machine_auto_orange.png", 1, 4, 4, 0));
	return true;
}
void CEnemyMachineAutoOrange::updateEntity(CKeyBoard *device)
{

}
void CEnemyMachineAutoOrange::updateEntity(float deltaTime)
{
	m_delay_Time++;
	if (m_delay_Time > 0 && m_delay_Time < 35)
	{
		check_State = true;
		m_Velocity.x = -2;
	}
	if (m_delay_Time >= 100)
		m_delay_Time = 0;

	if (m_delay_Time >= 35)
	{
		check_State = false;
		m_Velocity.x = 0;
	}
}

void CEnemyMachineAutoOrange::updateEntity(RECT rectCamera)
{

}

void  CEnemyMachineAutoOrange::drawEntity()
{
	if (check_State)
		this->m_listSprite[0]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
	else
		this->m_listSprite[0]->Render(1, 3, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 3);
}