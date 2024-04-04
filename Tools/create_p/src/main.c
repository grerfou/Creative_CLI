#include <stdio.h>
#include "create.h"


int main()
{
  if (create_cpp() != 0) 
  {
    perror("Erreur lors de la création du projet raylib en c ...");
    return 1;
  }

  return 0;
}



