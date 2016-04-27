
#include <opencv2/opencv.hpp>
#include <iostream>
#include "mlb_fspecial.h"
using namespace std;
using namespace cv;


//修改
int fmain(int argc, char **argv) {
	Mat m=fspecial("gaussian",5,5,4);
	for(int y=0;y<m.rows;y++){
		float* data=m.ptr<float>(y);
		for(int x=0;x<m.cols;x++)
			cout<<(float)data[x]<<",  ";
		cout<<endl;
	}
//	imshow(" ",m);
	waitKey();
}
