#include "Window.h"

#include <iostream>
#include "../VideoWriter/VideoWriter.h"

Window::Window(const std::string& name) : 
	m_name(name)
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
	IplImage* canny = cvCreateImage(
		cvSize(w, h),
		IPL_DEPTH_8U,
		1);
	IplImage* gray = cvCreateImage(
		cvSize(w, h),
		IPL_DEPTH_8U,
		1);

	auto nextFrame = [&]() {
		IplImage* frame = camera.getFrame();
		Image::gray(frame, gray);
		Image::canny(gray, 100, 100, 3, canny);

		return canny;
	};
	auto callback = [&](IplImage* currFrame) {
		write.add(currFrame);
	};
	drawLoop(nextFrame, callback);

	Image t1(gray);
	Image t2(canny);
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

void Window::draw()
{
	Mouse mouse(m_name.c_str());
	auto nextFrame = [&]() {
		return mouse.rectangle();
	};
	auto callback = [](IplImage* currFrame) {};
	drawLoop(nextFrame, callback);
}
