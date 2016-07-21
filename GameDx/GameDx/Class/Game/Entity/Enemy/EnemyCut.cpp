#include "EnemyCut.h"


CEnemyCut::CEnemyCut()
{
}

CEnemyCut::CEnemyCut(vector3d m_position_player)
{
	this->initEntity();
	m_position_p = m_position_player;
}


CEnemyCut::~CEnemyCut()
{
}

bool CEnemyCut::initEntity()
{
	m_Position = vector3d(350.0f, 300.0f, 0.0f);
	// LOAD SPRITE
	this->loadSprite();
	return true;

}


bool CEnemyCut::loadSprite()
{
	this->m_listSprite.push_back(new CSprite(L"Resource//Image//Game//Sprites//BossCutMan//enemy_cut.png", 1, 2, 2, 0));
	return true;
}

void CEnemyCut::updateEntity(CKeyBoard *device)
{

}
void CEnemyCut::updateEntity(float deltaTime)
{

	this->m_Position.x += this->m_Velocity.x*deltaTime;
	this->m_Position.y += this->m_Velocity.y*deltaTime;

	if (abs(350 - m_position_p.x) <= 120)
	{
		if (abs(350 - m_position_p.x) <= 120 && abs(350 - m_position_p.x) >= 80)
		{
			m_Velocity.x = 6;
		}
		else if (abs(350 - m_position_p.x) <= 80 && abs(350 - m_position_p.x) >= 50)
		{
			m_Velocity.x = 4.5;
		}
		else if (abs(350 - m_position_p.x) <= 50 && abs(350 - m_position_p.x) >= 20)
		{
			m_Velocity.x = 3.5;
		}
		else
		{
			m_Velocity.x = 1.5;
		}
		if (m_position_p.x - 350 < 0)
		{
			m_Velocity.x = -m_Velocity.x;
			if (m_isJUMP)
			{
				m_Velocity.y++;
			}
			else
			{
				m_isJUMP = true;
				m_Velocity.y = -17;
			}
		}
		else
		{
			if (m_isJUMP)
			{
				m_Velocity.y++;
			}
			else
			{
				m_isJUMP = true;
				m_Velocity.y = -17;
			}
		}
	}
	else
	{
		m_Velocity.y = 0;
		m_Velocity.x = 0;
	}
	if (m_Position.y >= 400)
	{
		m_isJUMP = false;
		m_Position = D3DXVECTOR3(350.0f, 300.0f, 0.0f);
	}
}

void CEnemyCut::updateEntity(RECT rectCamera)
{

}

void CEnemyCut::drawEntity()
{
	if (m_isLEFT)
		this->m_listSprite[0]->Render(m_Position, vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
	else
		this->m_listSprite[0]->Render(m_Position, vector2d(-1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true, 10);
}
