#ifndef WALL_H
#define WALL_H

//Inherited Class
#include "entity.h"

class Wall : public Entity
{
private:
		
public:
	Wall(float xPos, float yPos);
	~Wall();
};
#endif //WALL_H
