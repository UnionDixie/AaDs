#pragma once
#include <tuple>
#include <OpenCV/otherlibs/highgui/highgui.h>
#include "../Settings/Setting.h"
#include "../Image/Image.h"

namespace Primitive {

	Image* createRect(
		const int x, 
		const int y, 
		const int w,
		const int h, 
		const std::tuple<int, int, int> bgrColor)
	{
		IplImage* img = cvCreateImage(
			cvSize(w, h),
			IPL_DEPTH_8U,
			3);
		const auto [b, g, r] = bgrColor;
		cvRectangle(
			img,
			cvPoint(x, y),
			cvPoint(x + w, y + h),
			cvScalar(b, g, r));

		return new Image(img);
	}

	Image* createLine(
		IplImage* img,
		CvPoint p1,
		CvPoint p2,
		CvScalar color,
		int thickness = 1,
		int connectivity = 8)
	{
		cvLine(img, p1, p2,	color, thickness, connectivity);

		return new Image(img);
	}

	//circle
	//ellipse
	//poly


	//text and font

}




