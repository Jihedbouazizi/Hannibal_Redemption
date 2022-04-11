
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include "perso.h"



int main()
{	 
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	SDL_Surface *screen,*bg,*timer;
  	SDL_Rect postimer;
	bg=IMG_Load("photos/wallpaperflare.com_wallpaper.jpg");
	postimer.x=10;
	postimer.y=10;
	SDL_Event event;
	perso p;
	Vie V;
  	minimap m;
	Score S;
	int collision, gameover;
	int quit=0;
	int Jump = 0;
	screen = SDL_SetVideoMode( 1200, 630, 32, SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF);
    init(&p);
	initVie(&V);
	initScore(&S);
	initmap (&m);
	TTF_Font *font=TTF_OpenFont("souls_font.ttf",90);
	SDL_Color white={0,0,0};
  	char ch[10];
  	Uint32 start;
  	int time;
    start=SDL_GetTicks();
	//Game loop
	while(quit == 0)
  	{ 
  		
		
		
   		SDL_BlitSurface(bg,NULL,screen,NULL);
		displaytime(&time);
  		sprintf(ch,"%d",time-((int)start/1000));
  		timer=TTF_RenderText_Blended(font,ch,white);
   		SDL_BlitSurface(timer,NULL,screen,&postimer);
  		m.posminimc=MAJminimap(p,&m,20);
   		displaymap(m,screen);
		afficherPerso(p,screen);
  		
  		
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
      		{				
				case SDL_QUIT:
        		{
         			quit = 1;
				}
				break;
				//Running right
				case SDL_KEYDOWN:
    			if(event.key.keysym.sym == SDLK_RIGHT)
				{
              		p.Signal = 1;
              		p.direction = 1;
            	}
				//Running left
    			if(event.key.keysym.sym == SDLK_LEFT)
				{
                	p.Signalb = 1;
                	p.direction = -1;
            	}
				//Jumping
            	if(event.key.keysym.sym == SDLK_UP)
				{
            		p.isJump = 1;
            	}
    			break;

    			case SDL_KEYUP:
    		
    			if(event.key.keysym.sym == SDLK_RIGHT)
            		p.Signal = 0;
            	if(event.key.keysym.sym == SDLK_LEFT)
              		p.Signalb = 0;
            	if(event.key.keysym.sym == SDLK_UP)
				{
              		Jump = 0;
            	}
    		    break;
				default:
				break;
			}
		}
		
      saut(&p);
      deplacerPerso(&p);
      animerPerso(&p);
      Changement_vie(collision, &gameover, &V, screen);
	  afficherScore(&S, collision, screen);
      	if (p.frame1 == 10)
		{
        	p.frame1 = 0;
		}
		//Run backwards animation reset
		if (p.frame2 == 0)
        {
			p.frame2 = 10;
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
      	SDL_Delay(10);
    	
	}
    //outside of the menu cycle
    SDL_FreeSurface(p.sprite);
	SDL_FreeSurface(bg);
  	freeminimap(&m);
    SDL_Quit();
    return EXIT_SUCCESS;
}
