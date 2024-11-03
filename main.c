#include <stdio.h>
#include "joueur.h"

int main() {
    Joueur joueurs[MAX_JOUEURS];
    int nombreJoueurs;
    char nomRecherche[50];
    int choix;
    int index;

    // lire les données du fichier
    lireFichier(joueurs, &nombreJoueurs);

    while (1) {
        printf("Veuillez taper 1 afin dajouter un joueur\n");
        printf("Veuillez taper 2 afin dafficher un joueur\n");
        printf("veuillez taper 3 pour Quitter\n");
        printf("A vous de jouer, entrez votre choix sil vous plait : ");
        scanf("%d", &choix);

        if (choix == 1) {
            char nomNouveau[50];
            int niveauNouveau;
            int viesNouveau;

            printf("Entrez le nom du nouveau joueur sil vous plait : ");
            scanf("%s", nomNouveau);
            printf("Entrez le niveau du nouveau joueur sil vous plait : ");
            scanf("%d", &niveauNouveau);
            printf("Entrez les vies restantes du nouveau joueur sil vous plait: ");
            scanf("%d", &viesNouveau);

            ajouterJoueur(joueurs, &nombreJoueurs, nomNouveau, niveauNouveau, viesNouveau);
        } else if (choix == 2) {
            printf("Entrez le nom du joueur à afficher sil vous plait: ");
            scanf("%s", nomRecherche);

            // afficher et chercher le joueur
            index = chercherJoueur(joueurs, nombreJoueurs, nomRecherche);
            if (index == -1) {
                printf("Joueur non trouvé. Veuillez réessayer sil vous plait.\n");
            } else {
                afficherJoueur(&joueurs[index]);
            }
        } else if (choix == 3) {
            break;
        } else {
            printf("Votre choix invalide. Veuillez réessayer sil vous plait.\n");
        }
    }

    return 0;
}
