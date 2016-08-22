#include "QuadTree.h"
#include "Class\Game\Entity\Map\MapManager.h"


CQuadTree::CQuadTree()
{
	m_Node = new CQuadNode(0, CBox2D(0, SIZE_MAP_HIGHT, SIZE_MAP_WIDTH, SIZE_MAP_HIGHT));
}


CQuadTree::~CQuadTree()
{
}

void CQuadTree::CreateTree()
{
	for (int i = 0; i < CMapManager::getInstance()->getListBackground().size(); ++i)
		m_Node->InsertEntity(CMapManager::getInstance()->getListBackground().at(i));
	for (int i = 0; i < CMapManager::getInstance()->getListBonus().size(); ++i)
		m_Node->InsertEntity(CMapManager::getInstance()->getListBonus().at(i));
	for (int i = 0; i < CMapManager::getInstance()->getListEnemy().size(); ++i)
		m_Node->InsertEntity(CMapManager::getInstance()->getListEnemy().at(i));
}

void CQuadTree::ReleaseTree()
{
	m_Node->ReleaseNode();
}

vector<CObjectss*> CQuadTree::Retrieve(CBox2D rectCamera)
{
	return m_Node->retrieveEntity(rectCamera);
}

