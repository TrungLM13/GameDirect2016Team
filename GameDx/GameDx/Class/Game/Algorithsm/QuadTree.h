#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Game\Algorithsm\Singleton.h"
#include "Class\Game\Algorithsm\QuadNode.h"

class CQuadTree : public CSingleton<CQuadTree>
{
public:
	CQuadTree();
	~CQuadTree();

	void								CreateTree();
	void								ReleaseTree();
	vector<CObjectss*>					Retrieve(CBox2D);
protected:
	CQuadNode*							m_Node;

};

#endif

