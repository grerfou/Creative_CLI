
//-----------------------------Documentation------------------------

//------------------------------------------------------------------


//-----------------------------Directive processeur-----------------

#include "stdio.h"
#include "raylib.h"

//------------------------------------------------------------------



//--------------------------------Déclaration Globales--------------

//------------------------------------------------------------------



//------------------------------Fonction Principales----------------

int main(void)
{

  const int screenWidth = 800;
  const int screenHeight = 450;

  InitWindow(screenWidth, screenHeight, "window name");

  SetTargetFPS(60); //fps


  // Simulation Boucle
  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(RAYWHITE);

    EndDrawing();
  }

  CloseWindow();
  return 0;

}

//------------------------------------------------------------------

//-------------------------------Sous-Programme---------------------

//------------------------------------------------------------------

