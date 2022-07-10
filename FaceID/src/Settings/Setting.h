#pragma once
#include <iostream>
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>

using cvImage = IplImage;

template<typename T>
void print(const T& data)
{
	std::cout << data << "\n";
}