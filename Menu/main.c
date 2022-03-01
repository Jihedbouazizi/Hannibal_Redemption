
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_timer.h>
#include <SDL/SDL_mixer.h>
#include "background.h"
#include "text.h"

int main()
{
    //Inisialisation de SDL
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);

    //Declaration des variables
    SDL_Surface *screen;
    int kd=0;
    int done=0;
    int backto=0;
    int niveau, i, volume;
    Image Backg;
    Bouton b[9];
    Animation A;
    SDL_Event event;
    
    Text tm, ts;
    atexit(SDL_Quit);

    if (Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) ==-1)
        {
           printf ("Error: %s\n", Mix_GetError ());
        }

    Mix_Chunk *loading, *click;
    volume=MIX_MAX_VOLUME;
    loading = Mix_LoadWAV ("Sounds/Loading.wav");
    click = Mix_LoadWAV ("Sounds/btnsnd.wav");

    Mix_VolumeChunk(loading, volume);

    screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE|SDL_DOUBLEBUF|SDL_RESIZABLE);
    if(!screen)
    {
        printf("Unable de set 600x300 video: %s\n", SDL_GetError());
    }
    
    //Inisialisation des images & textes
    initBack(&Backg);
    initImages(b);
    initMainText(&tm);
    initSecondText(&ts);
    //Initanimation(&A);
    
      
  //Boucle de jeu
    while(!done)
    {

        Mix_PlayChannel (-1, loading, 0);  
       //afficheranimation(A, screen);
        afficherBackg(Backg, screen); 
        afficherbutton(b, Backg.niveau, screen);
        if(Backg.niveau==1)
        {
        displayMainText(tm, screen);
        displaySecondText(ts, screen);
        }
        SDL_Flip(screen);
        while(SDL_PollEvent(&event))
        {

             switch(event.type)
             {
               case SDL_QUIT:
                    done=1;
               break;

               case SDL_KEYDOWN:
	               	if((Backg.niveau==1)&&(event.key.keysym.sym == SDLK_ESCAPE))
                   {
	              	  done = 1;
                   }

                  //ESCAPE pour le retour au menu (Start)
                  if((Backg.niveau==4)&&(event.key.keysym.sym == SDLK_ESCAPE))
                   {
	              	  Backg.niveau=1;
                   }

                  //ESCAPE pour le retour au menu (settings)
                  if((Backg.niveau==2)&&(event.key.keysym.sym == SDLK_ESCAPE))
                   {
	              	  Backg.niveau=1;
                   }
                  //ESCAPE pour le retour au menu (Credits)
                  if((Backg.niveau==3)&&(event.key.keysym.sym == SDLK_ESCAPE))
                   {
	              	  Backg.niveau=1;
                   }
                  //F Fullscreen
                  if((Backg.niveau==2)&&(event.key.keysym.sym == SDLK_f))
                  {
                    SDL_WM_ToggleFullScreen(screen);
                  }
                  //S settings menu
                  if((Backg.niveau==1)&&(event.key.keysym.sym == SDLK_s))
                  {
                    Backg.niveau=2;
                  }
                  //P pour jouer
                  if((Backg.niveau==1)&&(event.key.keysym.sym == SDLK_p))
                  {
                    Backg.niveau=4;
                  }
                  //C pour Credits
                  if((Backg.niveau==1)&&(event.key.keysym.sym == SDLK_c))
                  {
                    Backg.niveau=3;
                  }
                  //Pour modifier
                  if(((event.key.keysym.sym == SDLK_DOWN)||(event.key.keysym.sym == SDLK_UP))&&(kd==0))
                  {
                    if(event.key.keysym.sym == SDLK_DOWN)
                    { 
                      b[0].actif = 1;
                      kd++;
                    }
                    else
                    if(event.key.keysym.sym == SDLK_UP)
                    {
                      kd=3;
                      b[3].actif = 1;
                      b[0].actif = 0;
                    }
                  }
                  else 
                  if(((event.key.keysym.sym == SDLK_DOWN)||(event.key.keysym.sym == SDLK_UP))&&(kd==1))
                  {
                    if(event.key.keysym.sym == SDLK_DOWN)
                    {
                      b[1].actif = 1;
                      kd++;
                    }
                    else
                    if(event.key.keysym.sym == SDLK_UP)
                    {
                      b[1].actif = 0;
                      b[0].actif = 1;
                    }
                  }
                  else
                  if(((event.key.keysym.sym == SDLK_DOWN)||(event.key.keysym.sym == SDLK_UP))&&(kd==2))
                  {
                    if(event.key.keysym.sym == SDLK_DOWN)
                    {
                      b[1].actif = 0;
                      b[2].actif = 1;
                      kd++;
                    } 
                    else
                    if(event.key.keysym.sym == SDLK_UP)
                    {
                      b[1].actif = 1;
                      b[2].actif = 0;
                    }
                  }
                  else
                  if(((event.key.keysym.sym == SDLK_DOWN)||(event.key.keysym.sym == SDLK_UP))&&(kd==3))
                  {
                    if(event.key.keysym.sym == SDLK_DOWN)
                    {
                    b[2].actif = 0;
                    b[3].actif = 1;
                    kd++;
                    }
                    else
                    if(event.key.keysym.sym == SDLK_UP)
                    {
                      b[2].actif = 1;
                      b[3].actif = 0;
                    }
                  }
                  else
                  if(kd==4)
                  {
                    b[3].actif = 0;
                    kd=0;
                  }
                    //////////////////////////////////////
		           break;

               //Pour le movement de souris
               case SDL_MOUSEMOTION:

               //2eme button de start
               if((Backg.niveau==1)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=174 && event.motion.y<=247))
                  {
                    b[0].actif=1;
                  }
               else
                  {
                    b[0].actif=0;
                  }

               //2eme button de Settings
               if((Backg.niveau==1)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=264 && event.motion.y<=337))
                  {
                    b[1].actif=1;
                  }
                  else
                  {
                    b[1].actif=0;
                  }

               //2eme button de Credits
               if((Backg.niveau==1)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=354 && event.motion.y<=427))
                  {
                    b[2].actif=1;
                  }
               else
                  {
                    b[2].actif=0;
                  }

               //2eme button de Exit
               if((Backg.niveau==1)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=444 && event.motion.y<=517))
                  {
                    b[3].actif=1;
                  }
               else
                  {
                    b[3].actif=0;
                  }
               break;

               //Pour click de souris
               case SDL_MOUSEBUTTONDOWN:

               //Click sur le button Start
               if((Backg.niveau==1)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=174 && event.motion.y<=247))
                {
                  Mix_PlayChannel (1, click, 0);
                  Backg.niveau=4;
                }

               //Click sur le button Exit
               if ((Backg.niveau==1)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 106 && event.button.x <= 391) && (event.button.y >= 444 && event.button.y <= 517))
                {
                  Mix_PlayChannel (1, click, 0);
                  done=1;
                }

               //Click sur le Settings button
               if ((Backg.niveau==1)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 106 && event.button.x <= 391) && (event.button.y >= 264 && event.button.y <= 337))
                {
                  Mix_PlayChannel (1, click, 0);
                  Backg.niveau=2;
                  b[4].actif=0;
                  b[5].actif=0;
                  b[6].actif=0;
                  b[7].actif=0;
                  b[8].actif=0; 
                } 

                //Click sur Fullscreen
                if ((Backg.niveau==2)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 527 && event.button.x <= 812) && (event.button.y >= 324 && event.button.y <= 397))
                     {
                       Mix_PlayChannel (1, click, 0);
                       SDL_WM_ToggleFullScreen(screen);
                     } 

                //Click sur plus
                if ((Backg.niveau==2)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 490 && event.button.x <= 549) && (event.button.y >= 257 && event.button.y <= 315))
                     {
                       Mix_PlayChannel (1, click, 0);
                       if(volume<128)
                       volume+=15;
                       Mix_VolumeChunk(loading ,volume);
                     }

                //Click sur minus
                if ((Backg.niveau==2)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 689 && event.button.x <= 747) && (event.button.y >= 257 && event.button.y <= 315))
                     {
                       Mix_PlayChannel (1, click, 0);
                       if(volume>0)
                       volume-=15;
                       Mix_VolumeChunk(loading, volume);
                     }
                //Click sur le Credits button 
                if ((Backg.niveau==1)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 159 && event.button.x <= 521) && (event.button.y >= 339 && event.button.y <= 483))
                {
                  Mix_PlayChannel (1, click, 0);
                  Backg.niveau=3;
                  b[9].actif=0;
                }

                //Click sur le Back to menu button de settings 
                if ((Backg.niveau==2)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 421 && event.button.x <= 783) && (event.button.y >= 385 && event.button.y <= 498))
                 {
                   Mix_PlayChannel (1, click, 0);
                   Backg.niveau=1;
                 }       
                
                 //Click sur le Back to menu button du credits 
                 if ((Backg.niveau==3)&&(event.button.button == SDL_BUTTON_LEFT) && (event.button.x >= 518 && event.button.x <= 803) && (event.button.y >= 488 && event.button.y <= 561))
                  {
                  Mix_PlayChannel (1, click, 0);
                  Backg.niveau=1;
                  }   
                
              break;
             }
        }
    }
    Mix_FreeChunk(loading);
    Mix_FreeChunk(click);
    librer(Backg, b);
    freeMainText(tm);
    freeSecondText(ts);
    TTF_CloseFont(ts.font);
    TTF_CloseFont(tm.font);
    TTF_Quit();
    return 0;
    
}
