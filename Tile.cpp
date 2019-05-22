#include "Tile.h"

Tile::Tile() {}
Tile::Tile(SDL_Rect s, SDL_Rect d) {
	m_rSrc = s;
	m_rDst = d;
}
bool Tile::isObstacle() { return m_bIsObstacle; }
bool Tile::isPoint() { return m_bIsPoint; }
bool Tile::isPowerUp() { return m_bIsPowerUp; }
bool Tile::isIntersection() { return m_bIsIntersection; }

void Tile::SetTileVariables(char c) {
	if (c == 'B') { // Black Tile
		m_bIsObstacle = false;
		m_bIsPoint = false;
		m_bIsPowerUp = false;
		m_bIsIntersection = false;
	}
	else if (c == 'A') { // Blue Tile
		m_bIsObstacle = true;
		m_bIsPoint = false;
		m_bIsPowerUp = false;
		m_bIsIntersection = false;
	}
	else if (c == 'P') { // Point Tile
		m_bIsObstacle = false;
		m_bIsPoint = true;
		m_bIsPowerUp = false;
		m_bIsIntersection = false;
	}
	else if (c == 'O') { // Power Up Tile
		m_bIsObstacle = false;
		m_bIsPoint = false;
		m_bIsPowerUp = true;
		m_bIsIntersection = false;
	}
	else if (c == 'I') {//Intersection with a point
		m_bIsObstacle = false;
		m_bIsPoint = true;
		m_bIsPowerUp = false;
		m_bIsIntersection = true;
	}
	else if (c == 'i') {//blank intersection
		m_bIsObstacle = false;
		m_bIsPoint = false;
		m_bIsPowerUp = false;
		m_bIsIntersection = true;
	}
}