#pragma once
#include <string>
#include <memory>
#include <functional>
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>
#include <OpenCV/cxcore/cxtypes.h>


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

	void addScalar(CvRect rect, const float scalar);

	void setRoi(CvRect rect);
	void unsetRoi();

	static void alphaMixie(Image& src1, Image& src2, float beta, Image& dst, float gamma = 0.0f);

private:
	std::unique_ptr<IplImage, std::function<void(IplImage*)>> m_img = nullptr;
};


