#pragma once
#include <string>
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>

class VideoWriter
{
public:
	VideoWriter(const std::string &name, int w, int h);
	~VideoWriter();

	void add(IplImage* frame);
private:
	CvVideoWriter* m_writer = nullptr;
	IplImage* m_logpolarFrame = nullptr;
	int m_w = 0;
	int m_h = 0;
};

