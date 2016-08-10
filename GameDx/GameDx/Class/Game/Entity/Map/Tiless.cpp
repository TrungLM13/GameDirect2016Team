#include "Tiless.h"


CTiless::CTiless()
{
	m_Position			= vector3dZero;
	m_ID				= -1;
	this->initEntity();
}

CTiless::CTiless(vector2d pos, int type)
{
	m_Position.x		= pos.x;
	m_Position.y		= pos.y;

	m_ID				= type;

	this->initEntity();

}
CTiless::~CTiless()
{
	if (!m_listSprite.empty())
		m_listSprite.clear();
}


bool	CTiless::loadSprite()
{
	switch (m_ID)
	{
	case TileStyle::TOF_GRASS_LEFT:
		m_listSprite.push_back(new CSprite(CInfomationResource::grass_left_map3));
		break;
	case TileStyle::TOF_GRASS_RIGHT:
		m_listSprite.push_back(new CSprite(CInfomationResource::grass_right_map3));
		break;
	case TileStyle::TOF_GRASS_MIDDLE:
		m_listSprite.push_back(new CSprite(CInfomationResource::grass_middle_map3));
		break;
	case TileStyle::TOF_GRASS_ONE_BUSH:
		m_listSprite.push_back(new CSprite(CInfomationResource::grass_small_map1));
		break;
	case TileStyle::TOF_GRASS_TOW_BUSH:
		m_listSprite.push_back(new CSprite(CInfomationResource::grass_normal_map1));
		break;
	case TileStyle::TOF_GRASS_THREE_BUSH:
		m_listSprite.push_back(new CSprite(CInfomationResource::grass_big_map1));
		break;

	case TileStyle::TOF_CASTTLE:
		m_listSprite.push_back(new CSprite(CInfomationResource::castle));
		break;

	case TileStyle::TOF_PIPE_HEAD_DOWN:
		m_listSprite.push_back(new CSprite(CInfomationResource::pipe_head_down));
		break;
	case TileStyle::TOF_PIPE_HEAD_BODY_DOWN:
		m_listSprite.push_back(new CSprite(CInfomationResource::pipe_head_body_down));
		break;
	case TileStyle::TOF_PIPE_BODY_DOWN:
		m_listSprite.push_back(new CSprite(CInfomationResource::pipe_body_down));
		break;
	case TileStyle::TOF_PIPE_HEAD_RIGHT:
		m_listSprite.push_back(new CSprite(CInfomationResource::pipe_head_right));
		break;
	case TileStyle::TOF_PIPE_BODY_RIGHT:
		m_listSprite.push_back(new CSprite(CInfomationResource::pipe_body_right));
		break;

	case TileStyle::TOF_CEMENT_PIPE:
		m_listSprite.push_back(new CSprite(CInfomationResource::cement_pipe));
		break;
	case TileStyle::TOF_CEMENT_BARRIER_RED:
		m_listSprite.push_back(new CSprite(CInfomationResource::cement_barrier_red));
		break;
	case TileStyle::TOF_CEMENT_BARRIER_BLUE:
		m_listSprite.push_back(new CSprite(CInfomationResource::cement_barrier_blue));
		break;
	case TileStyle::TOF_CEMENT_LANE_RED:
		m_listSprite.push_back(new CSprite(CInfomationResource::cement_lane_red));
		break;
	case TileStyle::TOF_CEMENT_LANE_BLE:
		m_listSprite.push_back(new CSprite(CInfomationResource::cement_barrier_blue));
		break;
	case TileStyle::TOF_CLOUND_ONE_MEMBER:
		m_listSprite.push_back(new CSprite(CInfomationResource::clound_small));
		break;
	case TileStyle::TOF_CLOUND_TOW_MEMBER:
		m_listSprite.push_back(new CSprite(CInfomationResource::clound_normal));
		break;
	case TileStyle::TOF_CLOUND_THREE_MEMBER:
		m_listSprite.push_back(new CSprite(CInfomationResource::clound_big));
		break;

	case TileStyle::TOF_MOUNTAIN_SMALL:
		m_listSprite.push_back(new CSprite(CInfomationResource::mountain_head));
		break;

	case TileStyle::TOF_MOUNTAIN_BIG:
		m_listSprite.push_back(new CSprite(CInfomationResource::mountain_body));
	default:
		return false;
	}

	return true;
}

bool	CTiless::initEntity()
{
	this->loadSprite();
	return true;
}

void	CTiless::drawEntity()
{
	for (int i = 0; i < m_listSprite.size(); ++i)
		m_listSprite.at(i)->Render(CCamera::getInstance()->setPositionEntity(m_Position));
}