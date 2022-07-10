#include "VideoWriter.h"

VideoWriter::VideoWriter(const std::string &name, int w, int h) : m_w(w), m_h(h)
{
	m_writer = cvCreateVideoWriter(
		name.c_str(),
		CV_FOURCC('i', 'Y', 'U', 'V'),
		30.f,
		cvSize(w, h));

	m_logpolarFrame = cvCreateImage(
		cvSize(m_w, m_h),
		IPL_DEPTH_8U,
		3);

}

VideoWriter::~VideoWriter()
{
	cvReleaseImage(&m_logpolarFrame);
	cvReleaseVideoWriter(&m_writer);
}

void VideoWriter::add(IplImage* frame)
{
	//cvLogPolar(
	//	frame,
	//	m_logpolarFrame,
	//	cvPoint2D32f(
	//		frame->width / 2,
	//		frame->height / 2),
	//	40,
	//	CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS);
	//cv2.cvtColor(imgname, cv2.COLOR_GRAY2BGR)

	cvWriteFrame(m_writer, frame);
}
