#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 1200
#define SCREEN_H 630

typedef struct {
    SDL_Surface	*img[4];
    SDL_Rect pos1;
    SDL_Rect pos2;
    int niveau;
}Image;

typedef struct {
    SDL_Surface	*img[2];
    SDL_Rect pos1;
    int actif;
}Bouton;

typedef struct {
    SDL_Surface	*img[3];
    SDL_Rect pos1;
    SDL_Rect pos2;
    int level;
}Animation;

void initBack(Image *Back);
void initImages(Bouton b[]);
//void Initanimation(Animation *An);

void librer(Image Back, Bouton b[]);
//void afficheranimation(Animation An, SDL_Surface *screen);
void afficherBackg(Image backg, SDL_Surface *screen);
void afficherbutton(Bouton b[], int actif, SDL_Surface *screen);
#endif
