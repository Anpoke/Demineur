#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>

int main(int argc, char *argv[])

{

    SDL_Surface *ecran = NULL, *zozor = NULL;

    SDL_Rect positionZozor;
    positionZozor.x = 320;
    positionZozor.y = 240;

    SDL_Event event; /* La variable contenant l'événement */

    int continuer = 1; /* Notre booléen pour la boucle */


    SDL_Init(SDL_INIT_VIDEO);


    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);

    SDL_WM_SetCaption("Gestion des événements en SDL", NULL);

    zozor = SDL_LoadBMP("zozor.bmp");

	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));

    

    while (continuer)

{

    SDL_WaitEvent(&event);

    switch(event.type)

    {

        case SDL_QUIT:

            continuer = 0;

            break;

        case SDL_MOUSEBUTTONDOWN:

        	if (event.button.button == SDL_BUTTON_RIGHT)
        	{
        		continuer = 0;
        		break;
        	}

        	if (event.button.button == SDL_BUTTON_WHEELUP )
        	{
        		SDL_ShowCursor(SDL_DISABLE);
        		break;
        	}

        	if (event.button.button == SDL_BUTTON_WHEELDOWN )
        	{
        		SDL_ShowCursor(SDL_ENABLE);
        		break;
        	}

        	case SDL_MOUSEMOTION :
        	
            positionZozor.x = event.motion.x;
            positionZozor.y = event.motion.y;
			break;

			case SDL_VIDEORESIZE:

    			positionZozor.x = event.resize.w / 2 - zozor->w / 2;

    			positionZozor.y = event.resize.h / 2 - zozor->h / 2;

    		break;
        	

    }


    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor); /* On place Zozor à sa nouvelle position */

    SDL_Flip(ecran);

}


    SDL_Quit();


    return EXIT_SUCCESS;

}