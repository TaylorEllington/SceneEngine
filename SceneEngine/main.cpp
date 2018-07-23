#include <windows.h>

#include "SceneEngine.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SceneEngine engine;


    engine.Run();

    return 0;
}