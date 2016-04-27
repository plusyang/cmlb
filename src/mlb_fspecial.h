/*
 * mlb_fspecial.h
 *
 *  Created on: 2016年4月27日
 *      Author: yzh
 */

#ifndef MLB_FSPECIAL_H_
#define MLB_FSPECIAL_H_

#include <opencv2/opencv.hpp>
#include<iostream>
/**
 * 生成核函数
 * @param type 'gaussian'---->高斯窗函数
 * @param m,n 矩阵size
 * @param sigma
 * @return
 */
cv::Mat fspecial(std::string type,int m,int n,int sigma);

#endif /* MLB_FSPECIAL_H_ */
