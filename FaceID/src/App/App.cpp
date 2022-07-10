#include "App.h"

#include "../Primitive/Primitive.h"
#include "../Matrix2d/Matrix2d.h"
#include "../Settings/Setting.h"

App::App() : 
	m_window1("Window1"),
	m_window2("Window2"),
	//m_window3("Window3"),
	//m_window4("Window4"),
	m_window5("Window5"),
	m_image("Data/airplane.jpg"),
	m_video("Data/2.AVI"),
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
	//m_window5.draw(m_cam);
	//m_image.addScalar(cvRect(230, 220, 100, 30), 150);
	//m_window5.draw(m_image);
	//std::unique_ptr<Image> rect(Rect::create(0, 0, 640, 480, {0, 0, 255}));
	//m_window5.draw(rect.get());
	//Matrix2d<float> mat({ 1, 2, 3, 4 }, 2, 2, CV_32FC1);
	//print(mat.get(1, 1));

	Image lena("Data/lena.jpg");
	lena.setRoi(cvRect(210, 210, 150, 150));
	m_window1.draw(lena);
	Image fruits("Data/fruits.jpg");
	fruits.setRoi(cvRect(120, 120, 150, 150));
	m_window5.draw(fruits);
	Image::alphaMixie(lena, fruits, 0.6f, fruits);
	lena.unsetRoi();
	fruits.unsetRoi();
	m_window2.draw(fruits);


	cvWaitKey(0);
}
