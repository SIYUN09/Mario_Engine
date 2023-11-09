#include "MarioApplication.h"

namespace Mario
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		
	{

	}
	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		mPlayer.Update();
		mMonster.Update();
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		mPlayer.Render(mHdc);
		mMonster.Render(mHdc);
	}
}