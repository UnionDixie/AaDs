#include "Camera.h"

#include <iostream>

Camera::Camera(int camInd)
{
	//m_cap = cvCreateCameraCapture(camInd); // Захват изображения с камеры
	//assert(m_cap != nullptr);
    //
	//cvSetCaptureProperty(m_cap, CV_CAP_PROP_FRAME_WIDTH, 320);//1280); 
	//cvSetCaptureProperty(m_cap, CV_CAP_PROP_FRAME_HEIGHT, 240);//960);
    //
	//double width = cvGetCaptureProperty(m_cap, CV_CAP_PROP_FRAME_WIDTH);
	//double height = cvGetCaptureProperty(m_cap, CV_CAP_PROP_FRAME_HEIGHT);
	//std::cout << width << " " <<  height << "\n";

    int numDevices = m_vi.listDevices();
    m_vi.setIdealFramerate(deviceId, 30);
    m_vi.setupDevice(deviceId, 1280, 960, VI_COMPOSITE);
    m_vi.showSettingsWindow(deviceId);  

    m_frame = cvCreateImage(
        cvSize(m_vi.getWidth(deviceId), m_vi.getHeight(deviceId)),
        IPL_DEPTH_8U,
        3);
}

Camera::~Camera()
{
	//cvReleaseCapture(&m_cap);
    m_vi.stopDevice(deviceId);
}

IplImage* Camera::getFrame()
{
    if (m_vi.isFrameNew(deviceId))
        m_vi.getPixels(
            deviceId, 
            (unsigned char*)m_frame->imageData,
            false, 
            true); 

	return m_frame;
}

std::pair<int, int> Camera::size()
{
    return std::pair<int, int>(m_vi.getWidth(deviceId), m_vi.getHeight(deviceId));
}
