#pragma once
#include "../Window/Window.h"
#include "../VideoCapture/VideoCapture.h"

class App
{
public:
	App();
	~App() = default;
	void run();
private:
	Window m_window1;
	Window m_window2;
	//Window m_window3;
	//Window m_window4;
	Window m_window5;
	Image m_image;
	VideoCapture m_video;
	Camera m_cam;
};

