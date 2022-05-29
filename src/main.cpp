#include "raylib.h"
#include "gamecontroller.h"

using namespace sound;
using namespace controller;

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Battle System");

    GameController _game;
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
    	_game.Update(); //Update Logic Phase

    	_game.Draw();	//Update Draw Phase
    }

    CloseAudioDevice();     // Close audio device (music streaming is automatically stopped)

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
