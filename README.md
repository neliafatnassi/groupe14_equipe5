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
