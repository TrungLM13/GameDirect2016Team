#include "RunState.h"
#include "StandState.h"

CRunState::CRunState() {
	m_IsShoot = false;
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
	if (player.m_IsAutoMove == false){
		if (input->KeyDown(DIK_RIGHT)) {
			player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X) = DIRECTION::DIRECTION_RIGHT;
			player.setVelocity(vector2d(9.8 * player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X), player.getVelocity().y));

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
			player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X) = DIRECTION::DIRECTION_LEFT;
			player.setVelocity(vector2d(9.8 * player.m_Direction.at(DIRECTIONINDEX::DIRECTION_X), player.getVelocity().y));

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
	else
		return this;
}

void CRunState::update(CPlayer& player, double deltaTime) {
	if (!player.m_IsCollision) {
		player.setPosition(vector3d(player.getPosition().x + player.getVelocity().x * deltaTime / 100, player.getPosition().y, 0));
	}

	if (player.m_IsAutoMove) {
		// If position x of player at the castle (350), stop running auto
		if (player.getPosition().x > 350) {
			player.m_IsAutoMove = false;
		}
		player.setPosition(vector3d(player.getPosition().x + player.getVelocity().x * deltaTime / 1000, player.getPosition().y, 0));
	}
}
