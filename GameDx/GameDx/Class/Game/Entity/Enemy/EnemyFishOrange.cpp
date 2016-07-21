#include "EnemyFishOrange.h"


CEnemyFishOrange::CEnemyFishOrange()
{
}

CEnemyFishOrange::CEnemyFishOrange(vector3d position)
{
	m_Position = position;
	m_CurrentPosition = position;
	m_Velocity.x = -3.5;
	m_Velocity.y = 2;
	this->loadSprite();
}


CEnemyFishOrange::~CEnemyFishOrange()
{
}

bool CEnemyFishOrange::initEntity()
{
	// LOAD SPRITE
	
	this->loadSprite();
	return true;
}


bool CEnemyFishOrange::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossBoomMan//enemy_fish_orange.png", 1, 1, 1, 0));
	return true;
}
void CEnemyFishOrange::updateEntity(CKeyBoard *device)
{}

void CEnemyFishOrange::updateEntity(float deltaTime)
{
	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;
	
	if (abs(m_Position.y - m_CurrentPosition.y) > 8)
	{
		m_Velocity.y *= -1;
	}
	
}

void CEnemyFishOrange::updateEntity(RECT rectCamera)
{

}

void CEnemyFishOrange::drawEntity()
{
	this->m_listSprite[0]->Render(0, 0, m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}