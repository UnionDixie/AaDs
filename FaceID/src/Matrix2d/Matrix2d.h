#pragma once
#include <string>
#include <vector>
#include <OpenCV/cv/cv.h>
#include <OpenCV/otherlibs/highgui/highgui.h>

template<typename Scalar>
class Matrix2d
{
public:
	//class Row
	//{
	//public:
	//	Row(CvMat* arr, const int row) : m_arr(arr), m_row(row)
	//	~Row() = default;
	//	Scalar& operator[](int coll)
	//	{
	//		//auto* mat = cvCreateMat(2, 2, CV_32FC1);
	//		//float d[] = { 1, 2, 3, 4 };
	//		//CvMat rotMat;
	//		//cvInitMatHeader(&rotMat, 2, 2, CV_32FC1, d);
	//		//cvGetElemType(&rotMat);
	//		//cvGetDims(&rotMat, nullptr);
	//		//cvGetDimSize(&rotMat, 0);
	//		float elent = CV_MAT_ELEM(rotMat, float, 0, 0);
	//		*((float*)CV_MAT_ELEM_PTR(*mat, 0, 0)) = 1.f;
	//	}
	//private:
	//	CvMat* m_arr;
	//	const int m_row;
	//};
	
	Matrix2d(CvMat* mat) : m_mat(*mat) 
	{
	}
	Matrix2d(
		const std::vector<Scalar> &data,
		int nRows, 
		int nColls,
		int type = CV_32FC1) :
		m_data(data),
		m_nRows(nRows),
		m_nColls(nColls),
		m_type(type)
	{
		cvInitMatHeader(&m_mat, m_nRows, m_nColls, m_type, m_data.data());
	}
	~Matrix2d() = default;

	void set(const int i, const int j, const Scalar &value)
	{
		*((float*)CV_MAT_ELEM_PTR(m_mat, i, j)) = value;
	}
	Scalar get(const int i, const int j)
	{
		return CV_MAT_ELEM(m_mat, float, i, j);
	}

	void save(const std::string& name)
	{
		cvSave(name.c_str(), &m_mat);
	}

	static Matrix2d<Scalar> load(const std::string& name)
	{
		return Matrix2d<Scalar>(cvLoad(name.c_str()));
	}

private:
	std::vector<Scalar> m_data;
	const int m_nRows = 0;
	const int m_nColls = 0;
	const int m_type = 0;
	CvMat m_mat;
};

