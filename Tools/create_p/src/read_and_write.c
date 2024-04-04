
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "read_and_write.h"

char *read_file(const char *filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    perror("Erreur lors de l'ouverture diu fichier");
    return NULL;
  }
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  rewind(file);

  char *content = (char *)malloc(size + 1);
  if (content == NULL)
  {
    perror("Erreur lors de l'allocation mémoire");
    fclose(file);
    return NULL;
  }
  fread(content, 1, size, file);
  content[size] = '\0';
  fclose(file);

  return content;
}

int write_file(const char *filename, const char *content)
{
  FILE *file = fopen(filename, "w");

  if (file == NULL)
  {
    perror("Erreur lors de l'ouverture du fichier");
    return 1;
  }

  fprintf(file, "%s", content);
  fclose(file);
  
  return 0;
}

