#ifndef MAP2_H
#define MAP2_H
#include <SDL.h>

class Map2
{
public:
	Map2();
	~Map2();
	
	void Draw(SDL_Surface* image, char mapLayer, SDL_Surface* sc);
	void Draw2(SDL_Surface* image, SDL_Surface* sc);
	
private:
	
	
	
};

#endif // !MAP2