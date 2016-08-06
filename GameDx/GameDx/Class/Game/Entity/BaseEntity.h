/****************************************************************************/
/* Create by Michael Le*/
/* 08/07/2015 */
/***************************************************************************/


#ifndef __CBASEENTITY_H__
#define __CBASEENTITY_H__

#include "Class\Game\Utill\stdafx.h"
#include "Class\Game\Utill\Config.h"
#include "Class\Framework\KeyBoard.h"
#include "Class\Mathematics\Box2D.h"
#include "Class\Framework\Sprite.h"
#include "Class\Framework\Camera.h"

class CBaseEntity
{
public:
	
	CBaseEntity();
	CBaseEntity(directDevice);
	~CBaseEntity();

	virtual bool			initEntity()										= 0;
	virtual void			updateEntity(CKeyBoard* deivce)						= 0;
	virtual void			updateEntity(RECT* camera)							= 0;
	virtual void			updateEntity(float deltaTime)						= 0;
	virtual void			drawEntity()										= 0;
	virtual	CBox2D			getBounding()										= 0;
	virtual const char*		getTagNode()										= 0;
	virtual vector2d		getVelocity()										= 0;
	virtual int				getTagNodeId()										{ return 0; };
	virtual vector3d		getPosition()										= 0;

protected:
	int						m_State;
	const char*				m_TagNode;
	CBox2D*					m_Bounding;
	vector3d				m_Position;
	vector<CSprite*>		m_listSprite;
	


protected:
	vector2d				m_Velocity;


};


#endif