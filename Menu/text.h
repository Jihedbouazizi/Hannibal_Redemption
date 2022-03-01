#ifndef TEXTE_H
#define TEXTE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


typedef struct{
    SDL_Rect position;
    TTF_Font *font;
    SDL_Surface * surfaceTexte;
    SDL_Color textColor;
    char text[50];
} Text;

void initMainText(Text *t);
void initSecondText(Text *s);
void freeMainText(Text A);
void freeSecondText(Text B);
void displayMainText(Text t, SDL_Surface *screen);
void displaySecondText(Text s, SDL_Surface *screen);
#endif
