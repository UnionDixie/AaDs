#pragma once
#include <string>
#include <functional>
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>
#include "../Image/Image.h"
#include "../VideoCapture/VideoCapture.h"
#include "../Slider/Slider.h"
#include "../Camera/Camera.h"

class Window
{
public:
	Window(const std::string &name);
	~Window();
	void draw(Image& image);
	void draw(Image* image);
	void draw(IplImage* image);
	void draw(VideoCapture& video);
	void draw(Camera& camera);

	void drawLoop(
		std::function<IplImage*()> nextFrame,
		std::function<void(IplImage*)> callback);

private:
	const std::string m_name = "Window";
};