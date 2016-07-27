#include "RunState.h"
#include "StandState.h"

CRunState::CRunState() {
}

CRunState::~CRunState() {

}

void CRunState::enter(CPlayer& player) {
	player.setState(PLAYERSTATES::RUN);
}

CBaseState* CRunState::handleInput(CPlayer& player, CKeyBoard* input){
	if (input->KeyDown(DIK_RIGHT)) {
		if (player.getVelocity().x < 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));

		if (input->KeyDown(DIK_UP)){
			if (player.getVelocity().y < 0)
				player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
			return new CJumpState();
		}
		return this;
	}
	if (input->KeyDown(DIK_LEFT)) {
		if (player.getVelocity().x > 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));


		if (input->KeyDown(DIK_UP)){
			if (player.getVelocity().y < 0)
				player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
			return new CJumpState();
		}

		return this;
	}

	return new CStandState();
}

void CRunState::update(CPlayer& player, double deltaTime) {
	if (player.getPosition().x <= BACKBUFFER_WIDTH || player.getPosition().x >= 0)
		player.setPosition(vector3d(player.getPosition().x + player.getVelocity().x * deltaTime / 100, player.getPosition().y, 0));
}