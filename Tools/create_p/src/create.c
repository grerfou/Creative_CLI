
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "create.h"
#include "read_and_write.h"

int create_c()
{
  if (mkdir("projet", 0777) == -1) {
    return 1;
  }

  if (chdir("projet") == -1) {
    return 1;
  }

  if (mkdir("src", 0777) == -1) {
    return 1;
  }

  if (chdir("src") == -1) {
    return 1;
  }

  char *makefile_content = read_file("../../template/makefile_template_c.txt");
  // Chemin 2 fois vers l'arriere car dans le repertoire "src"
  if (makefile_content == NULL) {
    return 1;
  }

  char *main_c_content = read_file("../../template/main_c_template.txt");
  if (main_c_content == NULL) {
    free(makefile_content);
    return 1;
  }

  if (write_file("Makefile", makefile_content) != 0) {
    free(makefile_content);
    free(main_c_content);
    return 1;
  }

  if (write_file("main.c", main_c_content) != 0) {
    free(makefile_content);
    free(main_c_content);
    return 1;
  }

  free(makefile_content);
  free(main_c_content);

  printf("Dossier 'projet' créé avec succès.\n");
  printf("Dossier 'src' créé avec succès.\n");
  printf("Makefile et main.c écrits à l'intérieur de src.\n");

    return 0;
}


int create_cpp()
{
  if (mkdir("projet", 0777) == -1) {
    return 1;
  }

  if (chdir("projet") == -1) {
    return 1;
  }

  if (mkdir("src", 0777) == -1) {
    return 1;
  }

  if (chdir("src") == -1) {
    return 1;
  }

  char *makefile_content = read_file("../../template/makefile_template_cpp.txt");
  // Chemin 2 fois vers l'arriere car dans le repertoire "src"
  if (makefile_content == NULL) {
    return 1;
  }

  char *main_cpp_content = read_file("../../template/main_cpp_template.txt");
  if (main_cpp_content == NULL) {
    free(makefile_content);
    return 1;
  }

  if (write_file("Makefile", makefile_content) != 0) {
    free(makefile_content);
    free(main_cpp_content);
    return 1;
  }

  if (write_file("main.cpp", main_cpp_content) != 0) {
    free(makefile_content);
    free(main_cpp_content);
    return 1;
  }

  free(makefile_content);
  free(main_cpp_content);

  printf("Dossier 'projet' créé avec succès.\n");
  printf("Dossier 'src' créé avec succès.\n");
  printf("Makefile et main.c écrits à l'intérieur de src.\n");

    return 0;
}


int create_p()
{
  if (mkdir("project_processing", 0777) == -1)
  {
    perror("Erreur lors de la création du dossier project-processing");
    return 1;
  }

  if (chdir("project_processing") == -1)
  {
    perror("Erreur lors du changement de repertoire vers project-processing");
    return 1;
  }

  char *processing_content = read_file("../template/processing_template.txt");
  if (processing_content == NULL)
  {
    return 1;
  }

  if (write_file("project_processing.pde", processing_content) !=0)
  {
    free(processing_content);
    return 1;
  }

  free(processing_content);

  printf("Dossier processing-project crée avec succée !\n");
  printf("project-processing ecrit avec sucsée !\n");
  
  return 0;
}









