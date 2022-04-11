#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "perso.h"

//Initialisation
void init(perso* p)
{
	//Image loading
	p->sprite = IMG_Load("photos/finalsprite.png");
    //Character position
    p->posperso.x = 200; 
    p->posperso.y = 530;
	//
    p->possprite.x = 0;
    p->possprite.y = 0;
    p->possprite.h = 100; 
    p->possprite.w = 182;
	p->direction = 1;
	p->Signal = 0;
	p->Signalb = 0;
	p->isJump = 0;
	p->col = 1;
	p->speed = 0;
	p->ground = p->posperso.y;
	p->frame1 = 1; //right
    p->frame2 = 10; //left
    p->frame3 = 1; //idle
    p->frame4 = 1;
	p->VarX=0;
}
//Affichage
void afficherPerso(perso p,SDL_Surface* screen)
{
	SDL_BlitSurface(p.sprite,&(p.possprite),screen,&(p.posperso));

}

void deplacerPerso(perso *p){
		
	if(((p->Signal == 1)||(p->Signalb == 1))&&(p->speed < 10))
	{
		p->speed+= 0.75;
	}
	if((p->Signal == 0)&&(p->Signalb == 0)&&(p->speed > 0))
	{
		p->speed-= 0.75;
	}
	
	if(p->speed <= 0)
	{
		p->speed = 0;
	}

	(p->posperso.x)+= p->speed*p->direction;
	if (p->posperso.x <= 0)
		p->posperso.x = 0;
	if (p->posperso.x >= 1200)
		p->posperso.x = 1200;
}

void animerPerso(perso *p){
	//Running forward
	if((p->direction == 1)&&(p->Signal == 1))
	{	
		p->possprite.x=(p->frame1)*182;
		p->possprite.y=0;
		p->possprite.h=100;
		p->possprite.w=182;
		p->frame1++;
        SDL_Delay(35);
	}
	//Running backward
	if((p->Signalb == 1)&&(p->direction == -1))
	{	
		p->possprite.x=(p->frame2)*182;
		p->possprite.y=600;
		p->possprite.h=100;
		p->possprite.w=182;
		p->frame2--;
        SDL_Delay(35);
	}	
	//Idle
	if((p->Signal == 0)&&(p->Signalb == 0)&&(p->isJump == 0))
	{
	  	p->possprite.x=(p->frame3)*182;
		p->possprite.y=100;
		p->possprite.h=100;
		p->possprite.w=182;
        p->frame3++;
        SDL_Delay(35);
	}
	//Jumping
	if((p->isJump == 1)&&(p->direction == 1))
	{
		p->possprite.x=182;
		p->possprite.y=200;
		p->possprite.h=100;
		p->possprite.w=182;	
        SDL_Delay(35);
	}
	if((p->isJump == 1)&&(p->direction == -1))
	{
		p->possprite.x=182;
		p->possprite.y=200;
		p->possprite.h=100;
		p->possprite.w=182;	
        SDL_Delay(35);
	}
}

void saut(perso *p)
{
	int y;
	int Amp = -300;
	float delta = -4*Amp;
	float x = (sqrt(delta) / (2));
	if((p->isJump == 1)||(p->col == 0))
	{
		p->VarX ++;
		printf("Jump!\n");
	}
	y = (int)((p->VarX - x)*(p->VarX - x) + Amp);
	if(y < 0)
	{
		p->col = 0;
	}
	if(y >= 0)
	{
		y = 0;
		p->VarX = 0;
		p->isJump = 0;
		p->col = 1;
	}
	p->posperso.y = (int) y + p->ground;
}

void initVie(Vie *vie)
{
	vie->vie_img[0]=IMG_Load("photos/vie 0.png");
	vie->vie_img[1]=IMG_Load("photos/vie 1.png");
	vie->vie_img[2]=IMG_Load("photos/vie 2.png");
	vie->vie_img[3]=IMG_Load("photos/vie 3.png");
	vie->posVie.x=150;
	vie->posVie.y=20;
	vie->valVie=3;
}
void Changement_vie(int collision, int *gameOver ,Vie *vie, SDL_Surface *screen)
{
	/*if ((collision>(3-vie->valVie)) && vie->valVie!=0)
	vie->valVie --;*/
	 if (vie->valVie==0)
	{
		*gameOver=1;
		SDL_BlitSurface(vie->vie_img[0], NULL, screen,&vie->posVie);
	}
 	else if (vie->valVie==1)
	{
		SDL_BlitSurface(vie->vie_img[1], NULL, screen, &vie->posVie);
	}
	 else if (vie->valVie==2)
	{
		SDL_BlitSurface(vie->vie_img[2], NULL, screen, &vie->posVie);
	}
	 else if (vie->valVie==3)
	{
		SDL_BlitSurface(vie->vie_img[3], NULL, screen, &vie->posVie);
	}
} 


void initScore(Score *score)
{
	char string[20];
	score->textColor.r=244;
    score->textColor.g=164;
    score->textColor.b=69;
	score->fondScore = IMG_Load("photos\bois.png");
	score->police = TTF_OpenFont("CharlemagneStd-Bold.otf", 35);
	score->scoreActuel=0;
	sprintf(string, "score = %d ", score->scoreActuel);
	(score->texteScore)=TTF_RenderText_Blended(score->police,string, score->textColor);
}

void afficherScore(Score *score, int collision, SDL_Surface *screen)
{
	score->posFond.x=950;
	score->posFond.y=20;

	score->posScore.x=score->posFond.x+20;
	score->posScore.y=score->posFond.y+20;

	score->textColor.r=244;
    score->textColor.g=164;
    score->textColor.b=69;

	char scoreString[10]=""; 
	char string[20];
	
	SDL_BlitSurface(score->fondScore, NULL, screen,&score->posFond);
	SDL_BlitSurface(score->texteScore, NULL, screen,&score->posScore);
	/*if (collision>=1)
	{
		score->scoreActuel=score->scoreActuel+10;
		sprintf(string, "score = %d ", score->scoreActuel);
		SDL_FreeSurface(score->texteScore);
		(score->texteScore)=TTF_RenderText_Blended(score->police,string, score->textColor);
	}    */    
}

void initmap(minimap *m)
{
  m->minibg=IMG_Load("photos/minibg.png");
  m->posminimap.x=80;
  m->posminimap.y=130;
  m->minimc=IMG_Load("photos/HeroKnight_Idle_0.png");
}

SDL_Rect MAJminimap(perso p,minimap *m,int resize)
{
 
  SDL_Rect posmcABS,posminimc;
  posmcABS.x=p.posperso.x;
  posmcABS.y=p.posperso.y;
  posminimc.x=posmcABS.x*resize/100+m->posminimap.x;
  posminimc.y=posmcABS.y*resize/100+m->posminimap.y+(-8);
  return posminimc;
}

void displaymap(minimap m,SDL_Surface *screen)
{
  SDL_BlitSurface(m.minibg,NULL,screen,&m.posminimap);
  SDL_BlitSurface(m.minimc,NULL,screen,&m.posminimc);
}

void freeminimap(minimap *m)
{
  SDL_FreeSurface(m->minibg);
  SDL_FreeSurface(m->minimc);
}

void displaytime(int *time)
{

   Uint32 aaa;
   aaa=SDL_GetTicks();
   *time=120-((int)aaa)/1000;
}






