
                          //main.c//

#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
int main() {
    char pl[T][T], direction;
    int x, y;
    int choix=0;
    int validation = 0;
    int i=0, j=0; //initialisation d'un plateau pour 4 joueurs
    initialiser_plateau(pl,4);

        do {
            do {
                printf("\n\n\n");
                afficher_plateau(pl);
                validation =0; //on met notre validation à 0
                choix=menu_action();
                if (choix==1){
                    validation= poser_barriere(pl); //si la barriere s'est bien pose alors le programme renvoie 1 donc il valide l'action sinon il renvoie 0
                }
                if (choix==2){
                    validation= deplacer_pion(pl,x,y, direction); //si le pion s'est déplace correctement alors le programme renvoie 1 donc il valide l'action sinon il renvoie 0
                }
                if(choix==3){
                    afficher_plateau(pl); //ici le joueur décide de sauter son tour donc la validation est automatique
                    validation = 1;
                }
            } while(validation!=1);  //tant qu'une action n'a pas été validée le programme se relance
            afficher_plateau(pl);
        } while (choix!=4);  //tant que le choix 4 n'est pas fait la partie continue
        printf("L'un des 2 joueurs abandonne");
        return 1;
    }






                 // .h //

#include <stdbool.h>
#ifndef TABLEAU_H
#define TABLEAU_H
#define T 17
void monTableau(int tableauVide[9][9]);
int config();
void initialiser_plateau(char plateau[T][T],int nj);
int menu_action ();
void afficher_plateau(char plateau[T][T]);
int poser_barriere(char plateau[T][T]);
bool deplacer_pion(char plateau[T][T], int x, int y, char direction);
int IA (char plateau[T][T], int *i, int *j);
#endif //TABLEAU_H



                  //PARTIE .c //
                  
#include <stdio.h>
#include "tableau.h"
#include <stdbool.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

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


int menu_action (){
    int selec=0;
    int validation=0;
    do{
        printf("Entrez l'action que vous souhaitez effectue : \n 1)poser une barriere\n 2)deplacer son pion\n 3)sauter son tour\n 4)abandon de la partie\n"); //affiche les possibilités
        scanf("%d", &selec);
        if(selec<5 && selec>0){ //verifie que le nombre saisi est correct
            if (selec==4){ //si le joueur décide d'abandonner un avertissement s'ouvre en cas de mauvaise manipulation
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
    }while(validation!=1); //tant que le programme n'a pas bien été effectué donc tant qu'on n'a pas choisi une option valide, le menu se relance
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
                if(j%2==0) {
                    switch (plateau[i][j]) {
                        case 1:
                            printf("| %c ", 0x03); // Affichage du pion 1
                        break;
                        case 2:
                            printf("| %c ",0x04); //Affichage du pion 2
                        break;
                        case 3:
                            printf("| %c ",0x05); //Affichage du pion 3
                        break;
                        case 4:
                            printf("| %c ",0x06); //Affichage du pion 4
                        break;
                        default:
                            printf("| %c ", ' '); //Case vide
                        break;

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
    char position= '0';
    int i=0;
    int j=0;
    printf("Voulez-vous posez une barriere ? o=oui sinon saisissez un autre caractere \n");
    scanf(" %c", &choixBarriere);
    if(choixBarriere=='o') {
        printf("saisissez la position de la barriere h pour horizontale et v pour verticale \n");
        scanf(" %c", &position);
        switch (position) {
            case 'h' :

                    printf("Saisissez une ligne impaire\n", i);
                    scanf("%d", &i);
                    if( i%2!=0 && i>0 && i<T) {
                        printf("Votre barriere est placee a la ligne %d\n", i);

                    }
                    else {
                        printf("Votre saisie est invalide\n");
                        return 0;
                    }


                printf("Saisissez une colonne paire\n", j);
                scanf("%d", &j);
                if( j%2==0 && j>0 && j<T) {
                    printf("Votre barriere est placee a la colonne %d\n", i);

                }
                else {
                    printf("Votre saisie est invalide\n");
                    return 0;
                }
            if (plateau[i][j]==5 || plateau[i][j+1]==5 || plateau[i][j+2]==5) {
                printf("Vous ne pouvez pas placer une barriere sur une barriere deja existante\n");
                return 0;
            }
            else {
                plateau[i][j]=5;
                plateau[i][j+1]=5;
                plateau[i][j+2]=5;
                return 1;
            }

            case 'v' :

                    printf("Saisissez une ligne paire\n", i);
                    scanf("%d", &i);
                    if( i%2==0 && i>0 && i<T) {
                        printf("Votre barriere est placee a la ligne %d\n", i);
                    }
                    else {
                        printf("Votre saisie est invalide\n");
                        return 0;
                    }


                printf("Saisissez une colonne impaire\n", j);
                scanf("%d", &j);
                if( j%2!=0 && j>0 && j<T) {
                    printf("Votre barriere est placee a la colonne %d\n", j);
                }
                else {
                    printf("Votre saisie est invalide\n");
                    return 0;
                }
            if (plateau[i][j]==5 || plateau[i+1][j]==5 || plateau[i+2][j]==5) {
                printf("Vous ne pouvez pas placer une barriere sur une barriere deja existante\n");
                return 0;
            }
            else {
                plateau[i][j]=5;
                plateau[i+1][j]=5;
                plateau[i+2][j]=5;
                return 1;
            }
        }
    }
    else {
        printf("vous allez etre renvoye au menu\n");
        return 0;
    }
}





bool deplacer_pion(char plateau[T][T], int x, int y, char direction) {
    printf("Entrer les coordonnees du pion a deplacer (x y) : \n");
    scanf("%d %d", &x, &y );
    printf("Entrer la direction h = haut, b = bas, d = droite, g = gauche \n");
    scanf(" %c", &direction);


    if ( x<0 || x>= T || y<0 || y>= T || plateau[x][y]==0) {
        return false; //Position invalide ou case vide
    }
    int newX = x, newY = y;
    switch (direction) {
        case'h':
            newX= newX-2;
        break;
        case'b':
            newX=newX+2;
        break;
        case'd':
            newY=newY+2;
        break;
        case'g':
            newY=newY-2;
        break;
        default:
            return false; //Direction invalide
    }
    if (newX <0 || newX >=T ||newY <0 || newY >=T || plateau[newX][newY] !=0) {
        printf("Vous ne pouvez pas vous deplacer ici, cette case est deja occupee\n");
        return false; //Déplacement impossible
    }
    plateau[newX][newY]=plateau[x][y];
    plateau[x][y] =0;

    return true;
}



int IA (){
srand(time(NULL));
int choix=0;
int i =0;
int j=0;
int validation=0;
int direction=0;

do{
choix=(rand())%2
  if (choix=1){
            i=(rand())%T;
            j=(rand())%T;
            plateau[i][j]=5;
            validation=1; //si la barriere s'est bien pose alors le programme renvoie 1 donc il valide l'action sinon il renvoie 0
    }
    if (choix=0){
    direction=(rand())%4;
     if (direction=0 && *i>0) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *i= (*i)-2; //modification des nouvelles coordonnés horizontale
        validation=1; //le déplacement s'est bien effectué
    }
    else if(direction=1 && *i<T) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *i=(*i)+2; //modification des nouvelles coordonnés horizontale
         validation=1; //le déplacement s'est bien effectué
    }
    else if(direction=2 && *j<T) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *j=(*j)+2; //modification des nouvelles coordonnés verticale
        validation=1; //le déplacement s'est bien effectué
    }
    else if(direction=3 && *j>0) {
        plateau[*i][*j]= '0'; //Suppression de l'ancienne position du pion
        *j=(*j)-2; //modification des nouvelles coordonnés verticale
        validation=1; //le déplacement s'est bien effectué
    }
    else {
        validation=0; //le déplacement s'est mal effectué
    }
    plateau[*i][*j]=1; //Nouvelle position du pion
}

}while(validation!=1) //tant que l'ia n'a pas effectué d'action vérifier son tour recommence jusqu'a ce que ca marche
}
