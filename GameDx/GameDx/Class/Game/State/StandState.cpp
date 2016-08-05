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
		if (player.getVelocity().x < 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));
		return new CRunState();
	}

	if (input->KeyDown(DIK_LEFT)) {
		if (player.getVelocity().x > 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));
		return new CRunState();
	}

	if (input->KeyPress(DIK_UP) || input->KeyDown(DIK_SPACE)){
		if (player.getVelocity().y < 0)
			player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));

		return new CJumpState();
	}

	if (input->KeyDown(DIK_P)){
		//return new CStandState(player, PLAYERSTATES::STAND_SHOOT);
		m_IsShoot = true;
		return this;
	}
	else
		m_IsShoot = false;

	/*if (player.getPlayerTag() == PLAYERTAGS::FIRE) {
		if (input->KeyDown(DIK_P)){
			return new CStandShootState();
		}
	}*/


	return nullptr;
}

void CStandState::update(CPlayer& player, double deltaTime) {
		player.setVelocity(vector2d(0, player.getVelocity().y));
}