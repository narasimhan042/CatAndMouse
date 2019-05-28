#include "Cat.h"
#include "Game.h"

Cat::Cat(SDL_Rect s, SDL_Rect d) {
	m_rSrc = s;
	m_rDst = d;
	dir = RIGHT;
}

bool Cat::isVulnerable() { return m_bIsVulnerable; }
bool Cat::isDead() { return m_bIsDead; }

char Cat::getDir() { return dir; }

void Cat::setDir(char d) { dir = d; }

int Cat::GetX() { return m_rDst.x / 32; }

int Cat::GetY() { return m_rDst.y / 32; }

int Cat::GetDestinationX() { return m_IDestinationX; }

int Cat::GetDestinationY() { return m_IDestinationY; }

int Cat::GetTargetX() { return 0; }

int Cat::GetTargetY() { return 0; }

void Cat::SetTargetX(int x) { m_iTargetX = x; }

void Cat::SetTargetY(int y) { m_iTargetY = y; }

void Cat::SetDestinationX(int destX) { m_IDestinationX = destX; }

void Cat::SetDestinationY(int destY) { m_IDestinationY = destY; }

void Cat::SetMoving(bool b) { m_bIsMoving = b; }

void Cat::MoveX(int dir) { m_rDst.x += dir; }

void Cat::MoveY(int dir) { m_rDst.y += dir; }

void Cat::Seek()
{
	int distance = 99999;
	int temp = 0;
	// Check if the square cat is on is an intersection
	if (m_level->m_Map[this->GetY()][this->GetX()].isIntersection())
	{
		// if north is not an obstacle and if the direction is the opposite of the checking direction to prevent U-turn
		if (!m_level->m_Map[this->GetY() - 1][this->GetX()].isObstacle() && this->getDir() != DOWN)
		{
			temp = 0;// reseting and checking the distance
			temp += (m_pPlayer->GetX() - this->GetX())*(m_pPlayer->GetX() - this->GetX());
			temp += (m_pPlayer->GetY() - (this->GetY() - 1))*(m_pPlayer->GetY() - (this->GetY() - 1));
			if (distance >= temp)
			{
				distance = temp;
				this->setDir(UP);
			}
		}
		// if east is not an obstacle and if the direction is the opposite of the checking direction to prevent U-turn
		if (!m_level->m_Map[this->GetY()][this->GetX() + 1].isObstacle() && this->getDir() != LEFT)
		{
			temp = 0;
			temp += (m_pPlayer->GetX() - (this->GetX() + 1))*(m_pPlayer->GetX() - (this->GetX() + 1));
			temp += (m_pPlayer->GetY() - this->GetY())*(m_pPlayer->GetY() - this->GetY());
			if (distance >= temp)
			{
				distance = temp;
				this->setDir(RIGHT);
			}
		}
		// if south is not an obstacle and if the direction is the opposite of the checking direction to prevent U-turn
		if (!m_level->m_Map[this->GetY() + 1][this->GetX()].isObstacle() && this->getDir() != UP)
		{
			temp = 0;
			temp += (m_pPlayer->GetX() - this->GetX())*(m_pPlayer->GetX() - this->GetX());
			temp += (m_pPlayer->GetY() - (this->GetY() + 1))*(m_pPlayer->GetY() - (this->GetY() + 1));
			if (distance >= temp)
			{
				distance = temp;
				this->setDir(DOWN);
			}
		}
		// if west is not an obstacle and if the direction is the opposite of the checking direction to prevent U-turn
		if (!m_level->m_Map[this->GetY()][this->GetX() - 1].isObstacle() && this->getDir() != RIGHT)
		{
			temp = 0;
			temp += (m_pPlayer->GetX() - (this->GetX() - 1))*(m_pPlayer->GetX() - (this->GetX() - 1));
			temp += (m_pPlayer->GetY() - this->GetY())*(m_pPlayer->GetY() - this->GetY());
			if (distance >= temp)
			{
				distance = temp;
				this->setDir(LEFT);
			}
		}
	}
	// if not moving then move in a direction
	if (!this->isDead() && !this->isMoving()) {
		if (this->getDir() == UP) {
			// If not an obstacle then sets the new destination square
			if (!m_level->m_Map[this->GetY() - 1][this->GetX()].isObstacle()) {
				this->SetDestinationY(this->GetDst().y - 32);
				this->SetDestinationX(this->GetDst().x);
				this->SetMoving(true);
			}
			else // if Obstacle it will check for another route
			{
				if (!m_level->m_Map[this->GetY()][this->GetX() + 1].isObstacle())
				{
					this->setDir(RIGHT);
				}
				else if (!m_level->m_Map[this->GetY()][this->GetX() - 1].isObstacle())
				{
					this->setDir(LEFT);
				}
				else
				{
					this->setDir(DOWN);
				}
			}
		}
		else if (this->getDir() == DOWN) {
			if (!m_level->m_Map[this->GetY() + 1][this->GetX()].isObstacle()) {
				this->SetDestinationY(this->GetDst().y + 32);
				this->SetDestinationX(this->GetDst().x);
				this->SetMoving(true);
			}
			else
			{
				if (!m_level->m_Map[this->GetY()][this->GetX() - 1].isObstacle())
				{
					this->setDir(LEFT);
				}
				else if (!m_level->m_Map[this->GetY()][this->GetX() + 1].isObstacle())
				{
					this->setDir(RIGHT);
				}
				else
				{
					this->setDir(UP);
				}
			}
		}
		else if (this->getDir() == LEFT) {
			if (!m_level->m_Map[this->GetY()][this->GetX() - 1].isObstacle())
			{
				this->SetDestinationX(this->GetDst().x - 32);
				this->SetDestinationY(this->GetDst().y);
				this->SetMoving(true);
			}
			else
			{
				if (!m_level->m_Map[this->GetY() - 1][this->GetX()].isObstacle())
				{
					this->setDir(UP);
				}
				else if (!m_level->m_Map[this->GetY() + 1][this->GetX()].isObstacle())
				{
					this->setDir(DOWN);
				}
				else
				{
					this->setDir(RIGHT);
				}
			}
		}
		else if (this->getDir() == RIGHT) {
			if (!m_level->m_Map[this->GetY()][this->GetX() + 1].isObstacle()) {
				this->SetDestinationX(this->GetDst().x + 32);
				this->SetDestinationY(this->GetDst().y);
				this->SetMoving(true);
			}
			else
			{
				if (!m_level->m_Map[this->GetY() - 1][this->GetX()].isObstacle())
				{
					this->setDir(UP);
				}
				else if (!m_level->m_Map[this->GetY() + 1][this->GetX()].isObstacle())
				{
					this->setDir(DOWN);
				}
				else
				{
					this->setDir(LEFT);
				}
			}
		}
	}
	// if moving continue moving till
	if (this->isMoving()) {
		if (this->GetDestinationX() > this->GetDst().x) {
			this->MoveX(1);
		}
		else if (this->GetDestinationX() < this->GetDst().x) {
			this->MoveX(-1);
		}
		else if (this->GetDestinationY() > this->GetDst().y) {
			this->MoveY(1);
		}
		else if (this->GetDestinationY() < this->GetDst().y) {
			this->MoveY(-1);
		}
		// if cat has gotten to destination then set moving to false
		else if (this->GetDestinationX() == this->GetDst().x && this->GetDestinationY() == this->GetDst().y) {
			this->SetMoving(false);
		}
	}
}

bool Cat::isMoving() { return m_bIsMoving; }

void Cat::SetVulnerable(bool b)
{
	if (b) {
		m_bIsVulnerable = true;
		if (!m_bIsDead) {
			m_rSrc = { 128, 0, 32, 32 };
		}
	}
	else {
		m_bIsVulnerable = false;
	}
}

void Cat::Die() {
	m_bIsDead = true;
	m_rSrc = {};
}