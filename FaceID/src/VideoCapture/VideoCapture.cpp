#include "VideoCapture.h"

VideoCapture::VideoCapture(const std::string nameVideoFile) :
	m_capture(cvCreateFileCapture(nameVideoFile.c_str()))
{

}

VideoCapture::~VideoCapture()
{
	cvReleaseCapture(&m_capture); // Закрытие файла
}

IplImage* VideoCapture::getNextFrame()
{
	return cvQueryFrame(m_capture);
}

CvCapture* VideoCapture::get()
{
	return m_capture;
}

double VideoCapture::nFrames() const
{
	return cvGetCaptureProperty(m_capture, CV_CAP_PROP_FRAME_COUNT);

}
