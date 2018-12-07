#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
	// 线性混合操作，g(x) = αf1(x) + (1 - α)f2(x)

	// 定义Mat对象
	Mat src1, src2, dst;
	// 打开图片，src1和src2
	src1 = imread("D:/OpenCVProject/day1207/LinuxLogo.jpg");
	src2 = imread("D:/OpenCVProject/day1207/win7logo.jpg");

	// 判断图片src1和src2是否存在
	if (!src1.data){
		cout << "could not load image linux logo...." << endl;
		return -1;
	}
	if (!src2.data){
		cout << "could not load image win7 logo...." << endl;
		return -1;
	}

	// 定义α值
	double alpha = 0.5;

	// 判断2张图片的宽，高和类型是否一样
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()){
		// 混合图像API，
		/* 第1个参数，输入图片1;
		   第2个参数，图片1的融合比例;
		   第3个参数，输入图片2;
		   第4个参数，图片2的融合比例;
		   第5个参数，偏差;
		   第6个参数，输出图片*/
		addWeighted(src1, alpha, src2, (1.0 - alpha), 1.0, dst);

		// 展示3张图片
		imshow("linuxlogo", src1);
		imshow("win7logo", src2);
		imshow("blend demo", dst);

	}
	else
	{
		printf("could not blend image");
		return -1;
	}

	waitKey(0);
	return 0;

}
