#include "JumpState.h"
#include "StandState.h"

CJumpState::CJumpState() {
	m_IsMoveX = false;
}

CJumpState::~CJumpState() {

}

void CJumpState::enter(CPlayer& player) {
	player.setState(PLAYERSTATES::JUMP);
}

CBaseState* CJumpState::handleInput(CPlayer& player, CKeyBoard* input) {
	if (player.getPosition().y <= 50)
		return new CStandState();

	if (input->KeyDown(DIK_RIGHT)) {
		m_IsMoveX = true;
		if (player.getVelocity().x < 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));

		return this;
	}
	else if (input->KeyDown(DIK_LEFT)) {
		m_IsMoveX = true;
		if (player.getVelocity().x > 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));
		return this;
	}
	return this;
}

void CJumpState::update(CPlayer& player, double deltaTime){
	// Cause coordinate axis of direct is downward

	double deltaX = 0;
	if (m_IsMoveX) {
		deltaX = player.getVelocity().x * deltaTime / 100;
	}

	if (player.getPosition().y >= 150)
		player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y *(-1)));

	player.setPosition(vector3d(player.getPosition().x + deltaX, player.getPosition().y + player.getVelocity().y *deltaTime / 40, 0));
}