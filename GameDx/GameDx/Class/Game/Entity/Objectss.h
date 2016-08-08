#ifndef __OBTS_H__
#define __OBTS_H__
#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Framework\Sprite.h"

class CObjectss
{
public:
	CObjectss();
	~CObjectss();
	virtual bool			initEntity()		= 0;
	virtual void			drawEntity()		= 0;

protected:
	const char*				m_TagNode;
	vector3d				m_Position;
	vector<CSprite*>		m_listSprite;
};

#endif