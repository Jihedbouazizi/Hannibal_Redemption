#include "text.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


void initMainText(Text *A)
{
    A->position.x=600;
    A->position.y=50;
    
    A->textColor.r=244;
    A->textColor.g=164;
    A->textColor.b=69;

    A->font = TTF_OpenFont("Fonts/CharlemagneStd-Bold.otf", 50);
}

void initSecondText(Text *B)
{
    B->position.x=800;
    B->position.y=100;
    
    B->textColor.r=244;
    B->textColor.g=164;
    B->textColor.b=69;

    B->font = TTF_OpenFont("Fonts/CharlemagneStd-Bold.otf", 30);
}

void freeMainText(Text A)
{
    SDL_FreeSurface(A.surfaceTexte);
}
void freeSecondText(Text B)
{
    SDL_FreeSurface(B.surfaceTexte);
}
void displayMainText(Text t, SDL_Surface *screen)
{
    t.surfaceTexte = TTF_RenderText_Solid(t.font, "The Matrix Studio", t.textColor);
    SDL_BlitSurface(t.surfaceTexte, NULL, screen, &t.position);
}
void displaySecondText(Text s, SDL_Surface *screen)
{
    s.surfaceTexte = TTF_RenderText_Solid(s.font, "Presents", s.textColor);
    SDL_BlitSurface(s.surfaceTexte, NULL, screen, &s.position);
}
