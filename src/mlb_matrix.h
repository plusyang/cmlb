/*
 * mlb_matrix.h
 *
 *  Created on: 2016年4月27日
 *      Author: yzh
 */

#ifndef MLB_MATRIX_H_
#define MLB_MATRIX_H_

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
using namespace cv;

/**
 * 显示mat
 * @param mat
 * @param line
 */
void showMat(Mat mat,int line);

/**
 * 二维卷积(see matlab conv2)
 * 边缘填充 0
 * @param src  源
 * @param kernel  核
 * @param flag 卷积类型  full--->Returns the full two-dimensional convolution (default) , 返回mat大小为 src+kernel-1
 * 					same--->Returns the central part of the convolution of the same size as A.
 * @return
 */
Mat conv2(const Mat & src,Mat &y,string flag="full");

/**
 * 二维滤波(see matlab filter)
 * @param kernel
 * @param src
 * @return
 */
Mat filter2(Mat kernel, const Mat & src);

#endif /* MLB_MATRIX_H_ */
