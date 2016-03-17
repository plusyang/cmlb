
#include <opencv2/opencv.hpp>
#include<iostream>

cv::Mat fspecial(std::string type,int m,int n,int sigma){
	cv::Mat resK;
	if(type=="gaussian"){
		double cx = (double)(m - 1) / 2;
		double cy = (double)(n - 1) / 2;
		cv::Mat K(m, n, CV_64FC1);
		double s2 = 2.0 * sigma * sigma;
		double x2, y2;
		for (int i = 0; i < m; i++)
		{
			x2 = pow(double(i - cx), 2);
			for (int j = 0; j < n; j++)
			{
				y2 = pow(double(j - cy), 2);
				K.ptr<double>(i)[j] = exp(-(x2 + y2) / s2);
			}
		}
		cv::Scalar all = sum(K);
//		std::cout<<1/all[0]<<std::endl;
		K.convertTo(resK, CV_32FC1,1/all[0]);
	}
	return resK;
}
