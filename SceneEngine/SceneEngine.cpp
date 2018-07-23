#include "SceneEngine.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

SceneEngine::SceneEngine()
{
    InitWindow();
    InitDirectX();
}


SceneEngine::~SceneEngine()
{
}

bool SceneEngine::InitWindow()
{

    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = mhAppInst;
    wc.hIcon = LoadIcon(0, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);
    wc.lpszMenuName = 0;
    wc.lpszClassName = mMainWndClassName.c_str();
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


    if (!RegisterClassEx(&wc))
    {
        MessageBox(0, L"something goofed in RegisterClass", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    //LUNA computes dimensions here, add later if neccessary. Hardcoded for now



    mhMainWnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        mMainWndClassName.c_str(),
        L"The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        mWidth, mHeight,
        NULL, NULL, mhAppInst, NULL);

    if (mhMainWnd == NULL)
    {
        DWORD dw = GetLastError();
        MessageBox(0, L"Something goofed in CreateWindow-", L"Error!", MB_ICONEXCLAMATION | MB_OK);
        return false;
    }

    ShowWindow(mhMainWnd, SW_SHOW);
    UpdateWindow(mhMainWnd);

    return true;

}

bool SceneEngine::InitDirectX()
{
    return false;
}

bool SceneEngine::LoadAssets()
{
    return false;
}

void SceneEngine::Run()
{

    //I guess this is the game loop
    MSG msg = { 0 };

   // mTimer.Reset();

    while (msg.message != WM_QUIT) {

        //get windows message
        if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else {
            //mTimer.Tick();
            //Update(mTimer);
            //Draw(mTimer);
        }
    }

}
