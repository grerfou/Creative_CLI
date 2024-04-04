#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour calculer la somme de deux nombres
int addition(int a, int b) {
    return a + b;
}

// Fonction pour calculer la différence de deux nombres
int soustraction(int a, int b) {
    return a - b;
}

int main() {
    char choix_str[10];
    int choix, a, b;

    do {
        // Afficher le menu
        printf("\nMenu Principal\n");
        printf("1. Addition\n");
        printf("2. Soustraction\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        fgets(choix_str, sizeof(choix_str), stdin);
        choix = atoi(choix_str);

        switch (choix) {
            case 1:
                printf("Entrez les deux nombres à additionner : ");
                fgets(choix_str, sizeof(choix_str), stdin);
                sscanf(choix_str, "%d %d", &a, &b);
                printf("La somme est : %d\n", addition(a, b));
                break;
            case 2:
                printf("Entrez les deux nombres à soustraire : ");
                fgets(choix_str, sizeof(choix_str), stdin);
                sscanf(choix_str, "%d %d", &a, &b);
                printf("La différence est : %d\n", soustraction(a, b));
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez choisir à nouveau.\n");
                break;
        }
        // Nettoyer le tampon d'entrée
        while (getchar() != '\n');

    } while (choix != 3);

    return 0;
}

