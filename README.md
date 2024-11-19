# groupe14_equipe5
                        // Config//
int config(){
int nb=0;
printf("Si vous souhaitez jouer une partie a 2,mettez 0 sinon mettez 1");
scanf("%d", nb);
if (nb<2)
  if(nb<1)
     printf("la partie sera pour 2 joueurs");
  else 
     printf("la partie sera pour 4 joueurs");
}
                        // Menu du jeu//
int main(void) {
   do{
      int choix=0;
      printf("~~~~~~Menu du jeu~~~~~~\n");
      printf("1) Lancer une nouvelle partie\n");
      printf("2) Reprendre une partie sauvegardee\n");
      printf("3) Afficher l'aide\n");
      printf("4) Afficher les scores des joueurs\n");
      printf("5) Quitter le jeu\n");
      printf("Veuillez saisir le numero de votre choix\n");
      scanf("%d",&choix);

      switch (choix) {
         case 1:
            nouvellePartie(); //Fonction qui sera appelée
         break;
         case 2:
            anciennePartie(); //Fonction qui sera appelée
         break;
         case 3:
            aide(); //Fonction qui sera appelée
         break;
         case 4:
            score(); //Fonction qui sera appelée
         break;
         case 5:
            quitterJeu(); //Fonction qui sera appelée
         break;
         default:
            printf("Veuillez choisir une des options qui vous est proposée\n");

      }
   }while(choix!=5);
}


                         // Tableau vide 9x9//
int main() {
    int tableauVide[9][9];
    monTableau(tableauVide);
}

#include <stdio.h>
void monTableau(int tableauVide[9][9]) {
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("|__", tableauVide[i][j]);
        }
        printf("\n");

    }
}

#ifndef TABLEAU_H
#define TABLEAU_H
void monTableau(int tableauVide[9][9]);
#endif //TABLEAU_H
                     //Nul//

{}

            
            
            //PARTIE main//
            
#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
int main()
{
    char pl[T][T];
    int i=0, j=0;
    //initialisation d'un plateau pour 4 joueurs
    initialiser_plateau(pl,4);
    afficher_plateau(pl);
    poser_barriere(pl);
    afficher_plateau(pl);
    deplacer_pion(pl, &i, &j);
    afficher_plateau(pl);
    

    return 0;

}

                  //PARTIE .c //
                  
#include <stdio.h>
#include "plateau.h"
#include <windows.h>

void initialiser_plateau(char plateau[T][T],int nj)
{
    int i,j;
    ///pour chaque ligne
    for(i=0; i<T; i++)
    {
        ///pour parcourir toute les cases de la ligne
        for(j=0; j<T; j++)
        {
            ///la case est mise à vide (0)
            plateau[i][j]=0;
        }
    }
    //si 2 joueurs, on met les pions au milieu des lignes du haut (indice 0) et du bas (indice T-1)
    if(nj==2)
    {
        plateau[0][T/2]=1;
        plateau[T-1][T/2]=2;
    }
    else
    {
        //sinon (4 joueurs) : pions dans chaque angle.
        plateau[0][T/2]=1;
        plateau[T-1][T/2]=2;
        plateau[T/2][0]=3;
        plateau[T/2][T-1]=4;
    }
}


void afficher_plateau(char plateau[T][T])
{
    int i,j;
    //pour chaque ligne
    for(i=0; i<T; i++)
    {
        //si la ligne est paire
        if(i%2==0)
        {
            for(j=0; j<T; j++)
            {
                //si la colonne est paire
                if(j%2==0)
                {
                    //si la case est vide, on affiche un espace
                    if(plateau[i][j]==0)
                    {
                        printf("| %c ", ' ');
                    }
                    //sinon
                    else
                    {
                        //si la case contient la valeur 1 (1er joueur)
                        if(plateau[i][j]==1) printf("| %c ", 0x03);
                        else {
                            //si la case contient la valeur 2 (2eme joueur)
                            if(plateau[i][j]==2) printf("| %c ",0x04);
                            else{
                                //si la case contient la valeur 2 (3eme joueur)
                                if(plateau[i][j]==3) printf("| %c ",0x05);
                                else {
                                    //si la case contient la valeur 2 (4eme joueur)
                                    if(plateau[i][j]==4) printf("| %c ",0x06);
                                }
                            }
                        }
                    }
                }
                //si la colonne est impaire
                else
                {
                    //si la case contient la valeur 5 (mur)
                    if(plateau[i][j]==5) printf("|%c",'X');
                    //sinon la case est vide
                    else printf("| ");
                }
            }
            //fin de la ligne
            printf("|\n");
        }
        //si la ligne est impaire
        else{
            for(j=0; j<T; j++)
            {
                //si la colonne est paire
                if(j%2==0){
                    //si la case contient la valeur 5 (mur)
                    if(plateau[i][j]==5) printf(" %c%c%c ",'X','X','X');
                    else printf("     ");
                }
                //si la colonne est impaire
                else{
                    //si la case contient la valeur 5 (mur)
                    if(plateau[i][j]==5) printf("%c",'X');
                    else printf(" ");
                }
            }
            printf("\n");
        }
    }
}


void poser_barriere(char plateau[T][T]) {
    char choixBarriere;
    int i,j;
    printf("Voulez-vous posez une barriere ? o=oui et n=non\n", choixBarriere);
    scanf("%c", &choixBarriere);
    if(choixBarriere=='o') {
        printf("Saisir les coordonees pour votre barriere\n", i, j);
        scanf("%d %d", &i, &j);
        //Vérification des valeurs rentrées
        if (i>=0 && i<T && j>=0 && j<T) {
            plateau[i][j]=5;
        }else {
            printf("Indices invalides. Rentrez d'autres valeurs\n");
        }

    }else {
        printf("Veuillez choisir une autre action\n");
    }
}



void deplacer_pion(char plateau[T][T], int *i, int *j) {
    char direction;
    printf("Dans quelle direction voulez-vous deplacer votre pion ?\n");
    printf(" h(haut), b(bas), d(droite), g(gauche)\n", direction);
    scanf("%c", &direction);

    //Suppression de l'ancienne position du pion
    plateau[*i][*j]= ' ';

    //Nouvelle position du pion
    if (direction=='h' && *i>0) {
        *i= (*j)-2;
    }
    else if(direction=='b' && *i<T) {
        *i=(*i)+2;
    }
    else if(direction=='d' && *i<T) {
        *i=(*i)+2;
    }
    else if(direction=='g' && *j>0) {
        *j=(*j)-2;
    }
    else {
        printf("Ce mouvement n'est pas possible\n");
    }

    plateau[*i][*j]=1;
}

                    //PARTIE .h//

void initialiser_plateau(char plateau[T][T],int nj);
void afficher_plateau(char plateau[T][T]);
void poser_barriere(char plateau[T][T]);
void deplacer_pion(char plateau[T][T], int *i, int *j);
