#pragma once
#include <string>
#include <OpenCV/otherlibs/highgui/highgui.h>
#include <OpenCV/cv/cv.h>

class Mouse
{
public:
	Mouse(const std::string nameWindow);
	~Mouse();
	IplImage* rectangle();
private:
	IplImage* m_image = nullptr;
	IplImage* m_temp = nullptr;
};

