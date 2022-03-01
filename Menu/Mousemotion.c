#include <SDL/SDL.h>
#include "background.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

void Mousemotion(Image backg, Bouton b[]){
                if((Backg.niveau==0)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=174 && event.motion.y<=247))
                  {
                    b[0].actif=1;
                  }
               else
                  {
                    b[0].actif=0;
                  }

               //2eme button de Settings
               if((Backg.niveau==0)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=264 && event.motion.y<=337))
                  {
                    b[1].actif=1;
                  }
                  else
                  {
                    b[1].actif=0;
                  }

               //2eme button de Credits
               if((Backg.niveau==0)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=354 && event.motion.y<=427))
                  {
                    b[2].actif=1;
                  }
               else
                  {
                    b[2].actif=0;
                  }

               //2eme button de Exit
               if((Backg.niveau==0)&&(event.motion.x>=106 && event.motion.x<=391)&&(event.motion.y>=444 && event.motion.y<=517))
                  {
                    b[3].actif=1;
                  }
               else
                  {
                    b[3].actif=0;
                  }
}