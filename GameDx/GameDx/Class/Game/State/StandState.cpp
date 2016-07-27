#include "StandState.h"

CStandState::CStandState() {
}

CStandState::~CStandState() {

}

void CStandState::enter(CPlayer& player) {
	player.setState(PLAYERSTATES::STAND);
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
	if (input->KeyPress(DIK_UP)){
		if (player.getVelocity().y < 0)
			player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
		return new CJumpState();
	}

	return nullptr;
}

void CStandState::update(CPlayer& player, double deltaTime) {
}