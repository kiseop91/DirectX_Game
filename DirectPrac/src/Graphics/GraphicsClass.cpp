#include "Graphics/GraphicsClass.h"



GraphicsClass::GraphicsClass()
	:m_D3D(0)
{
}

GraphicsClass::GraphicsClass(const GraphicsClass & _others)
{
}


GraphicsClass::~GraphicsClass()
{
}

bool GraphicsClass::Initialize(int _screenWidth, int _screenHeight, HWND _hwnd)
{
	bool result;

	m_D3D = new D3DClass;
	if (!m_D3D)
	{
		return false;
	}

	//다이렉트 객체 초기화
	result = m_D3D->Initialize(_screenWidth, _screenHeight, VSYNC_ENABLED, _hwnd, FULL_SCREEN, SCREEN_DEPTH, SCREEN_NEAR);
	if (!result)
	{
		MessageBox(_hwnd, L"다이렉트 초기화 오류", L"Error", MB_OK);
		return false;
	}
	return true;
}

void GraphicsClass::Shutdown()
{
	if (m_D3D)
	{
		m_D3D->Shutdown();
		delete m_D3D;
		m_D3D = 0;
	}

	return;
}

bool GraphicsClass::Frame()
{
	bool result;

	result = Render();
	if (!result)
	{
		return false;
	}

	return true;
}

bool GraphicsClass::Render()
{
	//버퍼 삭제
	m_D3D->BeginScene(1.f, 0.0f, 1.0f, 1.0f);
	


	//버퍼 출력
	m_D3D->EndScene();

	return true;
}
