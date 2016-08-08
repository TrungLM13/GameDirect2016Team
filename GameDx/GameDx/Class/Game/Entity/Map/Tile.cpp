#include "Tile.h"

CTile::CTile()
{

}

CTile::CTile(vector3d pos, int State)
{
	m_Pos = pos;
	m_Index = State;
}


CTile::~CTile()
{
}

bool CTile::initEntity()
{
	return true;
}

void CTile::updateEntity(float deltaTime)
{
	
}

void CTile::updateEntity(CKeyBoard* device)
{

}

void CTile::updateEntity(RECT* rectCamera)
{

}
void CTile::updateCollision(CBaseEntity*, float deltaTime)
{

}
void CTile::drawEntity()
{

}

bool CTile::loadSprite()
{
	return true;
}

