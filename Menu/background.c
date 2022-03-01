#include <SDL/SDL.h>
#include "background.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void initBack(Image *Back)
{

    Back->img[0]= IMG_Load("Background/background1.jpg");
    Back->img[1]= IMG_Load("Background/HANNIBAdL.png");
    Back->img[2]= IMG_Load("Background/settings.png");
    Back->img[3]= IMG_Load("Background/credits.png");
    Back->img[4]= IMG_Load("Background/Hannibl.jpg");

    Back->pos1.x=0; 
    Back->pos1.y=0; 
    Back->pos2.x=0; 
    Back->pos2.y=0; 
    Back->pos2.w=(SCREEN_W);
    Back->pos2.h=(SCREEN_H);
    Back->niveau=1;
}




void initImages(Bouton b[])
{
    b[0].img[0]=IMG_Load("Buttons/start.png");
    b[0].img[1]=IMG_Load("Buttons/START1.png");

    b[1].img[0]=IMG_Load("Buttons/Settings.png");
    b[1].img[1]= IMG_Load("Buttons/settings1.png"); 

    b[2].img[0]= IMG_Load("Buttons/CREDITS.png");    
    b[2].img[1]= IMG_Load("Buttons/CREDITS1.png");    

    b[3].img[0]= IMG_Load("Buttons/EXIT.png");    
    b[3].img[1]= IMG_Load("Buttons/EXIT1.png");   

    b[4].img[0]= IMG_Load("Buttons/Audio.png");    
    b[4].img[1]= IMG_Load("Buttons/Audio.png");    

    b[5].img[0]= IMG_Load("Buttons/plus.png");    
    b[5].img[1]= IMG_Load("Buttons/plus.png");    

    b[6].img[0]= IMG_Load("Buttons/Minus.png");    
    b[6].img[1]= IMG_Load("Buttons/Minus.png");    

    b[7].img[0]= IMG_Load("Buttons/Fullscreen.png");    
    b[7].img[1]= IMG_Load("Buttons/Fullscreen.png");  

    b[8].img[0]= IMG_Load("Buttons/backtomenu.png");    
    b[8].img[1]= IMG_Load("Buttons/backtomenu.png");  

    b[9].img[0]= IMG_Load("Buttons/backtomenu.png");    
    b[9].img[1]= IMG_Load("Buttons/backtomenu.png");
   

    b[0].pos1.x=106;
    b[0].pos1.y=174;

    b[1].pos1.x=106;
    b[1].pos1.y=264;

    b[2].pos1.x=106;
    b[2].pos1.y=354;

    b[3].pos1.x=106;
    b[3].pos1.y=444;

    b[4].pos1.x=470;
    b[4].pos1.y=177;

    b[5].pos1.x=490;
    b[5].pos1.y=257;

    b[6].pos1.x=689;
    b[6].pos1.y=257;

    b[7].pos1.x=470;
    b[7].pos1.y=324;

    b[8].pos1.x=470;
    b[8].pos1.y=424;

    b[9].pos1.x=450;
    b[9].pos1.y=488;

    b[0].actif=0;
    b[1].actif=0;
    b[2].actif=0;
    b[3].actif=0;
    b[4].actif=0;
    b[5].actif=0;
    b[6].actif=0;
    b[7].actif=0;
    b[8].actif=0;
    b[9].actif=0;

}

/*void Initanimation(Animation *An)
{

    An->img[0]=IMG_Load("frames/a3.png");
    An->img[1]=IMG_Load("frames/a2.png");
    An->img[2]=IMG_Load("frames/a1.png");


    An->pos1.x=0; 
    An->pos1.y=0; 
    An->pos2.x=0; 
    An->pos2.y=0; 
    An->pos2.w=(SCREEN_W);
    An->pos2.h=(SCREEN_H);
    An->level=0;

}*/

void afficherBackg(Image backg, SDL_Surface *screen)
{
    SDL_BlitSurface(backg.img[backg.niveau], &backg.pos2, screen, &backg.pos1);
}

void afficherbutton(Bouton b[], int niveau, SDL_Surface *screen)
{
    int i;
    if(niveau==1)
    {
        for(i=0; i<4; i++)
        {
            SDL_BlitSurface(b[i].img[b[i].actif], NULL, screen, &b[i].pos1);
        }
    }
    else
      if(niveau==2)
      {
         for(i=4; i<9; i++)
          SDL_BlitSurface(b[i].img[b[i].actif], NULL, screen, &b[i].pos1);    
      }
    else
      if(niveau==3)
      {
          SDL_BlitSurface(b[9].img[b[9].actif], NULL, screen, &b[9].pos1);
      }
}

/*void afficheranimation(Animation An , SDL_Surface *screen)
{
  
        SDL_BlitSurface(An.img[An.level], &An.pos2, screen, &An.pos1);
        //SDL_Delay(100);
        
}*/



void librer(Image Back ,Bouton b[])
{
    int i;

    for(i=0; i<4; i++)
    {
        SDL_FreeSurface(Back.img[i]);
    }

    while(i<10)
        {  
            SDL_FreeSurface(b[i].img[0]);
            SDL_FreeSurface(b[i].img[1]);
            i++;
        }
    
}
