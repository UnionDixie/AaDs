#include "Window.h"

#include <iostream>
#include "../VideoWriter/VideoWriter.h"

Window::Window(const std::string& name) : m_name(name)
{
	cvNamedWindow(m_name.c_str(), CV_WINDOW_AUTOSIZE);
}

Window::~Window()
{
	cvDestroyWindow(m_name.c_str());
}

void Window::draw(Image& image)
{
	cvShowImage(m_name.c_str(), image.get());
}

void Window::draw(Image* image)
{
	cvShowImage(m_name.c_str(), image->get());
}

void Window::draw(IplImage* image)
{
	cvShowImage(m_name.c_str(), image);
}

void Window::draw(VideoCapture& video)
{
	Slider slider("Bar", m_name, &video);
	IplImage* frame = nullptr;
	int speed = 33;
	while (true) {
		frame = video.getNextFrame();
		if (frame == nullptr)
			break;
		slider.next();
		draw(frame);
		char keyCode = cvWaitKey(speed);
		if (keyCode == 27)
			break;
		if (keyCode == 119)
			speed-=5;
		if (keyCode == 115)
			speed+=25;
		std::cout << speed << "\n";
	}
}

void Window::draw(Camera& camera)
{
	IplImage* frame = nullptr;
	const int speed = 33;
	const auto [w, h] = camera.size();
	VideoWriter write("3.avi", w, h);
	while (true) {
		frame = camera.getFrame();
		if (frame == nullptr)
			break;
		write.add(frame);
		draw(frame);
		char keyCode = cvWaitKey(speed);
		if (keyCode == 27)
			break;
	}
	int x = 5;
}
