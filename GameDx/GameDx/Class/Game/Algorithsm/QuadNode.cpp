#include "QuadNode.h"

CQuadNode::CQuadNode()
{
	m_NodeLevel = 0;
	m_NodeSize	= CBoxZero;
}

CQuadNode::~CQuadNode()
{
}

CQuadNode::CQuadNode(int Level, CBox2D NodeBound)
{
	m_NodeLevel = Level;
	m_NodeSize	= NodeBound;
}

int CQuadNode::getNodeLevel()
{
	return m_NodeLevel;
}

void CQuadNode::setNodeLevel(int Level)
{
	m_NodeLevel = Level;
}

CBox2D CQuadNode::getNodeSize()
{
	return m_NodeSize;
}

void CQuadNode::setNodeSize(CBox2D Size)
{
	m_NodeSize = Size;
}

CQuadNode** CQuadNode::getParent()
{
	return m_Node;
}

void CQuadNode::SplitParent()
{
	m_Node			= new CQuadNode*[4];

	this->m_Node[0] = new CQuadNode(this->m_NodeLevel + 1, CBox2D(this->m_NodeSize.getX(), this->m_NodeSize.getY(), this->m_NodeSize.getWidth() / 2, this->m_NodeSize.getHeight() / 2));
	this->m_Node[1] = new CQuadNode(this->m_NodeLevel + 1, CBox2D(this->m_NodeSize.getX() + this->m_NodeSize.getWidth() / 2, this->m_NodeSize.getY(), this->m_NodeSize.getWidth() / 2, this->m_NodeSize.getHeight() / 2));
	this->m_Node[2] = new CQuadNode(this->m_NodeLevel + 1, CBox2D(this->m_NodeSize.getX(), this->m_NodeSize.getY() + this->m_NodeSize.getHeight() / 2, this->m_NodeSize.getWidth() / 2, this->m_NodeSize.getHeight() / 2));
	this->m_Node[3] = new CQuadNode(this->m_NodeLevel + 1, CBox2D(this->m_NodeSize.getX() + this->m_NodeSize.getWidth() / 2, this->m_NodeSize.getY() + this->m_NodeSize.getHeight() / 2, this->m_NodeSize.getWidth() / 2, this->m_NodeSize.getHeight() / 2));
}

vector<CBaseEntity*> CQuadNode::getEntityList()
{
	return m_EntityList;
}

void CQuadNode::ReleaseNode()
{
	SAFE_RELEASE(m_Node);
}

bool CQuadNode::InsertEntity(CBaseEntity* entity)
{
	if (!this)
	{
		if (CBox2D::Intersect(m_Node[0]->getNodeSize(), entity->getBounding()))
			m_Node[0]->InsertEntity(entity);
		if (CBox2D::Intersect(m_Node[1]->getNodeSize(), entity->getBounding()))
			m_Node[1]->InsertEntity(entity);
		if (CBox2D::Intersect(m_Node[2]->getNodeSize(), entity->getBounding()))
			m_Node[2]->InsertEntity(entity);
		if (CBox2D::Intersect(m_Node[3]->getNodeSize(), entity->getBounding()))
			m_Node[3]->InsertEntity(entity);
	}
	

	if (CBox2D::Intersect(this->getNodeSize(), entity->getBounding()))
		m_EntityList.push_back(entity);

	if (m_EntityList.size() > MAX_OBJECT_OF_NODE && (m_NodeSize.getWidth() > BACKBUFFER_WIDTH || m_NodeSize.getHeight()>BACKBUFFER_HEIGHT))
	{
		this->SplitParent();

		if (CBox2D::Intersect(m_Node[0]->getNodeSize(), m_EntityList.back()->getBounding()))
			m_Node[0]->InsertEntity(m_EntityList.back());
		if (CBox2D::Intersect(m_Node[1]->getNodeSize(), m_EntityList.back()->getBounding()))
			m_Node[1]->InsertEntity(m_EntityList.back());
		if (CBox2D::Intersect(m_Node[2]->getNodeSize(), m_EntityList.back()->getBounding()))
			m_Node[2]->InsertEntity(m_EntityList.back());
		if (CBox2D::Intersect(m_Node[3]->getNodeSize(), m_EntityList.back()->getBounding()))
			m_Node[3]->InsertEntity(m_EntityList.back());

		m_EntityList.pop_back();
	}
		return true;
}