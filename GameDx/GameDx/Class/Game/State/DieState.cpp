 #include "DieState.h"

CDieState::CDieState() {
}

CDieState::~CDieState() {

}

void CDieState::enter(CPlayer& player) {
	player.setVelocity(vector2d(VEL_PLAYER_X, VEL_PLAYER_Y));
	player.setState(PLAYERSTATES::DIE);
}

CBaseState* CDieState::handleInput(CPlayer& player, CKeyBoard* input){

	return nullptr;
}

void CDieState::update(CPlayer& player, double deltaTime) {
	if (player.getVelocity().y >= 0)
	{
		player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
	}

	player.setPosition(vector3d(player.getPosition().x, player.getPosition().y + player.getVelocity().y * deltaTime / 30, 0));
}