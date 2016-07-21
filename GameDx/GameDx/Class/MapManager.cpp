#include "MapManager.h"
#include <fstream>
#include "Framework\Camera.h"

Map::Map()
{
	
}

Map::~Map()
{

}


bool Map::initEntity()
{
	ifstream data;
	data.open(L"Resource\\Image\\Maps\\cutman.txt");
	int x;
	int y;
	string type;

	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\1.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\2.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\3.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\4.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\5.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\6.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\7.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\8.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\9.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\10.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\11.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\12.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\13.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\14.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\15.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\16.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\17.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\18.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\19.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\20.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\21.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\22.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\23.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\24.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\25.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\26.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\27.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\28.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\29.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\30.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\31.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\32.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\33.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\34.png", 1, 1, 1, 0));
	m_listSprite.push_back(new CSprite(L"Resource\\Image\\Maps\\Tiles\\Cutman\\35.png", 1, 1, 1, 0));
	
	while (data >> x >> y >> type)
	{
		x *= 2;
		y *= 2; y += 32;
		if (type == "0C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 0));
		if (type == "1C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 1));
		if (type == "2C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 2));
		if (type == "3C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 3));
		if (type == "4C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 4));
		if (type == "5C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 5));
		if (type == "6C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 6));
		if (type == "7C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 7));
		if (type == "8C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 8));
		if (type == "9C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 9));
		if (type == "10C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 10));
		if (type == "11C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 11));
		if (type == "12C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 12));
		if (type == "13C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 13));
		if (type == "14C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 14));
		if (type == "15C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 15));
		if (type == "16C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 16));
		if (type == "17C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 17));
		if (type == "18C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 18));
		if (type == "19C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 19));
		if (type == "20C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 20));
		if (type == "21C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 21));
		if (type == "22C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 22));
		if (type == "23C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 23));
		if (type == "24C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 24));
		if (type == "25C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 25));
		if (type == "26C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 26));
		if (type == "27C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 27));
		if (type == "28C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 28));
		if (type == "29C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 29));
		if (type == "30C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 30));
		if (type == "31C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 31));
		if (type == "32C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 32));
		if (type == "33C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 33));
		if (type == "34C")
			listTile.push_back(new CTile(vector3d((float)x, (float)y, 0.5f), 34));
	}
	return true;
}

void Map::drawEntity()
{
	for (int i = 0; i < listTile.size(); i++)
	{
		//if isDraw == true
		m_listSprite[listTile[i]->m_Index]->Render(CCamera::setPositionEntity(listTile[i]->m_Pos), vector2d(2.0, 2.0), 0.0f, DRAWCENTER_LEFT_TOP, true, FPS);
	}
}