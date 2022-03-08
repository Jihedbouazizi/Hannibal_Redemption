#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Personnage.h"



int main()
{	 
	SDL_Init(SDL_INIT_VIDEO);
    
    SDL_Surface *screen;
	SDL_Event event;
	person p;
	int done=0;
	int Jump = 0;
    float direction=0; 
	int att=0; 
	screen = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_RESIZABLE);
    initperson(&p);

	while(!done)
  	{ 
  		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
  		afficherPerso(p,screen);
		
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
      		{				
				case SDL_QUIT:
        		{
         				done = 1;
				}
				break;
				case SDL_KEYDOWN:
				//Right attack
				if(event.key.keysym.sym == SDLK_a)
                {
                    direction = 2;
    		    }
				//Run right
    		    if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    direction = 1;
    		    }
				//Run left
    		    if(event.key.keysym.sym == SDLK_LEFT)
                {
                    direction = -1;
                }
				//Jumping
				if(event.key.keysym.sym == SDLK_UP)
				{
            		p.jump = 1;
				}
            

    		    break;
    		    case SDL_KEYUP:
    		
    		    if(event.key.keysym.sym == SDLK_RIGHT)
                {
					direction = 0;
				}
				if(event.key.keysym.sym == SDLK_LEFT)
                {
					direction = 0;
				}
				if(event.key.keysym.sym == SDLK_a)
                {
                    direction = 0;
    		    }
				if(event.key.keysym.sym == SDLK_UP)
              	{
				  	p.jump = 0;
				}
                break;
            }
		}
		deplacerPerso (&p, direction);
		animerPerson(&p);
		//saut(&p);
    	//Run straight animation rest
		if (p.frame1 == 10)
		{
        	p.frame1 = 0;
		}
		//Run backwards animation reset
		if (p.frame2 == 10)
        {
			p.frame2 = 0;
		}
		//Idle reset
		if (p.frame3 == 8)
		{
        	p.frame3 = 0;
		}
		//Attack reset
		if (p.frame4 == 6)
		{
        	p.frame4 = 0;
		}
        SDL_Flip(screen);
		

    }
        
            
  

    librer(p);

    SDL_Quit();
    return EXIT_SUCCESS;
}
