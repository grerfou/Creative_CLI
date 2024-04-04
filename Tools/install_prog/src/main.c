#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vérifie si un logiciel est installé
int isInstalled(const char *software) {
    FILE *fp;
    char command[100];

    // Utilise which pour vérifier si le logiciel est installé
    sprintf(command, "which %s > /dev/null 2>&1", software);
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Erreur lors de l'exécution de la commande.\n");
        exit(EXIT_FAILURE);
    }

    // sortie de la commande
    int status = pclose(fp);

    // Si statut commande est 0 logiciel installé
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Fonction pour installer un logiciel
void installSoftware(const char *software) {
    printf("Installation de %s...\n", software);

    // commande systèm pour install le logiciel
    char command[100];
    sprintf(command, "brew install %s ", software);
    system(command);
}

int main() {
    // Liste des logiciels nécessaires
    const char *requiredSoftware[] = {"gcc", "make", "raylib", "node", "processing"};

    // Vérifier et installer les logiciels nécessaires
    int i;
    for (i = 0; i < sizeof(requiredSoftware) / sizeof(requiredSoftware[0]); i++) {
        if (!isInstalled(requiredSoftware[i])) {
            installSoftware(requiredSoftware[i]);
        } else {
            printf("%s est déjà installé.\n", requiredSoftware[i]);
        }
    }
    return 0;
}




/*
*
*
* Comment je fait pour crée mon MakeFile dans mon cli ? 
* Comment je commente le code pour dire que j'ai modifier le Makefile ? 
*
*
*/


