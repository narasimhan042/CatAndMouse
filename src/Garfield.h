#pragma once
#include "Cat.h"

class Garfield : public Cat
{
private:
	int PRIORITY[4];
	
public :
	void setPriority(int first, int second, int third, int forth)
	{
		PRIORITY[0] = first;
		PRIORITY[1] = second;
		PRIORITY[2] = third;
		PRIORITY[3] = forth;
	}

	void Seek();

};