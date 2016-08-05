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

}