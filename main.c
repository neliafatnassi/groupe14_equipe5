#include <stdio.h>

int main(void) {
#include <stdio.h>
#include <stdlib.h>

    int main() {
        int *arrays[10]; // Tableau de pointeurs pour stocker les adresses de 10 tableaux dynamiques
        int sizes[10];   // Taille de chaque tableau
        int i, j;

        // Initialisation de la taille de chaque tableau
        for (i = 0; i < 10; i++) {
            sizes[i] = (i + 1) * 5;  // Exemple : taille de chaque tableau est (i+1) * 5
            arrays[i] = (int *)malloc(sizes[i] * sizeof(int));  // Allocation dynamique pour chaque tableau

            // Vérification de la réussite de l'allocation
            if (arrays[i] == NULL) {
                printf("Erreur d'allocation mémoire pour le tableau %d\n", i);
                return 1;  // Sortie en cas d'échec d'allocation
            }
        }

        // Remplissage des tableaux avec des valeurs
        for (i = 0; i < 10; i++) {
            printf("Tableau %d : ", i + 1);
            for (j = 0; j < sizes[i]; j++) {
                arrays[i][j] = j + 1;  // Remplissage avec des valeurs de 1 à taille du tableau
                printf("%d ", arrays[i][j]);
            }
            printf("\n");
        }

        // Libération de la mémoire allouée
        for (i = 0; i < 10; i++) {
            free(arrays[i]);
        }

        return 0;
    }

    printf("Hello, World!\n");
    return 0;
}
