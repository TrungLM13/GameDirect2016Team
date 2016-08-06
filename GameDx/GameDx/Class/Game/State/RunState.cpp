#include "RunState.h"
#include "StandState.h"

CRunState::CRunState() {
	m_IsShoot = false;
	m_MoveDirection = 0;
}

CRunState::~CRunState() {

}

void CRunState::enter(CPlayer& player) {
	if (m_IsShoot) {
		player.setState(PLAYERSTATES::MOVE_SHOOT);
	}
	else {
		player.setState(PLAYERSTATES::RUN);
	}
}

CBaseState* CRunState::handleInput(CPlayer& player, CKeyBoard* input){
	if (input->KeyDown(DIK_RIGHT)) {
		m_MoveDirection = DIRECTION::DIRECTION_RIGHT;
		player.setVelocity(vector2d(9.8 * m_MoveDirection, player.getVelocity().y));

		if (player.getVelocity().x <= 0)
		{
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));
		}

		if (input->KeyDown(DIK_UP) || input->KeyDown(DIK_SPACE)){
			if (player.getVelocity().y < 0)
				player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
			return new CJumpState();
		}

		if (input->KeyDown(DIK_P)){
			m_IsShoot = true;
		}
		else
			m_IsShoot = false;

		return this;
	}
	if (input->KeyDown(DIK_LEFT)) {
		m_MoveDirection = DIRECTION::DIRECTION_LEFT;
		player.setVelocity(vector2d(9.8 * m_MoveDirection, player.getVelocity().y));

		if (player.getVelocity().x >= 0)
			player.setVelocity(vector2d(player.getVelocity().x * (-1), player.getVelocity().y));


		if (input->KeyDown(DIK_UP)){
			if (player.getVelocity().y < 0)
				player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
			return new CJumpState();
		}

		if (input->KeyDown(DIK_SPACE)){
			if (player.getVelocity().y < 0)
				player.setVelocity(vector2d(player.getVelocity().x, player.getVelocity().y * (-1)));
			return new CJumpState();
		}

		if (input->KeyDown(DIK_P)){
			m_IsShoot = true;
		}
		else
			m_IsShoot = false;

		return this;
	}

	return new CStandState();
}

void CRunState::update(CPlayer& player, double deltaTime) {
	if (!player.m_IsCollision) {
		player.setPosition(vector3d(player.getPosition().x + player.getVelocity().x * deltaTime / 100, player.getPosition().y, 0));
	}
}

int  CRunState::getMoveDirection() {
	return m_MoveDirection;
}

void CRunState::setMoveDirection(DIRECTION direction) {
	m_MoveDirection = direction;
}
