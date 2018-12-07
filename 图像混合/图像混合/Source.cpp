#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){
	// ���Ի�ϲ�����g(x) = ��f1(x) + (1 - ��)f2(x)

	// ����Mat����
	Mat src1, src2, dst;
	// ��ͼƬ��src1��src2
	src1 = imread("D:/OpenCVProject/day1207/LinuxLogo.jpg");
	src2 = imread("D:/OpenCVProject/day1207/win7logo.jpg");

	// �ж�ͼƬsrc1��src2�Ƿ����
	if (!src1.data){
		cout << "could not load image linux logo...." << endl;
		return -1;
	}
	if (!src2.data){
		cout << "could not load image win7 logo...." << endl;
		return -1;
	}

	// �����ֵ
	double alpha = 0.5;

	// �ж�2��ͼƬ�Ŀ��ߺ������Ƿ�һ��
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()){
		// ���ͼ��API��
		/* ��1������������ͼƬ1;
		   ��2��������ͼƬ1���ںϱ���;
		   ��3������������ͼƬ2;
		   ��4��������ͼƬ2���ںϱ���;
		   ��5��������ƫ��;
		   ��6�����������ͼƬ*/
		addWeighted(src1, alpha, src2, (1.0 - alpha), 1.0, dst);

		// չʾ3��ͼƬ
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
