#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *grille = NULL;

	SDL_Rect positionGrille;
	positionGrille.x = 0;
    positionGrille.y = 0;

	SDL_Event event;

	int continuer = 1;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_WM_SetIcon(SDL_LoadBMP("index.bmp"), NULL);

	ecran = SDL_SetVideoMode(1200, 825, 32, SDL_HWSURFACE);

	SDL_WM_SetCaption("DEMINEUR", NULL);

	grille = SDL_LoadBMP("BG2.bmp");

	while(continuer)
	{


		SDL_WaitEvent(&event);

    switch(event.type)

    {

    	case SDL_QUIT:

            continuer = 0;

            break;

            case SDL_KEYDOWN:

        	switch(event.key.keysym.sym)
        	{
        		case SDLK_ESCAPE:
        			continuer = 0;
        			break;
        	}

        	case SDL_MOUSEBUTTONUP:

        	if (0 <= event.motion.x <= 1200 && 0 <= event.motion.y <= 825 && event.button.button == SDL_BUTTON_LEFT)
        	{
        		continuer = 0;
        		break;
        	}

    }

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

    SDL_BlitSurface(grille, NULL, ecran, &positionGrille);

    SDL_Flip(ecran);

}


    SDL_Quit();


    return EXIT_SUCCESS;

}
