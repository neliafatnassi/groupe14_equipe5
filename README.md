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



\\\le point h\\\
#ifndef TABLEAU_H
#define TABLEAU_H
void monTableau(int tableauVide[9][9]);
int config();
void initialiser_plateau(char plateau[T][T],int nj);
int menu_action ();
void afficher_plateau(char plateau[T][T]);
int poser_barriere(char plateau[T][T]);
int deplacer_pion(char plateau[T][T], int *i, int *j);
#endif //TABLEAU_H



            //PARTIE main//
            
#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
int main()
{
  char pl[T][T];
    int choix=0;
    int validation = 0;
    int i=0, j=0; //initialisation d'un plateau pour 4 joueurs
    initialiser_plateau(pl,4);
    do { //tant que le choix 4 n'est pas fait la partie continue
    do { //tant qu'une action n'a pas été validé le programme se relance
    afficher_plateau(pl);
    validation =0; //on met notre validation à 0
    choix=menu_action();
    if (choix=1){
    validation= poser_barriere(pl); //si la barriere s'est bien pose alors le programme renvoie 1 donc il valide l'action sinon il renvoie 0
    }
    if (choix=2){
    validation= deplacer_pion(pl, &i, &j); //si le pion s'est déplace correctement alors le programme renvoie 1 donc il valide l'action sinon il renvoie 0
    }
    if(choix=3){
    afficher_plateau(pl); //ici le joueur décide de sauter son tour donc la validation est automatique
    validation = 1;
    }
    } while(validation!=1)
    afficher_plateau(pl);
   } while(choix!=4)
    printf("L'un des 2 joueurs abandonne");
    return 1;
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
\\\menu des actions\\\
#include <stdio.h>
int menu_action (){
int selec=0;
int validation=0;
do{
printf("Entrez l'action que vous souhaitez effectue : 1)poser une barriere\n 2)deplacer son pion\n 3)sauter son tour\n 4)abandon de la partie\n"); //affiche les possibilités
scanf("%d", &selec);
if(selec<5 && selec>0){ //verifie que le nombre saisi est correct
if (selec=4){ //si le joueur décide d'abandonner un avertissement s'ouvre en cas de mauvaise manipulation
printf("attention tout abandon est définitif et entraine directement la fin de la partie\n");
printf("saisissez 1 si vous souhaitez abandonner definitivement\n");
scanf("%d", &validation); //on demande la saisi d'une validation à la main pour l'abandon
  if (validation!=1){
  selec=0;
  printf("vous allez etre renvoye au menu");
}
}
else {
validation=1; //on valide que le programme a bien été effectué
}
}
}while(validation!=1) //tant que le programme n'a pas bien été effectué donc tant qu'on n'a pas choisi une option valide, le menu se relance
return selec; //on retourne à notre main l'option choisi
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


int poser_barriere(char plateau[T][T]) {
    char choixBarriere ='0';
    int i=0;
    int j=0;
    printf("Voulez-vous posez une barriere ? o=oui sinon saisissez un autre caractere \n");
    scanf("%c", &choixBarriere);
    if(choixBarriere=='o') {
        printf("Saisir les coordonnees pour votre barriere\n");
        scanf("%d %d", &i, &j);
        //Vérification des valeurs rentrées
        if (i>=0 && i<T && j>=0 && j<T) {
            plateau[i][j]=5;
            return 1;
        }else {
            printf("Indices invalides. Vous allez etre renvoye au menu\n");
            return 0;
        }
      else {
       printf("vous allez etre renvoye au menu\n");
       return 0;
      }
    }
}



int deplacer_pion(char plateau[T][T], int *i, int *j) {
    char direction;
    printf("Dans quelle direction voulez-vous deplacer votre pion ?\n");
    printf(" h(haut), b(bas), d(droite), g(gauche)\n"); //affichage des commandes
    scanf("%c", &direction);
    if (direction=='h' && *i>0) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *i= (*i)-2; //modification des nouvelles coordonnés horizontale
        return 1; //le déplacement s'est bien effectué
    }
    else if(direction=='b' && *i<T) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *i=(*i)+2; //modification des nouvelles coordonnés horizontale
        return 1; //le déplacement s'est bien effectué
    }
    else if(direction=='d' && *j<T) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *j=(*j)+2; //modification des nouvelles coordonnés verticale
        return 1; //le déplacement s'est bien effectué
    }
    else if(direction=='g' && *j>0) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *j=(*j)-2; //modification des nouvelles coordonnés verticale
        return 1; //le déplacement s'est bien effectué
    }
    else {
        printf("Ce mouvement n'est pas possible\n");
        return 0; //le déplacement s'est mal effectué
    }
    plateau[*i][*j]=1; //Nouvelle position du pion
}
