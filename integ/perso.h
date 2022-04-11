#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED

typedef struct 
{
	SDL_Surface *sprite; // Image load
	SDL_Rect posperso; //Character position
	SDL_Rect possprite; //Sprite position
	int num;
	int direction;
	int Signal;
	int Signalb;
	int col;
	int ground;
	int isJump;
	int frame1; //run right
	int frame2; //run left
	int frame3; //idle
	int frame4;
	float VarX;
	float speed;
	
	
}perso;


typedef struct 
{
	SDL_Surface* vie_img[4];
	SDL_Rect posVie;
	int valVie;	
}Vie;

typedef struct
{
	SDL_Surface* fondScore;
	SDL_Rect posFond;
	SDL_Surface* texteScore;
	TTF_Font *police;
	SDL_Rect posScore;
	SDL_Color textColor;
	int scoreActuel;	
}Score;


typedef struct 
{
SDL_Surface *minibg;
SDL_Rect posminimap;
SDL_Surface *minimc;
SDL_Rect posminimc;
}minimap;


void initmap (minimap *m);
SDL_Rect MAJminimap( perso p,minimap *m,int resize);
void displaymap (minimap m, SDL_Surface * screen);
void freeminimap (minimap * m);
void displaytime (int *time);
void sauvegarder ( int score,char nomjoueur[],char nomfichier[]);
void meilleur ( char nomfichier [],int  *score, char nomjoueur[]);

void initScore(Score *score);
void afficherScore(Score *score,int collision, SDL_Surface *screen);

void initVie(Vie *vie);
void Changement_vie(int collision,int *gameOver ,Vie *vie,SDL_Surface *screen);

void init(perso* p);
void afficherPerso(perso p,SDL_Surface* screen);
void deplacerPerso(perso *p);
void animerPerso(perso *p);
void saut(perso *p);

#endif // HEADER_H_INCLUDED
