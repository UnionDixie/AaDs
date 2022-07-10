#pragma once
#include <string>
#include <memory>
#include <OpenCV/otherlibs/highgui/highgui.h>

class VideoCapture
{
public:
	VideoCapture(const std::string nameVideoFile);
	~VideoCapture();
	IplImage* getNextFrame();
	CvCapture* get();
	double nFrames() const;
private:
	CvCapture* m_capture;
};

