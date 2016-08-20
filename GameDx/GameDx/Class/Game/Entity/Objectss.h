#ifndef __OBTS_H__
#define __OBTS_H__
#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Framework\Sprite.h"
#include "Class\Game\Utill\ResourceManager\BaseResource.h"

class CObjectss
{
public:
	CObjectss();
	virtual ~CObjectss() = 0;

	virtual bool			initEntity()		=0;
	virtual bool			loadSprite()		=0;
	virtual void			drawEntity()		=0;

protected:
	const char*				m_TagNode;
	vector3d				m_Position;
	vector<CSprite*>		m_listSprite;
	CBaseResource*			m_ResouceImage;
};

#endif