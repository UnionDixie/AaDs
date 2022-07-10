#include "Mouse.h"

CvRect box;
bool drawing_box = false;

void draw_box(IplImage* img, CvRect rect) {
	cvRectangle(
		img,
		cvPoint(box.x, box.y),
		cvPoint(box.x + box.width, box.y + box.height),
		cvScalar(0xff, 0x00, 0x00));
}

void my_mouse_callback(int event, int x, int y, int flags, void* param) {
	IplImage* image = (IplImage*)param;
	switch (event) {
	case CV_EVENT_MOUSEMOVE: {
		if (drawing_box) {
			box.width = x - box.x;
			box.height = y - box.y;
		}
	}
	break;
	case CV_EVENT_LBUTTONDOWN: {
		drawing_box = true;
		box = cvRect(x, y, 0, 0);
	}
	break;
	case CV_EVENT_LBUTTONUP: {
		drawing_box = false;
		if (box.width < 0) {
			box.x += box.width;
			box.width *= -1;
		}
		if (box.height < 0) {
			box.y += box.height;
			box.height *= -1;
		}
		draw_box(image, box);
	}
	break;
	}
}

Mouse::Mouse(const std::string nameWindow)
{
	box = cvRect(-1, -1, 0, 0);
	m_image = cvCreateImage(
		cvSize(200, 200),
		IPL_DEPTH_8U,
		3);
	cvZero(m_image);
	m_temp = cvCloneImage(m_image);
	cvSetMouseCallback(
		nameWindow.c_str(),
		my_mouse_callback,
		(void*)m_image);
}

Mouse::~Mouse()
{
	cvReleaseImage(&m_image);
	cvReleaseImage(&m_temp);
}

IplImage* Mouse::rectangle()
{
	cvCopyImage(m_image, m_temp);
	if (drawing_box)
		draw_box(m_temp, box);
	return m_temp;
}
