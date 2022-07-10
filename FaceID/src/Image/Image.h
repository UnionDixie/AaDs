#pragma once
#include <string>
#include <memory>
#include <functional>
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>

class Image
{
public:
	Image(const std::string& path);
	Image(IplImage* frame);
	~Image();

	IplImage* get();
	bool isEmpty() const;

	Image* smooth() const;
	Image* pyrDown(int filter = IPL_GAUSSIAN_5x5) const;
	Image* canny(const double lowThresh, const double highThresh, const double aperture);
	Image* toGray();

private:
	std::unique_ptr<IplImage, std::function<void(IplImage*)>> m_img = nullptr;
};


