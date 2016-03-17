#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

void showMat(Mat mat,int line){
	int row =mat.rows;
	int col= mat.cols;

	for(int i=0;i<line;i++){
		float* data=mat.ptr<float>(i);
		for(int j=0;j<col;j++){
			cout<<data[j]<<"  , ";
		}
		cout<<endl;
	}
}


Mat conv2(Mat &x,Mat &y,string flag="full"){  //x -->src  ,y-->kernel
	int x_r=x.rows;
	int x_c=x.cols;
	int y_r=y.rows;
	int y_c=y.cols;

	int z_r=x_r+y_r-1;
	int z_c=x_c+y_c-1;
	Mat z=Mat::zeros(z_r,z_c,CV_32FC1);

	Mat x32;
	x.convertTo(x32,CV_32FC1);

	Mat_<float> x_mat=x32;
	Mat_<float> y_mat=y;
	Mat_<float> z_mat=z;

	for(int i=0;i<z.rows;i++){
		for(int j=0;j<z.cols;j++){
			float temp=0;
			for(int m=0;m<y_r;m++){
				for(int n=0;n<y_c;n++){
					if( (i-m>=0)&&(i-m)<x_r && (j-n>=0)&&(j-n)<x_c ){
//						if(y_r==7)
//							cout<<"xxx " <<(double)x_mat(i-m,j-n)<<"   yyy "<<(double)y_mat(m,n)<<endl;
						temp+=y_mat(m,n)*x_mat(i-m,j-n);
					}
				}
			}
			z_mat(i,j)=temp;
		}
	}

	if(flag=="same"){
		Mat roi=z_mat(Rect(y_c/2,y_r/2,x_c,x_r));
		z=roi;
	}
	return z;
}

Mat filter2(Mat kernel,Mat & src){

	int krow=kernel.rows;
	int kcol=kernel.cols;
	int length=krow*kcol;

	Mat_<float> ker_mat=kernel;
	float* kdata=(float *)kernel.data;

	float swap=0;
	//kernel rot 180
	for(int i=0;i<length/2;i++){
		swap=kdata[i];
		kdata[i]=kdata[length-1-i];
		kdata[length-1-i]=swap;
	}

	kernel=Mat(krow,kcol,CV_32FC1,kdata);
	//showMat(kernel,3);
	return conv2(src,ker_mat,"same");
}

Mat dot_pow(Mat & src){
	int row=src.rows;
	int col=src.cols;

	Mat res;
	src.copyTo(res);
	Mat_<float> data=res;
	for(int i=0;i<row;i++)
		for(int j=0 ;j<col;j++)
			data(i,j)=pow(data(i,j),2);

	return res;
}
