
/*

Programme permettant de crée un template de programe .c pour travailler avec raylib

*/



#include <stdio.h>      //  Bibliothéque standart entrée sortie en c
#include <stdlib.h>     //  Bibliotheque standart allocation dynamique, controle process..
#include <sys/stat.h>   //  Bibliotheque manipulationn de fichier 
#include <unistd.h>     //  Bibliothéque gestion de process (chdir)

//  Lire le contenue d'un fichier 
char *read_file(const char *filename) { 
    FILE *file = fopen(filename, "r");                                    //  Ouverture du fichier 
    if (file == NULL) {                                                   //  Verifie ouverture du fichier 
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;                                                      //  Null si erreur 
    }

    fseek(file, 0, SEEK_END);                                             //  Curseur fin du fichier 
    long size = ftell(file);                                              //  Position du curseur --> taille du fichier 
    rewind(file);                                                         //  Curseur début de fichier 

    char *content = (char *)malloc(size + 1);                             //  Stock le contenue du fichier 
    if (content == NULL) {                                                //  Vérifie allocation mémoire
        perror("Erreur lors de l'allocation de mémoire");
        fclose(file);                                                     //  Fermeture du fichier 
        return NULL;                                                      //  Null si erreur
    }

    fread(content, 1, size, file);                                        //  Lit contenue du fichier dans content 
    content[size] = '\0';                                                 //  Null à la fin pour terminer la chaine de caractére 
    fclose(file);                                                         //  Fermeture du fichier 

    return content;                                                       //  Retourne le contenue du fichier 
}

// Ecrire dans un fichier 
int write_file(const char *filename, const char *content) {
    FILE *file = fopen(filename, "w");                                    //  Ouvre le fichier en ecriture (w), crée le fichier si il n'existe pas 
    if (file == NULL) {                                                   //  Vérifie ouverture fichier 
        perror("Erreur lors de l'ouverture du fichier");
        return 1;                                                         //  1 si erreur 
    }

    fprintf(file, "%s", content);                                         //  Ecrit le contenue du fichier 
    fclose(file);                                                         //  Ferme le fichier

    return 0;                                                             // O si valide 
}

// Fonction principale
int main() {
    if (mkdir("projet", 0777) == -1) {                                                //  Crée dossier "projet" 
        perror("Erreur lors de la création du dossier");
        return 1;                                                                     //  1 si erreur
    }

    if (chdir("projet") == -1) {                                                      //  Répertoir --> "projet"
        perror("Erreur lors du changement de répertoire");
        return 1;                                                                     //  1 si erreur 
    }

    if (mkdir("src", 0777) == -1) {                                                   //  Crée un dossier "src" dans "projet"
        perror("Erreur lors de la création du dossier src");
        return 1;                                                                     //  1 si erreur 
    }

    if (chdir("src") == -1) {                                                         //  Répertoire --> "src"
        perror("Erreur lors du changement de répertoire vers src");
        return 1;                                                                     //  1 si erreur 
    }

    char *makefile_content = read_file("../../template/makefile_template.txt");       //  Lit le fichier  
    if (makefile_content == NULL) {
        return 1;                                                                     //  1 si erreur 
    }

    char *main_c_content = read_file("../../template/main_cpp_template.txt");           //  Lit le fichier 
    if (main_c_content == NULL) {
        free(makefile_content);                                                       //  Libérent la mémoire 
        return 1;                                                                     //  1 si erreur
    }

    if (write_file("Makefile", makefile_content) != 0) {                              //  Ecrit Makefile
        free(makefile_content);                                                       //  Libérent la mémoire 
        free(main_c_content);                                                         //  Libérent la mémoire
        return 1;                                                                     //  1 si erreur
    }

    if (write_file("main.cpp", main_c_content) != 0) {                                  //  Ecrit main.c 
        free(makefile_content);                                                       //  Libérent la mémoire
        free(main_c_content);                                                         //  Libérent la mémoire 
        return 1;                                                                     //  1 si erreur 
    }

    free(makefile_content);                                                           //  Libérent la mémoire 
    free(main_c_content);                                                             //  Libérent la mémoire 

    printf("Dossier 'projet' créé avec succès.\n");                                   //
    printf("Dossier 'src' créé avec succès.\n");                                      //  Message de succées
    printf("Makefile et main.c écrits à l'intérieur de src.\n");                      //

    return 0;                                                                         //  0 si succées
}

