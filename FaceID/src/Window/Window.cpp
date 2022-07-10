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
	auto nextFrame = [&]() {
		return video.getNextFrame();
	};
	auto callback = [&](IplImage* currFrame) {
		slider.next();
	};
	drawLoop(nextFrame, callback);
}

void Window::draw(Camera& camera)
{
	const auto [w, h] = camera.size();
	VideoWriter write("3.avi", w, h);
	auto nextFrame = [&]() {
		return camera.getFrame();
	};
	auto callback = [&](IplImage* currFrame) {
		write.add(currFrame);
	};
	drawLoop(nextFrame, callback);
}

void Window::drawLoop(
	std::function<IplImage* ()> nextFrame,
	std::function<void(IplImage*)> callback)
{
	IplImage* frame = nullptr;
	int speed = 33;
	while (true) {
		frame = nextFrame();
		if (frame == nullptr)
			break;
		draw(frame);
		callback(frame);
		char keyCode = cvWaitKey(speed);
		if (keyCode == 27)
			break;
	}
}
