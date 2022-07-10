#include "Slider.h"

VideoCapture* m_video;

void onTrackbarSlide(int pos) {
	cvSetCaptureProperty(
		m_video->get(),
		CV_CAP_PROP_POS_FRAMES,
		pos);
}


Slider::Slider(
	const std::string &name,
	const std::string& nameWindow,
	VideoCapture *video) :
	m_name(name),
	m_nameWindow(nameWindow)
{
	m_video = video;

	cvCreateTrackbar(
		name.c_str(),
		nameWindow.c_str(),
		&m_pos,
		static_cast<int>(video->nFrames()),
		onTrackbarSlide);

}

void Slider::next()
{
	cvSetTrackbarPos(m_name.c_str(), m_nameWindow.c_str(), m_pos + 1);
}


