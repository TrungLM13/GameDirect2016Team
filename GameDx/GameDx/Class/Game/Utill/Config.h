/****************************************************************************/
/* Create by Michael Le*/
/* 07/07/2015 */
/***************************************************************************/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <tchar.h>
#include <iostream>

/*DEFINE*/
#define FPS							60
#define GAME_RATE					(1000.0f/60.0f)
#define WINDOWS_NAME				L"Oishi"
#define DRAWCENTER_LEFT_TOP			1					
#define DRAWCENTER_LEFT_MIDDLE		2			
#define DRAWCENTER_LEFT_BOTTOM		3					
#define DRAWCENTER_MIDDLE_TOP		4				
#define DRAWCENTER_MIDDLE_MIDDLE	5					
#define DRAWCENTER_MIDDLE_BOTTOM	6		
#define DRAWCENTER_RIGHT_TOP		7
#define DRAWCENTER_RIGHT_MIDDLE		8
#define DRAWCENTER_RIGHT_BOTTOM		9

#define KEYBOARD_BUFFER_SIZE		1024
#define ISKEYDOWN(keystatus)		(keystatus & 0x80)

#define directDevice				LPDIRECT3DDEVICE9

#define vector3d					D3DXVECTOR3
#define vector3dZero				D3DXVECTOR3(0.0f,0.0f,0.5f)
#define	vector3dMinimum				D3DXVECTOR3(-10000, -10000, 0.5f)
#define vector2d					D3DXVECTOR2
#define vector2dZero				D3DXVECTOR2(0.0f,0.0f)
#define vector4d					D3DXVECTOR4

#define CBoxZero					CBox2D(0, 0, 0, 0)			

#define matrix						D3DXMATRIX

#define PI							3.14

#define SIGN(A)						(A >= 0 ? 1 : -1)
#define DIRECT_COORDINATE(A)		{-(A)}
#define SAFE_RELEASE(A)				{if (A) {delete A; A = 0;}}

#define BACKBUFFER_WIDTH			256
#define	BACKBUFFER_HEIGHT			240

#define SCREEN_SIZE					CBox2D()
#define deltaBoundingBox			vector2d(5.0f, 5.0f)

#define DEFAULT_FONT_SIZE			8
#define DEFAULT_FONTNAME			_T("MegaMan 2")
#define DEFAULT_FONTPATH			_T("Resource//Font//megaman_2.ttf")
#define DEFAULT_FONT_COLOR			0xFFFFFFFF
#define DAFAULT_TEXT_COLOR_STAGE	0x9AFEFFFF

#define START_GAME_STRING			"PRESS START"
#define PRODUCTOR					"PROJECT GAME UIT"
#define TM							"TM"

#define SELECT_CUTMAN_STRING		"CUTMAN"
#define SELECT_GUTMAN_STRING		"GUTMAN"
#define	SELECT_ICEMAN_STRING		"ICEMAN"
#define	SELECT_BOMBMAN_STRING		"BOMBMAN"
#define	SELECT_FIREMAN_STRING		"FIREMAN"
#define	SELECT_ELECMAN				"ELECMAN"
#define SELECT_STAGE_STRING			"SELECT\nSTAGE"
#define PRESS_START_GAME_STRING		"PRESS\nSTART"

#define DEFAULT_POINT_STRING		L"0000"
#define CUTMAN_STAGE_INFO_STRING	L"CUTMAN\n\nCLEAR POINT"
#define BOMBMAN_STAGE_INFO_STRING	L"BOMBMAN\n\nCLEAR POINT"
#define FIREMAN_STAGE_INFO_STRING	L"FIREMAN\n\nCLEAR POINT"

#define VEL_PLAYER_X 4
#define VEL_PLAYER_Y 19
#define ACCEL_PLAYER_X 0.5f
#define ACCEL_PLAYER_Y 1

#define POOLSIZE					5
#define LEVELPOOL(A)				(A*POOLSIZE)		
#define GAME_OVER_STRING			"GAME  OVER"
#define CONTINUE_STRING				"CONTINUE"
#define SELECT_STAGE_STRING_GV		"SELECT  STAGE"
/************************************/

/*ENUM*/
enum GAMESTATE
{
	STATE_END,
	STATE_RUN
};


enum CAMERASTATE
{
	CAMERA_NORMAL,						// with rockman, this mean is update for X asix
	CAMERA_AUTO,						// with rockman, this mean is update for Y asix
	CAMERA_STOP
};


enum KEYSTATE
{
	KEY_PRESS = 0,
	KEY_RELEASE,
	KEY_UP,
	KEY_DOWN
};

enum BULLETSTATE
{
	BULLET_STATE_SHOW,
	BULLET_STATE_INVIS,
	BULLET_STATE_HIT,
	BULLET_STATE_DIE
};


enum STAGESELECTED
{
	CUTMAN,
	GUTSMAN,
	ICEMAN,
	BOMBMAN,
	FIREMAN,
	ELECMAN
};

enum DIRECTION
{
	DIRECTION_NONE	=  0,
	DIRECTION_RIGHT =  1,
	DIRECTION_UP	=  1,
	DIRECTION_LEFT	= -1,
	DIRECTION_DOWN	= -1
};

enum COLDIRECTION
{
	COLDIRECTION_NONE,
	COLDIRECTION_TOP,
	COLDIRECTION_BOTTOM,
	COLDIRECTION_LEFT,
	COLDIRECTION_RIGHT
};
/******************/

/*STRUCT*/

struct MapIntro
{
	std::string		m_mapName;
	int				m_point;
	int				m_timer;
	int				m_coin;
	int				m_helths;
};

struct MapInfo
{
	std::string		m_mapName;
	std::string		m_pathData;
	MapInfo(){
		m_mapName		= "NOPE";
		m_pathData		= "NOPE";
	}
	MapInfo(std::string mapName, std::string pathData){
		m_mapName		= mapName;
		m_pathData		= pathData;
	}
};
struct KeyState
{
	int KeyCode;
	KEYSTATE KeyStates;
};

enum PLAYERSTATES
{
	START = 0,
	STAND = 1,
	RUN = 2,
	JUMP = 3,
	STAND_SHOOT = 4,
	MOVE_SHOOT = 5,
	JUMP_SHOOT = 6,
	CLIMB = 7,
	SIT = 8,
	DIE = 9
};

enum PLAYERTAGS
{
	SMALL = 0,
	BIG = 1,
	FIRE = 2,
	UNDYING = 3
};

enum MUSHROOM_STATE
{
	MUSH_RUN = 0,
	MUSH_DIE = 1
};
/******************************/

/*CONST*/
/******************/

/******************************/

/*VLD*/
#ifndef __VLD_H__
#define __VLD_H__
//#include <vld.h>
#endif
/********************/

#define				SIZE_MAP_WIDTH			20000
#define				SIZE_MAP_HIGHT			20000
#define				MAX_OBJECT_OF_NODE		4
#define				MAX_LEVEL_OF_NODE		5

#endif