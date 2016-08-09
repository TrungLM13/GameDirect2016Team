#ifndef __ARCHITECTURE_ENTITY_H__
#define __ARCHITECTURE_ENTITY_H__

#include <tchar.h>
#include <iostream>

typedef enum TYPEOFTILE{
	TOF_GRASS_LEFT				= 0,
	TOF_GRASS_RIGHT,
	TOF_GRASS_MIDDLE,
	TOF_GRASS_ONE_BUSH,
	TOF_GRASS_TOW_BUSH,
	TOF_GRASS_THREE_BUSH,

	TOF_CASTTLE,

	TOF_PIPE_HEAD_RIGHT,
	TOF_PIPE_BODY_RIGHT,
	TOF_PIPE_HEAD_DOWN,
	TOF_PIPE_HEAD_BODY_DOWN,
	TOF_PIPE_BODY_DOWN,

	TOF_CEMENT_PIPE,
	TOF_CEMENT_BARRIER_BLUE,
	TOF_CEMENT_BARRIER_RED,
	TOF_CEMENT_LANE_BLE,
	TOF_CEMENT_LANE_RED,

	TOF_CLOUND_ONE_MEMBER,
	TOF_CLOUND_TOW_MEMBER,
	TOF_CLOUND_THREE_MEMBER,

	TOF_MOUNTAIN_SMALL,
	TOF_MOUNTAIN_BIG
} TileStyle;


#endif