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
	if (player.getPosition().y <= 50)
		return new CStandState();

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
	double deltaX = 0;

	if (m_IsMoveX) {
		deltaX = player.getVelocity().x * deltaTime / 100;
	}

	if (player.getPosition().y >= 150)
		player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y *(-1)));
	if (m_IsJumpHigh) {
		if (player.getPosition().y >= 190)
			player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y *(-1)));
	}
	else {
		if (player.getPosition().y >= 150)
			player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y *(-1)));
	}


	player.setPosition(vector3d(player.getPosition().x + deltaX, player.getPosition().y + player.getVelocity().y *deltaTime / 40, 0));
}