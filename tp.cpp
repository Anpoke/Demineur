#include <stdlib.h>

#include <stdio.h>

#include <SDL/SDL.h>




void pause();


    int main(int argc, char *argv[])

{

    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *zozor = NULL;

    SDL_Rect positionFond, positionZozor;


    positionFond.x = 0;
    positionFond.y = 0;
    positionZozor.x = 500;
    positionZozor.y = 260;


    SDL_Init(SDL_INIT_VIDEO);


    SDL_WM_SetIcon(SDL_LoadBMP("index.bmp"), NULL);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);

    SDL_WM_SetCaption("DEMINEUR", NULL);

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 102, 51, 0));

    /* Chargement d'une image Bitmap dans une surface */
	imageDeFond = SDL_LoadBMP("lac_en_montagne.bmp");
	/* On blitte par-dessus l'écran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

    zozor = SDL_LoadBMP("zozor.bmp");
    /* On rend le bleu derrière Zozor transparent : */
	SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));
	/* Transparence Alpha moyenne (128) : */
	SDL_SetAlpha(zozor, SDL_SRCALPHA, 128);
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);


    SDL_Flip(ecran);

    pause();


    SDL_FreeSurface(imageDeFond); /* On libère la surface */
    SDL_FreeSurface(zozor);

    SDL_Quit();


    return EXIT_SUCCESS;

}


 

void pause()

{

    int continuer = 1;

    SDL_Event event;

 

    while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

        }

    }

}