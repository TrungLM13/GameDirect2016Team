#include "JumpState.h"
#include "StandState.h"

CJumpState::CJumpState() {
	m_IsMoveX = false;
	m_IsJumpHigh = false;
	m_IsShoot = false;
}

CJumpState::~CJumpState() {

}

void CJumpState::enter(CPlayer& player) {
	if (m_IsShoot)
	{
		player.setState(PLAYERSTATES::JUMP_SHOOT);
	}
	else {
		player.setState(PLAYERSTATES::JUMP);
	}
}

CBaseState* CJumpState::handleInput(CPlayer& player, CKeyBoard* input) {
	if (input->KeyDown(DIK_SPACE)) {
		m_IsJumpHigh = true;
	}

	if (input->KeyDown(DIK_P)){
		m_IsShoot = true;
	}
	else
		m_IsShoot = false;

	if (input->KeyDown(DIK_RIGHT)) {
		m_IsMoveX = true;
		if (player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X) == DIRECTION::DIRECTION_LEFT)
			player.setVelocity(vector2d(CHANGE_DIRECTION(player.getVelocity().x), player.getVelocity().y));

		return this;
	}
	else if (input->KeyDown(DIK_LEFT)) {
		m_IsMoveX = true;
		if (player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X) == DIRECTION::DIRECTION_RIGHT)
			player.setVelocity(vector2d(CHANGE_DIRECTION(player.getVelocity().x), player.getVelocity().y));
		return this;
	}
	return this;
}

void CJumpState::update(CPlayer& player, double deltaTime){
	double deltaX = 0;

	if (m_IsMoveX) {
		if (player.getVelocity().x == VEL_PLAYER_X_MIN)
		{
			player.setVelocity(vector2d(VEL_PLAYER_X, VEL_PLAYER_Y));
		}
		deltaX = player.getVelocity().x * deltaTime / 100;
	}

	if (m_IsJumpHigh) {
		if (player.getPosition().y >= player.m_PreJumpPos.y + PLAYER_JUMP_HIGH_LIMIT)
			player.setVelocity(vector2d(player.getVelocity().x, CHANGE_DIRECTION(player.getVelocity().y)));
	}
	else {
		if (player.getPosition().y >= player.m_PreJumpPos.y + PLAYER_JUMP_LIMIT)
			player.setVelocity(vector2d(player.getVelocity().x, CHANGE_DIRECTION(player.getVelocity().y)));
	}

	player.setPosition(vector3d(player.getPosition().x + deltaX, player.getPosition().y + player.getVelocity().y *deltaTime / 40, 0));
}

void CJumpState::update(CPlayer& player, CBaseEntity* entity) {
}