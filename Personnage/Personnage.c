#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Personnage.h"



void initperson(person *p)
{
    p->sprite= IMG_Load("photos/finalfinal.png");
    
    p->posperso.x=200; 
    p->posperso.y=400;

    p->possprite.x=0;
    p->possprite.y=0;
    p->possprite.h=100; 
    p->possprite.w=182;

    p->score=0;
    p->nbrvie=3;
    p->direction=0; 

    p->frame1=1; //right
    p->frame2=1; //left
    p->frame3=1; //idle
    p->frame4=1; //attack
    p->jump;
}

void afficherPerso(person p,SDL_Surface* screen)
{
	SDL_BlitSurface(p.sprite,&(p.possprite),screen,&(p.posperso));
}

void deplacerPerso (person *p, float dt)
{   
    p->direction=dt;
    //Standing
    if(dt==0)
    {
        p->posperso.x=p->posperso.x;
    }
    //Moving right
    if(dt==1)
    {
        p->posperso.x+=5;
    }
    //Moving left
    if(dt==-1)
    {
        p->posperso.x-=5;
    }

    

}

void animerPerson(person *p)
{   
    
    //Run straight animation
	if(p->direction == 1)
    {	
		p->possprite.x=(p->frame1)*182;
		p->possprite.y=0;
		p->possprite.h=100;
		p->possprite.w=182;
		p->frame1++;
        SDL_Delay(35);
	}

    //Run backwards animation
    if(p->direction == -1)
    {
		p->possprite.x=(p->frame2)*182;
		p->possprite.y=600;
		p->possprite.h=100;
		p->possprite.w=182;
		p->frame2++;
        SDL_Delay(35);
	}

    //animation idle
    if(p->direction == 0)
    {	
		p->possprite.x=(p->frame3)*182;
		p->possprite.y=100;
		p->possprite.h=100;
		p->possprite.w=182;
        p->frame3++;
        SDL_Delay(50);
	}

    //Attack animation
    if(p->direction == 2)
    {	
		p->possprite.x=(p->frame4)*182;
		p->possprite.y=400;
		p->possprite.h=100;
		p->possprite.w=182;
        p->frame4++;
        SDL_Delay(50);
	}

    if((p->jump == 1)&&(p->direction == 1))
	{
		p->possprite.x=182;
		p->possprite.y=200;
		p->possprite.h=100;
		p->possprite.w=182;	
	}
	if((p->jump == 1)&&(p->direction == -1))
	{
		p->possprite.x=182;
		p->possprite.y=200;
		p->possprite.h=100;
		p->possprite.w=182;	
	}
}

void saut(person *p)
{
    if(p->jump==1)
    {
        p->posperso.y+=10;
    }
    if(p->jump==0)
    {
        p->posperso.y+=-10;
    }
}


void librer(person p)
{
    SDL_FreeSurface(p.sprite);
}
