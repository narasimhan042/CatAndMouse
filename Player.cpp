#include "Player.h"

Player::Player(SDL_Rect s, SDL_Rect d) {
	m_rSrc = s;
	m_rDst = d;
	center.x = center.y = 16;
	angle = 0;
	frame = 0;
}

bool Player::isMoving() { return m_bIsMoving; }
bool Player::isPoweredUp() { return m_bIsPoweredUp; }
bool Player::isDead() { return m_bIsDead; }

int Player::GetX() { return m_rDst.x / 32; }
int Player::GetY() { return m_rDst.y / 32; }

int Player::GetDestinationX() { return m_IDestinationX; }
int Player::GetDestinationY() { return m_IDestinationY; }
void Player::SetDestinationX(int destX) { m_IDestinationX = destX; }
void Player::SetDestinationY(int destY) { m_IDestinationY = destY; }
void Player::SetMoving(bool b) { m_bIsMoving = b; }
void Player::SetPowered(bool b) { m_bIsPoweredUp = b; }

// new animation function for mouse
void Player::animate()
{
	if (frame < 2)
	{
		frame++;
		m_rSrc.x = frame*m_rSrc.w;
	}
	else
	{
		frame = 0;
	}
}

void Player::MoveX(int dir) {
	m_rDst.x += m_IMoveSpeed * dir;
}

void Player::MoveY(int dir) {
	m_rDst.y += m_IMoveSpeed * dir;
}

void Player::Die() {
	m_bIsDead = true;
	m_rSrc = {};
}