#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "background.h"

void initBack(background *b)
{

    char ch[50];
    for (int i = 1; i < 51; i++)
    {
        sprintf(ch, "src/Layer %d.png", i);
        b->is[i - 1] = IMG_Load(ch);
    }

    b->positionbackground.w = b->is[1]->w;
    b->positionbackground.h = b->is[1]->h;
    b->positionback_partage.w = b->is[1]->w;
    b->positionback_partage.h = b->is[1]->h;
    b->anim = 0;
    b->image = IMG_Load("src/Layer 1.png"); /// chargement de l'image  de background

    /* for (int i = 1; i < 4; i++)
     {
        sprintf(ch, "src/Layer %d.png", i);
        b->image = IMG_Load("ch");
     }
  */
    //// initialisation position background1
    b->positionbackground.x = 0;
    b->positionbackground.y = -200;
    b->positionbackground.w = 0;
    b->positionbackground.h = 0;

    //// initialisation position camera 1
    b->camera1.x = 0;
    b->camera1.y = 0;
    b->camera1.w = 600;
    b->camera1.h = 630;

    //// initialisation position background 2
    b->positionback_partage.x = 600;
    b->positionback_partage.y = 0;
    b->positionback_partage.h = 0;
    b->positionback_partage.w = 0;

    //// initialisation position camera 2
    b->camera2.x = 0;
    b->camera2.y = 0;
    b->camera2.w = 600;
    b->camera2.h = 630;
}

void aficherBack(SDL_Surface *screen, background *b)
{
    SDL_BlitSurface(b->image, &b->camera1, screen, &b->positionbackground); /// blite de 1ere background
}

/*********************************************************************************/

void aficherBack_partage(SDL_Surface *screen, background *b)
{

    SDL_BlitSurface(b->image, &b->camera2, screen, &b->positionback_partage); /// blite de 2eme background avec partage
}
/*********************************************************************************/

void scrolling_down(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.down == 1)
    {
        if (b->camera1.y < 70)
        {
            b->camera1.y += velocity;
        }
    }
}
/*********************************************************************************/

void scrolling_down_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.s == 1)
    {
        if (b->camera2.y < 70)
        {
            b->camera2.y += velocity;
        }
    }
}


/*********************************************************************************/
void scrolling_up(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.up == 1)
    {
        if (b->camera1.y > 5)
{
            b->camera1.y -= 5;
        }
    }
}
/*********************************************************************************/
void scrolling_up_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.z == 1)
    {
        if (b->camera2.y >5)
        {
            b->camera2.y -= 5;
        }
    }
}
/*********************************************************************************/

void scrolling_right(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.right == 1)
    {
        if (b->camera1.x < 5160)
        {
            b->camera1.x += velocity;
        }
    }
}

/*********************************************************************************/

void scrolling_right_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{
    if (M.d == 1)
    {
        if (b->camera2.x < 5160)
        {
            b->camera2.x += velocity;
        }
    }
}

/*********************************************************************************/

void scrolling_left(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.left == 1)
    {
        if (b->camera1.x > 5)
        {
            b->camera1.x -= velocity;
        }
    }
}
void detect(background *b, SDL_Surface *screen)
{


        if (b->camera1.x > 1200)
        {
                printf("HEYYYYY\n");
        }
        
    }

/*********************************************************************************/

void scrolling_left_partage(background *b, float velocity, SDL_Surface *screen, mouvement M)
{

    if (M.q == 1)
    {
        if (b->camera2.x > 5)
        {
            b->camera2.x -= velocity;
        }

        
    }
}
/*********************************************************************************/

///// initialisation des deplacement
void init_Mouvement(mouvement *M)
{
    M->left = 0;
    M->right = 0;
    M->up = 0;
    M->q = 0;
    M->d = 0;
    M->z = 0;
    M->s = 0;
    M->down = 0;
}
/***************************UPDATE**********************************/

void afficher_bg(background bg, SDL_Surface *screen)
{
    SDL_BlitSurface(bg.is[bg.anim], NULL, screen, &bg.positionbackground);
    SDL_BlitSurface(bg.is[bg.anim], NULL, screen, &bg.positionback_partage);
}
void changement_imagebg(background *bg)
{
    bg->anim++;
    if (bg->anim == 50)
        bg->anim = 0;
}

void Initanimation(SDL_Surface *screen,image *img1,image *img2,image *img3)
{
    img1->img[0] = IMG_Load("layer1.png");
    img2->img[1] = IMG_Load("layer2.png");
    img3->img[2] = IMG_Load("layer3.png");
    img1->pos.x = 300;
    img1->pos.y = 150;

    
}


void afficherimage(SDL_Surface *screen,image *img1,image *img2,image *img3){
                SDL_BlitSurface(img1, NULL, screen, &img1->pos);
                SDL_BlitSurface(img2, NULL, screen, &img1->pos);
                SDL_BlitSurface(img3, NULL, screen, &img1->pos);

}
