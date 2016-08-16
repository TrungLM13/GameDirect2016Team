#include "ClimbState.h"


CClimbState::CClimbState() {

}

CClimbState::~CClimbState() {

}

void CClimbState::enter(CPlayer& player) {
	player.setState(PLAYERSTATES::CLIMB);
}

CBaseState* CClimbState::handleInput(CPlayer& player, CKeyBoard* input) {
	return this;
}

void CClimbState::update(CPlayer& player, double deltaTime) {
	player.setVelocity(vector2d((float)VEL_PLAYER_X, (float)(-VEL_DEFAULT_Y)));

	if (player.m_IsAutoMove == false)
		player.setPosition(vector3d(player.getPosition().x, player.getPosition().y + player.getVelocity().y * deltaTime / 240, 0));
}