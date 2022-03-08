#ifndef PERSONNAGE_H
#define PERSONNAGE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1200
#define SCREEN_H 630

typedef struct 
{
	SDL_Surface *sprite;// Image load
	SDL_Rect posperso;//Character position
	SDL_Rect possprite;//Sprite positin
	int score;
    int nbrvie;
	float direction;
	int frame1; //run right
	int frame2; //run left
	int frame3; //idle
	int frame4; //attack
	int jump;
}person;

void initperson(person *p);
void afficherPerso(person p, SDL_Surface* screen);
void deplacerPerso (person *p, float dt);
void animerPerson(person *p);
void saut(person *p);
void librer(person p);

#endif