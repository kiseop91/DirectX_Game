#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>


#include "InputClass.h"
#include "GraphicsClass.h"

class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass& _other);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND _hwnd, UINT _umsg, WPARAM _wparam, LPARAM _lparam);

private:
	bool Frame();
	void IntializeWindows(int& _screenWidth, int& _screenHeight);
	void ShutDownWindows();

private:
	LPCWSTR m_ApplicationName;
	HINSTANCE m_hInstance;
	HWND m_Hwnd;

	InputClass* m_Input;
	GraphicsClass* m_Graphics;

};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static SystemClass* ApplicationHandle = 0;
