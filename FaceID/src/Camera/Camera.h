#pragma once
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>
#include <VideoInput/videoInput.h>

class Camera
{
public:
	Camera(int camInd = CV_CAP_ANY);
	~Camera();
	//dont free him
	IplImage* getFrame();

	std::pair<int, int> size();

private:
	//CvCapture* m_cap;
	videoInput m_vi;
	int deviceId = 0;
	IplImage* m_frame = nullptr;
};

