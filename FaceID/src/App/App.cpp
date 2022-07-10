#include "App.h"

App::App() : 
	//m_window1("Window1"),
	//m_window2("Window2"),
	//m_window3("Window3"),
	//m_window4("Window4"),
	m_window5("Window5"),
	m_image("airplane.jpg"),
	m_video("2.AVI"),
	m_cam(0)
{
	
}

void App::run()
{
	//m_window1.draw(m_video);
	//m_window1.draw(m_image);
	//cvWaitKey(0);
	//std::unique_ptr<Image> smooth(m_image.smooth());
	//m_window2.draw(smooth.get());
	//std::unique_ptr<Image> pyrDown(m_image.pyrDown());
	//m_window3.draw(pyrDown.get());
	//std::unique_ptr<Image> pyrDown2(pyrDown->pyrDown());
	//std::unique_ptr<Image> gray(pyrDown2->toGray());
	//std::unique_ptr<Image> canny(smooth->toGray()->canny(100, 100, 3));
	//m_window4.draw(canny.get());

	m_window5.draw(m_cam);


	//cvWaitKey(0);
}
