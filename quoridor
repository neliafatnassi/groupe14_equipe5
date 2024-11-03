#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // Pour getch() sous Windows

#define TAILLE 9
#define MENU_ITEMS 5

// Structure pour les coordonnées
typedef struct {
    int x, y;
} Coord;

// Structure pour chaque joueur
typedef struct {
    Coord position;
    char symbole;
} Joueur;

// Options du menu
const char *menuOptions[MENU_ITEMS] = {
    "Nouvelle Partie",
    "Reprendre Partie",
    "Afficher l'Aide",
    "Afficher les Scores",
    "Quitter"
};

// Fonction pour afficher le plateau avec bordures et séparateurs
void afficher_plateau(char plateau[TAILLE][TAILLE], Joueur *joueur1, Joueur *joueur2) {
    system("cls");  // Efface l'écran sous Windows
    printf("   ");
    for (int i = 0; i < TAILLE; i++) {
        printf(" %d ", i);  // Etiquettes de colonnes
    }
    printf("\n");

    for (int i = 0; i < TAILLE; i++) {
        printf(" %d ", i);  // Etiquettes de lignes
        for (int j = 0; j < TAILLE; j++) {
            if (i == joueur1->position.x && j == joueur1->position.y) {
                printf("|%c|", joueur1->symbole);  // Joueur 1
            } else if (i == joueur2->position.x && j == joueur2->position.y) {
                printf("|%c|", joueur2->symbole);  // Joueur 2
            } else {
                printf("| |");  // Case vide
            }
        }
        printf("\n");
    }
}

// Fonction pour initialiser le plateau
void initialiser_plateau(char plateau[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            plateau[i][j] = ' ';
        }
    }
}

// Fonction pour sélectionner un symbole
char choisir_symbole(int joueur_num) {
    char symbole;
    printf("Joueur %d, choisissez un symbole pour votre personnage  ", joueur_num);
    scanf(" %c", &symbole);
    return symbole;
}

// Fonction pour déplacer un joueur
void deplacer_joueur(char plateau[TAILLE][TAILLE], Joueur *joueur, char direction) {
    int newX = joueur->position.x;
    int newY = joueur->position.y;

    // Modifier les coordonnées selon la direction
    if (direction == 'Z' || direction == 'z') newX--;  // Avant (haut)
    else if (direction == 'S' || direction == 's') newX++;  // Bas
    else if (direction == 'Q' || direction == 'q') newY--;  // Gauche
    else if (direction == 'D' || direction == 'd') newY++;  // Droite

    // Vérifier que les nouvelles coordonnées sont valides
    if (newX >= 0 && newX < TAILLE && newY >= 0 && newY < TAILLE) {
        joueur->position.x = newX;
        joueur->position.y = newY;
    } else {
        printf("Deplacement invalide.\n");
    }
}


// Menu principal
void afficher_menu() {
    printf("\n=== Menu du Jeu ===\n");
    for (int i = 0; i < MENU_ITEMS; i++) {
        printf("%d. %s\n", i + 1, menuOptions[i]);
    }
}

void nouvelle_partie(Joueur *joueur1, Joueur *joueur2, char plateau[TAILLE][TAILLE]) {
    initialiser_plateau(plateau);
    joueur1->position.x = 0;
    joueur1->position.y = TAILLE / 2;
    joueur2->position.x = TAILLE - 1;
    joueur2->position.y = TAILLE / 2;
    joueur1->symbole = choisir_symbole(1);
    joueur2->symbole = choisir_symbole(2);
    printf("Nouvelle partie commencée!\n");
}

int main() {
    char plateau[TAILLE][TAILLE];
    Joueur joueur1, joueur2;
    int choix;
    char direction;

    while (1) {
        afficher_menu();
        printf("Choisissez une option: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                nouvelle_partie(&joueur1, &joueur2, plateau);
                while (1) {  // Boucle de jeu
                    afficher_plateau(plateau, &joueur1, &joueur2);

                    printf("Joueur 1, entrez un deplacement (W/A/S/D): ");
                    direction = getch();
                    deplacer_joueur(plateau, &joueur1, direction);

                    afficher_plateau(plateau, &joueur1, &joueur2);

                    printf("Joueur 2, entrez un deplacement (W/A/S/D): ");
                    direction = getch();
                    deplacer_joueur(plateau, &joueur2, direction);
                }
                break;
            case 2:
                printf("Reprise de la derniere partie sauvegardee...\n");
                // Charger la partie sauvegardée ici
                break;
            case 3:
                printf("Ce jeu se joue sur un plateau. Le but est d atteindre le premier, le bord oppose a sa ligne de depart. \n les murs sont autorise pour ralentir l'adversaire ! \n Aide: Utilisez la touches w pour avancer \n A pour reculer \n S pour aller vers la gauche \n D pour se deplacer vers la droite. \n Pour poser les murs rien de plus simple ! cliquer sur T et indiquer l'emplacement du murs ");
                break;
            case 4:
                printf("Scores non disponibles.\n");
                break;
            case 5:
                printf("Quitter le jeu. Au revoir !\n");
                exit(0);
            default:
                printf("Option invalide.\n");
        }
    }

    return 0;
}

