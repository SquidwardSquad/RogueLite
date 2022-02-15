#ifndef WALL_H
#define WALL_H

#include "entity.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Wall : public Entity
{
private:
		
public:
	Wall(float xPos, float yPos);
	~Wall();
	
};
#endif
