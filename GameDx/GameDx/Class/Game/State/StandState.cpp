#include "StandState.h"

CStandState::CStandState() {
	m_IsShoot = false;
}

CStandState::~CStandState() {

}

void CStandState::enter(CPlayer& player) {
	if (m_IsShoot)
	{
		player.setState(PLAYERSTATES::STAND_SHOOT);
	}
	else
	{
		player.setState(PLAYERSTATES::STAND);
	}
}

CBaseState* CStandState::handleInput(CPlayer& player, CKeyBoard* input){

	if (input->KeyDown(DIK_RIGHT)) {
		if (player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X) == DIRECTION::DIRECTION_LEFT)
			player.setVelocity(vector2d(CHANGE_DIRECTION(player.getVelocity().x), player.getVelocity().y));
		return new CRunState();
	}

	if (input->KeyDown(DIK_LEFT)) {
		if (player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X) == DIRECTION::DIRECTION_RIGHT)
			player.setVelocity(vector2d(CHANGE_DIRECTION(player.getVelocity().x), player.getVelocity().y));
		return new CRunState();
	}

	if (input->KeyPress(DIK_UP) || input->KeyDown(DIK_SPACE)){
		if (player.getVelocity().y < 0)
			player.setVelocity(vector2d(player.getVelocity().x, CHANGE_DIRECTION(player.getVelocity().y)));

		return new CJumpState();
	}

	if (input->KeyDown(DIK_P)){
		m_IsShoot = true;
		return this;
	}
	else
		m_IsShoot = false;
	return nullptr;
}

void CStandState::update(CPlayer& player, double deltaTime) {
	if (!player.m_IsAutoMove)
		player.setVelocity(vector2d(VEL_PLAYER_X_MIN, player.getVelocity().y));
	else {
		this->exitCurrentState(player, new CRunState());
		player.getState()->enter(player);
	}
}