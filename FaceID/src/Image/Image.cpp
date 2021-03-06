#include "Image.h"

Image::Image(IplImage* frame) :
	m_img(frame, [](IplImage* frme) {cvReleaseImage(&frme); })
{

}

Image::Image(const std::string& path) : Image(cvLoadImage(path.c_str()))
{
}

Image::~Image()
{
}

IplImage* Image::get()
{
	return m_img.get();
}

IplImage* Image::release()
{
	return m_img.release();
}

bool Image::isEmpty() const
{
	return m_img == nullptr;
}

Image* Image::smooth() const
{
	IplImage* out = cvCreateImage(
		cvGetSize(m_img.get()),
		IPL_DEPTH_8U,
		3);
	cvSmooth(m_img.get(), out, CV_GAUSSIAN, 9, 9);

	return new Image(out);
}

Image* Image::pyrDown(int filter) const
{
	const int width = m_img.get()->width;
	const int height = m_img.get()->height;

	assert(width % 2 == 0 && height % 2 == 0);

	IplImage* out = cvCreateImage(
		cvSize(width / 2, height / 2),
		m_img.get()->depth,
		m_img.get()->nChannels);
	cvPyrDown(m_img.get(), out);

	return new Image(out);
}

Image* Image::canny(
	const double lowThresh,
	const double highThresh,
	const double aperture)
{
	IplImage* out = cvCreateImage(
		cvSize(m_img.get()->width, m_img.get()->height),
		IPL_DEPTH_8U,
		1);
	canny(m_img.get(), lowThresh, highThresh, aperture, out);

	return new Image(out);
}

Image* Image::toGray()
{	
	IplImage* out = cvCreateImage(
		cvSize(m_img.get()->width, m_img.get()->height),
		IPL_DEPTH_8U,
		1);
	gray(m_img.get(), out);

	return new Image(out);
}

void Image::gray(IplImage* src, IplImage* dst)
{
	cvCvtColor(src, dst, CV_RGB2GRAY);
}

void Image::canny(
	IplImage* src,
	const double lowThresh,
	const double highThresh,
	const double aperture,
	IplImage* dst)
{
	if (src->nChannels != 1)
		return;
	cvCanny(src, dst, lowThresh, highThresh, (int)aperture);
}

//IplImage* Image::clone(IplImage* src)
//{
//	IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
//	cvCopy(src, dst); 
//	return dst;
//}

void Image::addScalar(CvRect rect, const float scalar)
{
	setRoi(rect);
	cvAddS(m_img.get(), cvScalar(scalar), m_img.get());
	unsetRoi();
}

void Image::setRoi(CvRect rect)
{
	cvSetImageROI(m_img.get(), rect);
}

void Image::unsetRoi()
{
	cvResetImageROI(m_img.get());
}

void Image::alphaMixie(
	Image& src1,
	Image& src2,
	float beta,
	Image& dst, 
	float gamma)
{
	cvAddWeighted(src1.get(), beta, src2.get(), 1 - beta, gamma, dst.get());
}
