#include "imageManagement.h"


bool ImageManagement::loadImage(char imgName[50])
{
	SDL_Surface* imgTitle = SDL_LoadBMP(imgName);
    if (!imgTitle)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return false;
    }
	return true;
}

void ImageManagement::drawImage(SDL_Surface *imgTitle, const SDL_Rect *srcrect, SDL_Surface *screen, SDL_Rect dstrect)
{
	SDL_BlitSurface(imgTitle, 0, screen, &dstrect);
}