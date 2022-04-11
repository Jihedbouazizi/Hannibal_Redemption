
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "score.h"
#include "minimap.h"

int main(int argc, char** argv)
{
  SDL_Surface *screen,*bg,*timer;
  SDL_Rect postimer;
bg=IMG_Load("bg.png");
  postimer.x=10;
  postimer.y=10;
  screen = SDL_SetVideoMode( 1200, 630, 32, SDL_HWSURFACE); //| SDL_FULLSCREEN);
  SDL_Event event;
  int quit=0;
perso p;
  minimap m;
  initmap (&m);
  TTF_Init();
	TTF_Font *font=TTF_OpenFont("souls_font.ttf",90);
	SDL_Color white={0,0,0};
  char ch[10];
  	Uint32 start;
  	int time;
   start=SDL_GetTicks();
  while (quit==0)
  {SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );


  		displaytime(&time);
  		sprintf(ch,"%d",time-((int)start/1000));
  		timer=TTF_RenderText_Blended(font,ch,white);
    SDL_BlitSurface(timer,NULL,screen,&postimer);
   m.posminimc=MAJminimap(p,&m,20);
    SDL_BlitSurface(bg,NULL,screen,NULL);
    displaymap(m,screen);

    while( SDL_PollEvent( &event ) )
        {
            switch(event.type)
            {
              case SDL_QUIT:
              quit=1;
              break;
              case SDL_KEYDOWN:
              if(event.key.keysym.sym == SDLK_ESCAPE)
              {
                quit=1;
              }
              
            }
        }
   
    SDL_Flip(screen);
  }
  SDL_FreeSurface(bg);
  freeminimap(&m);
  SDL_Quit;
  return 0;
}
