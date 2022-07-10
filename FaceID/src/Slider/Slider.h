#pragma once
#include <string>
#include <OpenCV/otherlibs/highgui/highgui.h>
#include "../VideoCapture/VideoCapture.h"

class Slider
{
public:
	Slider(
		const std::string& name,
		const std::string& nameWindow,
		VideoCapture* video);
	~Slider() = default;
	void next();
private:
	int m_pos = 0;
	const std::string m_name;
	const std::string m_nameWindow;
};

