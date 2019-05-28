#pragma once
#include "Sprite.h"
#include <SDL.h>

enum DIRECTION {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Cat : public Sprite {
private:
	bool m_bIsVulnerable = false, m_bIsDead = false, m_bIsMoving = false;
	int m_IDestinationX, m_IDestinationY;
	char dir;
	int m_iTargetX, m_iTargetY;
	const Level* m_level = Game::GetInstance()->GetLevel();
	const Player* m_pPlayer = Game::GetInstance()->GetPlayer();

public:
	Cat(SDL_Rect s, SDL_Rect d);

	bool isVulnerable();
	bool isDead();
	bool isMoving();
	char getDir();
	void setDir(char d);
	int GetX();
	int GetY();
	int GetDestinationX();
	int GetDestinationY();
	int GetTargetX();
	int GetTargetY();
	void SetTargetX(int x);
	void SetTargetY(int y);
	void SetDestinationX(int destX);
	void SetDestinationY(int destY);
	void SetMoving(bool b);
	void MoveX(int dir);
	void MoveY(int dir);

	void Seek();

	void SetVulnerable(bool b);
	void Die();
};