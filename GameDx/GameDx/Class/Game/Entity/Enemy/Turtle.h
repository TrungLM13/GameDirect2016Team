#include "Class\Game\Entity\MovableEntity.h"
#include "Class\Framework\Camera.h"
#include "Class\Game\State\TurtleState\TurtleBaseState.h"
#include "Class\Game\Algorithsm\Singleton.h"
#include "Class\Game\Utill\ShowBouding.h"

#ifndef __TURTLE_H__
#define __TURTLE_H__

class TBaseState;

class Turtle : public CMovable, public CSingleton<Turtle>
{
public:
	Turtle();
	Turtle(directDevice);
	~Turtle();

	virtual bool			initEntity()											override;
	virtual void			updateEntity(float deltaTime)							override;
	virtual void			updateEntity(RECT* camera)								override;
	virtual void			updateEntity(CKeyBoard *device)							override;
	virtual void			drawEntity()											override;
	virtual int				getTagNodeId()											override;
	virtual	vector3d		getPosition()											override;
	virtual bool			loadSprite()											override;

public:
	void setPosition(vector3d position);
	void setState(TURTLE_STATE state);
	void setVelocity(vector2d velocity);
	void setState(TBaseState* state);
	TBaseState* getState();
	void setTurtleTag(int playerTag);
	int getTurtleTag();


protected:
	vector2d				m_Acceleration;
	TBaseState*				m_Turtle_State;
	int						m_Turtle_Tag;
private:
};
#endif
