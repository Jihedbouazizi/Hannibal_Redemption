#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

int main()
{
    
    image img1;
    image img2;
    image img3;
    SDL_Surface *screen, *image;
    mouvement M;
    background b;
    int continuer = 1;
    Mix_Music *music;

    ////////////////////////////////////// musique continue/////////////////////////
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    music = Mix_LoadMUS("music.mp3");
    Mix_PlayMusic(music, -1);
    //////////////////////////////

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO); //// initialisation de SDL
    // SDL_WM_SetIcon(IMG_Load("icon.png"), NULL);/// image de l'icon
    screen = SDL_SetVideoMode(1200, 630, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); //// creation de fenetre
    SDL_WM_SetCaption("Hannibal Redemption", NULL);                          /// nom de fenetre

    init_Mouvement(&M); // appel fonction initialisation des deplacement
    initBack(&b);       // appel fonction initialisation de background 1 et 2
    Initanimation(screen, &img1, &img2, &img3);
    ///////////////////////////////////////////////// evenement////////////////////////////////////////
    SDL_Event event;
    SDL_EnableKeyRepeat(1, 0); // curseur continue
    while (continuer)
    {

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                break;

            case SDL_KEYDOWN:

                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;

                case SDLK_RIGHT:
                    M.right = 1;
                    break;

                case SDLK_LEFT:
                    M.left = 1;
                    break;
                case SDLK_DOWN:
                    M.down = 1;
                case SDLK_s:
                    M.s = 1;
                    break;
                case SDLK_UP:
                    M.up = 1;
                case SDLK_z:
                    M.z = 1;
                    break;
                case SDLK_d:
                    M.d = 1;
                    break;

                case SDLK_q:
                    M.q = 1;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                case SDLK_RIGHT:
                    M.right = 0;
                    break;

                case SDLK_LEFT:
                    M.left = 0;
                    break;

                case SDLK_d:
                    M.d = 0;
                    break;

                case SDLK_q:
                    M.q = 0;
                    break;

                case SDLK_UP:
                    M.up = 0;
                    break;

                case SDLK_z:
                    M.z = 0;
                    break;

                case SDLK_s:
                    M.s = 0;
                    break;

                case SDLK_DOWN:
                    M.down = 0;
                    break;
                }

                break;
            }
            //////////////////////////////////////////////////////////////////

            //////////////////////////// appele fonction scrolling //////////////////////////
            scrolling_right(&b, 5, screen, M);
            scrolling_right_partage(&b, 5, screen, M);

            scrolling_left(&b, 5, screen, M);
            scrolling_left_partage(&b, 5, screen, M);

            scrolling_down(&b, 3, screen, M);
            scrolling_down_partage(&b, 3, screen, M);

            scrolling_up(&b, 3, screen, M);
            scrolling_up_partage(&b, 3, screen, M);
            ////////////////////
        }
        // changement_imagebg(&b);

        aficherBack(screen, &b);         /// appel fonction affichage back 1
        aficherBack_partage(screen, &b); /// appel fonction affichage back 2 avec partage d'ecran
        SDL_Flip(screen);                // mise a jour de l'ecran
                                         // afficher_bg(b,screen);
        // Initanimation(screen);
        afficherimage(screen, &img1, &img2, &img3);
        detect(&b,screen);
    }

    SDL_FreeSurface(screen);
    SDL_FreeSurface(image);
    Mix_FreeMusic(music);
    SDL_Quit();
    return 0;
}
