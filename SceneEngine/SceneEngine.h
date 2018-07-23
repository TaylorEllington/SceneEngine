#pragma once
#include <Windows.h>
#include <wrl.h>
#include <string>


#include <d3d12.h>
#include <dxgi1_4.h>

#pragma comment(lib,"d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")
#pragma comment(lib, "dxgi.lib")

class SceneEngine
{
public:
    SceneEngine();
    ~SceneEngine();

    bool InitWindow();
    bool InitDirectX();
    bool LoadAssets();

    void Run();


private:

    //Windows wierdness, this string must match in both the RegisterClassEx and CreateWindowEx
    //Function calls, or else you get a 1407 - ERROR_CANNOT_FIND_WND_CLASS
    std::wstring mMainWndClassName = L"MainWnd";
    //Window Init stuff
    HINSTANCE mhAppInst = nullptr; //application instance handle
    HWND      mhMainWnd = nullptr; //window handle
    std::wstring mMainWndCaption = L"d3d App";
    DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
    int mWidth = 500;
    int mHeight = 500;


};

